#include <errno.h>

#include <media/AudioParameter.h>
#include <media/AudioParameter.h>
#include <utils/Vector.h>

#include "audio_hw.h"

using android::String8;
using android::String16;
using android::Vector;

extern "C" {
int _ZN7android17AudioHardwareBase7setModeEi(struct AudioHardwareANM *ANM, int mode);
int _ZN7android17AudioHardwareBase15getMasterVolumeEPf(struct AudioHardwareANM *ANM, float* volume);
int _ZN7android17AudioHardwareBase9dumpStateEiRKNS_6VectorINS_8String16EEE(struct AudioHardwareANM *ANM, int fd, const Vector<String16>& args);
int _ZN7android17AudioHardwareBase13setParametersERKNS_7String8E(struct AudioHardwareANM *ANM, const String8& keyValuePairs);
int _ZN7android17AudioHardwareBase13getParametersERKNS_7String8E(struct AudioHardwareANM *ANM, const String8& keyValuePairs);
int _ZN7android17AudioHardwareBase18getInputBufferSizeEjii(struct AudioHardwareANM *ANM, uint32_t sampleRate, int format, int channelCount);
}

namespace android {
		namespace AudioHardwareBase {
				int setMode(struct AudioHardwareANM *ANM, int mode) {
					return _ZN7android17AudioHardwareBase7setModeEi(ANM, mode);
				}
				int getMasterVolume(struct AudioHardwareANM *ANM, float* volume) {
					return _ZN7android17AudioHardwareBase15getMasterVolumeEPf(ANM, volume);
				}
				int dumpState(struct AudioHardwareANM *ANM, int fd, const Vector<String16>& args) {
					return _ZN7android17AudioHardwareBase9dumpStateEiRKNS_6VectorINS_8String16EEE(ANM, fd, args);
				}
				int setParameters(struct AudioHardwareANM *ANM, const String8& keyValuePairs) {
					return _ZN7android17AudioHardwareBase13setParametersERKNS_7String8E(ANM, keyValuePairs);
				}
				int getParameters(struct AudioHardwareANM *ANM, const String8& keyValuePairs) {
					return _ZN7android17AudioHardwareBase13getParametersERKNS_7String8E(ANM, keyValuePairs);
				}
				int getInputBufferSize(struct AudioHardwareANM *ANM, uint32_t sampleRate, int format, int channelCount) {
					return _ZN7android17AudioHardwareBase18getInputBufferSizeEjii(ANM, sampleRate, format, channelCount);
				}
		}
}

extern "C" {
int _ZN7android16AudioHardwareANM10getMicMuteEPb(struct AudioHardwareANM *ANM, bool* state);
int _ZN7android16AudioHardwareANM15setMasterVolumeEf(struct AudioHardwareANM *ANM, float volume);
void _ZN7android16AudioHardwareANM18getInputBufferSizeEjii(struct AudioHardwareANM *ANM, unsigned int a1, int a2, int a3);
int _ZN7android16AudioHardwareANM9initCheckEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE(struct AudioHardwareANM *ANM, int a1, android::adm_api_type_t a2);
int _ZN7android16AudioHardwareANM14setVoiceVolumeEf(struct AudioHardwareANM *ANM, float a1);
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
int _ZN7android16AudioHardwareANM14getOutputStateEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_config* a2, int* a3);
void _ZN7android16AudioHardwareANM27notifyOutputAboutNormalModeEv(struct AudioHardwareANM *ANM);
void _ZN7android16AudioHardwareANM12forceRerouteEv(struct AudioHardwareANM *ANM);
int _ZN7android16AudioHardwareANM7setModeEi(struct AudioHardwareANM *ANM, int mode);
void _ZN7android16AudioHardwareANM19setIfVoIPprocessingEbi(struct AudioHardwareANM *ANM, bool a1, int a2);
void _ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE(struct AudioHardwareANM *ANM, android::RoutingInfo* a1);
void _ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE(struct AudioHardwareANM *ANM, android::RoutingInfo* a1);
void _ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv(struct AudioHardwareANM *ANM, bool a1, android::notification_type_t a2, void const* a3);
void _ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE(struct AudioHardwareANM *ANM, int a1, android::Vector<android::String16> const& a2);
void _ZN7android16AudioHardwareANM8askChildEPKcb(struct AudioHardwareANM *ANM, char const* a1, bool a2);
void _ZN7android16AudioHardwareANM15getNumParameterEPKcRj(struct AudioHardwareANM *ANM, char const* a1, unsigned int& a2);
void _ZN7android16AudioHardwareANM13getParametersERKNS_7String8E(struct AudioHardwareANM *ANM, android::String8 const& a1);
int _ZN7android16AudioHardwareANM13setParametersERKNS_7String8E(struct AudioHardwareANM *ANM, android::String8 const& keyValuePair);
void _ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamOut* a1);
void _ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_output_flags_t a2, audio_config* a3, int* a4);
}

