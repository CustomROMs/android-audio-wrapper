#include <errno.h>

#include <media/AudioParameter.h>
#include <media/AudioParameter.h>
#include <utils/Vector.h>

#include "audio_hw.h"

using android::String8;
using android::String16;
using android::Vector;

class DeviceList;

#include "audiohw_symbols.h"

namespace android {
	namespace AudioHardwareBase1 {
		int setMode(struct AudioHardwareANM *ANM, int mode) {
			return shim_ZN7android17AudioHardwareBase7setModeEi(ANM, mode);
		}
		int getMasterVolume(struct AudioHardwareANM *ANM, float* volume) {
			return shim_ZN7android17AudioHardwareBase15getMasterVolumeEPf(ANM, volume);
		}
		int dumpState(struct AudioHardwareANM *ANM, int fd, const Vector<String16>& args) {
			return shim_ZN7android17AudioHardwareBase9dumpStateEiRKNS_6VectorINS_8String16EEE(ANM, fd, args);
		}
		int setParameters(struct AudioHardwareANM *ANM, const String8& keyValuePairs) {
			return shim_ZN7android17AudioHardwareBase13setParametersERKNS_7String8E(ANM, keyValuePairs);
		}
		char *getParameters(struct AudioHardwareANM *ANM, const String8& keyValuePairs) {
			return shim_ZN7android17AudioHardwareBase13getParametersERKNS_7String8E(ANM, keyValuePairs);
		}
		int getInputBufferSize(struct AudioHardwareANM *ANM, uint32_t sampleRate, int format, int channelCount) {
			return shim_ZN7android17AudioHardwareBase18getInputBufferSizeEjii(ANM, sampleRate, format, channelCount);
		}
	}
}

namespace android {
	namespace AudioHardwareANM {
		void handleError(struct AudioHardwareANM *ANM, int a1, android::adm_api_type_t a2);
	}
}

extern "C" int getpriority(int, int);
extern "C" void setpriority(int, int, int);

namespace android {
	namespace AudioStreamOutANM {
		   namespace CommandThread {
			int start(struct CommandThread *CT) {
				   return shim_ZN7android17AudioStreamOutANM13CommandThread5startEv(CT);
			}
			int exit(struct CommandThread *CT) {
				   return shim_ZN7android17AudioStreamOutANM13CommandThread4exitEv(CT);
			}
			int dump(struct CommandThread *CT, android::String8& a1) {
				   return shim_ZN7android17AudioStreamOutANM13CommandThread4dumpERNS_7String8E(CT, a1);
			}
			int insertCommand_l(struct CommandThread *CT, struct Command* c) {
				   return shim_ZN7android17AudioStreamOutANM13CommandThread15insertCommand_lEPNS1_7CommandE(CT, c);
			}
			int setForce(struct CommandThread *CT) {
				   return shim_ZN7android17AudioStreamOutANM13CommandThread8setForceEv(CT);
			}
			int setStream(struct CommandThread *CT, audio_stream_type_t a1) {
				   return shim_ZN7android17AudioStreamOutANM13CommandThread9setStreamE19audio_stream_type_t(CT, a1);
			}
			int setDevices(struct CommandThread *CT, unsigned int a1) {
				   return shim_ZN7android17AudioStreamOutANM13CommandThread10setDevicesEj(CT, a1);
			}
			int setState(struct CommandThread *CT, int newState)
			{
			  struct Command *cmd; // r0@1 MAPDST

			  cmd = (struct Command *) calloc(0x10, 1); //operator new(0x10u);
			  cmd->unk3 = 0;
			  cmd->unk4 = 0;
			  cmd->mCmdType = 1;
			  cmd->mState = newState;
			  pthread_mutex_lock(&CT->mMutex);
			  android::AudioStreamOutANM::CommandThread::insertCommand_l(CT, cmd);
			  pthread_cond_signal(&CT->mPthreadCond);
			  return pthread_mutex_unlock(&CT->mMutex);
			}
		}
	}
}

