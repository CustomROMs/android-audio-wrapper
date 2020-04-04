/*
 * Copyright (C) 2011 The Android Open Source Project
 * Copyright (C) 2013 Thomas Wendt <thoemy@gmx.net>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "AudioWrapper"
//#define LOG_NDEBUG 0

#include <errno.h>
#include <pthread.h>
#include <stdint.h>
#include <malloc.h>
#include <sys/time.h>
#include <dlfcn.h>

#include <cutils/log.h>

#include "common.h"
#include "include/4.0/hardware/audio.h"

#include <utils/KeyedVector.h>

#include "audio_hw.h"
//#include "audiohw_symbols.h"
//#include <hardware/audio.h>

#include <hardware/hardware.h>
#include <system/audio.h>

using android::KeyedVector;
using android::SortedVector;

using android::NO_ERROR;

//#include <hardware_legacy/AudioHardwareInterface.h>
//#include <hardware_legacy/AudioSystemLegacy.h>

extern "C" void *gHandle;

struct AudioHardwareANM *gANM;

SortedVector<struct AudioStreamInANM*> *gInputs;
SortedVector<struct AudioStreamOutANM*> *gOutputs;
SortedVector<struct AudioStreamInANM*> *gInANMs;
SortedVector<struct AudioStreamOutANM*> *gOutANMs;

#include "audiohw_symbols.cpp"

extern "C" {
	int legacy_adev_open(const hw_module_t* module, const char* name,
                            hw_device_t** device);
							
	int legacy_adev_close(hw_device_t* device);
	size_t legacy_adev_get_input_buffer_size(const struct audio_hw_device *dev,
                                         const struct audio_config *config);
	int legacy_adev_open_input_stream(struct audio_hw_device *dev,
                                  audio_io_handle_t handle,
                                  audio_devices_t devices,
                                  struct audio_config *config,
                                  struct audio_stream_in **stream_in,
                                  audio_input_flags_t flags __unused,
                                  const char *address __unused,
                                  audio_source_t source __unused);
	void legacy_adev_close_input_stream(struct audio_hw_device *dev,
                               struct audio_stream_in *stream);
}

struct audio_hw_device *gDevice;

struct wrapper_audio_device {
    struct audio_hw_device device;
    struct wrapper::audio_hw_device *wrapped_device;
};

struct wrapper_stream_out {
    struct audio_stream_out stream;
    struct wrapper::audio_stream_out *wrapped_stream;
};

struct wrapper_stream_in {
    struct audio_stream_in stream;
    struct wrapper::audio_stream_in *wrapped_stream;
};

struct legacy_audio_module {
    struct audio_module module;
};

struct legacy_audio_device {
    struct audio_hw_device device;

    struct AudioHardwareInterface *hwif;
};

struct legacy_stream_out {
    struct audio_stream_out stream;

    void *unk0;
    void *unk1;
    struct AudioStreamOutANM *legacy_out;
};

struct legacy_stream_in {
    struct audio_stream_in stream;

   struct AudioStreamInANM *legacy_in;
};

enum {
    HAL_API_REV_1_0,
    HAL_API_REV_2_0,
    HAL_API_REV_NUM
} hal_api_rev;

/**
 * device macros.
 */
#define WRAPPED_DEVICE(d) (((struct wrapper_audio_device*) d)->wrapped_device)

#define WRAPPED_DEVICE_CALL(d, func, ...) ({\
    WRAPPED_DEVICE(d)->func(WRAPPED_DEVICE(d), ##__VA_ARGS__);   \
})

#define RETURN_WRAPPED_DEVICE_CALL(d, func, ...) ({\
    ALOGV("%s", __FUNCTION__); \
    return WRAPPED_DEVICE(d)->func(WRAPPED_DEVICE(d), ##__VA_ARGS__); \
})

/**
 * Stream in macros.
 */
