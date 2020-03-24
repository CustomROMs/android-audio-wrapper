LOCAL_PATH := $(call my-dir)

include $(LOCAL_PATH)/config.mk

L_CFLAGS := -g -Wall

#
# Audio Policy Wrapper
#
ifeq ($(BUILD_AUDIO_POLICY_WRAPPER), true)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    common.cpp \
    aps_wrapper.cpp \
    audio_policy.cpp

LOCAL_SHARED_LIBRARIES := \
    libhardware liblog libutils
LOCAL_STATIC_LIBRARIES := libmedia_helper

LOCAL_CFLAGS := $(L_CFLAGS)

LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE := audio_policy.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_TAGS := optional

#include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_HEAPTRACKED_SHARED_LIBRARY)
endif

#
# Audio HW Wrapper
#
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    load.c \
    common.cpp \
    audio_hw.cpp

#    audio_hw_hal.cpp

LOCAL_SHARED_LIBRARIES := \
    libste_adm libhardware liblog libutils libdl

LOCAL_STATIC_LIBRARIES := libmedia_helper

LOCAL_CFLAGS := $(L_CFLAGS)
LOCAL_INCLUDES := hardware/libhardware_legacy/include

LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE := audio.primary.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_TAGS := optional

LOCAL_LDFLAGS := -Wl,--unresolved-symbols=ignore-in-object-files

include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_HEAPTRACKED_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
       test.cpp

LOCAL_INCLUDES := hardware/libhardware_legacy/include
LOCAL_INCLUDES += hardware/libhardware/include

LOCAL_INCLUDES += hardware/u8500/libutils_legacy
#LOCAL_C_INCLUDES += hardware/u8500/libutils/include
LOCAL_SHARED_LIBRARIES := libLog libaudiohw_test

LOCAL_MODULE := audiohw_test
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
       libtest.cpp

LOCAL_INCLUDES := hardware/libhardware_legacy/include
LOCAL_INCLUDES += hardware/libhardware/include

LOCAL_INCLUDES += hardware/u8500/libutils_legacy
#LOCAL_C_INCLUDES += hardware/u8500/libutils/include
LOCAL_SHARED_LIBRARIES := libLog

LOCAL_MODULE := libaudiohw_test
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