namespace android {
        namespace AudioStreamOutANM {
                int connectIfFmRadio(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM16connectIfFmRadioEv(OutANM);
                }
                int disconnectIfFmRadio(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM19disconnectIfFmRadioEv(OutANM);
                }
                int changeDevice(struct AudioStreamOutANM *OutANM, int a1, unsigned int a2, audio_stream_type_t a3, bool a4) {
                        return shim_ZN7android17AudioStreamOutANM12changeDeviceEij19audio_stream_type_tb(OutANM, a1, a2, a3, a4);
                }
                int updateState(struct AudioStreamOutANM *outANM, int newState) {
					int state; // r3@1
					int oldPriority; // r6@3

					ALOGE("%s: updateState(%d -> %d)", __func__, outANM->mState, newState);
					state = outANM->mState;
					if ( state & 8 && state != newState )
					{
						   oldPriority = getpriority(0, 0);
						   setpriority(0, 0, -19);
						   pthread_mutex_lock(&outANM->mMutex);
						   android::AudioStreamOutANM::disconnectIfFmRadio(outANM);
						   pthread_mutex_unlock(&outANM->mMutex);
						   setpriority(0, 0, oldPriority);
					}
					return android::AudioStreamOutANM::CommandThread::setState(outANM->mCommandThread, newState);
                }
                int getCurrentState(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM15getCurrentStateEv(OutANM);
                }
                int normalMode(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM10normalModeEv(OutANM);
                }
                int forceReroute(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM12forceRerouteEv(OutANM);
                }
                int setFactoryTest(struct AudioStreamOutANM *OutANM, unsigned int a1) {
                        return shim_ZN7android17AudioStreamOutANM14setFactoryTestEj(OutANM, a1);
                }
                int setStereoToMono(struct AudioStreamOutANM *OutANM, bool a1) {
                        return shim_ZN7android17AudioStreamOutANM15setStereoToMonoEb(OutANM, a1);
                }
                int setup(struct AudioStreamOutANM *OutANM, int* a1, unsigned int* a2, unsigned int* a3, unsigned int a4) {
                        return shim_ZN7android17AudioStreamOutANM5setupEPiPjS2_j(OutANM, a1, a2, a3, a4);
                }
                int sampleRate(struct AudioStreamOutANM *OutANM) {
                        return shim_ZNK7android17AudioStreamOutANM10sampleRateEv(OutANM);
                }
                int channels(struct AudioStreamOutANM *OutANM) {
                        return shim_ZNK7android17AudioStreamOutANM8channelsEv(OutANM);
                }
                int format(struct AudioStreamOutANM *OutANM) {
                        return shim_ZNK7android17AudioStreamOutANM6formatEv(OutANM);
                }
                int setVolume(struct AudioStreamOutANM *OutANM, float a1, float a2) {
                        return shim_ZN7android17AudioStreamOutANM9setVolumeEff(OutANM, a1, a2);
                }
                int getRenderPosition(struct AudioStreamOutANM *OutANM, unsigned int* a1) {
                        return shim_ZN7android17AudioStreamOutANM17getRenderPositionEPj(OutANM, a1);
                }
                int getNumParameter(struct AudioStreamOutANM *OutANM, char const* a1, unsigned int& a2) {
                        return shim_ZN7android17AudioStreamOutANM15getNumParameterEPKcRj(OutANM, a1, a2);
                }
                int getParameters(struct AudioStreamOutANM *OutANM, android::String8 const& a1) {
                        return shim_ZN7android17AudioStreamOutANM13getParametersERKNS_7String8E(OutANM, a1);
                }
                int calc_buffer_size(struct AudioStreamOutANM *OutANM) {
                        return shim_ZNK7android17AudioStreamOutANM16calc_buffer_sizeEv(OutANM);
                }
                int latency(struct AudioStreamOutANM *OutANM) {
                        return shim_ZNK7android17AudioStreamOutANM7latencyEv(OutANM);
                }
                int bufferSize(struct AudioStreamOutANM *outANM) {
                    unsigned int size = 4096; // power of two --> should meet granularity requirements easily
					unsigned int channels = popcount(outANM->mChannels);
					if (outANM->mSampleRate != 0 && channels != 0) {
						size = 32 * channels + channels* 2 * (22 * outANM->mSampleRate / 1000)-32;
					    size -= size % 32;
					}
					ALOGI("bufferSize(): %d bytes (%d, %d), %d Hz\n",
						size * NUMBER_OF_BUFFERS_PER_WRITE,
						size, NUMBER_OF_BUFFERS_PER_WRITE, outANM->mSampleRate);
					return size * NUMBER_OF_BUFFERS_PER_WRITE;
                }
                int reconnect_adm(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM13reconnect_admEv(OutANM);
                }
                int preCloseDevice(struct AudioStreamOutANM *OutANM, struct DeviceList* a1) {
                        return shim_ZN7android17AudioStreamOutANM14preCloseDeviceEPNS_10DeviceListE(OutANM, a1);
                }

                int getSpecialRouting(struct AudioStreamOutANM *OutANM, struct DeviceList* a1, struct DeviceList* a2) {
                        return shim_ZN7android17AudioStreamOutANM17getSpecialRoutingEPNS_10DeviceListES2_(OutANM, a1, a2);
                }
                int liveOrgansUpdate(struct AudioStreamOutANM *OutANM, bool a1) {
                        return shim_ZN7android17AudioStreamOutANM16liveOrgansUpdateEb(OutANM, a1);
                }
                int getChangeType(struct AudioStreamOutANM *OutANM, int a1, int a2, bool a3, bool a4, special_routing_t a5) {
                        return shim_ZN7android17AudioStreamOutANM13getChangeTypeEiibbNS0_17special_routing_tE(OutANM, a1, a2, a3, a4, a5);
                }
                int changeRefCount(struct AudioStreamOutANM *OutANM, audio_stream_type_t a1, int a2) {
                        return shim_ZN7android17AudioStreamOutANM14changeRefCountE19audio_stream_type_ti(OutANM, a1, a2);
                }
                int getHighestPriorityStream(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM24getHighestPriorityStreamEv(OutANM);
                }
                int refreshDeviceList(struct AudioStreamOutANM *OutANM, struct DeviceList* a1, int a2, unsigned int a3, audio_stream_type_t a4, struct AudioHardwareANM* a5) {
                        return shim_ZN7android17AudioStreamOutANM17refreshDeviceListEPNS_10DeviceListEij19audio_stream_type_tPNS_16AudioHardwareANME(OutANM, a1, a2, a3, a4, a5);
                }
                int updateConfiguration(struct AudioStreamOutANM *OutANM, int a1, unsigned int a2, audio_stream_type_t a3) {
                        return shim_ZN7android17AudioStreamOutANM19updateConfigurationEij19audio_stream_type_t(OutANM, a1, a2, a3);
                }
                int willChange(struct AudioStreamOutANM *OutANM, int a1, unsigned int a2, audio_stream_type_t a3, bool& a4, bool& a5, special_routing_t& a6) {
                        return shim_ZN7android17AudioStreamOutANM10willChangeEij19audio_stream_type_tRbS2_RNS0_17special_routing_tE(OutANM, a1, a2, a3, a4, a5, a6);
                }
                int getConnectionId(struct AudioStreamOutANM *OutANM, int a1) {
                        return shim_ZN7android17AudioStreamOutANM15getConnectionIdEi(OutANM, a1);
                }
                int closeDevice(struct AudioStreamOutANM *OutANM, struct DeviceList* a1) {
                        return shim_ZN7android17AudioStreamOutANM11closeDeviceEPNS_9DeviceMapE(OutANM, a1);
                }
                int closeDevices(struct AudioStreamOutANM *outANM, struct DeviceList* deviceList1) {
					struct DeviceList *deviceList = deviceList1;
			       	if (!deviceList1)
                        deviceList = outANM->mDeviceList;
					
					int deviceIdx;
					int deviceListSize;
					int rc;
					  if (!outANM->mStandby)
					  {
						android::AudioStreamOutANM::preCloseDevice(outANM, deviceList);
						while (1)
						{
						  deviceListSize = outANM->mDeviceListSize;
						  rc = android::AudioStreamOutANM::closeDevice(outANM, &deviceList[deviceIdx]);
						  ALOGE("%s: closeDevice %d / %d (%s) returned %d", __func__, deviceIdx, deviceListSize, deviceList[deviceIdx].mDeviceName, rc);

						  if (rc == -19)
						  {
							break;
						  }
						  ++deviceIdx;
						  if ( deviceIdx >= deviceListSize)
							break;
						}

						for (int i = 0; i < outANM->mDeviceListSize; i++)
						{
						  ALOGE("%s: device[%d]: %s, isVoip=%d", __func__, i, deviceList[i].mDeviceName, deviceList[i].mIsVoip);
						  if (!deviceList[i].mIsVoip)                  // ! isVoip
						  {
							munmap(outANM->mAdmBufSharedMem1, outANM->mAdmNumBufs1 * outANM->mAdmBufSize1);
							outANM->mAdmBufSharedMem1 = NULL;
							outANM->mAdmBufSize1 = 0;
							outANM->mAdmNumBufs1 = 0;
							break;
						  }
						}

						for (int i = 0; i < outANM->mDeviceListSize; i++)
						{
						  if (deviceList[i].mIsVoip)                  // isVoip
						  {
							munmap(outANM->mAdmBufSharedMem2, outANM->mAdmNumBufs2 * outANM->mAdmBufSize2);
							outANM->mAdmBufSharedMem2 = NULL;
							outANM->mAdmBufSize2 = 0;
							outANM->mAdmNumBufs2 = 0;
							break;
						  }
						  i++;
						}
						outANM->mStandby = 1;
					  }
					  return 0;
					  // return shim_ZN7android17AudioStreamOutANM12closeDevicesEPNS_10DeviceListE(outANM, deviceList1);
                }
                int standby(struct AudioStreamOutANM *outANM) {
                    ALOGE("%s: standby() called", __func__);
                    pthread_mutex_lock(&outANM->mMutex);
                    android::AudioStreamOutANM::closeDevices(outANM, 0);
                    pthread_mutex_unlock(&outANM->mMutex);
                    return 0;
                }
                int openDevice(struct AudioStreamOutANM *OutANM, android::DeviceMap* a1, bool a2) {
                        return shim_ZN7android17AudioStreamOutANM10openDeviceEPNS_9DeviceMapEb(OutANM, a1, a2);
                }
                int doTransition(struct AudioStreamOutANM *OutANM, int a1, unsigned int a2, audio_stream_type_t a3, change_type_t a4) {
                        return shim_ZN7android17AudioStreamOutANM12doTransitionEij19audio_stream_type_tNS0_13change_type_tE(OutANM, a1, a2, a3, a4);
                }
                int openDevices(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM11openDevicesEv(OutANM);
                }
                int restore(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM7restoreEv(OutANM);
                }
				int MIN(int a, int b) {
					return (a < b) ? a : b;
				}
				