extern struct AudioHardwareANM *gANM;

namespace android {
	namespace AudioHardwareANM {
		int getMicMute(struct AudioHardwareANM *ANM, bool *state) {
			*state = gANM->mIsMicMuted;
			return 0;
		}
		int setMasterVolume(struct AudioHardwareANM *ANM, float volume) {
			return -ENOSYS;
		}
		
		// already implemented in adev_get_input_buffer_size
		void getInputBufferSize(struct AudioHardwareANM *ANM, unsigned int a1, int a2, int a3) {
			_ZN7android16AudioHardwareANM18getInputBufferSizeEjii(gANM, a1, a2, a3);
		}

		int initCheck(struct AudioHardwareANM *ANM) {
			int outSz = ANM->mOutputs.size();
			int inSz = ANM->mInputs.size();
			if (outSz > 0 || inSz > 0) {
				ALOGI("%s: Already initialized! out=%d, in=%d", __func__, outSz, inSz);
				return NO_ERROR;
			}

			ALOGV("%s: OK", __func__);
			return NO_ERROR;
		}
		void handleError(struct AudioHardwareANM *ANM, int a1, android::adm_api_type_t a2) {
			_ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE(gANM, a1, a2);
		}
		int setVoiceVolume(struct AudioHardwareANM *ANM, float volume) {
			if (volume < 0.0) {
				ALOGE("%s: setVoiceVolume(%f): Bad value", __func__, volume);
				return BAD_VALUE;
			}
			
			ALOGE("%s: setVoiceVolume(%d)", __func__, (int)volume);
			int rc = ste_adm_client_set_cscall_downstream_volume((int)volume);

			if (rc) {
				ALOGE("%s: ste_adm_client_set_cscall_downstream_volume failed", __func__);
				//android::AudioHardwareANM::handleError(ANM, rc, 5);
				return UNKNOWN_ERROR;
			}

			return NO_ERROR;
		}
		void makeParam(struct AudioHardwareANM *ANM, char *a1, unsigned int a2) {
			_ZN7android16AudioHardwareANM9makeParamEPKcj(gANM, a1, a2);
		}
		void hasValidInputs(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM14hasValidInputsEv(gANM);
		}
		void getActiveInput(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM14getActiveInputEv(gANM);
		}
		void singleInput(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM11singleInputEv(gANM);
		}
		void dumpErrorHistoryItem(struct AudioHardwareANM *ANM, android::String8& a1, android::ApiHistoryItem* a2) {
			_ZN7android16AudioHardwareANM20dumpErrorHistoryItemERNS_7String8EPNS_14ApiHistoryItemE(gANM, a1, a2);
		}
		void dumpErrorHistory(struct AudioHardwareANM *ANM, android::String8& a1) {
			_ZN7android16AudioHardwareANM16dumpErrorHistoryERNS_7String8E(gANM, a1);
		}
		void getMode(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM7getModeEv(gANM);
		}
		void predictInputDevice(struct AudioHardwareANM *ANM, unsigned int a1) {
			_ZN7android16AudioHardwareANM18predictInputDeviceEj(gANM, a1);
		}
		void updateDevice(struct AudioHardwareANM *ANM, bool a1, android::DeviceMap* a2, int a3) {
			_ZN7android16AudioHardwareANM12updateDeviceEbPNS_9DeviceMapEi(gANM, a1, a2, a3);
		}
		void getCSCallConnectionId(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM21getCSCallConnectionIdEv(gANM);
		}
		void disconnectCSCall(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM16disconnectCSCallEv(gANM);
		}
		void suspendInputs(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM13suspendInputsEv(gANM);
		}
		void resumeInputs(struct AudioHardwareANM *ANM, int a1) {
			_ZN7android16AudioHardwareANM12resumeInputsEi(gANM, a1);
		}
		void suspendInputIfDeviceIsWrong(struct AudioHardwareANM *ANM, unsigned int a1) {
			_ZN7android16AudioHardwareANM27suspendInputIfDeviceIsWrongEj(gANM, a1);
		}
		void doRoutingChange(struct AudioHardwareANM *ANM, android::RoutingInfo* a1) {
			_ZN7android16AudioHardwareANM15doRoutingChangeEPNS_11RoutingInfoE(gANM, a1);
		}
		void isNRisSupportedInBT(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM19isNRisSupportedInBTEv(gANM);
		}
		void isVideoCall(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM11isVideoCallEv(gANM);
		}
		void isExtraVolume(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM13isExtraVolumeEv(gANM);
		}
		void isHACMode(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM9isHACModeEv(gANM);
		}
		void getCurrentCallOutput(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM20getCurrentCallOutputEv(gANM);
		}
		void getCurrentCallInput(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM19getCurrentCallInputEv(gANM);
		}
		void getActiveState(struct AudioHardwareANM *ANM, int a1) {
			_ZN7android16AudioHardwareANM14getActiveStateEi(gANM, a1);
		}
		void lock(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM4lockEv(gANM);
		}
		void unlock(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM6unlockEv(gANM);
		}
		void setMicMute(struct AudioHardwareANM *ANM, bool a1) {
			_ZN7android16AudioHardwareANM10setMicMuteEb(gANM, a1);
		}
		void setRxMute(struct AudioHardwareANM *ANM, bool a1) {
			_ZN7android16AudioHardwareANM9setRxMuteEb(gANM, a1);
		}
		void setRingbackMute(struct AudioHardwareANM *ANM, bool a1) {
			_ZN7android16AudioHardwareANM15setRingbackMuteEb(gANM, a1);
		}
		void onRingback(struct AudioHardwareANM *ANM, bool a1) {
			_ZN7android16AudioHardwareANM10onRingbackEb(gANM, a1);
		}
		void doUpdateState(struct AudioHardwareANM *ANM, int a1, bool a2) {
			_ZN7android16AudioHardwareANM13doUpdateStateEib(gANM, a1, a2);
		}
		void updateState(struct AudioHardwareANM *ANM, int a1) {
			_ZN7android16AudioHardwareANM11updateStateEi(gANM, a1);
		}
		void stopVoIP(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM8stopVoIPEv(gANM);
		}
		void startVoIP(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM9startVoIPEv(gANM);
		}
		void stopCSCall(struct AudioHardwareANM *ANM) {
			if (gANM->csCallState & 1)
			{
				ALOGI("%s: Stop CSCall, (%p)", __func__, gANM->csCallState);
				android::AudioHardwareANM::updateState(gANM, gANM->csCallState & 0xFFFFFFFE);
			}
		}

