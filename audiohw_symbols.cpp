#include "audio_hw.h"


extern "C" {
void _ZN7android16AudioHardwareANM10getMicMuteEPb(struct AudioHardwareANM *ANM, bool* a1);
void _ZN7android16AudioHardwareANM15setMasterVolumeEf(struct AudioHardwareANM *ANM, float a1);
void _ZN7android16AudioHardwareANM18getInputBufferSizeEjii(struct AudioHardwareANM *ANM, unsigned int a1, int a2, int a3);
void _ZN7android16AudioHardwareANM9initCheckEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE(struct AudioHardwareANM *ANM, int a1, android::adm_api_type_t a2);
void _ZN7android16AudioHardwareANM14setVoiceVolumeEf(struct AudioHardwareANM *ANM, float a1);
void _ZN7android16AudioHardwareANM9makeParamEPKcj(struct AudioHardwareANM *ANM, char const* a1, unsigned int a2);
void _ZN7android16AudioHardwareANM14hasValidInputsEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM14getActiveInputEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM11singleInputEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM20dumpErrorHistoryItemERNS_7String8EPNS_14ApiHistoryItemE(struct AudioHardwareANM *ANM, android::String8& a1, android::ApiHistoryItem* a2);
void _ZN7android16AudioHardwareANM16dumpErrorHistoryERNS_7String8E(struct AudioHardwareANM *ANM, android::String8& a1);
void _ZN7android16AudioHardwareANM7getModeEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM18predictInputDeviceEj(struct AudioHardwareANM *ANM, unsigned int a1);
void _ZN7android16AudioHardwareANM12updateDeviceEbPNS_9DeviceMapEi(struct AudioHardwareANM *ANM, bool a1, android::DeviceMap* a2, int a3);
void _ZN7android16AudioHardwareANM21getCSCallConnectionIdEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM16disconnectCSCallEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM13suspendInputsEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM12resumeInputsEi(struct AudioHardwareANM *ANM, int a1);
void _ZN7android16AudioHardwareANM27suspendInputIfDeviceIsWrongEj(struct AudioHardwareANM *ANM, unsigned int a1);
void _ZN7android16AudioHardwareANM15doRoutingChangeEPNS_11RoutingInfoE(struct AudioHardwareANM *ANM, android::RoutingInfo* a1);
void _ZN7android16AudioHardwareANM19isNRisSupportedInBTEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM11isVideoCallEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM13isExtraVolumeEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM9isHACModeEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM20getCurrentCallOutputEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM19getCurrentCallInputEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM14getActiveStateEi(struct AudioHardwareANM *ANM, int a1);
void _ZN7android16AudioHardwareANM4lockEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM6unlockEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM10setMicMuteEb(struct AudioHardwareANM *ANM, bool a1);
void _ZN7android16AudioHardwareANM9setRxMuteEb(struct AudioHardwareANM *ANM, bool a1);
void _ZN7android16AudioHardwareANM15setRingbackMuteEb(struct AudioHardwareANM *ANM, bool a1);
void _ZN7android16AudioHardwareANM10onRingbackEb(struct AudioHardwareANM *ANM, bool a1);
void _ZN7android16AudioHardwareANM13doUpdateStateEib(struct AudioHardwareANM *ANM, int a1, bool a2);
void _ZN7android16AudioHardwareANM11updateStateEi(struct AudioHardwareANM *ANM, int a1);
void _ZN7android16AudioHardwareANM8stopVoIPEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM9startVoIPEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM10stopCSCallEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM11startCSCallEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM15unmuteAllSoundsEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM13muteAllSoundsEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM13unmuteFmRadioEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM11muteFmRadioEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM16closeInputStreamEPNS_13AudioStreamInE(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamIn* a1);
void _ZN7android16AudioHardwareANM11stopFmRadioEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM12startFmRadioEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM14getOutputStateEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_config* a2, int* a3);
void _ZN7android16AudioHardwareANM27notifyOutputAboutNormalModeEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM12forceRerouteEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM7setModeEi(struct AudioHardwareANM *ANM, int a1);
void _ZN7android16AudioHardwareANM19setIfVoIPprocessingEbi(struct AudioHardwareANM *ANM, bool a1, int a2);
void _ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE(struct AudioHardwareANM *ANM, android::RoutingInfo* a1);
void _ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE(struct AudioHardwareANM *ANM, android::RoutingInfo* a1);
void _ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv(struct AudioHardwareANM *ANM, bool a1, android::notification_type_t a2, void const* a3);
void _ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE(struct AudioHardwareANM *ANM, int a1, android::Vector<android::String16> const& a2);
void _ZN7android16AudioHardwareANM8askChildEPKcb(struct AudioHardwareANM *ANM, char const* a1, bool a2);
void _ZN7android16AudioHardwareANM15getNumParameterEPKcRj(struct AudioHardwareANM *ANM, char const* a1, unsigned int& a2);
void _ZN7android16AudioHardwareANM13getParametersERKNS_7String8E(struct AudioHardwareANM *ANM, android::String8 const& a1);
void _ZN7android16AudioHardwareANM13setParametersERKNS_7String8E(struct AudioHardwareANM *ANM, android::String8 const& a1);
void _ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamOut* a1);
void _ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_output_flags_t a2, audio_config* a3, int* a4);
}