                int doWrite(struct AudioStreamOutANM *outANM, void const* buffer, unsigned int bytes, int offset) {
				  //ALOGE("%s: offset=%d", __func__, offset);
				  int v6; // r11@1
				  unsigned int result; // r0@2
				  size_t chunkSize; // r7@5
				  void *v9; // r5@7
				  int rc1; // r0@7
				  int v11; // r3@8
				  int v12; // r1@8
				  const char *v13; // r2@8
				  void *v14; // r1@9
				  int rc2; // r10@9
				  unsigned int consumedBytes; // r8@15
				  void *admBufSharedMem; // [sp+Ch] [bp-34h]@16
				  int v20; // [sp+14h] [bp-2Ch]@7
				  
				  int admBufSize;
				  int *admCurBufIdxPtr;
				  int admCurBufIdx;
				  int ADMConnectionID;
				  int admNumBufs;
				  int mCurBufOffset = 0;
				  
				   int err;
				  unsigned int consumed_bytes = 0;
				  
				  if (!offset) {
						admBufSize = outANM->mAdmBufSize1;
						admBufSharedMem = outANM->mAdmBufSharedMem1;
						admCurBufIdxPtr = &outANM->mCurBufIdx1;
						ADMConnectionID = outANM->mADMConnectionID1;
						admNumBufs = outANM->mAdmNumBufs1;
				  } else {
						admBufSize = outANM->mAdmBufSize2;
						admBufSharedMem = outANM->mAdmBufSharedMem2;
						admCurBufIdxPtr = &outANM->mCurBufIdx2;
						ADMConnectionID = outANM->mADMConnectionID2;
						admNumBufs = outANM->mAdmNumBufs2;
				  }
				  
					if (bytes == 0 || bytes > (size_t) admBufSize) {
						ALOGE("write(): Requested to write invalid amount of bytes! (%d, mAdmBufSize=%d)", bytes, admBufSize);
						return BAD_VALUE;
					}

					if (admBufSharedMem == NULL) {
						ALOGE("write(): AudioStreamOutANM::write - output buffer not yet allocated");
						return INVALID_OPERATION;
					}

				      while (consumed_bytes < bytes) {
							int fillLength = admBufSize;

							unsigned int transfer_bytes = MIN(MIN(fillLength, admBufSize - mCurBufOffset), bytes - consumed_bytes);

							ALOGV("write(): Copy %d bytes to buffer (%d) 0x%08X at offset %d",
										transfer_bytes, *admCurBufIdxPtr, (uint32_t) admBufSharedMem + (*admCurBufIdxPtr)*admBufSize, mCurBufOffset);
							memcpy(admBufSharedMem + (*admCurBufIdxPtr)*admBufSize + mCurBufOffset,
								   ((const char*) buffer) + consumed_bytes,
								   transfer_bytes);
							mCurBufOffset += transfer_bytes;

							if (mCurBufOffset >= fillLength) {
								int newLpaMode = 0;
								err = ste_adm_client_send(ADMConnectionID, (*admCurBufIdxPtr), mCurBufOffset, &newLpaMode);
								ALOGV("write(): Sent %d bytes to ADM", mCurBufOffset);

								*admCurBufIdxPtr = (*admCurBufIdxPtr + 1) % admNumBufs;
								mCurBufOffset = 0;

								if (err != OK) {
									ALOGE("write(): Failed to send audio data to ADM: %d", err);
									return FAILED_TRANSACTION;
								}
							}
							consumed_bytes += transfer_bytes;
						}
						
					ALOGV("write(): Completed\n");

					return bytes;
                }
                int write(struct AudioStreamOutANM *outANM, const void *buf, unsigned int bytes) {
				  int rc; // r3@1
				  unsigned int ret; // r8@2
				  int v9; // r1@5
				  char *v10; // r8@6
				  unsigned int i; // r3@9
				  int v12; // r1@10
				  unsigned int v13; // lr@10
				  int j; // r3@12
				  int deviceIdx; // r2@18
				  DeviceList *deviceList; // r1@18

				  pthread_mutex_lock(&outANM->mMutex);
				  rc = android::AudioStreamOutANM::openDevices(outANM);
				  if (rc)
				  {
					ret = 0;
					ALOGI("%s: write: openDevices failed: %d", __func__, rc);
				  }
				  else if ( bytes )
				  {
					/*v9 = 0;
					while ( rc < outANM->mDeviceListSize )
					{
					  v10 = &outANM->mDeviceList[rc++];
					  v9 |= *(v10 + 2);
					}
					android::HalAudioProcessing::processOutput(&outANM->mANM->unk_idx1, v9, buf, bytes);
					if ( outANM->unk671 )
					{
					  for ( i = 0; i < bytes >> 2; i = (i + 1) )
					  {
						v12 = 4 * i + 2;
						v13 = *(buf + 2 * i) + *(buf + v12);
						*(buf + v12) = v13 >> 1;
						*(buf + 2 * i) = v13 >> 1;
					  }
					}*/
					bool hasVoipDev = true;
					for ( j = 0; ; ++j )
					{
					  if ( j >= outANM->mDeviceListSize )
					  {
						ret = bytes;
						hasVoipDev = false;
						break;
					  }
					  if ( outANM->mDeviceList[j].mIsVoip )
						break;
					}
					if (hasVoipDev)
						ret = android::AudioStreamOutANM::doWrite(outANM, buf, bytes, 1);

					deviceIdx = 0;
					deviceList = outANM->mDeviceList;
					while ( deviceIdx < outANM->mDeviceListSize )
					{
					  if ( !deviceList[deviceIdx].mIsVoip )
					  {
						// ALOGE("%s: %s offset = %d", __func__, deviceList[deviceIdx].mDeviceName, deviceList[deviceIdx].mIsVoip);
						ret = android::AudioStreamOutANM::doWrite(outANM, buf, bytes, deviceList[deviceIdx].mIsVoip);
						break;
					  }
					  ++deviceIdx;
					}
				  }
				  else
				  {
					ret = -22;
					ALOGI("%s: Requested to write 0 bytes!", __func__);
				  }
				  pthread_mutex_unlock(&outANM->mMutex);
				  return ret;
                }
                int AudioStreamOutANM(struct AudioStreamOutANM *OutANM, struct AudioHardwareANM* a1) {
                        return shim_ZN7android17AudioStreamOutANMC2EPNS_16AudioHardwareANME(OutANM, a1);
                }
 
