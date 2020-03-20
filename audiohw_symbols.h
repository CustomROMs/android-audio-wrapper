#include "audio_hw.h"

/*extern "C" void *_ZN7android16AudioHardwareANM13muteAllSoundsEv;

namespace android {
namespace AudioHardwareANM {
	void (*muteAllSounds)(struct AudioHardwareANM *ANM);
}
}*/

extern "C" {
	void _ZN7android16AudioHardwareANM13muteAllSoundsEv(struct AudioHardwareANM *ANM);
}
