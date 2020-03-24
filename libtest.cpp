#include "test.h"

KeyedVector<audio_io_handle_t, AudioOutputDescriptor *> *gOutputs;
KeyedVector<audio_io_handle_t, AudioOutputDescriptor *> *gOutputs1;

void createVec(void) {
	KeyedVector<audio_io_handle_t, AudioOutputDescriptor *> *mOutputs = new KeyedVector<audio_io_handle_t, AudioOutputDescriptor *>[1];
	gOutputs = mOutputs;
	gOutputs1 = mOutputs;
	mOutputs->add(0, NULL);
}