                int dump(struct AudioStreamOutANM *OutANM, int a1, Vector<String16> const& a2) {
                        return shim_ZN7android17AudioStreamOutANM4dumpEiRKNS_6VectorINS_8String16EEE(OutANM, a1, a2);
                }

                int doUpdateForce(struct AudioStreamOutANM *OutANM) {
                        return shim_ZN7android17AudioStreamOutANM13doUpdateForceEv(OutANM);
                }

                int doUpdateStream(struct AudioStreamOutANM *OutANM, audio_stream_type_t a1) {
                        return shim_ZN7android17AudioStreamOutANM14doUpdateStreamE19audio_stream_type_t(OutANM, a1);
                }

                int setParameters(struct AudioStreamOutANM *OutANM, String8 const& a1) {
                        return shim_ZN7android17AudioStreamOutANM13setParametersERKNS_7String8E(OutANM, a1);
                }

                int doUpdateState(struct AudioStreamOutANM *OutANM, int a1) {
                        return shim_ZN7android17AudioStreamOutANM13doUpdateStateEi(OutANM, a1);
                }
        }
}


namespace android {
	namespace AudioStreamInANM {
		int isFake(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM6isFakeEv(inANM);
		}
		int isActive(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM8isActiveEv(inANM);
		}
		int suspend(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM7suspendEv(inANM);
		}
		int resume(struct AudioStreamInANM *inANM, int a1) {
			return shim_ZN7android16AudioStreamInANM6resumeEi(inANM, a1);
		}
		int suspendIfDeviceIsWrong(struct AudioStreamInANM *inANM, unsigned int a1) {
			return shim_ZN7android16AudioStreamInANM22suspendIfDeviceIsWrongEj(inANM, a1);
		}
		int getDevicePerState(struct AudioStreamInANM *inANM, int a1, unsigned int a2, struct AudioHardwareANM* a3) {
			return shim_ZN7android16AudioStreamInANM17getDevicePerStateEijPNS_16AudioHardwareANME(inANM, a1, a2, a3);
		}
		int setMute(struct AudioStreamInANM *inANM, bool a1) {
			return shim_ZN7android16AudioStreamInANM7setMuteEb(inANM, a1);
		}
		int unfake(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM6unfakeEv(inANM);
		}
		int setup(struct AudioStreamInANM *inANM, int* a1, unsigned int* a2, unsigned int* a3, unsigned int a4) {
			return shim_ZN7android16AudioStreamInANM5setupEPiPjS2_j(inANM, a1, a2, a3, a4);
		}
		int updateState(struct AudioStreamInANM *inANM, int a1) {
			return shim_ZN7android16AudioStreamInANM11updateStateEi(inANM, a1);
		}
		int fake(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM4fakeEv(inANM);
		}
		int sampleRate(struct AudioStreamInANM *inANM) {
			return shim_ZNK7android16AudioStreamInANM10sampleRateEv(inANM);
		}
		int calc_buffer_size(struct AudioStreamInANM *inANM) {
			return shim_ZNK7android16AudioStreamInANM16calc_buffer_sizeEv(inANM);
		}
		int channels(struct AudioStreamInANM *inANM) {
			return shim_ZNK7android16AudioStreamInANM8channelsEv(inANM);
		}
		int format(struct AudioStreamInANM *inANM) {
			return shim_ZNK7android16AudioStreamInANM6formatEv(inANM);
		}
		int getInputFramesLost(struct AudioStreamInANM *inANM) {
			return 0;
		}
		int setGain(struct AudioStreamInANM *inANM, float a1) {
			return NO_ERROR;
		}
		int bufferSize(struct AudioStreamInANM *inANM) {
			return shim_ZNK7android16AudioStreamInANM10bufferSizeEv(inANM);
		}
		int dump(struct AudioStreamInANM *inANM, int a1, Vector<String16> const& a2) {
			return NO_ERROR;
		}
		int doSetMute(struct AudioStreamInANM *inANM, bool a1) {
			return shim_ZN7android16AudioStreamInANM9doSetMuteEb(inANM, a1);
		}
		int AudioStreamInANM(struct AudioStreamInANM *inANM, struct AudioHardwareANM* a1) {
			return shim_ZN7android16AudioStreamInANMC2EPNS_16AudioHardwareANME(inANM, a1);
		}
		int getNumParameter(struct AudioStreamInANM *inANM, char const* a1, unsigned int& a2) {
			return shim_ZN7android16AudioStreamInANM15getNumParameterEPKcRj(inANM, a1, a2);
		}
		char *getParameters(struct AudioStreamInANM *inANM, String8 const& a1) {
			return shim_ZN7android16AudioStreamInANM13getParametersERKNS_7String8E(inANM, a1);
		}
		int reconnect_adm(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM13reconnect_admEv(inANM);
		}
		int postOpenDevice(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM14postOpenDeviceEv(inANM);
		}
		int openDevices(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM11openDevicesEv(inANM);
		}
		int transitionAffectsCSCall(struct AudioStreamInANM *inANM, int a1, int a2) {
			return shim_ZN7android16AudioStreamInANM23transitionAffectsCSCallEii(inANM, a1, a2);
		}
		int liveOrgansUpdate(struct AudioStreamInANM *inANM, bool a1) {
			return shim_ZN7android16AudioStreamInANM16liveOrgansUpdateEb(inANM, a1);
		}
		int closeDevices(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM12closeDevicesEv(inANM);
		}
		int standby(struct AudioStreamInANM *inANM) {
			ALOGI("%s: [%d] standby() called", __func__, inANM->mInputIdx);
			pthread_mutex_lock(&inANM->mMutex);
			android::AudioStreamInANM::closeDevices(inANM);
			pthread_mutex_unlock(&inANM->mMutex);
			
			return NO_ERROR;
		}
		int restore(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM7restoreEv(inANM);
		}
		
