#include "common.h"
#include "include/4.0/hardware/audio.h"

//#include "audio_hw.h"
#include <hardware/audio.h>
//#include "include/utils/LegacyVectorImpl.h"
//#include "include/utils/KeyedVector.h"

#include <hardware/hardware.h>
#include <system/audio.h>

#include <hardware_legacy/AudioPolicyInterface.h>
//using android_legacy::SortedVector;

#include <utils/KeyedVector.h>

using android::KeyedVector;

    enum stream_type {
        DEFAULT          =-1,
        VOICE_CALL       = 0,
        SYSTEM           = 1,
        RING             = 2,
        MUSIC            = 3,
        ALARM            = 4,
        NOTIFICATION     = 5,
        BLUETOOTH_SCO    = 6,
        ENFORCED_AUDIBLE = 7, // Sounds that cannot be muted by user and must be routed to speaker
        DTMF             = 8,
        TTS              = 9,
#ifdef LEGACY_ALSA_AUDIO
        INCALL_MUSIC     = 10,
#endif
        NUM_STREAM_TYPES
    };

        enum routing_strategy {
            STRATEGY_MEDIA,
            STRATEGY_PHONE,
            STRATEGY_SONIFICATION,
            STRATEGY_SONIFICATION_RESPECTFUL,
            STRATEGY_DTMF,
            STRATEGY_ENFORCED_AUDIBLE,
            NUM_STRATEGIES
        };



typedef int status_t;

class IOProfile;

        class AudioOutputDescriptor
        {
        public:
            AudioOutputDescriptor(const IOProfile *profile);

            status_t    dump(int fd);

            audio_devices_t device() const;
            void changeRefCount(int stream, int delta);

            bool isDuplicated() const { return (mOutput1 != NULL && mOutput2 != NULL); }
            audio_devices_t supportedDevices();
            uint32_t latency();
            bool sharesHwModuleWith(const AudioOutputDescriptor *outputDesc);
            bool isActive(uint32_t inPastMs = 0) const;
            bool isStreamActive(int stream,
                                uint32_t inPastMs = 0,
                                nsecs_t sysTime = 0) const;
            bool isStrategyActive(int strategy,
                             uint32_t inPastMs = 0,
                             nsecs_t sysTime = 0) const;

            audio_io_handle_t mId;              // output handle
            uint32_t mSamplingRate;             //
            audio_format_t mFormat;             //
            audio_channel_mask_t mChannelMask;     // output configuration
            uint32_t mLatency;                  //
            audio_output_flags_t mFlags;   //
            audio_devices_t mDevice;                   // current device this output is routed to
            uint32_t mRefCount[NUM_STREAM_TYPES]; // number of streams of each type using this output
            nsecs_t mStopTime[NUM_STREAM_TYPES];
            AudioOutputDescriptor *mOutput1;    // used by duplicated outputs: first output
            AudioOutputDescriptor *mOutput2;    // used by duplicated outputs: second output
            float mCurVolume[NUM_STREAM_TYPES];   // current stream volume
            int mMuteCount[NUM_STREAM_TYPES];     // mute request counter
            const IOProfile *mProfile;          // I/O profile this output derives from
            bool mStrategyMutedByDevice[NUM_STRATEGIES]; // strategies muted because of incompatible
                                                // device selection. See checkDeviceMuteStrategies()
            uint32_t mDirectOpenCount; // number of clients using this output (direct outputs only)
            bool mForceRouting; // Next routing for this output will be forced as current device routed is null
        };


