/*
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

#define LOG_TAG "AudioWrapperCommon"
// #define LOG_NDEBUG 0

#include <string.h>
#include <malloc.h>
#include <limits.h>

#include <cutils/log.h>

#include "common.h"

extern "C" int hw_get_module_by_path(char *path, const struct hw_module_t **module);

int load_vendor_module(const hw_module_t* wrapper_module, const char* name,
                       hw_device_t** device, const char* inst)
{
    const hw_module_t* module;
    char module_name[PATH_MAX];
    int ret = 0;
    ALOGI("%s", __FUNCTION__);

    snprintf(module_name, PATH_MAX, "/system/lib/audio.primary.stock.so");

    ret = hw_get_module_by_path(module_name, &module);
    ALOGE_IF(ret, "%s: couldn't load vendor module %s (%s)", __FUNCTION__,
             module_name, strerror(-ret));
    if (ret)
        goto out;

    ret = module->methods->open(module, name, device);
    ALOGE_IF(ret, "%s: couldn't open hw device in %s (%s)", __FUNCTION__,
             module_name, strerror(-ret));
    if(ret)
        goto out;

    return 0;
 out:
    *device = NULL;
    return ret;
}

static wrapper::audio_devices_t fixup_audio_devices(wrapper::audio_devices_t device)
{
    return device;
}

uint32_t convert_audio_devices(const uint32_t devices, flags_conversion_mode_t mode)
{
    uint32_t ret;
    switch(mode) {
    case ICS_TO_JB:
        ret = devices;
        ALOGI("%s: ICS_TO_JB (0x%x -> 0x%x)", __FUNCTION__, devices, ret);
        break;
    case JB_TO_ICS:
        ret = devices;
        ALOGI("%s: JB_TO_ICS (0x%x -> 0x%x)", __FUNCTION__, devices, ret);
        break;
    default:
        ALOGE("%s: Invalid conversion mode %d", __FUNCTION__, mode);
        ret = devices;
    }

    return ret;
}

char * fixup_audio_parameters(const char *kv_pairs, flags_conversion_mode_t mode)
{
    int value;
    size_t len;
    char *out;

    android::AudioParameter param = android::AudioParameter(android::String8(kv_pairs));
    android::String8 key = android::String8(android::AudioParameter::keyRouting);

    if (param.getInt(key, value) == android::NO_ERROR) {
        ALOGI("%s: Fixing routing value (value: %x, mode: %d)", __FUNCTION__,
              value, mode);
        value = convert_audio_devices(value, mode);

        // Adds value as a singed int that might be negative. Doesn't cause any
        // problems because the bit representation is the same.
        param.addInt(key, value);

        // When param is freed the string returned by param.toString() seems to
        // be freed as well, so copy it.
        android::String8 fixed_kv_pairs = param.toString();
        len = fixed_kv_pairs.length();
        out = (char *) malloc(len + 1);
        strcpy(out, fixed_kv_pairs.string());

        ALOGI("%s: fixed_kv_pairs: %s (%d)", __FUNCTION__, out, strlen(out));
    } else {
        len = strlen(kv_pairs);
        out = (char *) malloc(len + 1);
        strcpy(out, kv_pairs);
    }

    return out;
}
