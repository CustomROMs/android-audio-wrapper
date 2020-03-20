import sys

'''strings /media/system1/root/CM13/vendor/samsung/u8500-common/common/system/lib/hw/audio.primary.montblanc.so |
				grep "android16AudioHardwareANM" | while read sym; do echo $sym";"`c++filt $sym`; done'''

s = '''_ZN7android16AudioHardwareANM10getMicMuteEPb;android::AudioHardwareANM::getMicMute(bool*)
_ZN7android16AudioHardwareANM15setMasterVolumeEf;android::AudioHardwareANM::setMasterVolume(float)
_ZN7android16AudioHardwareANM18getInputBufferSizeEjii;android::AudioHardwareANM::getInputBufferSize(unsigned int, int, int)
_ZN7android16AudioHardwareANM9initCheckEv;android::AudioHardwareANM::initCheck()
_ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE;android::AudioHardwareANM::handleError(int, android::adm_api_type_t)
_ZN7android16AudioHardwareANM14setVoiceVolumeEf;android::AudioHardwareANM::setVoiceVolume(float)
_ZN7android16AudioHardwareANMC2Ev;android::AudioHardwareANM::AudioHardwareANM()
_ZN7android16AudioHardwareANMC1Ev;android::AudioHardwareANM::AudioHardwareANM()
_ZN7android16AudioHardwareANM9makeParamEPKcj;android::AudioHardwareANM::makeParam(char const*, unsigned int)
_ZN7android16AudioHardwareANM14hasValidInputsEv;android::AudioHardwareANM::hasValidInputs()
_ZN7android16AudioHardwareANM14getActiveInputEv;android::AudioHardwareANM::getActiveInput()
_ZN7android16AudioHardwareANM11singleInputEv;android::AudioHardwareANM::singleInput()
_ZN7android16AudioHardwareANM20dumpErrorHistoryItemERNS_7String8EPNS_14ApiHistoryItemE;android::AudioHardwareANM::dumpErrorHistoryItem(android::String8&, android::ApiHistoryItem*)
_ZN7android16AudioHardwareANM16dumpErrorHistoryERNS_7String8E;android::AudioHardwareANM::dumpErrorHistory(android::String8&)
_ZN7android16AudioHardwareANM7getModeEv;android::AudioHardwareANM::getMode()
_ZN7android16AudioHardwareANM18predictInputDeviceEj;android::AudioHardwareANM::predictInputDevice(unsigned int)
_ZN7android16AudioHardwareANM12updateDeviceEbPNS_9DeviceMapEi;android::AudioHardwareANM::updateDevice(bool, android::DeviceMap*, int)
_ZN7android16AudioHardwareANM21getCSCallConnectionIdEv;android::AudioHardwareANM::getCSCallConnectionId()
_ZN7android16AudioHardwareANM16disconnectCSCallEv;android::AudioHardwareANM::disconnectCSCall()
_ZN7android16AudioHardwareANM13suspendInputsEv;android::AudioHardwareANM::suspendInputs()
_ZN7android16AudioHardwareANM12resumeInputsEi;android::AudioHardwareANM::resumeInputs(int)
_ZN7android16AudioHardwareANM27suspendInputIfDeviceIsWrongEj;android::AudioHardwareANM::suspendInputIfDeviceIsWrong(unsigned int)
_ZN7android16AudioHardwareANM15doRoutingChangeEPNS_11RoutingInfoE;android::AudioHardwareANM::doRoutingChange(android::RoutingInfo*)
_ZN7android16AudioHardwareANM19isNRisSupportedInBTEv;android::AudioHardwareANM::isNRisSupportedInBT()
_ZN7android16AudioHardwareANM11isVideoCallEv;android::AudioHardwareANM::isVideoCall()
_ZN7android16AudioHardwareANM13isExtraVolumeEv;android::AudioHardwareANM::isExtraVolume()
_ZN7android16AudioHardwareANM9isHACModeEv;android::AudioHardwareANM::isHACMode()
_ZN7android16AudioHardwareANM20getCurrentCallOutputEv;android::AudioHardwareANM::getCurrentCallOutput()
_ZN7android16AudioHardwareANM19getCurrentCallInputEv;android::AudioHardwareANM::getCurrentCallInput()
_ZN7android16AudioHardwareANM14getActiveStateEi;android::AudioHardwareANM::getActiveState(int)
_ZN7android16AudioHardwareANM4lockEv;android::AudioHardwareANM::lock()
_ZN7android16AudioHardwareANM6unlockEv;android::AudioHardwareANM::unlock()
_ZN7android16AudioHardwareANM10setMicMuteEb;android::AudioHardwareANM::setMicMute(bool)
_ZN7android16AudioHardwareANM9setRxMuteEb;android::AudioHardwareANM::setRxMute(bool)
_ZN7android16AudioHardwareANM15setRingbackMuteEb;android::AudioHardwareANM::setRingbackMute(bool)
_ZN7android16AudioHardwareANM10onRingbackEb;android::AudioHardwareANM::onRingback(bool)
_ZN7android16AudioHardwareANM13doUpdateStateEib;android::AudioHardwareANM::doUpdateState(int, bool)
_ZN7android16AudioHardwareANM11updateStateEi;android::AudioHardwareANM::updateState(int)
_ZN7android16AudioHardwareANM8stopVoIPEv;android::AudioHardwareANM::stopVoIP()
_ZN7android16AudioHardwareANM9startVoIPEv;android::AudioHardwareANM::startVoIP()
_ZN7android16AudioHardwareANM10stopCSCallEv;android::AudioHardwareANM::stopCSCall()
_ZN7android16AudioHardwareANM11startCSCallEv;android::AudioHardwareANM::startCSCall()
_ZN7android16AudioHardwareANM15unmuteAllSoundsEv;android::AudioHardwareANM::unmuteAllSounds()
_ZN7android16AudioHardwareANM13muteAllSoundsEv;android::AudioHardwareANM::muteAllSounds()
_ZN7android16AudioHardwareANM13unmuteFmRadioEv;android::AudioHardwareANM::unmuteFmRadio()
_ZN7android16AudioHardwareANM11muteFmRadioEv;android::AudioHardwareANM::muteFmRadio()
_ZN7android16AudioHardwareANM16closeInputStreamEPNS_13AudioStreamInE;android::AudioHardwareANM::closeInputStream(android::AudioStreamIn*)
_ZN7android16AudioHardwareANM11stopFmRadioEv;android::AudioHardwareANM::stopFmRadio()
_ZN7android16AudioHardwareANM12startFmRadioEv;android::AudioHardwareANM::startFmRadio()
_ZN7android16AudioHardwareANM14getOutputStateEv;android::AudioHardwareANM::getOutputState()
_ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi;android::AudioHardwareANM::openInputStream(audio_devices_t, audio_config*, int*)
_ZN7android16AudioHardwareANM27notifyOutputAboutNormalModeEv;android::AudioHardwareANM::notifyOutputAboutNormalMode()
_ZN7android16AudioHardwareANM12forceRerouteEv;android::AudioHardwareANM::forceReroute()
_ZN7android16AudioHardwareANM7setModeEi;android::AudioHardwareANM::setMode(int)
_ZN7android16AudioHardwareANM19setIfVoIPprocessingEbi;android::AudioHardwareANM::setIfVoIPprocessing(bool, int)
_ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE;android::AudioHardwareANM::doRoutingEnd(android::RoutingInfo*)
_ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE;android::AudioHardwareANM::doRoutingStart(android::RoutingInfo*)
_ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv;android::AudioHardwareANM::childNotify(bool, android::notification_type_t, void const*)
_ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE;android::AudioHardwareANM::dump(int, android::Vector<android::String16> const&)
_ZN7android16AudioHardwareANM8askChildEPKcb;android::AudioHardwareANM::askChild(char const*, bool)
_ZN7android16AudioHardwareANM15getNumParameterEPKcRj;android::AudioHardwareANM::getNumParameter(char const*, unsigned int&)
_ZN7android16AudioHardwareANM13getParametersERKNS_7String8E;android::AudioHardwareANM::getParameters(android::String8 const&)
_ZN7android16AudioHardwareANM13setParametersERKNS_7String8E;android::AudioHardwareANM::setParameters(android::String8 const&)
_ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE;android::AudioHardwareANM::closeOutputStream(android::AudioStreamOut*)
_ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi;android::AudioHardwareANM::openOutputStream(audio_devices_t, audio_output_flags_t, audio_config*, int*)'''