#define WRAPPED_STREAM_IN(p) (((struct wrapper_stream_in*) p)->wrapped_stream)
#define WRAPPED_STREAM_IN_COMMON(s) (WRAPPED_STREAM_IN(s)->common)
#define WRAPPED_STREAM_IN_COMMON_CALL(s, func, ...) ({\
    WRAPPED_STREAM_IN_COMMON(s).func(&WRAPPED_STREAM_IN_COMMON(s), ##__VA_ARGS__); \
})
#define RETURN_WRAPPED_STREAM_IN_CALL(s, func, ...) ({\
    ALOGV("%s", __FUNCTION__); \
    return WRAPPED_STREAM_IN(s)->func(WRAPPED_STREAM_IN(s), ##__VA_ARGS__); \
})
#define RETURN_WRAPPED_STREAM_IN_COMMON_CALL(s, func, ...) ({\
    ALOGV("%s", __FUNCTION__); \
    return WRAPPED_STREAM_IN_COMMON(s).func(&WRAPPED_STREAM_IN_COMMON(s), ##__VA_ARGS__); \
})


/**
 * Stream out macros.
 */
#define WRAPPED_STREAM_OUT(p) (((struct wrapper_stream_out*) p)->wrapped_stream)
#define WRAPPED_STREAM_OUT_COMMON(s) (WRAPPED_STREAM_OUT(s)->common)
#define WRAPPED_STREAM_OUT_COMMON_CALL(s, func, ...) ({\
    WRAPPED_STREAM_OUT_COMMON(s).func(&WRAPPED_STREAM_OUT_COMMON(s), ##__VA_ARGS__); \
})
#define RETURN_WRAPPED_STREAM_OUT_CALL(s, func, ...) ({\
    ALOGV("%s", __FUNCTION__); \
    return WRAPPED_STREAM_OUT(s)->func(WRAPPED_STREAM_OUT(s), ##__VA_ARGS__); \
})
#define RETURN_WRAPPED_STREAM_OUT_COMMON_CALL(s, func, ...) ({\
    ALOGV("%s", __FUNCTION__); \
    return WRAPPED_STREAM_OUT_COMMON(s).func(&WRAPPED_STREAM_OUT_COMMON(s), ##__VA_ARGS__); \
})

static inline struct AudioStreamInANM* toInANM(struct audio_stream *in) {
	struct legacy_stream_in *lin;
	lin = (struct legacy_stream_in *)WRAPPED_STREAM_IN(in);
	struct AudioStreamInANM *inANM = (struct AudioStreamInANM*)lin->legacy_in;
	return inANM;
}

static inline struct AudioStreamInANM* toInANMc(const struct audio_stream *in) {
	struct legacy_stream_in *lin;
	lin = (struct legacy_stream_in *)WRAPPED_STREAM_IN(in);
	struct AudioStreamInANM *inANM = (struct AudioStreamInANM*)lin->legacy_in;
	return inANM;
}

static inline struct AudioStreamOutANM* toOutANM(struct audio_stream *out) {
	struct legacy_stream_out *lout;
	lout = (struct legacy_stream_out *)WRAPPED_STREAM_OUT(out);
	struct AudioStreamOutANM *outANM = (struct AudioStreamOutANM*)lout->legacy_out;
	return outANM;
}

static inline struct AudioStreamOutANM* toOutANMc(const struct audio_stream *out) {
	struct legacy_stream_out *lout;
	lout = (struct legacy_stream_out *)WRAPPED_STREAM_OUT(out);
	struct AudioStreamOutANM *outANM = (struct AudioStreamOutANM*)lout->legacy_out;
	return outANM;
}

static uint32_t out_get_sample_rate(const struct audio_stream *stream)
{
    struct AudioStreamOutANM *outANM = toOutANMc(stream);
	
	return outANM->mSampleRate;
}

static int out_set_sample_rate(struct audio_stream *stream, uint32_t rate)
{
    return 0;
}

static size_t out_get_buffer_size(const struct audio_stream *stream)
{
	struct AudioStreamOutANM *outANM = toOutANMc(stream);

	//RETURN_WRAPPED_STREAM_OUT_COMMON_CALL(stream, get_buffer_size);
	return android::AudioStreamOutANM::bufferSize(outANM);
}

static audio_channel_mask_t out_get_channels(const struct audio_stream *stream)
{
    struct AudioStreamOutANM *outANM = toOutANMc(stream);

	return outANM->mChannels;
}

static audio_format_t out_get_format(const struct audio_stream *stream)
{
    struct AudioStreamOutANM *outANM = toOutANMc(stream);

	return outANM->mFormat;
}

