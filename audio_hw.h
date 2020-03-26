/*
 * Copyright (C) 2020 The LineageOS Project
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

#ifndef _AUDIOHW
#define _AUDIOHW

#define DEFAULT_IN_SAMPLE_RATE (8000)
#define DEFAULT_OUT_SAMPLING_RATE 44100

//#include <utils/KeyedVector.h>

#include <pthread.h>

#ifdef __cplusplus
//#if !defined(TEST)
#include <hardware_legacy/AudioHardwareInterface.h>
#include <hardware_legacy/AudioPolicyManagerBase.h>

#include <utils/KeyedVector.h>

using android::KeyedVector;
using android::SortedVector;


using android_audio_legacy::AudioStreamOut;
//#endif


class AudioOutputDescriptor;
class AudioInputDescriptor;
#else
#endif


/**
 * TTY modes
 */
typedef enum {
  STE_ADM_TTY_MODE_OFF = 0,
  STE_ADM_TTY_MODE_FULL,
  STE_ADM_TTY_MODE_HCO,
  STE_ADM_TTY_MODE_VCO,
} ste_adm_tty_mode_t;


#define STE_ADM_TTY_MODE_INVALID ((ste_adm_tty_mode_t)-1)
  
#ifdef __cplusplus
extern "C"
{
#endif
	int ste_adm_client_set_cscall_tty_mode(ste_adm_tty_mode_t tty_mode);
    int ste_adm_client_set_cscall_downstream_volume(int volume);
    int ste_adm_client_get_cscall_upstream_volume(int* volume);
    int ste_adm_client_connect(void);
    int ste_adm_client_disconnect(int client_id);
    int ste_adm_set_cscall_devices(int client_id, const char* indev, const char* outdev);
    int ste_adm_client_set_cscall_upstream_volume(int volume);
    int ste_adm_client_set_cscall_voip_mode(int enabled, int *mode);
    int ste_adm_client_set_cscall_tty_mode(ste_adm_tty_mode_t tty_mode);
    int ste_adm_client_drain(int client_id);
    int ste_adm_dev2dev_connect(const char* src_dev, const char* dst_dev, int *flags);
    int ste_adm_dev2dev_disconnect(int client_id);
    int ste_adm_close_device(int client_id, const char* device_name);
    int ste_adm_client_open_device(int client_id, const char* device_name,
		int samplerate, int format, int* actual_samplerate, char** bufp, int bufsz, int num_bufs);
    int ste_adm_client_send(int client_id, int buf_idx, int data_size, int *lpa_mode);
    int ste_adm_client_set_app_volume(const char* dev_name, int volume);
    int ste_adm_client_receive(int client_id, int* buf_idx);
    int ste_adm_set_toplevel_map_live(const char *toplevel_device,  const char *new_actual_device,
		const char *toplevel_device2, const char *new_actual_device2);
    int ste_adm_client_set_toplevel_map(const char *toplevel_device, const char *actual_device);
    int ste_adm_set_cscall_loopback_mode(int mode, int codec);
#ifdef __cplusplus
}
#endif

#define UNKNOWN_ERROR  0x80000000

#ifdef __cplusplus
namespace android {
	typedef int adm_api_type_t;
	typedef int notification_type_t;
	class ApiHistoryItem;
	class DeviceMap;
	class RoutingInfo;
}

/* 144 */
struct audio_hw_device_sec
{
  struct hw_device_t common;
  uint32_t (*get_supported_devices)(const struct audio_hw_device *dev);
  int (*init_check)(const struct audio_hw_device *dev);
  int ( *set_voice_volume)(struct audio_hw_device *dev, float volume);
  int ( *set_master_volume)(struct audio_hw_device *dev, float volume);
  int ( *get_master_volume)(struct audio_hw_device *dev, float *volume);
  int ( *set_mode)(struct audio_hw_device *dev, audio_mode_t mode);
  int ( *set_mic_mute)(struct audio_hw_device *dev, bool state);
  int ( *get_mic_mute)(const struct audio_hw_device *dev, bool *state);
  int ( *set_parameters)(struct audio_hw_device *dev, const char *kv_pairs);
  char *( *get_parameters)(const struct audio_hw_device *dev, const char *keys);
  size_t ( *get_input_buffer_size)(const struct audio_hw_device *dev, const struct audio_config *config);
  int ( *open_output_stream)(struct audio_hw_device *dev, audio_io_handle_t handle, audio_devices_t devices, audio_output_flags_t flags, struct audio_config *config, struct audio_stream_out **stream_out, const char *address);
  void ( *close_output_stream)(struct audio_hw_device *dev, struct audio_stream_out *stream_out);
  int ( *open_broadcast_stream)(struct audio_hw_device *dev, uint32_t devices, int format, uint32_t channels, uint32_t sample_rate, uint32_t audio_source, void **out);
  void ( *close_broadcast_stream)(struct audio_hw_device *dev, void *out);
  int ( *open_input_stream)(struct audio_hw_device *dev, audio_io_handle_t handle, audio_devices_t devices, struct audio_config *config, struct audio_stream_in **stream_in, audio_input_flags_t flags, const char *address, audio_source_t source);
  void ( *close_input_stream)(struct audio_hw_device *dev, struct audio_stream_in *stream_in);
  int ( *dump)(const struct audio_hw_device *dev, int fd);
  struct AudioHardwareANM *mANM;
};


/* 26 */
struct __attribute__((aligned(4))) AudioStreamInANM
{
  int unk1;
  struct AudioHardwareANM *mANM;
  bool mMuted;
  bool unk3;
  bool unk4;
  bool unk5;
  int mMutedAppVol;
  int mADMConnectionID;
  char unk_xx[160];
  int mDeviceListSize;
  bool mStandby;
  bool unk92;
  bool unk93;
  bool unk94;
  int mChannels;
  int mSampleRate;
  audio_format_t mFormat;
  int mAdmNumBufs;
  int mAdmBufSize;
  void *mAdmBufSharedMem;
  pthread_mutex_t mMutex;
  char unk_xx2[8];
  int mDevicesList;
  int unk_DevicesList;
  int mState;
  int mInputSource;
  int unk_inputSource;
  bool mIsFake;
  bool unk22;
  bool unk23;
  bool unk24;
  int mInputIdx;
  int unk26;
  bool mDeviceIsWrong;
  bool mReadInProgress;
};

struct AudioStreamOutANM;

/* 25 */
struct __attribute__((aligned(4))) AudioHardwareANM
{
  int mIsMicMuted;
  void (*destructor)(void);
  bool unk_xx1;
  bool index_start1;
  int unk_idx2;
  int unk_idx3;
  /* Lists if output and input descriptors */
  int mInputs[5];
  int mOutputs[5];
  //SortedVector<struct AudioStreamOutANM*> mOutputs;

  bool unk1;
  bool unk100;
  bool unk101;
  bool unk102;
  int mUpstreamVolume;
  int csCallState;
  pthread_mutex_t mutex;
  struct timeval *time;
  int unk999;
  int unk5;
  char unk6[16];
  char unk7[16];
  bool mBtHeadsetEnabled;
  bool unk9;
  bool unk10;
  bool mExtraVolumeEnabled;
  bool unk12;
  bool mIsMono;
  bool unk14;
  bool unk15;
  ste_adm_tty_mode_t mTtyMode;
  char unk_xx[496];
  int unk17;
  bool unk18;
  bool unk20;
  bool unk21;
  bool unk22;
  int unk23;
  int devices1;
  int devices2;
  int mFormat;
  int mChannelMask;
  int mChannelMask2;
  int mInputSource;
  int mFrameCount;
};
#endif

#endif