#s = '''_ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv android::AudioHardwareANM::childNotify(bool, android::notification_type_t, void const*)'''

#symbols = [(i.split(";")[0], i.split(";")[1].split("(")[0], i.split(" ")[1].split("(")[1].split(")")[0].split(", ")) for i in s.split("\n")]
symbols = []

for i in s.split("\n"):
	mangled, demangled = i.split(";")
	if not "(" in demangled:
		continue

	demangled_no_args = demangled.split("(")[0]
	args = demangled.split("(")[1].split(")")[0].split(", ")
	symbols.append([mangled, demangled_no_args, args])
	#print(mangled, demangled_no_args, args)

#sys.exit()

template = '''#include "audio_hw.h"

extern {
%s
}

namespace android {
	namespace AudioHardwareANM {
%s
	}
}
'''

#print(l)
externs = []
foos = []
for mangled, demangled, args in symbols:
	#print(args)
	if args == ['']:
		named_args = "struct AudioHardwareANM *ANM"
		args_no_type = "ANM"
	else:
		named_args = "struct AudioHardwareANM *ANM, " + ", ".join(["{type} a{num}".format(type=arg.replace(",", ""), num=n) for (n, arg) in enumerate(args, start=1)])
		args_no_type = "ANM, " + ", ".join(["a{num}".format(num=n) for (n, _) in enumerate(args, start=1)])

	e = "void %s(%s);" % (mangled, named_args)
	externs.append(e)
	foo_name = demangled.split("::")[-1]
	foo = ('''		void %s(%s) {
			%s(%s);
		}''' % (foo_name, named_args, mangled, args_no_type))

	foos.append(foo)

print(template % ("\n".join(externs), "\n".join(foos)))