static int out_set_format(struct audio_stream *stream, audio_format_t format)
{
    return 0;
}

static int out_standby(struct audio_stream *stream)
{
    RETURN_WRAPPED_STREAM_OUT_COMMON_CALL(stream, standby);
}

static int out_dump(const struct audio_stream *stream, int fd)
{
    return 0;
}

static int out_set_parameters(struct audio_stream *stream, const char *kvpairs)
{
    ALOGI("%s: kvpairs: %s", __FUNCTION__, kvpairs);
    int ret;
    char * fixed_kvpairs = fixup_audio_parameters(kvpairs, JB_TO_ICS);
    ret = WRAPPED_STREAM_OUT_COMMON_CALL(stream, set_parameters, fixed_kvpairs);
    free(fixed_kvpairs);
    return ret;
}

static char * out_get_parameters(const struct audio_stream *stream, const char *keys)
{
    ALOGI("%s: keys: %s", __FUNCTION__, keys);
    char * kvpairs = WRAPPED_STREAM_OUT_COMMON_CALL(stream, get_parameters, keys);
    char * fixed_kvpairs = fixup_audio_parameters(kvpairs, ICS_TO_JB);
    free(kvpairs);
    return fixed_kvpairs;
}

static uint32_t out_get_latency(const struct audio_stream_out *stream)
{
    struct AudioStreamOutANM *outANM = toOutANM((struct audio_stream*)stream);

	return outANM->mLatency;
}

static int out_set_volume(struct audio_stream_out *stream, float left,
                          float right)
{
    return 0;
}

static ssize_t out_write(struct audio_stream_out *stream, const void* buffer,
                         size_t bytes)
{
    struct AudioStreamOutANM *outANM = toOutANM((struct audio_stream*)stream);
	
	//ALOGE("%s: bytes = %d", __func__, bytes); 
	
	//RETURN_WRAPPED_STREAM_OUT_CALL(stream, write, buffer, bytes);
	
	int ret = android::AudioStreamOutANM::write(outANM, buffer, bytes);
	//ALOGE("%s: bytes = %d, ret = %d", __func__, bytes, ret); 
	
	return ret;
}

static int out_get_render_position(const struct audio_stream_out *stream,
                                   uint32_t *dsp_frames)
{
	*dsp_frames=0;
	return NO_ERROR;
}

static int out_add_audio_effect(const struct audio_stream *stream, effect_handle_t effect)
{
    return NO_ERROR;
}

static int out_remove_audio_effect(const struct audio_stream *stream, effect_handle_t effect)
{
    return NO_ERROR;
}

/** audio_stream_in implementation **/
static uint32_t in_get_sample_rate(const struct audio_stream *stream)
{
    ALOGE("%s: ", __func__);
    struct AudioStreamInANM *inANM = toInANMc(stream);
	
	return inANM->mSampleRate;
}

static int in_set_sample_rate(struct audio_stream *stream, uint32_t rate)
{
    ALOGE("%s: implement me!", __func__);
	
	return 0;
}

static size_t in_get_buffer_size(const struct audio_stream *stream)
{
	ALOGE("%s: ", __func__);
	struct AudioStreamInANM *inANM = toInANMc(stream);
	
	return android::AudioHardwareANM::getInputBufferSize(gANM, inANM->mSampleRate, inANM->mFormat, inANM->mChannels);
}

static audio_channel_mask_t in_get_channels(const struct audio_stream *stream)
{
	struct AudioStreamInANM *inANM = toInANMc(stream);

	return inANM->mChannels;
}

static audio_format_t in_get_format(const struct audio_stream *stream)
{
    ALOGE("%s: ", __func__);
	struct AudioStreamInANM *inANM = toInANMc(stream);
	
	return inANM->mFormat;
}

static int in_set_format(struct audio_stream *stream, audio_format_t format)
{
    ALOGE("%s: implement me!", __func__);
	
	return 0;
}

static int in_standby(struct audio_stream *stream)
{
    ALOGE("%s: ", __func__);
	struct AudioStreamInANM *inANM = toInANMc(stream);
	
    return android::AudioStreamInANM::standby(inANM);
}