namespace android {
	namespace AudioHardwareANM {
		void getMicMute(struct AudioHardwareANM *ANM, bool* a1) {
			_ZN7android16AudioHardwareANM10getMicMuteEPb(ANM, a1);
		}
		void setMasterVolume(struct AudioHardwareANM *ANM, float a1) {
			_ZN7android16AudioHardwareANM15setMasterVolumeEf(ANM, a1);
		}
		void getInputBufferSize(struct AudioHardwareANM *ANM, unsigned int a1, int a2, int a3) {
			_ZN7android16AudioHardwareANM18getInputBufferSizeEjii(ANM, a1, a2, a3);
		}
		void initCheck(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM9initCheckEv(ANM);
		}
		void handleError(struct AudioHardwareANM *ANM, int a1, android::adm_api_type_t a2) {
			_ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE(ANM, a1, a2);
		}
		void setVoiceVolume(struct AudioHardwareANM *ANM, float a1) {
			_ZN7android16AudioHardwareANM14setVoiceVolumeEf(ANM, a1);
		}
		void makeParam(struct AudioHardwareANM *ANM, char const* a1, unsigned int a2) {
			_ZN7android16AudioHardwareANM9makeParamEPKcj(ANM, a1, a2);
		}
		void hasValidInputs(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM14hasValidInputsEv(ANM);
		}
		void getActiveInput(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM14getActiveInputEv(ANM);
		}
		void singleInput(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM11singleInputEv(ANM);
		}
		void dumpErrorHistoryItem(struct AudioHardwareANM *ANM, android::String8& a1, android::ApiHistoryItem* a2) {
			_ZN7android16AudioHardwareANM20dumpErrorHistoryItemERNS_7String8EPNS_14ApiHistoryItemE(ANM, a1, a2);
		}
		void dumpErrorHistory(struct AudioHardwareANM *ANM, android::String8& a1) {
			_ZN7android16AudioHardwareANM16dumpErrorHistoryERNS_7String8E(ANM, a1);
		}
		void getMode(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM7getModeEv(ANM);
		}
		void predictInputDevice(struct AudioHardwareANM *ANM, unsigned int a1) {
			_ZN7android16AudioHardwareANM18predictInputDeviceEj(ANM, a1);
		}
		void updateDevice(struct AudioHardwareANM *ANM, bool a1, android::DeviceMap* a2, int a3) {
			_ZN7android16AudioHardwareANM12updateDeviceEbPNS_9DeviceMapEi(ANM, a1, a2, a3);
		}
		void getCSCallConnectionId(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM21getCSCallConnectionIdEv(ANM);
		}
		void disconnectCSCall(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM16disconnectCSCallEv(ANM);
		}
		void suspendInputs(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM13suspendInputsEv(ANM);
		}
		void resumeInputs(struct AudioHardwareANM *ANM, int a1) {
			_ZN7android16AudioHardwareANM12resumeInputsEi(ANM, a1);
		}
		void suspendInputIfDeviceIsWrong(struct AudioHardwareANM *ANM, unsigned int a1) {
			_ZN7android16AudioHardwareANM27suspendInputIfDeviceIsWrongEj(ANM, a1);
		}
		void doRoutingChange(struct AudioHardwareANM *ANM, android::RoutingInfo* a1) {
			_ZN7android16AudioHardwareANM15doRoutingChangeEPNS_11RoutingInfoE(ANM, a1);
		}
		void isNRisSupportedInBT(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM19isNRisSupportedInBTEv(ANM);
		}
		void isVideoCall(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM11isVideoCallEv(ANM);
		}
		void isExtraVolume(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM13isExtraVolumeEv(ANM);
		}
		void isHACMode(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM9isHACModeEv(ANM);
		}
		void getCurrentCallOutput(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM20getCurrentCallOutputEv(ANM);
		}
		void getCurrentCallInput(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM19getCurrentCallInputEv(ANM);
		}
		void getActiveState(struct AudioHardwareANM *ANM, int a1) {
			_ZN7android16AudioHardwareANM14getActiveStateEi(ANM, a1);
		}
		void lock(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM4lockEv(ANM);
		}
		void unlock(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM6unlockEv(ANM);
		}
		void setMicMute(struct AudioHardwareANM *ANM, bool a1) {
			_ZN7android16AudioHardwareANM10setMicMuteEb(ANM, a1);
		}
		void setRxMute(struct AudioHardwareANM *ANM, bool a1) {
			_ZN7android16AudioHardwareANM9setRxMuteEb(ANM, a1);
		}
		void setRingbackMute(struct AudioHardwareANM *ANM, bool a1) {
			_ZN7android16AudioHardwareANM15setRingbackMuteEb(ANM, a1);
		}
		void onRingback(struct AudioHardwareANM *ANM, bool a1) {
			_ZN7android16AudioHardwareANM10onRingbackEb(ANM, a1);
		}
		void doUpdateState(struct AudioHardwareANM *ANM, int a1, bool a2) {
			_ZN7android16AudioHardwareANM13doUpdateStateEib(ANM, a1, a2);
		}
		void updateState(struct AudioHardwareANM *ANM, int a1) {
			_ZN7android16AudioHardwareANM11updateStateEi(ANM, a1);
		}
		void stopVoIP(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM8stopVoIPEv(ANM);
		}
		void startVoIP(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM9startVoIPEv(ANM);
		}
		void stopCSCall(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM10stopCSCallEv(ANM);
		}
		void startCSCall(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM11startCSCallEv(ANM);
		}
		void unmuteAllSounds(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM15unmuteAllSoundsEv(ANM);
		}
		void muteAllSounds(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM13muteAllSoundsEv(ANM);
		}
		void unmuteFmRadio(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM13unmuteFmRadioEv(ANM);
		}
		void muteFmRadio(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM11muteFmRadioEv(ANM);
		}
		void closeInputStream(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamIn* a1) {
			_ZN7android16AudioHardwareANM16closeInputStreamEPNS_13AudioStreamInE(ANM, a1);
		}
		void stopFmRadio(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM11stopFmRadioEv(ANM);
		}
		void startFmRadio(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM12startFmRadioEv(ANM);
		}
		void getOutputState(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM14getOutputStateEv(ANM);
		}
		void openInputStream(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_config* a2, int* a3) {
			_ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi(ANM, a1, a2, a3);
		}
		void notifyOutputAboutNormalMode(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM27notifyOutputAboutNormalModeEv(ANM);
		}
		void forceReroute(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM12forceRerouteEv(ANM);
		}
		void setMode(struct AudioHardwareANM *ANM, int a1) {
			_ZN7android16AudioHardwareANM7setModeEi(ANM, a1);
		}
		void setIfVoIPprocessing(struct AudioHardwareANM *ANM, bool a1, int a2) {
			_ZN7android16AudioHardwareANM19setIfVoIPprocessingEbi(ANM, a1, a2);
		}
		void doRoutingEnd(struct AudioHardwareANM *ANM, android::RoutingInfo* a1) {
			_ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE(ANM, a1);
		}
		void doRoutingStart(struct AudioHardwareANM *ANM, android::RoutingInfo* a1) {
			_ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE(ANM, a1);
		}
		void childNotify(struct AudioHardwareANM *ANM, bool a1, android::notification_type_t a2, void const* a3) {
			_ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv(ANM, a1, a2, a3);
		}
		void dump(struct AudioHardwareANM *ANM, int a1, android::Vector<android::String16> const& a2) {
			_ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE(ANM, a1, a2);
		}
		void askChild(struct AudioHardwareANM *ANM, char const* a1, bool a2) {
			_ZN7android16AudioHardwareANM8askChildEPKcb(ANM, a1, a2);
		}
		void getNumParameter(struct AudioHardwareANM *ANM, char const* a1, unsigned int& a2) {
			_ZN7android16AudioHardwareANM15getNumParameterEPKcRj(ANM, a1, a2);
		}
		void getParameters(struct AudioHardwareANM *ANM, android::String8 const& a1) {
			_ZN7android16AudioHardwareANM13getParametersERKNS_7String8E(ANM, a1);
		}
		void setParameters(struct AudioHardwareANM *ANM, android::String8 const& a1) {
			_ZN7android16AudioHardwareANM13setParametersERKNS_7String8E(ANM, a1);
		}
		void closeOutputStream(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamOut* a1) {
			_ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE(ANM, a1);
		}
		void openOutputStream(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_output_flags_t a2, audio_config* a3, int* a4) {
			_ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi(ANM, a1, a2, a3, a4);
		}
	}
}

