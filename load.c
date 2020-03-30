/*
 * Copyright (C) 2008 The Android Open Source Project
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

#include <hardware/hardware.h>
#include <hardware/audio.h>
#include <dlfcn.h>
#include <errno.h>

#define LOG_TAG "AudioWrapper"
#include <cutils/log.h>

void *gHandle = NULL;

#define LOAD_SYMBOL(shim_symbol, real_symbol)					 			\
	shim_symbol = dlsym(gHandle, real_symbol);						 		\
	if (!shim_symbol) { 						 							\
		ALOGE("%s: Failed to find %s symbol", __func__, real_symbol);		\
	}

#include "audiohw_symbols.h"

/**
 * Load the file defined by the variant and if successful
 * return the dlopen handle and the hmi.
 * @return 0 = success, !0 = failure.
 */
static int load_simple(const char *path,
        struct hw_module_t **pHmi)
{
    int status = -EINVAL;
    void *handle = NULL;
    struct hw_module_t *hmi = NULL;

    /*
     * load the symbols resolving undefined symbols before
     * dlopen returns. Since RTLD_GLOBAL is not or'd in with
     * RTLD_NOW the external symbols will not be global
     */
    handle = dlopen(path, RTLD_NOW);
    if (handle == NULL) {
        char const *err_str = dlerror();
        ALOGE("load: module=%s\n%s", path, err_str?err_str:"unknown");
        status = -EINVAL;
        goto done;
    }

