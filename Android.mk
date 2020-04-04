LOCAL_PATH := $(call my-dir)

include $(LOCAL_PATH)/config.mk


#######################################################################################3

## Definitions used by several targets. ##
##										##

###################################
# AHI files
#
###################################

#Location for sourcefiles needed for the ANM, AHI implementation
SRC_FOLDER_AHI := legacy/src/ahi
#Location of dbg specific files
SRC_FOLDER_DBG := legacy/src

# Source files needed to build Audio Network Manager.
SRC_FILES_ANM := \
	$(SRC_FOLDER_AHI)/ste_anm_ahi.cpp \
	$(SRC_FOLDER_AHI)/ste_anm_ahi_output.cpp \
	$(SRC_FOLDER_AHI)/ste_anm_ahi_input.cpp \
	$(SRC_FOLDER_AHI)/ste_anm_ahi_admbase.cpp \
	$(SRC_FOLDER_DBG)/ste_anm_dbg.cpp



###################################
# Audio Policy files
#
###################################
#Source folder for Audio Policy Manager
SRC_FOLDER_AP := legacy/src/policy

#Source filed for Audio Policy Manager
SRC_FILES_AP := \
	$(SRC_FOLDER_AP)/ste_anm_ap.cpp \
    $(SRC_FOLDER_DBG)/ste_anm_dbg.cpp


###################################
# Flags
#
###################################

# Common flags
CFLAGS_COMMON_ANM := -DLOG_WARNINGS \
	-DLOG_ERRORS \
	-D_POSIX_SOURCE

ifeq ($(A2DP_USES_STANDARD_ANDROID_PATH),true)
CFLAGS_COMMON_ANM += -DSTD_A2DP_MNGT
endif
# Host specific flags
CFLAGS_HOST_ANM :=


# Target specific flags.
CFLAGS_TARGET_ANM := \
	-DTARGET_BUILD

# Headers from external packages.
EXTERNAL_INCLUDES_ANM := \
	external/alsa-lib/include \
	$(MULTIMEDIA_PATH)/audio/adm/include \
	$(MULTIMEDIA_PATH)/shared/utils/include

#######################################################################################################
#
# TARGET SHARED LIBRARY #
#
########################################################################################################

#ifeq ($(strip $(BOARD_USES_LD_ANM)),true)

#
# Build audio_policy.PLATFORM for Audio Policy Manager
#

# Make a libaudiopolicy which can be used by both audio_policy.PLATFORM and audio.primary.PLATFORM
include $(CLEAR_VARS)


LOCAL_SRC_FILES := $(SRC_FILES_AP)

LOCAL_CFLAGS += $(CFLAGS_COMMON_ANM)

LOCAL_MODULE := libaudiopolicy
LOCAL_MODULE_TAGS := optional

ifeq ($(BOARD_HAVE_BLUETOOTH),true)
  LOCAL_CFLAGS += -DWITH_BLUETOOTH -DWITH_A2DP
endif

LOCAL_STATIC_LIBRARIES := \
	libmedia_helper

LOCAL_SHARED_LIBRARIES := \
	libste_adm \
	libcutils \
	libstelpcutils \
	libutils \
	libmedia \
	libhardware_legacy \
	libdl \
	libc

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/legacy/include \
	$(EXTERNAL_INCLUDES_ANM)

include $(BUILD_SHARED_LIBRARY)

# Generate the audio_policy.PLATFORM shared library used by Audio HAL
include $(CLEAR_VARS)

LOCAL_MODULE := audio_policy.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE_TAGS := optional

LOCAL_STATIC_LIBRARIES := \
	libmedia_helper

LOCAL_SHARED_LIBRARIES := \
	libste_adm \
	libaudiopolicy \
	libcutils \
	libutils \
	libmedia \
	libhardware_legacy \
	libdl \
	libc

# Add static link to libaudiopolicy_legacy and expose
# it from this shared library
LOCAL_WHOLE_STATIC_LIBRARIES := \
	libaudiopolicy_legacy

#include $(BUILD_SHARED_LIBRARY)

#
# Build audio.primary.PLATFORM for Audio Hardware
#

include $(CLEAR_VARS)
LOCAL_MODULE := audio.primary1.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE_TAGS := optional

#Android libraries to link against.
LOCAL_SHARED_LIBRARIES := \
	libste_adm \
	libcutils \
	libstelpcutils \
	libutils \
	libmedia \
	libhardware \
	liblog \
	libasound \
	libdl \
	libaudiopolicy

#	RilInterface.cpp \
#        ril_interface.c \

LOCAL_SRC_FILES += \
	$(SRC_FILES_ANM)

LOCAL_CFLAGS += \
	$(CFLAGS_COMMON_ANM) \
	$(CFLAGS_TARGET_ANM)

LOCAL_C_INCLUDES += \
	$(EXTERNAL_INCLUDES_ANM) \
	$(LOCAL_PATH)/legacy/include

# Static libraries to link against. We also need
# the ADM client library.
LOCAL_STATIC_LIBRARIES += \
	libmedia_helper

# Add static link to libaudiohw_legacy and expose
# it from this shared library
LOCAL_WHOLE_STATIC_LIBRARIES := \
	libaudiohw_legacy

#Build an executable for host using the above variables
#include $(BUILD_SHARED_LIBRARY)


###########################################


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
    audio_hw.cpp \
	audio_hw_hal.cpp \
	AudioHardwareInterface.cpp \
	$(SRC_FOLDER_AHI)/ste_anm_ahi.cpp \
	$(SRC_FOLDER_AHI)/ste_anm_ahi_output.cpp \
	$(SRC_FOLDER_AHI)/ste_anm_ahi_input.cpp \
	$(SRC_FOLDER_AHI)/ste_anm_ahi_admbase.cpp \
	$(SRC_FOLDER_DBG)/ste_anm_dbg.cpp

LOCAL_SHARED_LIBRARIES := \
    libste_adm libhardware liblog libutils libcutils libdl libstelpcutils libmedia

LOCAL_CFLAGS := $(L_CFLAGS)
LOCAL_INCLUDES := hardware/libhardware_legacy/include

LOCAL_CFLAGS += \
	$(CFLAGS_COMMON_ANM) \
	$(CFLAGS_TARGET_ANM)

LOCAL_C_INCLUDES += \
	$(EXTERNAL_INCLUDES_ANM) \
	$(LOCAL_PATH)/legacy/include

LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE := audio.primary.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_TAGS := optional

#LOCAL_LDFLAGS := -Wl,--unresolved-symbols=ignore-in-object-files

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