static int in_dump(const struct audio_stream *stream, int fd)
{
    return 0;
}

static int in_set_parameters(struct audio_stream *stream, const char *kvpairs)
{
    ALOGE("%s: ", __func__);
	
	struct AudioStreamInANM *inANM = toInANMc(stream);
	
	String8 params(kvpairs);
	return android::AudioStreamInANM::setParameters(inANM, params);
}

static char *in_get_parameters(const struct audio_stream *stream,
                                const char *keys)
{
    ALOGE("%s: ", __func__);
	
	struct AudioStreamInANM *inANM = toInANMc(stream);
	
	String8 s(keys);
	return android::AudioStreamInANM::getParameters(inANM, s);
}

static int in_set_gain(struct audio_stream_in *stream, float gain)
{
	ALOGE("%s: not impemented", __func__);
	
	return NO_ERROR;
}

static ssize_t in_read(struct audio_stream_in *stream, void* buffer,
                       size_t bytes)
{
    ALOGE("%s: ", __func__);
	struct AudioStreamInANM *inANM = toInANM((struct audio_stream*)stream);

    return android::AudioStreamInANM::read(inANM, buffer, bytes);
}

static uint32_t in_get_input_frames_lost(struct audio_stream_in *stream)
{
    ALOGV("%s: ", __func__);
	struct AudioStreamInANM *inANM = toInANM((struct audio_stream*)stream);

    return android::AudioStreamInANM::getInputFramesLost(inANM);
}

static int in_add_audio_effect(const struct audio_stream *stream, effect_handle_t effect)
{
	ALOGE("%s: not impemented", __func__);
	
	return NO_ERROR;
}

static int in_remove_audio_effect(const struct audio_stream *stream, effect_handle_t effect)
{
	ALOGE("%s: not impemented", __func__);
	
	return NO_ERROR;
}

static int adev_open_output_stream(struct audio_hw_device *dev,
                              audio_io_handle_t handle,
                              audio_devices_t devices,
                              audio_output_flags_t flags,
                              struct audio_config *config,
                              struct audio_stream_out **stream_out,
			      const char *address __unused)
{
    struct wrapper_stream_out *out;
	struct AudioStreamOutANM * OutANM;
    int ret;
    ALOGI("%s: devices 0x%x", __FUNCTION__, devices);
	
    out = (struct wrapper_stream_out *)calloc(1, sizeof(struct wrapper_stream_out));
    if (!out)
        return -ENOMEM;

    struct wrapper_audio_device* our_dev = reinterpret_cast<struct wrapper_audio_device*>(dev);


    ret = WRAPPED_DEVICE(dev)->open_output_stream(WRAPPED_DEVICE(dev), handle, devices, flags,
                              config, &WRAPPED_STREAM_OUT(out));

    if(ret < 0)
        goto err_open;
	
	OutANM = toOutANM((struct audio_stream*)out);
	gOutANMs->add(OutANM);

	ALOGE("%s: sampleRate = %d, format = %d, channel_mask=%p, conn id=%d, mAdmNumBufs1=%d, mAdmBufSize1=%d, mAdmBufSharedMem1=%d", __func__, OutANM->mSampleRate, OutANM->mFormat, OutANM->mChannels, OutANM->mADMConnectionID1, OutANM->mAdmNumBufs1, OutANM->mAdmBufSize1, OutANM->mAdmBufSharedMem1);

    out->stream.common.get_sample_rate = out_get_sample_rate;
    out->stream.common.set_sample_rate = out_set_sample_rate;
    out->stream.common.get_buffer_size = out_get_buffer_size;
    out->stream.common.get_channels = out_get_channels;
    out->stream.common.get_format = out_get_format;
    out->stream.common.set_format = out_set_format;
    out->stream.common.standby = out_standby;
    out->stream.common.dump = out_dump;
    out->stream.common.set_parameters = out_set_parameters;
    out->stream.common.get_parameters = out_get_parameters;
    out->stream.common.add_audio_effect = out_add_audio_effect;
    out->stream.common.remove_audio_effect = out_remove_audio_effect;
    out->stream.get_latency = out_get_latency;
    out->stream.set_volume = out_set_volume;
    out->stream.write = out_write;
    out->stream.get_render_position = out_get_render_position;
    out->stream.get_next_write_timestamp = NULL; //out_get_next_write_timestamp;

    *stream_out = &out->stream;
    return 0;

err_open:
    free(out);
    *stream_out = NULL;
    return ret;
}