		void startCSCall(struct AudioHardwareANM *ANM) {
			if ( !(gANM->csCallState & 1) )
			{
				ALOGI("%s: Start CSCall, %p", __func__, gANM->csCallState);
				android::AudioHardwareANM::setRingbackMute(gANM, false);
				android::AudioHardwareANM::updateState(gANM, gANM->csCallState | 1);
			}
		}
		void unmuteAllSounds(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM15unmuteAllSoundsEv(gANM);
		}
		void muteAllSounds(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM13muteAllSoundsEv(gANM);
		}
		void unmuteFmRadio(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM13unmuteFmRadioEv(gANM);
		}
		void muteFmRadio(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM11muteFmRadioEv(gANM);
		}
		void closeInputStream(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamIn* a1) {
			_ZN7android16AudioHardwareANM16closeInputStreamEPNS_13AudioStreamInE(gANM, a1);
		}
		void stopFmRadio(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM11stopFmRadioEv(gANM);
		}
		void startFmRadio(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM12startFmRadioEv(gANM);
		}
		int getOutputState(struct AudioHardwareANM *ANM) {
			return _ZN7android16AudioHardwareANM14getOutputStateEv(gANM);
		}
		void openInputStream(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_config* a2, int* a3) {
			_ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi(gANM, a1, a2, a3);
		}
		void notifyOutputAboutNormalMode(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM27notifyOutputAboutNormalModeEv(gANM);
		}
		void forceReroute(struct AudioHardwareANM *ANM) {
			_ZN7android16AudioHardwareANM12forceRerouteEv(gANM);
		}
		int setMode(struct AudioHardwareANM *ANM, int mode) {
			ALOGI("setMode(%d)", mode);
			ALOGE("%s: mIsMono: %d, mFormat: %d, mTtyMode: %d, mChannelMask: %d", __func__, gANM->mIsMono, gANM->mFormat, gANM->mTtyMode, gANM->mChannelMask);
			android::AudioHardwareBase::setMode(gANM, mode);
			if ( mode != 2 )
			{
				android::AudioHardwareANM::stopCSCall(gANM);
				if ( mode == 4 ) {
					if ( !gANM->unk10 )
					{
					  gANM->unk10 = 1;
					  if ( gANM->csCallState & 2 )
						android::AudioHardwareANM::forceReroute(gANM);
					}
				}
				return NO_ERROR;
			}

			if (gANM->unk10) {
				gANM->unk10 = 0;
				if (gANM->csCallState & 2)
					android::AudioHardwareANM::forceReroute(gANM);
			}
			
			if (mode != 4) {
				if ( mode == 2 ) {
					android::AudioHardwareANM::startCSCall(gANM);
				} else if (!mode) {
					android::AudioHardwareANM::notifyOutputAboutNormalMode(gANM);
				}
			} else {
				if (!gANM->unk10 ) {
					gANM->unk10 = 1;
					if ( gANM->csCallState & 2 )
						android::AudioHardwareANM::forceReroute(gANM);
				}
			}

			ALOGI("setMode(%d) end", mode);
			return NO_ERROR;
		}
		void setIfVoIPprocessing(struct AudioHardwareANM *ANM, bool a1, int a2) {
			_ZN7android16AudioHardwareANM19setIfVoIPprocessingEbi(gANM, a1, a2);
		}
		void doRoutingEnd(struct AudioHardwareANM *ANM, android::RoutingInfo* a1) {
			_ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE(gANM, a1);
		}
		void doRoutingStart(struct AudioHardwareANM *ANM, android::RoutingInfo* a1) {
			_ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE(gANM, a1);
		}
		void childNotify(struct AudioHardwareANM *ANM, bool a1, android::notification_type_t a2, void const* a3) {
			_ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv(gANM, a1, a2, a3);
		}
		void dump(struct AudioHardwareANM *ANM, int a1, android::Vector<android::String16> const& a2) {
			_ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE(gANM, a1, a2);
		}
		void askChild(struct AudioHardwareANM *ANM, char const* a1, bool a2) {
			_ZN7android16AudioHardwareANM8askChildEPKcb(gANM, a1, a2);
		}
		void getNumParameter(struct AudioHardwareANM *ANM, char const* a1, unsigned int& a2) {
			_ZN7android16AudioHardwareANM15getNumParameterEPKcRj(gANM, a1, a2);
		}
		void getParameters(struct AudioHardwareANM *ANM, android::String8 const& a1) {
			_ZN7android16AudioHardwareANM13getParametersERKNS_7String8E(gANM, a1);
		}
		
