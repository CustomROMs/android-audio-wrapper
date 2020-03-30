/*
 * Copyright (C) 2011 The Android Open Source Project
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

#define LOG_TAG "AudioWrapper"
//#define LOG_NDEBUG 0

#include <errno.h>
#include <pthread.h>
#include <stdint.h>
#include <malloc.h>
#include <sys/time.h>
#include <sys/types.h>
#include <dlfcn.h>

#include <cutils/log.h>

#include "test.h"

extern int *gOutputs;
KeyedVector<audio_io_handle_t, AudioOutputDescriptor *> *gOutputs1;

using android::SortedVector;

extern void *createVec(void);

int (*size)(void);

int main() {
	//printf("sizeof(AudioHardwareANM) = %d\n", sizeof(AudioHardwareANM));
	//printf("sizeof(AudioHardwareANM1) = %d\n", sizeof(AudioHardwareANM1));
	//printf("sizeof(AudioHardwareANM1) = %d\n", sizeof(AudioHardwareANM1));

	KeyedVector<int*, void*> testVector;
	KeyedVector<audio_io_handle_t, AudioOutputDescriptor *> mOutputs;
	SortedVector<void*> mOutputs111;
	printf("sizeof(testVector) = %d\n", sizeof(testVector));
	printf("sizeof(mOutputs) = %d\n", sizeof(mOutputs));
	printf("sizeof(mOutputs111) = %d\n", sizeof(mOutputs111));
	//int *testVecPtr = static_cast<int*>(mOutputs.data());
	createVec();


	for (int i = 0; i < 5; i++) {
		printf("%s: gOutputs[%d] = %p\n", __func__, i, gOutputs[i]);
	}

	printf("%s: gOutputs.size() = %d\n", __func__, gOutputs1->size());
	printf("%s: mOutputs.size() = %d\n", __func__, mOutputs.size());

	mOutputs.add(1, NULL);
	printf("%s: mOutputs.size() = %d\n", __func__, mOutputs.size());
	mOutputs.add(2, NULL);
	printf("%s: mOutputs.size() = %d\n", __func__, mOutputs.size());

	int test1 = 5;
	int *testptr = &test1;

	*testptr = 4;
	printf("%d\n", *testptr);

	delete gOutputs;

	//printf("%x\n", 2);
	return 0;
}