		unsigned int doRead(struct AudioStreamInANM *inANM, void *buffer, size_t chunkSize)
		{
		  signed int retryAttempts; // r7@1
		  int rc; // r0@2 MAPDST
		  int inputSource; // r3@7
		  int v9; // r1@7
		  int unk26; // r10@14
		  int format; // r9@15
		  signed int formatDivider; // r1@16
		  int admBufSize; // ST18_4@18
		  int channels; // r11@18
		  int v15; // ST1C_4@18
		  signed int channelsCount; // r0@18
		  int sampleRate; // ST20_4@18
		  unsigned int v18; // r0@18
		  int inputSource1; // r2@18
		  int v20; // r1@18
		  void *dest; // [sp+24h] [bp-3Ch]@1
		  int buf_idx; // [sp+34h] [bp-2Ch]@2

		  retryAttempts = 3;
		  dest = buffer;
		  while ( 1 )
		  {
			while ( 1 )
			{
			  inANM->mReadInProgress = 1;
			  buf_idx = 0;
			  rc = ste_adm_client_receive(inANM->mADMConnectionID, &buf_idx);
			  inANM->mReadInProgress = 0;
			  android::AudioHardwareANM::handleError(inANM->mANM, rc, 2);
			  if ( rc != -9 )
				break;
			  --retryAttempts;
			  if ( android::AudioStreamInANM::restore(inANM) )
				return 0x80000002;
			  ALOGE("%s: Reconnected to ADM server", __func__);
			  if ( !retryAttempts )
				return chunkSize;
			}
			if ( rc )
			  break;
			memcpy(dest, (inANM->mAdmBufSharedMem + buf_idx * inANM->mAdmBufSize), chunkSize);
			if ( inANM->unk26 < 0 )
			{
			  inANM->unk26 = 250;
			  inputSource = inANM->mInputSource;
			  v9 = inputSource - 6 + ((inputSource - 6) <= 0) - (inputSource - 6); // ???
			  if ( inputSource == 10 )
				v9 |= 1u;
			  if ( (v9 || inputSource == 1) && inANM->mDevicesList == 0x100000 && !inANM->mState )
				inANM->unk26 = 0;
			}
			unk26 = inANM->unk26;
			if ( unk26 > 249 )
			  return chunkSize;
			format = inANM->mFormat;
			if ( format == 1 )
			  formatDivider = 2;
			else
			  formatDivider = 1;
			admBufSize = inANM->mAdmBufSize;
			channels = inANM->mChannels;
			v15 = inANM->mAdmBufSize / formatDivider;
			channelsCount = popcount(inANM->mChannels);
			sampleRate = inANM->mSampleRate;
			v18 = 1000 * (v15 / channelsCount) / sampleRate;
			inANM->unk26 = unk26 + v18;
			ALOGI(
			  "%s: micbias: %d %d (f:%d ch:0x%x bs:%d sr:%d)",
			  __func__,
			  v18,
			  unk26 + v18,
			  format,
			  channels,
			  admBufSize,
			  sampleRate);
			inputSource1 = inANM->mInputSource;
			v20 = inputSource1 - 6 + ((inputSource1 - 6) <= 0) - (inputSource1 - 6); // ???
			if ( inputSource1 == 10 )
			  v20 |= 1u;
			if ( !v20 )
			{
			  memset(dest, 0, chunkSize);
			  return chunkSize;
			}
		  }
		  ALOGE("%s: Failed to receive audio data from ADM: %d", __func__, rc);
		  return 0x80000002;
		}