    gHandle = handle;

	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM10getMicMuteEPb, "_ZN7android16AudioHardwareANM10getMicMuteEPb");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM15setMasterVolumeEf, "_ZN7android16AudioHardwareANM15setMasterVolumeEf");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM18getInputBufferSizeEjii, "_ZN7android16AudioHardwareANM18getInputBufferSizeEjii");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM9initCheckEv, "_ZN7android16AudioHardwareANM9initCheckEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE, "_ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM14setVoiceVolumeEf, "_ZN7android16AudioHardwareANM14setVoiceVolumeEf");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM9makeParamEPKcj, "_ZN7android16AudioHardwareANM9makeParamEPKcj");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM14hasValidInputsEv, "_ZN7android16AudioHardwareANM14hasValidInputsEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM14getActiveInputEv, "_ZN7android16AudioHardwareANM14getActiveInputEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM11singleInputEv, "_ZN7android16AudioHardwareANM11singleInputEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM20dumpErrorHistoryItemERNS_7String8EPNS_14ApiHistoryItemE, "_ZN7android16AudioHardwareANM20dumpErrorHistoryItemERNS_7String8EPNS_14ApiHistoryItemE");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM16dumpErrorHistoryERNS_7String8E, "_ZN7android16AudioHardwareANM16dumpErrorHistoryERNS_7String8E");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM7getModeEv, "_ZN7android16AudioHardwareANM7getModeEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM18predictInputDeviceEj, "_ZN7android16AudioHardwareANM18predictInputDeviceEj");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM12updateDeviceEbPNS_9DeviceMapEi, "_ZN7android16AudioHardwareANM12updateDeviceEbPNS_9DeviceMapEi");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM21getCSCallConnectionIdEv, "_ZN7android16AudioHardwareANM21getCSCallConnectionIdEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM16disconnectCSCallEv, "_ZN7android16AudioHardwareANM16disconnectCSCallEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM13suspendInputsEv, "_ZN7android16AudioHardwareANM13suspendInputsEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM12resumeInputsEi, "_ZN7android16AudioHardwareANM12resumeInputsEi");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM27suspendInputIfDeviceIsWrongEj, "_ZN7android16AudioHardwareANM27suspendInputIfDeviceIsWrongEj");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM15doRoutingChangeEPNS_11RoutingInfoE, "_ZN7android16AudioHardwareANM15doRoutingChangeEPNS_11RoutingInfoE");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM19isNRisSupportedInBTEv, "_ZN7android16AudioHardwareANM19isNRisSupportedInBTEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM11isVideoCallEv, "_ZN7android16AudioHardwareANM11isVideoCallEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM13isExtraVolumeEv, "_ZN7android16AudioHardwareANM13isExtraVolumeEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM9isHACModeEv, "_ZN7android16AudioHardwareANM9isHACModeEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM20getCurrentCallOutputEv, "_ZN7android16AudioHardwareANM20getCurrentCallOutputEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM19getCurrentCallInputEv, "_ZN7android16AudioHardwareANM19getCurrentCallInputEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM14getActiveStateEi, "_ZN7android16AudioHardwareANM14getActiveStateEi");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM4lockEv, "_ZN7android16AudioHardwareANM4lockEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM6unlockEv, "_ZN7android16AudioHardwareANM6unlockEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM10setMicMuteEb, "_ZN7android16AudioHardwareANM10setMicMuteEb");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM9setRxMuteEb, "_ZN7android16AudioHardwareANM9setRxMuteEb");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM15setRingbackMuteEb, "_ZN7android16AudioHardwareANM15setRingbackMuteEb");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM10onRingbackEb, "_ZN7android16AudioHardwareANM10onRingbackEb");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM13doUpdateStateEib, "_ZN7android16AudioHardwareANM13doUpdateStateEib");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM11updateStateEi, "_ZN7android16AudioHardwareANM11updateStateEi");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM8stopVoIPEv, "_ZN7android16AudioHardwareANM8stopVoIPEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM9startVoIPEv, "_ZN7android16AudioHardwareANM9startVoIPEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM10stopCSCallEv, "_ZN7android16AudioHardwareANM10stopCSCallEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM11startCSCallEv, "_ZN7android16AudioHardwareANM11startCSCallEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM15unmuteAllSoundsEv, "_ZN7android16AudioHardwareANM15unmuteAllSoundsEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM13muteAllSoundsEv, "_ZN7android16AudioHardwareANM13muteAllSoundsEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM13unmuteFmRadioEv, "_ZN7android16AudioHardwareANM13unmuteFmRadioEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM11muteFmRadioEv, "_ZN7android16AudioHardwareANM11muteFmRadioEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM16closeInputStreamEPNS_13AudioStreamInE, "_ZN7android16AudioHardwareANM16closeInputStreamEPNS_13AudioStreamInE");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM11stopFmRadioEv, "_ZN7android16AudioHardwareANM11stopFmRadioEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM12startFmRadioEv, "_ZN7android16AudioHardwareANM12startFmRadioEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM14getOutputStateEv, "_ZN7android16AudioHardwareANM14getOutputStateEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi, "_ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM27notifyOutputAboutNormalModeEv, "_ZN7android16AudioHardwareANM27notifyOutputAboutNormalModeEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM12forceRerouteEv, "_ZN7android16AudioHardwareANM12forceRerouteEv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM7setModeEi, "_ZN7android16AudioHardwareANM7setModeEi");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM19setIfVoIPprocessingEbi, "_ZN7android16AudioHardwareANM19setIfVoIPprocessingEbi");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE, "_ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE, "_ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv, "_ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE, "_ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM8askChildEPKcb, "_ZN7android16AudioHardwareANM8askChildEPKcb");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM15getNumParameterEPKcRj, "_ZN7android16AudioHardwareANM15getNumParameterEPKcRj");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM13getParametersERKNS_7String8E, "_ZN7android16AudioHardwareANM13getParametersERKNS_7String8E");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM13setParametersERKNS_7String8E, "_ZN7android16AudioHardwareANM13setParametersERKNS_7String8E");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE, "_ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE");
	LOAD_SYMBOL(shim_ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi, "_ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi");
	

    LOAD_SYMBOL(shim_ZN7android17AudioHardwareBase7setModeEi, "_ZN7android17AudioHardwareBase7setModeEi");
    LOAD_SYMBOL(shim_ZN7android17AudioHardwareBase15getMasterVolumeEPf, "_ZN7android17AudioHardwareBase15getMasterVolumeEPf");
    LOAD_SYMBOL(shim_ZN7android17AudioHardwareBase9dumpStateEiRKNS_6VectorINS_8String16EEE, "_ZN7android17AudioHardwareBase9dumpStateEiRKNS_6VectorINS_8String16EEE");
    LOAD_SYMBOL(shim_ZN7android17AudioHardwareBase13setParametersERKNS_7String8E, "_ZN7android17AudioHardwareBase13setParametersERKNS_7String8E");
    LOAD_SYMBOL(shim_ZN7android17AudioHardwareBase13getParametersERKNS_7String8E, "_ZN7android17AudioHardwareBase13getParametersERKNS_7String8E");
    LOAD_SYMBOL(shim_ZN7android17AudioHardwareBase18getInputBufferSizeEjii, "_ZN7android17AudioHardwareBase18getInputBufferSizeEjii");
	
	
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM6isFakeEv, "_ZN7android16AudioStreamInANM6isFakeEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM8isActiveEv, "_ZN7android16AudioStreamInANM8isActiveEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM7suspendEv, "_ZN7android16AudioStreamInANM7suspendEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM6resumeEi, "_ZN7android16AudioStreamInANM6resumeEi");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM22suspendIfDeviceIsWrongEj, "_ZN7android16AudioStreamInANM22suspendIfDeviceIsWrongEj");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM17getDevicePerStateEijPNS_16AudioHardwareANME, "_ZN7android16AudioStreamInANM17getDevicePerStateEijPNS_16AudioHardwareANME");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM7setMuteEb, "_ZN7android16AudioStreamInANM7setMuteEb");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM6unfakeEv, "_ZN7android16AudioStreamInANM6unfakeEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM5setupEPiPjS2_j, "_ZN7android16AudioStreamInANM5setupEPiPjS2_j");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM11updateStateEi, "_ZN7android16AudioStreamInANM11updateStateEi");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM4fakeEv, "_ZN7android16AudioStreamInANM4fakeEv");
	LOAD_SYMBOL(shim_ZNK7android16AudioStreamInANM10sampleRateEv, "_ZNK7android16AudioStreamInANM10sampleRateEv");
	LOAD_SYMBOL(shim_ZNK7android16AudioStreamInANM16calc_buffer_sizeEv, "_ZNK7android16AudioStreamInANM16calc_buffer_sizeEv");
	LOAD_SYMBOL(shim_ZNK7android16AudioStreamInANM8channelsEv, "_ZNK7android16AudioStreamInANM8channelsEv");
	LOAD_SYMBOL(shim_ZNK7android16AudioStreamInANM6formatEv, "_ZNK7android16AudioStreamInANM6formatEv");
	LOAD_SYMBOL(shim_ZNK7android16AudioStreamInANM18getInputFramesLostEv, "_ZNK7android16AudioStreamInANM18getInputFramesLostEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM7setGainEf, "_ZN7android16AudioStreamInANM7setGainEf");
	LOAD_SYMBOL(shim_ZNK7android16AudioStreamInANM10bufferSizeEv, "_ZNK7android16AudioStreamInANM10bufferSizeEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM4dumpEiRKNS_6VectorINS_8String16EEE, "_ZN7android16AudioStreamInANM4dumpEiRKNS_6VectorINS_8String16EEE");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM9doSetMuteEb, "_ZN7android16AudioStreamInANM9doSetMuteEb");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANMC2EPNS_16AudioHardwareANME, "_ZN7android16AudioStreamInANMC2EPNS_16AudioHardwareANME");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM15getNumParameterEPKcRj, "_ZN7android16AudioStreamInANM15getNumParameterEPKcRj");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM13getParametersERKNS_7String8E, "_ZN7android16AudioStreamInANM13getParametersERKNS_7String8E");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM13reconnect_admEv, "_ZN7android16AudioStreamInANM13reconnect_admEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM14postOpenDeviceEv, "_ZN7android16AudioStreamInANM14postOpenDeviceEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM11openDevicesEv, "_ZN7android16AudioStreamInANM11openDevicesEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM23transitionAffectsCSCallEii, "_ZN7android16AudioStreamInANM23transitionAffectsCSCallEii");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM16liveOrgansUpdateEb, "_ZN7android16AudioStreamInANM16liveOrgansUpdateEb");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM12closeDevicesEv, "_ZN7android16AudioStreamInANM12closeDevicesEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM7standbyEv, "_ZN7android16AudioStreamInANM7standbyEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM7restoreEv, "_ZN7android16AudioStreamInANM7restoreEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM6doReadEPvl, "_ZN7android16AudioStreamInANM6doReadEPvl");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM4readEPvl, "_ZN7android16AudioStreamInANM4readEPvl");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM17refreshDeviceListEPNS_10DeviceListEijiPNS_16AudioHardwareANME, "_ZN7android16AudioStreamInANM17refreshDeviceListEPNS_10DeviceListEijiPNS_16AudioHardwareANME");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM16updateDeviceListEbb, "_ZN7android16AudioStreamInANM16updateDeviceListEbb");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM10willChangeEijiRbS1_, "_ZN7android16AudioStreamInANM10willChangeEijiRbS1_");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM14changeDevice_lEijib, "_ZN7android16AudioStreamInANM14changeDevice_lEijib");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM17changeDeviceForceEv, "_ZN7android16AudioStreamInANM17changeDeviceForceEv");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM32changeDeviceRoutesAndInputSourceEjib, "_ZN7android16AudioStreamInANM32changeDeviceRoutesAndInputSourceEjib");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM13setParametersERKNS_7String8E, "_ZN7android16AudioStreamInANM13setParametersERKNS_7String8E");
	LOAD_SYMBOL(shim_ZN7android16AudioStreamInANM17changeDeviceStateEi, "_ZN7android16AudioStreamInANM17changeDeviceStateEi");


	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM11updateStateEi, "_ZN7android17AudioStreamOutANM11updateStateEi");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM15getCurrentStateEv, "_ZN7android17AudioStreamOutANM15getCurrentStateEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM10normalModeEv, "_ZN7android17AudioStreamOutANM10normalModeEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM12forceRerouteEv, "_ZN7android17AudioStreamOutANM12forceRerouteEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM14setFactoryTestEj, "_ZN7android17AudioStreamOutANM14setFactoryTestEj");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM15setStereoToMonoEb, "_ZN7android17AudioStreamOutANM15setStereoToMonoEb");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM5setupEPiPjS2_j, "_ZN7android17AudioStreamOutANM5setupEPiPjS2_j");
	LOAD_SYMBOL(shim_ZNK7android17AudioStreamOutANM10sampleRateEv, "_ZNK7android17AudioStreamOutANM10sampleRateEv");
	LOAD_SYMBOL(shim_ZNK7android17AudioStreamOutANM8channelsEv, "_ZNK7android17AudioStreamOutANM8channelsEv");
	LOAD_SYMBOL(shim_ZNK7android17AudioStreamOutANM6formatEv, "_ZNK7android17AudioStreamOutANM6formatEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM9setVolumeEff, "_ZN7android17AudioStreamOutANM9setVolumeEff");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM17getRenderPositionEPj, "_ZN7android17AudioStreamOutANM17getRenderPositionEPj");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM15getNumParameterEPKcRj, "_ZN7android17AudioStreamOutANM15getNumParameterEPKcRj");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13getParametersERKNS_7String8E, "_ZN7android17AudioStreamOutANM13getParametersERKNS_7String8E");
	LOAD_SYMBOL(shim_ZNK7android17AudioStreamOutANM16calc_buffer_sizeEv, "_ZNK7android17AudioStreamOutANM16calc_buffer_sizeEv");
	LOAD_SYMBOL(shim_ZNK7android17AudioStreamOutANM7latencyEv, "_ZNK7android17AudioStreamOutANM7latencyEv");
	LOAD_SYMBOL(shim_ZNK7android17AudioStreamOutANM10bufferSizeEv, "_ZNK7android17AudioStreamOutANM10bufferSizeEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13reconnect_admEv, "_ZN7android17AudioStreamOutANM13reconnect_admEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM14preCloseDeviceEPNS_10DeviceListE, "_ZN7android17AudioStreamOutANM14preCloseDeviceEPNS_10DeviceListE");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM16connectIfFmRadioEv, "_ZN7android17AudioStreamOutANM16connectIfFmRadioEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM19disconnectIfFmRadioEv, "_ZN7android17AudioStreamOutANM19disconnectIfFmRadioEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM17getSpecialRoutingEPNS_10DeviceListES2_, "_ZN7android17AudioStreamOutANM17getSpecialRoutingEPNS_10DeviceListES2_");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM16liveOrgansUpdateEb, "_ZN7android17AudioStreamOutANM16liveOrgansUpdateEb");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13getChangeTypeEiibbNS0_17special_routing_tE, "_ZN7android17AudioStreamOutANM13getChangeTypeEiibbNS0_17special_routing_tE");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM14changeRefCountE19audio_stream_type_ti, "_ZN7android17AudioStreamOutANM14changeRefCountE19audio_stream_type_ti");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM24getHighestPriorityStreamEv, "_ZN7android17AudioStreamOutANM24getHighestPriorityStreamEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM17refreshDeviceListEPNS_10DeviceListEij19audio_stream_type_tPNS_16AudioHardwareANME, "_ZN7android17AudioStreamOutANM17refreshDeviceListEPNS_10DeviceListEij19audio_stream_type_tPNS_16AudioHardwareANME");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM19updateConfigurationEij19audio_stream_type_t, "_ZN7android17AudioStreamOutANM19updateConfigurationEij19audio_stream_type_t");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM10willChangeEij19audio_stream_type_tRbS2_RNS0_17special_routing_tE, "_ZN7android17AudioStreamOutANM10willChangeEij19audio_stream_type_tRbS2_RNS0_17special_routing_tE");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM15getConnectionIdEi, "_ZN7android17AudioStreamOutANM15getConnectionIdEi");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM11closeDeviceEPNS_9DeviceMapE, "_ZN7android17AudioStreamOutANM11closeDeviceEPNS_9DeviceMapE");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM12closeDevicesEPNS_10DeviceListE, "_ZN7android17AudioStreamOutANM12closeDevicesEPNS_10DeviceListE");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM7standbyEv, "_ZN7android17AudioStreamOutANM7standbyEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM10openDeviceEPNS_9DeviceMapEb, "_ZN7android17AudioStreamOutANM10openDeviceEPNS_9DeviceMapEb");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM12doTransitionEij19audio_stream_type_tNS0_13change_type_tE, "_ZN7android17AudioStreamOutANM12doTransitionEij19audio_stream_type_tNS0_13change_type_tE");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM12changeDeviceEij19audio_stream_type_tb, "_ZN7android17AudioStreamOutANM12changeDeviceEij19audio_stream_type_tb");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM11openDevicesEv, "_ZN7android17AudioStreamOutANM11openDevicesEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM7restoreEv, "_ZN7android17AudioStreamOutANM7restoreEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM7doWriteEPKvji, "_ZN7android17AudioStreamOutANM7doWriteEPKvji");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM5writeEPKvj, "_ZN7android17AudioStreamOutANM5writeEPKvj");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANMC2EPNS_16AudioHardwareANME, "_ZN7android17AudioStreamOutANMC2EPNS_16AudioHardwareANME");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM4dumpEiRKNS_6VectorINS_8String16EEE, "_ZN7android17AudioStreamOutANM4dumpEiRKNS_6VectorINS_8String16EEE");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13doUpdateForceEv, "_ZN7android17AudioStreamOutANM13doUpdateForceEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM14doUpdateStreamE19audio_stream_type_t, "_ZN7android17AudioStreamOutANM14doUpdateStreamE19audio_stream_type_t");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM15doUpdateDevicesEj, "_ZN7android17AudioStreamOutANM15doUpdateDevicesEj");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13setParametersERKNS_7String8E, "_ZN7android17AudioStreamOutANM13setParametersERKNS_7String8E");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13doUpdateStateEi, "_ZN7android17AudioStreamOutANM13doUpdateStateEi");

	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13CommandThread5startEv, "_ZN7android17AudioStreamOutANM13CommandThread5startEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13CommandThread4exitEv, "_ZN7android17AudioStreamOutANM13CommandThread4exitEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13CommandThread4dumpERNS_7String8E, "_ZN7android17AudioStreamOutANM13CommandThread4dumpERNS_7String8E");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13CommandThread15insertCommand_lEPNS1_7CommandE, "_ZN7android17AudioStreamOutANM13CommandThread15insertCommand_lEPNS1_7CommandE");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13CommandThread8setForceEv, "_ZN7android17AudioStreamOutANM13CommandThread8setForceEv");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13CommandThread9setStreamE19audio_stream_type_t, "_ZN7android17AudioStreamOutANM13CommandThread9setStreamE19audio_stream_type_t");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13CommandThread10setDevicesEj, "_ZN7android17AudioStreamOutANM13CommandThread10setDevicesEj");
	LOAD_SYMBOL(shim_ZN7android17AudioStreamOutANM13CommandThread8setStateEi, "_ZN7android17AudioStreamOutANM13CommandThread8setStateEi");


    /* Get the address of the struct hal_module_info. */
    const char *sym = "HMI";
    hmi = (struct hw_module_t *)dlsym(handle, sym);
    if (hmi == NULL) {
        ALOGE("load: couldn't find symbol %s", sym);
        status = -EINVAL;
        goto done;
    }

    hmi->dso = handle;

    /* success */
    status = 0;

    done:
    if (status != 0) {
        hmi = NULL;
        if (handle != NULL) {
            dlclose(handle);
            handle = NULL;
        }
    } else {
        ALOGE("loaded HAL path=%s hmi=%p handle=%p",
                path, *pHmi, handle);
    }

    *pHmi = hmi;

    return status;
}

int hw_get_module_by_path2(char *path, const struct hw_module_t **module)
{
    return load_simple(path, module);
}