		int *outputCheckIdx(struct vector *outputs, int outputIdx)
		{
			/*int size = outputs->size;
			if ( outputIdx >= size) {
				ALOGE("itemAt: index %d is past size %d", outputIdx, size);
				return NULL;
			}
			
			int *outputs_ptr = reinterpret_cast<int*>(outputs);
			
			return outputs_ptr + sizeof(struct vector *) + 4 * outputIdx;*/
			return NULL;
		}

		int setParameters(struct AudioHardwareANM *ANM, android::String8 const& keyValuePair) {
			#if 0
			AudioParameter param = AudioParameter(keyValuePair);
			String8 value;

			if (param.get(String8("bt_headset_nrec"), value) == NO_ERROR)
			{
				bool btMatchFlag = (value == "on");
				android::AudioHardwareANM::lock(gANM);
				if (btMatchFlag != gANM->mBtHeadsetEnabled)
				{
					gANM->mBtHeadsetEnabled = btMatchFlag;
					if ( android::AudioHardwareANM::getOutputState(gANM) << 30 )
						android::AudioHardwareANM::forceReroute(gANM);
				}
				android::AudioHardwareANM::unlock(gANM);
			}
			
			if (param.get(String8("extraVolume"), value) == NO_ERROR)
			{
				bool extraVolumeFlag = (value == "true");
				android::AudioHardwareANM::lock(gANM);
				if (extraVolumeFlag != gANM->mExtraVolumeEnabled)
				{
					gANM->mExtraVolumeEnabled = extraVolumeFlag;
					if (android::AudioHardwareANM::getOutputState(gANM) & 1)
						android::AudioHardwareANM::forceReroute(gANM);
				}
				android::AudioHardwareANM::unlock(gANM);
			}
			
			ste_adm_tty_mode_t ttyMode = STE_ADM_TTY_MODE_INVALID;
			
			if (param.get(String8("tty_mode"),value) == NO_ERROR) {
				if (value == "tty_full") {
					ttyMode = STE_ADM_TTY_MODE_FULL;
				} else if (value == "tty_vco") {
					ttyMode = STE_ADM_TTY_MODE_VCO;
				} else if (value == "tty_hco") {
					ttyMode = STE_ADM_TTY_MODE_HCO;
				} else {
					ttyMode = STE_ADM_TTY_MODE_OFF;
				}
			}
			
			if (ttyMode != STE_ADM_TTY_MODE_INVALID) {
				gANM->mTtyMode = ttyMode;
			}
			
			if (ttyMode == STE_ADM_TTY_MODE_VCO) {
					ALOGI("%s: ste_adm_client_set_cscall_tty_mode(%d)", __func__, gANM->mTtyMode);
					int setTtyModeRet = ste_adm_client_set_cscall_tty_mode(gANM->mTtyMode);
					android::AudioHardwareANM::handleError(gANM, setTtyModeRet, 11);
					if (setTtyModeRet)
						ALOGE("%s: ste_adm_client_set_cscall_tty_mode failed: %d", __func__, setTtyModeRet);
			}
			
			if (ttyMode == STE_ADM_TTY_MODE_OFF) {
				if (param.get(String8("voip"), value) == NO_ERROR)
				{
					if (value == "on")
						android::AudioHardwareANM::startVoIP(gANM);
					else
						android::AudioHardwareANM::stopVoIP(gANM);
				}
			}
			
			if (param.get(String8("fm_radio_volume"), value) == NO_ERROR)
			{
				if (value == "on")
					android::AudioHardwareANM::startFmRadio(gANM);
				else
					android::AudioHardwareANM::stopFmRadio(gANM);
			}
			
			int intVal;
			
			if (param.getInt(String8("fm_radio_mute"), intVal) == NO_ERROR)
			{
				if (intVal)
					android::AudioHardwareANM::muteFmRadio(gANM);
				else
					android::AudioHardwareANM::unmuteFmRadio(gANM);
			}
			
			if (param.getInt(String8("all_sound_mute"), intVal) == NO_ERROR)
			{
				if (intVal)
					android::AudioHardwareANM::muteAllSounds(gANM);
				else
					android::AudioHardwareANM::unmuteAllSounds(gANM);
			}
			
			if (param.getInt(String8("toMono"), intVal) == NO_ERROR)
			{
				gANM->mIsMono = (bool)intVal;
				
				int idx = 0;
				/*while (idx < ANM->mOutputs.size)
				{
					int *output = outputCheckIdx(&ANM->mOutputs, idx++);
					 if (output != NULL) {
						android::AudioStreamOutANM::setStereoToMono(*output, ANM->mIsMono);
					} 
				}*/

			}
			
			if (param.get(String8("dha"), value) == NO_ERROR)
			{
				/*
					char *charVal = value.string();
					
					ste_adm_set_DHA_mode(charVal, *(value - 3) - 1);
				*/
			}
			
			//  android::String8::String8(&s1, &unk_12858);
			//  android::String8::String8(&v75, &unk_12858);
			
			if (param.getInt(String8(android::AudioParameter::keyRouting), intVal) == NO_ERROR)
			{
				gANM->devices1 = intVal & 0x3FFFF;
				gANM->devices2 = intVal & 0x97FC0000;
				if (gANM->devices1)
				{
				  /*android::AudioHardwareANM::makeParam(&v77, ANM, v36, v38);
				  android::String8::append(&s1, &v77);
				  android::String8::~String8(&v77);*/
				}
 
				if (gANM->devices2)
				{
				  /*
				  android::AudioHardwareANM::makeParam(&v78, ANM, v36, v40);
				  android::String8::append(&v75, &v78);
				  android::String8::~String8(&v78);
				  */
				}
			}
			 #endif
			return _ZN7android16AudioHardwareANM13setParametersERKNS_7String8E(gANM, keyValuePair);
		}
		void closeOutputStream(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamOut* a1) {
			_ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE(gANM, a1);
		}
		void openOutputStream(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_output_flags_t a2, audio_config* a3, int* a4) {
			_ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi(ANM, a1, a2, a3, a4);
		}
	}
}