		size_t read(struct AudioStreamInANM *inANM, void *buffer, size_t bytes) {
		  size_t chunkSize; // r9@9
		  size_t readBytesCount; // r0@11 MAPDST
		  size_t i; // r6@17
		  int inputSource; // r0@21
		  int v12; // r3@22
		  unsigned int channelsCount; // r0@25

		  pthread_mutex_lock(&inANM->mMutex);
		  if (android::AudioStreamInANM::openDevices(inANM))
		  {
			bytes = 0;
			ALOGE("%s: read: openDevices failed", __func__);
		  }
		  else if ( inANM->mDeviceListSize )
		  {
			if ( bytes )
			{
			  if ( inANM->mAdmBufSharedMem )
			  {
				for ( i = 0; i < bytes; i += readBytesCount )
				{
				  chunkSize = bytes - i;
				  if ( bytes - i >= inANM->mAdmBufSize )
					chunkSize = inANM->mAdmBufSize;
				  readBytesCount = android::AudioStreamInANM::doRead(inANM, buffer + i, chunkSize);
				  if ( readBytesCount <= 0 )
				  {
					bytes = readBytesCount;
					ALOGE("%s: read failed: %ld", __func__, readBytesCount);
					goto out;
				  }
				  if ( readBytesCount > chunkSize )
				  {
					bytes = 0x80000000;
					ALOGE("%s: read too much: %ld", __func__, readBytesCount);
					goto out;
				  }
				  if ( readBytesCount != chunkSize )
					ALOGE(
					  "%s: read wrong amount of bytes %ld != %ld",
					  __func__,
					  readBytesCount,
					  chunkSize);
				}
				if ( !inANM->mState )
				{
				  inputSource = inANM->mInputSource;
				  if ( inputSource <= 1 )
					v12 = (inputSource - 5 + ((inputSource - 5) <= 0) - (inputSource - 5)) | 1;
				  else
					v12 = inputSource - 5 + ((inputSource - 5) <= 0) - (inputSource - 5);
				  if ( v12 )
				  {
					channelsCount = popcount(inANM->mChannels);
					/*android::HalAudioProcessing::processInput(
					  &inANM->mANM->unk_idx1,
					  inANM->mSampleRate,
					  channelsCount,
					  buffer,
					  i);*/
				  }
				}
				bytes = i;
			  }
			  else
			  {
				bytes = -38;
				ALOGE("%s: read - input buffer not yet allocated", __func__);
			  }
			}
			else
			{
			  ALOGE("%s: Requested to read invalid amount of bytes! bytes=0 mAdmBufSize=%d", __func__, inANM->mAdmBufSize);
			  bytes = -22;
			}
		  }
		  else
		  {
			ALOGE("%s: [%d] Empty device list, nothing to read", __func__, inANM->mInputIdx);
			memset(buffer, 0, bytes);
		  }
		out:
		  pthread_mutex_unlock(&inANM->mMutex);
		  return bytes;
		}

		int refreshDeviceList(struct AudioStreamInANM *inANM, DeviceList* a1, int a2, unsigned int a3, int a4, struct AudioHardwareANM* a5) {
			return shim_ZN7android16AudioStreamInANM17refreshDeviceListEPNS_10DeviceListEijiPNS_16AudioHardwareANME(inANM, a1, a2, a3, a4, a5);
		}
		int updateDeviceList(struct AudioStreamInANM *inANM, bool a1, bool a2) {
			return shim_ZN7android16AudioStreamInANM16updateDeviceListEbb(inANM, a1, a2);
		}
		int willChange(struct AudioStreamInANM *inANM, int a1, unsigned int a2, int a3, bool& a4, bool& a5) {
			return shim_ZN7android16AudioStreamInANM10willChangeEijiRbS1_(inANM, a1, a2, a3, a4, a5);
		}
		int changeDevice_l(struct AudioStreamInANM *inANM, int a1, unsigned int a2, int a3, bool a4) {
			return shim_ZN7android16AudioStreamInANM14changeDevice_lEijib(inANM, a1, a2, a3, a4);
		}
		int changeDeviceForce(struct AudioStreamInANM *inANM) {
			return shim_ZN7android16AudioStreamInANM17changeDeviceForceEv(inANM);
		}
		int changeDeviceRoutesAndInputSource(struct AudioStreamInANM *inANM, unsigned int a1, int a2, bool a3) {
			return shim_ZN7android16AudioStreamInANM32changeDeviceRoutesAndInputSourceEjib(inANM, a1, a2, a3);
		}
		int setParameters(struct AudioStreamInANM *inANM, android::String8 const& a1) {
			return shim_ZN7android16AudioStreamInANM13setParametersERKNS_7String8E(inANM, a1);
		}
		int changeDeviceState(struct AudioStreamInANM *inANM, int a1) {
			return shim_ZN7android16AudioStreamInANM17changeDeviceStateEi(inANM, a1);
		}
	}
}

extern struct AudioHardwareANM *gANM;
extern SortedVector<struct AudioStreamInANM*> *gInputs;
extern SortedVector<struct AudioStreamOutANM*> *gOutputs;

namespace android {
	namespace AudioHardwareANM {
		int getMicMute(struct AudioHardwareANM *ANM, bool *state) {
			*state = gANM->mIsMicMuted;
			return 0;
		}
		int setMasterVolume(struct AudioHardwareANM *ANM, float volume) {
			return -ENOSYS;
		}

		int getInputBufferSize(struct AudioHardwareANM *ANM, unsigned int sampleRate, audio_format_t format, int channelsCount) {
			size_t bufferSize = (40 * channelsCount * sampleRate) / 1000;
			ALOGE("%s: channels count: %d, format: %d, sampleRate: %d, size=%d", __func__, channelsCount, format, sampleRate, bufferSize);

			return bufferSize;
		}