static void adev_close_output_stream(struct audio_hw_device *dev,
                                     struct audio_stream_out *stream)
{
	struct AudioStreamOutANM * OutANM = toOutANM((struct audio_stream*)stream);
	ssize_t index = gOutANMs->indexOf(OutANM);
    if (index < 0) {
        ALOGE("closeOutputStream(): Unknown output stream %x\n",
            (unsigned int)OutANM);
    } else {
        gOutANMs->removeAt(index);
    }

    WRAPPED_DEVICE_CALL(dev, close_output_stream, WRAPPED_STREAM_OUT(stream));
    free(stream);
}

static int adev_set_parameters(struct audio_hw_device *dev, const char *kvpairs)
{
	struct audio_hw_device_sec *adev = (struct audio_hw_device_sec *)dev;
    //ALOGI("%s: kvpairs: %s", __FUNCTION__, kvpairs);
    /*char *fixed_kvpairs = fixup_audio_parameters(kvpairs, JB_TO_ICS);
    int ret = WRAPPED_DEVICE_CALL(dev, set_parameters, fixed_kvpairs);
    free(fixed_kvpairs);
    return ret;*/
	android::String8 s(kvpairs);
	ALOGI("%s: kvpairs = %s", __FUNCTION__, kvpairs);
	
	return android::AudioHardwareANM::setParameters(adev->mANM, s);
}

static char * adev_get_parameters(const struct audio_hw_device *dev,
                                  const char *keys)
{
    String8 s8;

    s8 = android::AudioHardwareANM::getParameters(gANM, String8(keys));
    return strdup(s8.string());
}

static uint32_t adev_get_supported_devices(const struct audio_hw_device *dev)
{
   return 0x87FE1C7F;
}

static int adev_init_check(const struct audio_hw_device *dev)
{
   struct audio_hw_device_sec *adev = (struct audio_hw_device_sec *)dev;
   return android::AudioHardwareANM::initCheck(adev->mANM);
}

static int adev_set_voice_volume(struct audio_hw_device *dev, float volume)
{
	struct audio_hw_device_sec *adev = (struct audio_hw_device_sec *)dev;
	ALOGE("%s: volume=%f", __func__, volume);
    return android::AudioHardwareANM::setVoiceVolume(adev->mANM, volume);
}

static int adev_get_master_volume(struct audio_hw_device *dev, float *volume)
{
    return 0;
}

static int adev_set_master_volume(struct audio_hw_device *dev, float volume)
{
    return 0;
}

static int adev_set_mode(struct audio_hw_device *dev, audio_mode_t mode)
{
    return android::AudioHardwareANM::setMode(gANM, mode);
}


static int adev_set_mic_mute(struct audio_hw_device *dev, bool state)
{
	int ret = WRAPPED_DEVICE(dev)->set_mic_mute(WRAPPED_DEVICE(dev), state);
    
	ALOGE("%s: gANM->mIsMicMuted=%d state=%d", __func__, gANM->mIsMicMuted, state);
	//gDevice->set_mic_mute(gDevice, state);
	return ret;
}

static int adev_get_mic_mute(const struct audio_hw_device *dev, bool *state)
{
	*state = gANM->mIsMicMuted;
    return 0;
}

static size_t adev_get_input_buffer_size(const struct audio_hw_device *dev,
                                    const struct audio_config *config)
{
	return gDevice->get_input_buffer_size(gDevice, config);
}

static int adev_open_input_stream(struct audio_hw_device *dev,
                             audio_io_handle_t handle,
                             audio_devices_t devices,
                             struct audio_config *config,
                             struct audio_stream_in **stream_in,
                                  audio_input_flags_t flags __unused,
                                  const char *address __unused,
                                  audio_source_t source __unused)
{
    return gDevice->open_input_stream(gDevice, handle, devices, config, stream_in, flags, address, source);
}


static void adev_close_input_stream(struct audio_hw_device *dev,
                                   struct audio_stream_in *in)
{
	gDevice->close_input_stream(gDevice, in);
}

