#include "audio_hw.h"

extern void _ZN7android16AudioHardwareANM13muteAllSoundsEv(struct AudioHardwareANM*);

namespace android {
     namespace AudioHardwareANM {
            void muteAllSounds(struct AudioHardwareANM *ANM) {
		_ZN7android16AudioHardwareANM13muteAllSoundsEv(ANM);
            }
     }
}