		int initCheck(struct AudioHardwareANM *ANM) {
			int outSz = gOutputs->size();
			int inSz = gInputs->size();
			if (outSz > 0 || inSz > 0) {
				ALOGI("%s: Already initialized! out=%d, in=%d", __func__, outSz, inSz);
				//return NO_ERROR;
			} else {
				ALOGI("%s: out=%d, in=%d", __func__, outSz, inSz);
			}

			ALOGV("%s: OK", __func__);
			return NO_ERROR;
		}
		void handleError(struct AudioHardwareANM *ANM, int a1, android::adm_api_type_t a2) {
			shim_ZN7android16AudioHardwareANM11handleErrorEiNS_14adm_api_type_tE(gANM, a1, a2);
		}
		int setVoiceVolume(struct AudioHardwareANM *ANM, float volume) {
			volume *= 8;

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
			shim_ZN7android16AudioHardwareANM9makeParamEPKcj(gANM, a1, a2);
		}
		void hasValidInputs(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM14hasValidInputsEv(gANM);
		}
		void getActiveInput(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM14getActiveInputEv(gANM);
		}
		void singleInput(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM11singleInputEv(gANM);
		}
		void dumpErrorHistoryItem(struct AudioHardwareANM *ANM, android::String8& a1, android::ApiHistoryItem* a2) {
			shim_ZN7android16AudioHardwareANM20dumpErrorHistoryItemERNS_7String8EPNS_14ApiHistoryItemE(gANM, a1, a2);
		}
		void dumpErrorHistory(struct AudioHardwareANM *ANM, android::String8& a1) {
			shim_ZN7android16AudioHardwareANM16dumpErrorHistoryERNS_7String8E(gANM, a1);
		}
		void getMode(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM7getModeEv(gANM);
		}
		void predictInputDevice(struct AudioHardwareANM *ANM, unsigned int a1) {
			shim_ZN7android16AudioHardwareANM18predictInputDeviceEj(gANM, a1);
		}
		void updateDevice(struct AudioHardwareANM *ANM, bool a1, android::DeviceMap* a2, int a3) {
			shim_ZN7android16AudioHardwareANM12updateDeviceEbPNS_9DeviceMapEi(gANM, a1, a2, a3);
		}
		void getCSCallConnectionId(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM21getCSCallConnectionIdEv(gANM);
		}
		void disconnectCSCall(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM16disconnectCSCallEv(gANM);
		}
		void suspendInputs(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM13suspendInputsEv(gANM);
		}
		void resumeInputs(struct AudioHardwareANM *ANM, int a1) {
			shim_ZN7android16AudioHardwareANM12resumeInputsEi(gANM, a1);
		}
		void suspendInputIfDeviceIsWrong(struct AudioHardwareANM *ANM, unsigned int a1) {
			shim_ZN7android16AudioHardwareANM27suspendInputIfDeviceIsWrongEj(gANM, a1);
		}
		void doRoutingChange(struct AudioHardwareANM *ANM, android::RoutingInfo* a1) {
			shim_ZN7android16AudioHardwareANM15doRoutingChangeEPNS_11RoutingInfoE(gANM, a1);
		}
		void isNRisSupportedInBT(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM19isNRisSupportedInBTEv(gANM);
		}
		void isVideoCall(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM11isVideoCallEv(gANM);
		}
		void isExtraVolume(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM13isExtraVolumeEv(gANM);
		}
		void isHACMode(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM9isHACModeEv(gANM);
		}
		void getCurrentCallOutput(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM20getCurrentCallOutputEv(gANM);
		}
		void getCurrentCallInput(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM19getCurrentCallInputEv(gANM);
		}
		int getActiveState(struct AudioHardwareANM *ANM, int csCallState) {
			  if ( csCallState & 1 )
			  {
				return 1;
			  }
			  else if ( csCallState & 2 )
			  {
				return 2;
			  }
			  else if ( (csCallState & 0x5E) == 8 )
			  {
				return 8;
			  }
			return 0;
		}
		void lock(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM4lockEv(gANM);
		}
		void unlock(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM6unlockEv(gANM);
		}
		int setMicMute(struct AudioHardwareANM *ANM, bool state) {
			char *sState; // r3@2
			int upstreamVolume; // r7@4
			int rc; // r7@6
			unsigned int result; // r0@7

			if ( state )
				sState = "true";
			else
				sState = "false";
			upstreamVolume = UNKNOWN_ERROR;
			ALOGI("setMicMute(%s)", sState);
			if (!state)
				upstreamVolume = gANM->mUpstreamVolume;
			ALOGI("adm_api: ste_adm_client_set_cscall_upstream_volume(%d)", upstreamVolume);
			rc = ste_adm_client_set_cscall_upstream_volume(upstreamVolume);
			android::AudioHardwareANM::handleError(gANM, rc, 6);
			if ( rc )
			{
				ALOGE("setMicMute() - ste_adm_client_set_cscall_upstream_volume() failed");
				return UNKNOWN_ERROR;
			}
			else
			{
				android::AudioHardwareANM::lock(gANM);
				int idx = 0;
				ALOGE("%s: gInputs->size() = %d", __func__, gInputs->size());
				/*while ( idx < gInputs->size() )
				{
					struct AudioStreamInANM *inANM = gInputs->itemAt(idx);
					android::AudioStreamInANM1::setMute(inANM, state);
					idx++;
				}*/
				gANM->mIsMicMuted = state;
				android::AudioHardwareANM::unlock(gANM);
				result = 0;
			}
			return result;
		}
		void setRxMute(struct AudioHardwareANM *ANM, bool mute) {
			 int rc; // r1@3
			  int volume; // r1@4 MAPDST

			  if ( mute != ANM->mRxMuted )
			  {
				ANM->mRxMuted = mute;
				ALOGV("setRxMute(%d)", mute);
				if ( ANM->mRxMuted )
				{
				 ALOGI("adm_api: ste_adm_client_set_cscall_downstream_volume(%d) rx_mute",
					0x80000000);
				  rc = ste_adm_client_set_cscall_downstream_volume(0x80000000);
				  android::AudioHardwareANM::handleError(ANM, rc, 5);
				}
				else
				{
				  android::AudioHardwareANM::setVoiceVolume(ANM, ANM->mVoiceVolumeLevel);
				}
			  }
		}
		void setRingbackMute(struct AudioHardwareANM *ANM, bool mute) {
			  ANM->mMuted = mute;
			  bool rxMute = true;
			  if ( !ANM->mMuted )
				rxMute = (ANM->csCallState >> 6) & 1;
			  return android::AudioHardwareANM::setRxMute(ANM, rxMute);
		}
		void onRingback(struct AudioHardwareANM *ANM, bool a1) {
			shim_ZN7android16AudioHardwareANM10onRingbackEb(gANM, a1);
		}
		void doUpdateState(struct AudioHardwareANM *ANM, int csCallState1, bool force)
		{
		  int newActiveState; // r8@1
		  signed int currActiveState; // r0@1
		  int v9; // r0@7
		  int i;
		 
		  ALOGI("%s: updateState 0x%x -> 0x%x", __func__, ANM->csCallState, csCallState1);
		  newActiveState = android::AudioHardwareANM::getActiveState(ANM, csCallState1);
		  currActiveState = android::AudioHardwareANM::getActiveState(ANM, ANM->csCallState);
		  ANM->csCallState = csCallState1;
		  if ( newActiveState != currActiveState || force )
		  {
			if ( currActiveState & 1 && newActiveState & 2 )
			{
			  v9 = 1;
			}
			else if ( newActiveState & 1 )
			{
			  v9 = (currActiveState >> 1) & 1;
			}
			else
			{
			  v9 = newActiveState & 1;
			}
			if ( force | v9 )
			{
			  i = 0;
			  while ( i < gOutANMs->size() )
			  {
				android::AudioStreamOutANM::updateState(gOutANMs->itemAt(i), 0);
				i++;
			  }
			}
			i = 0;
			while ( i < gOutANMs->size() )
			{
			  android::AudioStreamOutANM::updateState(gOutANMs->itemAt(i), newActiveState);
			  i++;
			}
			ALOGV("updateState end");
		  }
		  else
		  {
			ALOGI("active state is the same: %d", newActiveState);
		  }
		}
		void updateState(struct AudioHardwareANM *ANM, int state)
		{
		  if ( ANM->csCallState != state )
		  {
			android::AudioHardwareANM::lock(ANM);
			android::AudioHardwareANM::doUpdateState(ANM, state, false);
			android::AudioHardwareANM::unlock(ANM);
		  }
		}
		void stopVoIP(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM8stopVoIPEv(gANM);
		}
		void startVoIP(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM9startVoIPEv(gANM);
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
			shim_ZN7android16AudioHardwareANM15unmuteAllSoundsEv(gANM);
		}
		void muteAllSounds(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM13muteAllSoundsEv(gANM);
		}
		void unmuteFmRadio(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM13unmuteFmRadioEv(gANM);
		}
		void muteFmRadio(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM11muteFmRadioEv(gANM);
		}
		void closeInputStream(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamIn* a1) {
			shim_ZN7android16AudioHardwareANM16closeInputStreamEPNS_13AudioStreamInE(gANM, a1);
		}
		void stopFmRadio(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM11stopFmRadioEv(gANM);
		}
		void startFmRadio(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM12startFmRadioEv(gANM);
		}
		int getOutputState(struct AudioHardwareANM *ANM) {
			return shim_ZN7android16AudioHardwareANM14getOutputStateEv(gANM);
		}