static int adev_dump(const audio_hw_device_t *dev, int fd)
{
    return 0;
}

static int adev_close(hw_device_t *dev)
{
    ALOGI("%s", __FUNCTION__);
    WRAPPED_DEVICE(dev)->common.close((hw_device_t*)&(WRAPPED_DEVICE(dev)));
    free(dev);
	
	gDevice->common.close((hw_device_t*)gDevice);
	
	delete gInANMs;
	delete gOutANMs;

    return 0;
}

static int adev_open(const hw_module_t* module, const char* name,
                     hw_device_t** device)
{
    struct wrapper_audio_device *adev;
    int ret;

    ALOGI("Wrapping vendor audio primary");

    if (strcmp(name, AUDIO_HARDWARE_INTERFACE) != 0)
        return -EINVAL;

    adev = (struct wrapper_audio_device *) calloc(1, sizeof(struct wrapper_audio_device));
    if (!adev)
        return -ENOMEM;

    ret = load_vendor_module(module, name, (hw_device_t**) &adev->wrapped_device,
                             AUDIO_HARDWARE_MODULE_ID_PRIMARY);
							 
	int rc1 = legacy_adev_open(module, AUDIO_HARDWARE_INTERFACE, (hw_device_t**)&gDevice);

    if (ret) {
        free(adev);
        return ret;
    }
	
	gInANMs = new SortedVector<struct AudioStreamInANM*>;
	gOutANMs = new SortedVector<struct AudioStreamOutANM*>;

    audio_hw_device_sec *legacy_device = (audio_hw_device_sec *)adev->wrapped_device;
    gANM = legacy_device->mANM;
	gInputs = (SortedVector<struct AudioStreamInANM*> *)gANM->mInputs;
	gOutputs = (SortedVector<struct AudioStreamOutANM*> *)gANM->mOutputs;

    ALOGE("%s: mIsMono: %d, mFormat: %d, mTtyMode: %d, mChannelMask: %d", __func__, gANM->mIsMono, gANM->mFormat, gANM->mTtyMode, gANM->mChannelMask);

    adev->device.common.tag = HARDWARE_DEVICE_TAG;
    adev->device.common.version = AUDIO_DEVICE_API_VERSION_2_0;
    adev->device.common.module = (struct hw_module_t *) module;
    adev->device.common.close = adev_close;

    adev->device.get_supported_devices = adev_get_supported_devices;
    adev->device.init_check = adev_init_check;
    adev->device.set_voice_volume = adev_set_voice_volume;
    adev->device.set_master_volume = adev_set_master_volume;
    adev->device.get_master_volume = NULL; //adev_get_master_volume;
    adev->device.set_master_mute = NULL; //adev_set_master_mute;
    adev->device.get_master_mute = NULL; //adev_get_master_mute;
    adev->device.set_mode = adev_set_mode;
    adev->device.set_mic_mute = adev_set_mic_mute;
    adev->device.get_mic_mute = adev_get_mic_mute;
    adev->device.set_parameters = adev_set_parameters;
    adev->device.get_parameters = adev_get_parameters;
    adev->device.get_input_buffer_size = adev_get_input_buffer_size;
    adev->device.open_output_stream = adev_open_output_stream;
    adev->device.open_input_stream = adev_open_input_stream;
    adev->device.close_output_stream = adev_close_output_stream;
    adev->device.close_input_stream = adev_close_input_stream;
    adev->device.dump = adev_dump;

    *device = &adev->device.common;

    return 0;
}

static struct hw_module_methods_t hal_module_methods = {
    .open = adev_open,
};

struct audio_module HAL_MODULE_INFO_SYM = {
    .common = {
        .tag = HARDWARE_MODULE_TAG,
        .module_api_version = AUDIO_MODULE_API_VERSION_0_1,
        .hal_api_version = HARDWARE_HAL_API_VERSION,
        .id = AUDIO_HARDWARE_MODULE_ID,
        .name = "LEGACY Audio HW Wrapper HAL",
        .author = "The Android Open Source Project",
        .methods = &hal_module_methods,
        .dso = NULL,
        .reserved = {0},
    },
};
