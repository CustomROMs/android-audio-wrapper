#ifndef _AUDIOHW_SYMBOLS
#define _AUDIOHW_SYMBOLS

#include "audio_hw.h"

struct AudioHardwareANM;
struct AudioStreamInANM;

#ifdef __cplusplus
extern "C" {
#endif

// AudioHardwareBase
int (*shim_ZN7android17AudioHardwareBase7setModeEi)(struct AudioHardwareANM *ANM, int mode);
int (*shim_ZN7android17AudioHardwareBase15getMasterVolumeEPf)(struct AudioHardwareANM *ANM, float* volume);
#ifdef __cplusplus
int (*shim_ZN7android17AudioHardwareBase9dumpStateEiRKNS_6VectorINS_8String16EEE)(struct AudioHardwareANM *ANM, int fd, const Vector<String16>& args);
#else
int (*shim_ZN7android17AudioHardwareBase9dumpStateEiRKNS_6VectorINS_8String16EEE)(struct AudioHardwareANM *ANM, int fd, int args);
#endif

#ifdef __cplusplus
int (*shim_ZN7android17AudioHardwareBase13setParametersERKNS_7String8E)(struct AudioHardwareANM *ANM, const String8& keyValuePairs);
char *(*shim_ZN7android17AudioHardwareBase13getParametersERKNS_7String8E)(struct AudioHardwareANM *ANM, const String8& keyValuePairs);
#else
int (*shim_ZN7android17AudioHardwareBase13setParametersERKNS_7String8E)(struct AudioHardwareANM *ANM, int keyValuePairs);
char *(*shim_ZN7android17AudioHardwareBase13getParametersERKNS_7String8E)(struct AudioHardwareANM *ANM, int keyValuePairs);
#endif
int (*shim_ZN7android17AudioHardwareBase18getInputBufferSizeEjii)(struct AudioHardwareANM *ANM, uint32_t sampleRate, int format, int channelCount);

// AudioHardwareANM
int (*shim_ZN7android16AudioHardwareANM10getMicMuteEPb)(struct AudioHardwareANM *ANM, bool* state);
int (*shim_ZN7android16AudioHardwareANM15setMasterVolumeEf)(struct AudioHardwareANM *ANM, float volume);
void (*shim_ZN7android16AudioHardwareANM18getInputBufferSizeEjii)(struct AudioHardwareANM *ANM, unsigned int a1, int a2, int a3);
int (*shim_ZN7android16AudioHardwareANM9initCheckEv)(struct AudioHardwareANM *ANM);
#ifdef __cplusplus
void (*shim_ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE)(struct AudioHardwareANM *ANM, int a1, android::adm_api_type_t a2);
#else
void (*shim_ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE)(struct AudioHardwareANM *ANM, int a1, int a2);
#endif
int (*shim_ZN7android16AudioHardwareANM14setVoiceVolumeEf)(struct AudioHardwareANM *ANM, float a1);
void (*shim_ZN7android16AudioHardwareANM9makeParamEPKcj)(struct AudioHardwareANM *ANM, char const* a1, unsigned int a2);
void (*shim_ZN7android16AudioHardwareANM14hasValidInputsEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM14getActiveInputEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM11singleInputEv)(struct AudioHardwareANM *ANM);
#ifdef __cplusplus
void (*shim_ZN7android16AudioHardwareANM20dumpErrorHistoryItemERNS_7String8EPNS_14ApiHistoryItemE)(struct AudioHardwareANM *ANM, android::String8& a1, android::ApiHistoryItem* a2);
void (*shim_ZN7android16AudioHardwareANM16dumpErrorHistoryERNS_7String8E)(struct AudioHardwareANM *ANM, android::String8& a1);
#else
void (*shim_ZN7android16AudioHardwareANM20dumpErrorHistoryItemERNS_7String8EPNS_14ApiHistoryItemE)(struct AudioHardwareANM *ANM, int a1, int* a2);
void (*shim_ZN7android16AudioHardwareANM16dumpErrorHistoryERNS_7String8E)(struct AudioHardwareANM *ANM, int a1);
#endif

void (*shim_ZN7android16AudioHardwareANM7getModeEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM18predictInputDeviceEj)(struct AudioHardwareANM *ANM, unsigned int a1);
#ifdef __cplusplus
void (*shim_ZN7android16AudioHardwareANM12updateDeviceEbPNS_9DeviceMapEi)(struct AudioHardwareANM *ANM, bool a1, android::DeviceMap* a2, int a3);
#else
void (*shim_ZN7android16AudioHardwareANM12updateDeviceEbPNS_9DeviceMapEi)(struct AudioHardwareANM *ANM, bool a1, int* a2, int a3);
#endif
void (*shim_ZN7android16AudioHardwareANM21getCSCallConnectionIdEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM16disconnectCSCallEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM13suspendInputsEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM12resumeInputsEi)(struct AudioHardwareANM *ANM, int a1);
void (*shim_ZN7android16AudioHardwareANM27suspendInputIfDeviceIsWrongEj)(struct AudioHardwareANM *ANM, unsigned int a1);
#ifdef __cplusplus
void (*shim_ZN7android16AudioHardwareANM15doRoutingChangeEPNS_11RoutingInfoE)(struct AudioHardwareANM *ANM, android::RoutingInfo* a1);
#else
void (*shim_ZN7android16AudioHardwareANM15doRoutingChangeEPNS_11RoutingInfoE)(struct AudioHardwareANM *ANM, int* a1);
#endif
void (*shim_ZN7android16AudioHardwareANM19isNRisSupportedInBTEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM11isVideoCallEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM13isExtraVolumeEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM9isHACModeEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM20getCurrentCallOutputEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM19getCurrentCallInputEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM14getActiveStateEi)(struct AudioHardwareANM *ANM, int a1);
void (*shim_ZN7android16AudioHardwareANM4lockEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM6unlockEv)(struct AudioHardwareANM *ANM);
int (*shim_ZN7android16AudioHardwareANM10setMicMuteEb)(struct AudioHardwareANM *ANM, bool a1);
void (*shim_ZN7android16AudioHardwareANM9setRxMuteEb)(struct AudioHardwareANM *ANM, bool a1);
void (*shim_ZN7android16AudioHardwareANM15setRingbackMuteEb)(struct AudioHardwareANM *ANM, bool a1);
void (*shim_ZN7android16AudioHardwareANM10onRingbackEb)(struct AudioHardwareANM *ANM, bool a1);
void (*shim_ZN7android16AudioHardwareANM13doUpdateStateEib)(struct AudioHardwareANM *ANM, int a1, bool a2);
void (*shim_ZN7android16AudioHardwareANM11updateStateEi)(struct AudioHardwareANM *ANM, int a1);
void (*shim_ZN7android16AudioHardwareANM8stopVoIPEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM9startVoIPEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM10stopCSCallEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM11startCSCallEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM15unmuteAllSoundsEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM13muteAllSoundsEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM13unmuteFmRadioEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM11muteFmRadioEv)(struct AudioHardwareANM *ANM);
#ifdef __cplusplus
void (*shim_ZN7android16AudioHardwareANM16closeInputStreamEPNS_13AudioStreamInE)(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamIn* a1);
#else
void (*shim_ZN7android16AudioHardwareANM16closeInputStreamEPNS_13AudioStreamInE)(struct AudioHardwareANM *ANM, int a1);
#endif
void (*shim_ZN7android16AudioHardwareANM11stopFmRadioEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM12startFmRadioEv)(struct AudioHardwareANM *ANM);
int (*shim_ZN7android16AudioHardwareANM14getOutputStateEv)(struct AudioHardwareANM *ANM);
#ifdef __cplusplus
struct AudioStreamInANM* (*shim_ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi)(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_config* a2, int* a3);
#else
struct AudioStreamInANM* (*shim_ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi)(struct AudioHardwareANM *ANM, int a1, int* a2, int* a3);
#endif

void (*shim_ZN7android16AudioHardwareANM27notifyOutputAboutNormalModeEv)(struct AudioHardwareANM *ANM);
void (*shim_ZN7android16AudioHardwareANM12forceRerouteEv)(struct AudioHardwareANM *ANM);
int (*shim_ZN7android16AudioHardwareANM7setModeEi)(struct AudioHardwareANM *ANM, int mode);
void (*shim_ZN7android16AudioHardwareANM19setIfVoIPprocessingEbi)(struct AudioHardwareANM *ANM, bool a1, int a2);

#ifdef __cplusplus
void (*shim_ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE)(struct AudioHardwareANM *ANM, android::RoutingInfo* a1);
void (*shim_ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE)(struct AudioHardwareANM *ANM, android::RoutingInfo* a1);
void (*shim_ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv)(struct AudioHardwareANM *ANM, bool a1, android::notification_type_t a2, void const* a3);
void (*shim_ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE)(struct AudioHardwareANM *ANM, int a1, android::Vector<android::String16> const& a2);
#else
void (*shim_ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE)(struct AudioHardwareANM *ANM, int* a1);
void (*shim_ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE)(struct AudioHardwareANM *ANM, int* a1);
void (*shim_ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv)(struct AudioHardwareANM *ANM, bool a1, int a2, void const* a3);
void (*shim_ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE)(struct AudioHardwareANM *ANM, int a1, int a2);
#endif	

void (*shim_ZN7android16AudioHardwareANM8askChildEPKcb)(struct AudioHardwareANM *ANM, char const* a1, bool a2);
#ifdef __cplusplus
void (*shim_ZN7android16AudioHardwareANM15getNumParameterEPKcRj)(struct AudioHardwareANM *ANM, char const* a1, unsigned int& a2);
#else
void (*shim_ZN7android16AudioHardwareANM15getNumParameterEPKcRj)(struct AudioHardwareANM *ANM, char const* a1, unsigned int a2);
#endif

#ifdef __cplusplus
char *(*shim_ZN7android16AudioHardwareANM13getParametersERKNS_7String8E)(struct AudioHardwareANM *ANM, android::String8 const& a1);
int (*shim_ZN7android16AudioHardwareANM13setParametersERKNS_7String8E)(struct AudioHardwareANM *ANM, android::String8 const& keyValuePair);
void (*shim_ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE)(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamOut* a1);
void (*shim_ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi)(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_output_flags_t a2, audio_config* a3, int* a4);
#else
char *(*shim_ZN7android16AudioHardwareANM13getParametersERKNS_7String8E)(struct AudioHardwareANM *ANM, int a1);
int (*shim_ZN7android16AudioHardwareANM13setParametersERKNS_7String8E)(struct AudioHardwareANM *ANM, int keyValuePair);
void (*shim_ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE)(struct AudioHardwareANM *ANM, int* a1);
void (*shim_ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi)(struct AudioHardwareANM *ANM);
#endif

// AudioStreamInANM
int (*shim_ZN7android16AudioStreamInANM6isFakeEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM8isActiveEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM7suspendEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM6resumeEi)(struct AudioStreamInANM *inANM, int a1);
int (*shim_ZN7android16AudioStreamInANM22suspendIfDeviceIsWrongEj)(struct AudioStreamInANM *inANM, unsigned int a1);
int (*shim_ZN7android16AudioStreamInANM17getDevicePerStateEijPNS_16AudioHardwareANME)(struct AudioStreamInANM *inANM, int a1, unsigned int a2, struct AudioHardwareANM* a3);
int (*shim_ZN7android16AudioStreamInANM7setMuteEb)(struct AudioStreamInANM *inANM, bool a1);
int (*shim_ZN7android16AudioStreamInANM6unfakeEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANMC1EPNS_16AudioHardwareANME)(struct AudioStreamInANM *inANM, struct AudioHardwareANM* a1);
int (*shim_ZN7android16AudioStreamInANM5setupEPiPjS2_j)(struct AudioStreamInANM *inANM, int* a1, unsigned int* a2, unsigned int* a3, unsigned int a4);
int (*shim_ZN7android16AudioStreamInANM11updateStateEi)(struct AudioStreamInANM *inANM, int a1);
int (*shim_ZN7android16AudioStreamInANM4fakeEv)(struct AudioStreamInANM *inANM);
int (*shim_ZNK7android16AudioStreamInANM10sampleRateEv)(struct AudioStreamInANM *inANM);
int (*shim_ZNK7android16AudioStreamInANM16calc_buffer_sizeEv)(struct AudioStreamInANM *inANM);
int (*shim_ZNK7android16AudioStreamInANM8channelsEv)(struct AudioStreamInANM *inANM);
int (*shim_ZNK7android16AudioStreamInANM6formatEv)(struct AudioStreamInANM *inANM);
int (*shim_ZNK7android16AudioStreamInANM18getInputFramesLostEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM7setGainEf)(struct AudioStreamInANM *inANM, float a1);
int (*shim_ZNK7android16AudioStreamInANM10bufferSizeEv)(struct AudioStreamInANM *inANM);

#ifdef __cplusplus
int (*shim_ZN7android16AudioStreamInANM4dumpEiRKNS_6VectorINS_8String16EEE)(struct AudioStreamInANM *inANM, int a1, Vector<String16> const& a2);
#else
int (*shim_ZN7android16AudioStreamInANM4dumpEiRKNS_6VectorINS_8String16EEE)(struct AudioStreamInANM *inANM, int a1, int a2);
#endif
	
int (*shim_ZN7android16AudioStreamInANM9doSetMuteEb)(struct AudioStreamInANM *inANM, bool a1);
int (*shim_ZN7android16AudioStreamInANMC2EPNS_16AudioHardwareANME)(struct AudioStreamInANM *inANM, struct AudioHardwareANM* a1);

#ifdef __cplusplus
int (*shim_ZN7android16AudioStreamInANM15getNumParameterEPKcRj)(struct AudioStreamInANM *inANM, char const* a1, unsigned int& a2);
char *(*shim_ZN7android16AudioStreamInANM13getParametersERKNS_7String8E)(struct AudioStreamInANM *inANM, android::String8 const& a1);
#else
int (*shim_ZN7android16AudioStreamInANM15getNumParameterEPKcRj)(struct AudioStreamInANM *inANM, char const* a1, unsigned int a2);
char *(*shim_ZN7android16AudioStreamInANM13getParametersERKNS_7String8E)(struct AudioStreamInANM *inANM, int a1);
#endif
int (*shim_ZN7android16AudioStreamInANM13reconnect_admEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM14postOpenDeviceEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM11openDevicesEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM23transitionAffectsCSCallEii)(struct AudioStreamInANM *inANM, int a1, int a2);
int (*shim_ZN7android16AudioStreamInANM16liveOrgansUpdateEb)(struct AudioStreamInANM *inANM, bool a1);
int (*shim_ZN7android16AudioStreamInANM12closeDevicesEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM7standbyEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANMD2Ev)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANMD0Ev)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANMD1Ev)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM7restoreEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM6doReadEPvl)(struct AudioStreamInANM *inANM, void* a1, long a2);
int (*shim_ZN7android16AudioStreamInANM4readEPvl)(struct AudioStreamInANM *inANM, void* a1, long a2);
#ifdef __cplusplus
int (*shim_ZN7android16AudioStreamInANM17refreshDeviceListEPNS_10DeviceListEijiPNS_16AudioHardwareANME)(struct AudioStreamInANM *inANM, DeviceList* a1, int a2, unsigned int a3, int a4, struct AudioHardwareANM* a5);
#else
int (*shim_ZN7android16AudioStreamInANM17refreshDeviceListEPNS_10DeviceListEijiPNS_16AudioHardwareANME)(struct AudioStreamInANM *inANM, int* a1, int a2, unsigned int a3, int a4, struct AudioHardwareANM* a5);
#endif
int (*shim_ZN7android16AudioStreamInANM16updateDeviceListEbb)(struct AudioStreamInANM *inANM, bool a1, bool a2);
#ifdef __cplusplus
int (*shim_ZN7android16AudioStreamInANM10willChangeEijiRbS1_)(struct AudioStreamInANM *inANM, int a1, unsigned int a2, int a3, bool& a4, bool& a5);
#else
int (*shim_ZN7android16AudioStreamInANM10willChangeEijiRbS1_)(struct AudioStreamInANM *inANM, int a1, unsigned int a2, int a3, bool a4, bool a5);
#endif
int (*shim_ZN7android16AudioStreamInANM14changeDevice_lEijib)(struct AudioStreamInANM *inANM, int a1, unsigned int a2, int a3, bool a4);
int (*shim_ZN7android16AudioStreamInANM17changeDeviceForceEv)(struct AudioStreamInANM *inANM);
int (*shim_ZN7android16AudioStreamInANM32changeDeviceRoutesAndInputSourceEjib)(struct AudioStreamInANM *inANM, unsigned int a1, int a2, bool a3);
#ifdef __cplusplus
int (*shim_ZN7android16AudioStreamInANM13setParametersERKNS_7String8E)(struct AudioStreamInANM *inANM, android::String8 const& a1);
#else
int (*shim_ZN7android16AudioStreamInANM13setParametersERKNS_7String8E)(struct AudioStreamInANM *inANM, int a1);
#endif
int (*shim_ZN7android16AudioStreamInANM17changeDeviceStateEi)(struct AudioStreamInANM *inANM, int a1);
#ifdef __cplusplus
}
#endif

#endif