		struct AudioStreamInANM* openInputStream(struct AudioHardwareANM *ANM, int devices, audio_config *config, int *status) {
			return shim_ZN7android16AudioHardwareANM15openInputStreamE15audio_devices_tP12audio_configPi(gANM, devices, config, status);
		}
		void notifyOutputAboutNormalMode(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM27notifyOutputAboutNormalModeEv(gANM);
		}
		void forceReroute(struct AudioHardwareANM *ANM) {
			shim_ZN7android16AudioHardwareANM12forceRerouteEv(gANM);
		}
		int setMode(struct AudioHardwareANM *ANM, int mode) {
			ALOGI("setMode(%d)", mode);
			ALOGE("%s: mIsMono: %d, mFormat: %d, mTtyMode: %d, mChannelMask: %d", __func__, gANM->mIsMono, gANM->mFormat, gANM->mTtyMode, gANM->mChannelMask);
			android::AudioHardwareBase1::setMode(gANM, mode);
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
			shim_ZN7android16AudioHardwareANM19setIfVoIPprocessingEbi(gANM, a1, a2);
		}
		void doRoutingEnd(struct AudioHardwareANM *ANM, android::RoutingInfo* a1) {
			shim_ZN7android16AudioHardwareANM12doRoutingEndEPNS_11RoutingInfoE(gANM, a1);
		}
		void doRoutingStart(struct AudioHardwareANM *ANM, android::RoutingInfo* a1) {
			shim_ZN7android16AudioHardwareANM14doRoutingStartEPNS_11RoutingInfoE(gANM, a1);
		}
		void childNotify(struct AudioHardwareANM *ANM, bool a1, android::notification_type_t a2, void const* a3) {
			shim_ZN7android16AudioHardwareANM11childNotifyEbNS_19notification_type_tEPKv(gANM, a1, a2, a3);
		}
		void dump(struct AudioHardwareANM *ANM, int a1, android::Vector<android::String16> const& a2) {
			shim_ZN7android16AudioHardwareANM4dumpEiRKNS_6VectorINS_8String16EEE(gANM, a1, a2);
		}
		void askChild(struct AudioHardwareANM *ANM, char const* a1, bool a2) {
			shim_ZN7android16AudioHardwareANM8askChildEPKcb(gANM, a1, a2);
		}
		void getNumParameter(struct AudioHardwareANM *ANM, char const* a1, unsigned int& a2) {
			shim_ZN7android16AudioHardwareANM15getNumParameterEPKcRj(gANM, a1, a2);
		}
		char *getParameters(struct AudioHardwareANM *ANM, android::String8 const& a1) {
			return shim_ZN7android16AudioHardwareANM13getParametersERKNS_7String8E(gANM, a1);
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
			
			//android::String8::String8(&s1, &unk_12858);
			//android::String8::String8(&v75, &unk_12858);
			
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

			return NO_ERROR;
		}
		void closeOutputStream(struct AudioHardwareANM *ANM, android_audio_legacy::AudioStreamOut* a1) {
			shim_ZN7android16AudioHardwareANM17closeOutputStreamEPNS_14AudioStreamOutE(gANM, a1);
		}
		void openOutputStream(struct AudioHardwareANM *ANM, audio_devices_t a1, audio_output_flags_t a2, audio_config* a3, int* a4) {
			shim_ZN7android16AudioHardwareANM16openOutputStreamE15audio_devices_t20audio_output_flags_tP12audio_configPi(ANM, a1, a2, a3, a4);
		}
	}
}