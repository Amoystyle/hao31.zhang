/*
+ fpi_error_code.h
*/

#ifndef __FPI_ERROR_CODE_H__
#define __FPI_ERROR_CODE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "fpi_base_type.h"

/* define dcpm error type */
typedef int32_t fpi_error;
	
#define fpi_error_code(error_module, error_code)	\
	(((error_module << 16) & 0xffff0000) | (error_code & 0x0000ffff))

/* define error module */
#define FPI_ERROR_SUCCESS								0x0000
#define FPI_ERROR_FAIL									0x0001
#define FPI_ERROR_UNSUPPORT								0x0002
#define FPI_ERROR_PARAMETER_ERROR						0x0003
#define FPI_ERROR_NOT_IMPLEMENT							0x0004


#if 0
#define FPI_ERROR_MODULE_COMMON                         0x0001
#define FPI_ERROR_MODULE_GRAPHICS						0x0002
    #define FPI_ERROR_MODULE_BASIC_IO						0x0003
#define FPI_ERROR_MODULE_CI                             0x0004 
    #define FPI_ERROR_MODULE_INIT							0x0005
#define FPI_ERROR_MODULE_LINEIN                         0x0006
#define FPI_ERROR_MODULE_PLAYBACK                       0x0007
#define FPI_ERROR_MODULE_VIDEO                          0x0008
#define FPI_ERROR_MODULE_AUDIO                          0x0009
#define FPI_ERROR_MODULE_SIGNAL                         0x000a
#define FPI_ERROR_MODULE_ZOOM                           0x000b
#define FPI_ERROR_MODULE_DVBC_CHANNEL_SEARCH            0x000c
#define FPI_ERROR_MODULE_DVBC_PSI                       0x000d
#define FPI_ERROR_MODULE_DVBC_EPG                       0x000e
#define FPI_ERROR_MODULE_ANALOG_SEARCH                  0x000f
#define FPI_ERROR_MODULE_EEPROM                         0x0010
#define FPI_ERROR_MODULE_PROXY							0x0011
#define FPI_ERROR_MODULE_MEDIA							0x0012
#define FPI_ERROR_MODULE_SCART							0x0013
#define FPI_ERROR_MODULE_MHEG                           0x0014
#define FPI_ERROR_MODULE_BOOKING                        0x0015
#define FPI_ERROR_MODULE_PVR                            0x0016
#define FPI_ERROR_MODULE_IIC                            0x0017
#define FPI_ERROR_MODULE_FACTORY                        0x0018
#define FPI_ERROR_MODULE_POWER                          0x0019
#define FPI_ERROR_MODULE_CEC                            0x001a
#define FPI_ERROR_MODULE_CHANNEL                        0x001b  //add by lwf 2013.12.23
#define FPI_ERROR_MODULE_3D                             0x001c  //add by lwf 2014.01,09
#endif




/*
--------gpio module error code-----------------------------------------------------------
*/
#define FPI_ERROR_GPIO_SUCCESS                  FPI_ERROR_SUCCESS
#define FPI_ERROR_GPIO_FAIL                     FPI_ERROR_FAIL     
#define FPI_ERROR_GPIO_ALREADY_INIT             fpi_error_code(SITA_MODULE_BASE_IO,  0x0001)
#define FPI_ERROR_GPIO_NOT_INIT                 fpi_error_code(SITA_MODULE_BASE_IO,  0x0002)
#define FPI_ERROR_GPIO_INVALID_PARAM            fpi_error_code(SITA_MODULE_BASE_IO,  0x0003)


/*
--------channel search module error code-------------------------------------------------
*/
#define FPI_ERROR_CHANNEL_SEARCH_SUCCESS			FPI_ERROR_SUCCESS
#define FPI_ERROR_CHANNEL_SEARCH_FAIL			    FPI_ERROR_FAIL
#define FPI_ERROR_CHANNEL_SEARCH_INVALID_PARAMETER	    fpi_error_code(SITA_MODULE_CHANNEL_SCAN,		0x0001)
#define FPI_ERROR_CHANNEL_SEARCH_NOT_SUPPORT	        fpi_error_code(SITA_MODULE_CHANNEL_SCAN,		0x0002)
#define FPI_ERROR_CHANNEL_SEARCH_UPDATE	                fpi_error_code(SITA_MODULE_CHANNEL_SCAN,		0x0003)
#define FPI_ERROR_CHANNEL_SEARCH_UNKNOW		            fpi_error_code(SITA_MODULE_CHANNEL_SCAN,     0xffff)

/*
--------proxy module error code-------------------------------------------------
*/
#define FPI_ERROR_PROXY_SUCCESS				FPI_ERROR_SUCCESS
#define FPI_ERROR_PROXY_FAIL				FPI_ERROR_FAIL
#define FPI_ERROR_PROXY_INVALID_PARAMETER	fpi_error_code(SITA_MODULE_PROXY,	0x0001)
#define FPI_ERROR_PROXY_NOT_SUPPORT			fpi_error_code(SITA_MODULE_PROXY,	0x0002)
#define FPI_ERROR_PROXY_MUTEX				fpi_error_code(SITA_MODULE_PROXY,	0x0003)
#define FPI_ERROR_PROXY_DEVICE_DRIVER		fpi_error_code(SITA_MODULE_PROXY,	0x0004)
#define FPI_ERROR_PROXY_GETSERVICE_ERROR	fpi_error_code(SITA_MODULE_PROXY,	0x0005)
#define FPI_ERROR_PROXY_TOKEN_ERROR		    fpi_error_code(SITA_MODULE_PROXY,	0x0006)
#define FPI_ERROR_PROXY_SBINDER_NULL		fpi_error_code(SITA_MODULE_PROXY,	0x0007)
#define FPI_ERROR_PROXY_EXCEPTION_ERROR		fpi_error_code(SITA_MODULE_PROXY,	0x0008)
#define FPI_ERROR_PROXY_TRANSACTION_ERROR	fpi_error_code(SITA_MODULE_PROXY,	0x0009)
#define FPI_ERROR_PROXY_UNKNOW				fpi_error_code(SITA_MODULE_PROXY, 	0xffff)


/*
--------video module error code-------------------------------------------------
*/
#define FPI_ERROR_VIDEO_SUCCESS				FPI_ERROR_SUCCESS
#define FPI_ERROR_VIDEO_FAIL				FPI_ERROR_FAIL
#define FPI_ERROR_VIDEO_INVALID_PARAMETER	fpi_error_code(SITA_MODULE_VIDEO,	0x0001)
#define FPI_ERROR_VIDEO_NOT_SUPPORT			fpi_error_code(SITA_MODULE_VIDEO,	0x0002)
#define FPI_ERROR_VIDEO_ACTION_DELAY			fpi_error_code(SITA_MODULE_VIDEO,	0x0003)
#define FPI_ERROR_VIDEO_NOT_INITIALIZE		fpi_error_code(SITA_MODULE_VIDEO,	0x0004)
#define FPI_ERROR_VIDEO_INIT_FAIL				fpi_error_code(SITA_MODULE_VIDEO,	0x0005)
#define FPI_ERROR_VIDEO_FILE_NOT_FOUND		fpi_error_code(SITA_MODULE_VIDEO,	0x0006)
#define FPI_ERROR_VIDEO_FILE_OPEN_FAIL		fpi_error_code(SITA_MODULE_VIDEO,	0x0007)
#define FPI_ERROR_VIDEO_FILE_READ_FAIL		fpi_error_code(SITA_MODULE_VIDEO,	0x0008)
#define FPI_ERROR_VIDEO_PATH_NOT_FOUND		fpi_error_code(SITA_MODULE_VIDEO,	0x0009)
#define FPI_ERROR_VIDEO_NULL_POINTER			fpi_error_code(SITA_MODULE_VIDEO,	0x000a)
#define FPI_ERROR_VIDEO_DB_READ_FAIL			fpi_error_code(SITA_MODULE_VIDEO,	0x000b)
#define FPI_ERROR_VIDEO_DB_WRITE_FAIL		fpi_error_code(SITA_MODULE_VIDEO,	0x000c)
#define FPI_ERROR_VIDEO_OUT_OF_MEM			fpi_error_code(SITA_MODULE_VIDEO,	0x000d)
#define FPI_ERROR_VIDEO_RESET_FAIL			fpi_error_code(SITA_MODULE_VIDEO,	0x000e)
#define FPI_ERROR_VIDEO_PARAM_READ_FAIL		fpi_error_code(SITA_MODULE_VIDEO,	0x000f)
#define FPI_ERROR_VIDEO_ARRAY_BOUNDS			fpi_error_code(SITA_MODULE_VIDEO,	0x0010)
#define FPI_ERROR_VIDEO_FPP_RET_FAIL			fpi_error_code(SITA_MODULE_VIDEO,	0x0011)

#define FPI_ERROR_VIDEO_RGBCS_RET_SUCCESS       fpi_error_code(SITA_MODULE_FPP,     fpp_internal_error_code(FPP_ERR_MODULE_VIDEO,0x01))
#define FPI_ERROR_VIDEO_RGBCS_RET_FAIL              fpi_error_code(SITA_MODULE_FPP,     fpp_internal_error_code(FPP_ERR_MODULE_VIDEO,0x02))
#define FPI_ERROR_VIDEO_HSICS_RET_SUCCESS        fpi_error_code(SITA_MODULE_FPP,     fpp_internal_error_code(FPP_ERR_MODULE_VIDEO,0x03))
#define FPI_ERROR_VIDEO_HSICS_RET_FAIL               fpi_error_code(SITA_MODULE_FPP,     fpp_internal_error_code(FPP_ERR_MODULE_VIDEO,0x04))


#define FPI_ERROR_VIDEO_UNKNOW				fpi_error_code(SITA_MODULE_VIDEO, 	0xffff)
/*
--------signal module error code-------------------------------------------------
*/
#define FPI_ERROR_SIGNAL_SUCCESS			FPI_ERROR_SUCCESS
#define FPI_ERROR_SIGNAL_FAIL			    FPI_ERROR_FAIL
#define FPI_ERROR_SIGNAL_INVALID_PARAMETER	fpi_error_code(SITA_MODULE_SIGNAL,	0x0001)
#define FPI_ERROR_SIGNAL_NOT_SUPPORT		fpi_error_code(SITA_MODULE_SIGNAL,	0x0002)
#define FPI_ERROR_SIGNAL_UNKNOW				fpi_error_code(SITA_MODULE_SIGNAL,  0xffff)
/*
--------zoom module error code-------------------------------------------------
*/
#define FPI_ERROR_ZOOM_SUCCESS			    FPI_ERROR_SUCCESS
#define FPI_ERROR_ZOOM_FAIL			        FPI_ERROR_FAIL
#define FPI_ERROR_ZOOM_INVALID_PARAMETER	fpi_error_code(SITA_MODULE_ZOOM,	0x0001)
#define FPI_ERROR_ZOOM_NOT_SUPPORT			fpi_error_code(SITA_MODULE_ZOOM,	0x0002)
#define FPI_ERROR_ZOOM_GET_AFD_INFO_FAIL	fpi_error_code(SITA_MODULE_ZOOM,	0x0003)
#define FPI_ERROR_ZOOM_GET_SIGNAL_FORMAT_FAIL	fpi_error_code(SITA_MODULE_ZOOM,	0x0004)
#define FPI_ERROR_ZOOM_GET_SCART_IN_VIDEO_TYPE_FAIL		fpi_error_code(SITA_MODULE_ZOOM,	0x0005)
#define FPI_ERROR_ZOOM_GET_VIDEO_STANDARD_FAIL		fpi_error_code(SITA_MODULE_ZOOM,	0x0006)
#define FPI_ERROR_ZOOM_SET_CROP_WINDOW_FAIL 		fpi_error_code(SITA_MODULE_ZOOM,	0x0007)
#define FPI_ERROR_ZOOM_SET_DISPLAY_WINDOW_FAIL		fpi_error_code(SITA_MODULE_ZOOM,	0x0008)
#define FPI_ERROR_ZOOM_GET_INI_DATA_FAIL		    fpi_error_code(SITA_MODULE_ZOOM,	0x0009)
#define FPI_ERROR_ZOOM_USING_DEFAULT		    fpi_error_code(SITA_MODULE_ZOOM,	0x000a)
#define FPI_ERROR_ZOOM_UNKNOW				fpi_error_code(SITA_MODULE_ZOOM, 	0xffff)
/*
--------linein module error code-------------------------------------------------
*/
#define FPI_ERROR_LINEIN_SUCCESS				FPI_ERROR_SUCCESS
#define FPI_ERROR_LINEIN_FAIL				    FPI_ERROR_FAIL
#define FPI_ERROR_LINEIN_INVALID_PARAMETER		fpi_error_code(SITA_MODULE_LINEIN,	0x0001)
#define FPI_ERROR_LINEIN_NOT_SUPPORT					fpi_error_code(SITA_MODULE_LINEIN,	0x0002)
#define FPI_ERROR_LINEIN_SOC_ABNORMAL				fpi_error_code(SITA_MODULE_LINEIN,	0x0003)
#define FPI_ERROR_LINEIN_BSP_ABNORMAL				fpi_error_code(SITA_MODULE_LINEIN,	0x0004)
#define FPI_ERROR_LINEIN_NOT_INITIALIZED			fpi_error_code(SITA_MODULE_LINEIN,	0x0005)
#define FPI_ERROR_LINEIN_SAME_PARAMETER			fpi_error_code(SITA_MODULE_LINEIN,	0x0006)
#define FPI_ERROR_LINEIN_NO_CONTROL_CLIENT		fpi_error_code(SITA_MODULE_LINEIN,	0x0007)
#define FPI_ERROR_LINEIN_SESSION_INDEX_OVERFLOW	fpi_error_code(SITA_MODULE_LINEIN,	0x0008)
#define FPI_ERROR_LINEIN_UNKNOW					fpi_error_code(SITA_MODULE_LINEIN,	0xffff)

/*
--------Audio module error code-------------------------------------------------
*/

#define FPI_ERROR_AUDIO_SUCCESS					FPI_ERROR_SUCCESS
#define FPI_ERROR_AUDIO_FAIL                    FPI_ERROR_FAIL
#define FPI_ERROR_AUDIO_INVALID_PARAMETER		fpi_error_code(SITA_MODULE_AUDIO,	0x0001)
#define FPI_ERROR_AUDIO_NOT_SUPPORT				fpi_error_code(SITA_MODULE_AUDIO,	0x0002)
#define FPI_ERROR_AUDIO_I2C_COMMUNICATION		fpi_error_code(SITA_MODULE_AUDIO,	0x0003)
#define FPI_ERROR_AUDIO_I2C_NOT_CONFIG			fpi_error_code(SITA_MODULE_AUDIO,	0x0004)
#define FPI_ERROR_AUDIO_CONFIG_SPEAKER			fpi_error_code(SITA_MODULE_AUDIO,	0x0005)
#define FPI_ERROR_AUDIO_CONFIG_HEADPHONE		fpi_error_code(SITA_MODULE_AUDIO,	0x0006)
#define FPI_ERROR_AUDIO_CONFIG_LINEOUT			fpi_error_code(SITA_MODULE_AUDIO,	0x0007)
#define FPI_ERROR_AUDIO_CONFIG_AVOUT			fpi_error_code(SITA_MODULE_AUDIO,	0x0008)
#define FPI_ERROR_AUDIO_CONFIG_BLUETOOTH		fpi_error_code(SITA_MODULE_AUDIO,	0x0009)
#define FPI_ERROR_AUDIO_BSP						fpi_error_code(SITA_MODULE_AUDIO,	0x000a)
#define FPI_ERROR_AUDIO_INPUT_PARAMETER_POINT_NULL  fpi_error_code(SITA_MODULE_AUDIO,	0x000b)
#define FPI_ERROR_AUDIO_GET_DB_ERROR				    fpi_error_code(SITA_MODULE_AUDIO,	0x000c)
#define FPI_ERROR_AUDIO_FPP_RET_ERROR				    fpi_error_code(SITA_MODULE_AUDIO,	0x000d)
#define FPI_ERROR_AUDIO_GET_INI_ERROR				    fpi_error_code(SITA_MODULE_AUDIO,	0x000e)
#define FPI_ERROR_AUDIO_CREATE_TIMER_FAIL			    fpi_error_code(SITA_MODULE_AUDIO,	0x000f)
#define FPI_ERROR_AUDIO_AMP_INIT_FAIL				    fpi_error_code(SITA_MODULE_AUDIO,	0x0010)
#define FPI_ERROR_AUDIO_AMP_CREATE_FAIL                                fpi_error_code(SITA_MODULE_AUDIO,	0x0011)
#define FPI_ERROR_AUDIO_AMP_PARAMETER_NULL                               fpi_error_code(SITA_MODULE_AUDIO,	0x0012)
#define FPI_ERROR_AUDIO_UNKNOW					fpi_error_code(SITA_MODULE_AUDIO,	0xffff)


/*
--------3d module error code-------------------------------------------------
*/

#define FPI_ERROR_3D_SUCCESS                         FPI_ERROR_SUCCESS
#define FPI_ERROR_3D_FAIL                            FPI_ERROR_FAIL
#define FPI_ERROR_3D_INVALID_PARAMETER               fpi_error_code(SITA_MODULE_3D,		0x0001)
#define FPI_ERROR_3D_INPUT_PARAMETER_POINT_NULL      fpi_error_code(SITA_MODULE_3D,		0x0002)
#define FPI_ERROR_3D_UNKNOW      fpi_error_code(SITA_MODULE_3D,		0xffff)


/*
--------Graphics module error code-------------------------------------------------
*/
#define FPI_ERROR_GRAPHICS_SUCCESS				FPI_ERROR_SUCCESS
#define FPI_ERROR_GRAPHICS_FAIL				    FPI_ERROR_FAIL
#define FPI_ERROR_GRAPHICS_NOT_SUPPORT			fpi_error_code(SITA_MODULE_GRAPHICS,	0x0001)
#define FPI_ERROR_GRAPHICS_INVALID_PARAMETER	fpi_error_code(SITA_MODULE_GRAPHICS, 	0x0002)
#define FPI_ERROR_GRAPHICS_OUT_OF_MEM			fpi_error_code(SITA_MODULE_GRAPHICS, 	0x0003)
#define FPI_ERROR_GRAPHICS_UNKNOW				fpi_error_code(SITA_MODULE_GRAPHICS,	0xffff)
/*
--------epg module error code-------------------------------------------------
*/
#define FPI_ERROR_EPG_SUCCESS                   FPI_ERROR_SUCCESS
#define FPI_ERROR_EPG_FAIL                      FPI_ERROR_FAIL
#define FPI_ERROR_EPG_INVALID_PARAMETER         fpi_error_code(SITA_MODULE_EPG,	0x0001)
#define FPI_ERROR_EPG_OUT_OF_MEM                fpi_error_code(SITA_MODULE_EPG,	0x0002)
#define FPI_ERROR_EPG_NO_EVENT_INFO             fpi_error_code(SITA_MODULE_EPG,	0x0003)
#define FPI_ERROR_EPG_INVALID_EVENT_INFO        fpi_error_code(SITA_MODULE_EPG,	0x0004)
#define FPI_ERROR_EPG_INVALID_EVENT_TYPE        fpi_error_code(SITA_MODULE_EPG,	0x0005)
#define FPI_ERROR_EPG_ADD_REQUEST_FAILED        fpi_error_code(SITA_MODULE_EPG,	0x0006)
#define FPI_ERROR_EPG_UNKNOW					fpi_error_code(SITA_MODULE_EPG,	0xffff)
/*
-------media module error code-------------------------------------------------
*/
#define FPI_ERROR_MEDIA_SUCCESS                 FPI_ERROR_SUCCESS
#define FPI_ERROR_MEDIA_FAIL                    FPI_ERROR_FAIL
#define FPI_ERROR_MEDIA_INVALID_PARAMETER       fpi_error_code(SITA_MODULE_MEDIA,	0x0001)
#define FPI_ERROR_MEDIA_MODULE_NOT_INITIALIZE   fpi_error_code(SITA_MODULE_MEDIA,	0x0002)
#define FPI_ERROR_MEDIA_MODULE_ALREADY_INITIALIZED  fpi_error_code(SITA_MODULE_MEDIA,	0x0003)
#define FPI_ERROR_MEDIA_MODULE_ALREADY_STARTED      fpi_error_code(SITA_MODULE_MEDIA,	0x0004)
#define FPI_ERROR_MEDIA_MODULE_SEMAPHORE_ERROR      fpi_error_code(SITA_MODULE_MEDIA,	0x0005)
#define FPI_ERROR_MEDIA_BUFFER_NO_DATA              fpi_error_code(SITA_MODULE_MEDIA,	0x0006)
#define FPI_ERROR_MEDIA_NO_SUPPORT                  fpi_error_code(SITA_MODULE_MEDIA,	0x0007)
#define FPI_ERROR_MEDIA_FOLDER_EMPTY                fpi_error_code(SITA_MODULE_MEDIA,	0x0008)
#define FPI_ERROR_MEDIA_UNKNOW						fpi_error_code(SITA_MODULE_MEDIA,		0xffff)


/*
--------------------IIC module error code---------------------------------------
*/
#define FPI_ERROR_IIC_SUCCESS                   FPI_ERROR_SUCCESS
#define FPI_ERROR_IIC_FAIL                      FPI_ERROR_FAIL
#define FPI_ERROR_IIC_ALREADY_INIT              fpi_error_code(SITA_MODULE_BASE_IIC,    0x0001)
#define FPI_ERROR_IIC_NOT_INIT                  fpi_error_code(SITA_MODULE_BASE_IIC,    0x0002)
#define FPI_ERROR_IIC_INVALID_PARAM             fpi_error_code(SITA_MODULE_BASE_IIC,    0x0003)
     
/*
--------pvr module error code-------------------------------------------------
*/
#define FPI_ERROR_PVR_SUCCESS                   FPI_ERROR_SUCCESS
#define FPI_ERROR_PVR_FAIL                      FPI_ERROR_FAIL
#define FPI_ERROR_PVR_TSI_ALREADY_USED          fpi_error_code(SITA_MODULE_PVR,	0x0001)
#define FPI_ERROR_PVR_NOT_ENOUGH_SPACE          fpi_error_code(SITA_MODULE_PVR,	0x0002)
#define FPI_ERROR_PVR_INTERNAL_ERROR            fpi_error_code(SITA_MODULE_PVR,	0x0003)
#define FPI_ERROR_PVR_RECORDING_NOT_FOUND       fpi_error_code(SITA_MODULE_PVR,	0x0004)
#define FPI_ERROR_PVR_DELETE_ERROR              fpi_error_code(SITA_MODULE_PVR,	0x0005)
#define FPI_ERROR_PVR_RECORD_STOP_ERROR         fpi_error_code(SITA_MODULE_PVR,	0x0006)
#define FPI_ERROR_PVR_NO_PLAYBACK_IN_PROGRESS   fpi_error_code(SITA_MODULE_PVR,	0x0007)
#define FPI_ERROR_PVR_NO_RECORD_IN_PROGRESS     fpi_error_code(SITA_MODULE_PVR,	0x0008)
#define FPI_ERROR_PVR_ILLEGAL_MOTION            fpi_error_code(SITA_MODULE_PVR,	0x0009)
#define FPI_ERROR_PVR_ILLEGAL_TIMES             fpi_error_code(SITA_MODULE_PVR,	0x000a)
#define FPI_ERROR_PVR_ALREADY_LOCKED            fpi_error_code(SITA_MODULE_PVR,	0x000b)
#define FPI_ERROR_PVR_ALREADY_UNLOCKED          fpi_error_code(SITA_MODULE_PVR,	0x000c)
#define FPI_ERROR_PVR_ALREADY_RECORDING         fpi_error_code(SITA_MODULE_PVR,	0x000d)
#define FPI_ERROR_PVR_ALREADY_PLAYING           fpi_error_code(SITA_MODULE_PVR,	0x000e)
#define FPI_ERROR_PVR_ALREADY_PAUSED            fpi_error_code(SITA_MODULE_PVR,	0x000f)
#define FPI_ERROR_PVR_READ_ERROR                fpi_error_code(SITA_MODULE_PVR,	0x0010)
#define FPI_ERROR_PVR_RENAME_ERROR              fpi_error_code(SITA_MODULE_PVR,	0x0011)
#define FPI_ERROR_PVR_BAD_PARAMETER             fpi_error_code(SITA_MODULE_PVR,	0x0012)
#define FPI_ERROR_PVR_NO_VIDEO					fpi_error_code(SITA_MODULE_PVR,	0x0013)
#define FPI_ERROR_PVR_UNKNOW				    fpi_error_code(SITA_MODULE_PVR,	0xffff)

/*
-----------------------factory module error code----------------------------------
*/
#define FPI_ERROR_FACTORY_SUCCESS               FPI_ERROR_SUCCESS 
#define FPI_ERROR_FACTORY_FAIL                      FPI_ERROR_FAIL 
#define FPI_ERROR_FACTORY_UART_HANDLE_FAIL      fpi_error_code(SITA_MODULE_FACTORY,	0x0001)
#define FPI_ERROR_FACTORY_UART_OPEN_FAIL        fpi_error_code(SITA_MODULE_FACTORY,	0x0002)
#define FPI_ERROR_FACTORY_UART_CLOSE_FAIL       fpi_error_code(SITA_MODULE_FACTORY,	0x0003)
#define FPI_ERROR_FACTORY_UART_READ_FAIL        fpi_error_code(SITA_MODULE_FACTORY,	0x0004)
#define FPI_ERROR_FACTORY_UART_WRITE_FAIL       fpi_error_code(SITA_MODULE_FACTORY,	0x0005)
#define FPI_ERROR_FACTORY_UART_WRITE_LENGTH_FAIL    fpi_error_code(SITA_MODULE_FACTORY,	0x0006)
#define FPI_ERROR_FACTORY_READ_FILE_FAIL        fpi_error_code(SITA_MODULE_FACTORY,	0x0007)
#define FPI_ERROR_FACTORY_WRITE_FILE_FAIL       fpi_error_code(SITA_MODULE_FACTORY,	0x0008)
#define FPI_ERROR_FACTORY_SSC_SET_FAIL          fpi_error_code(SITA_MODULE_FACTORY,	0x0009)
#define FPI_ERROR_FACTORY_WATCH_DOG_OPERATE_FAIL       fpi_error_code(SITA_MODULE_FACTORY,	0x000a)
#define FPI_ERROR_FACTORY_WHITE_BALANCE_SET_FAIL       fpi_error_code(SITA_MODULE_FACTORY,	0x000b)
#define FPI_ERROR_FACTORY_IC_OPERATE_FAIL       fpi_error_code(SITA_MODULE_FACTORY,	0x000c)
#define FPI_ERROR_FACTORY_OPEN_INPUT_DEVICE_FAIL       fpi_error_code(SITA_MODULE_FACTORY,	0x000d)
#define FPI_ERROR_FACTORY_SOCKET_FAIL           fpi_error_code(SITA_MODULE_FACTORY,	0x000e)
#define FPI_ERROR_FACTORY_CRC_FAIL              fpi_error_code(SITA_MODULE_FACTORY,	0x000f)
#define FPI_ERROR_FACTORY_CALLBACK_FAIL         fpi_error_code(SITA_MODULE_FACTORY,	0x0010)
#define FPI_ERROR_FACTORY_USB_CLONE_FAIL        fpi_error_code(SITA_MODULE_FACTORY,	0x0011)
#define FPI_ERROR_FACTORY_USB_UPGRATE_FAIL      fpi_error_code(SITA_MODULE_FACTORY,	0x0012)
#define FPI_ERROR_FACTORY_PRESET_FAIL           fpi_error_code(SITA_MODULE_FACTORY,	0x0013)
#define FPI_ERROR_FACTORY_UNKNOW				fpi_error_code(SITA_MODULE_FACTORY,	0xffff)


/*
--------ci module error code-------------------------------------------------
*/
#define FPI_ERROR_CI_SUCCESS                    FPI_ERROR_SUCCESS
#define FPI_ERROR_CI_FAIL                       FPI_ERROR_FAIL

#define FPI_ERROR_CI_INVALID_PARAMETER          fpi_error_code(SITA_MODULE_CI,	0x0001)
#define FPI_ERROR_CI_NOT_SUPPORT                fpi_error_code(SITA_MODULE_CI,	0x0002)
#define FPI_ERROR_CI_INIT_FAIL                  fpi_error_code(SITA_MODULE_CI,	0x0003)
#define FPI_ERROR_CI_REGISTER_FAIL              fpi_error_code(SITA_MODULE_CI,	0x0004)

//pcmcia error code
#define FPI_ERROR_CI_NOT_INSERT                 fpi_error_code(SITA_MODULE_CI,	0x0005)
#define FPI_ERROR_CI_RESET_FAIL                 fpi_error_code(SITA_MODULE_CI,	0x0006)
#define FPI_ERROR_CI_DETECT_READY_FAIL          fpi_error_code(SITA_MODULE_CI,	0x0007)
#define FPI_ERROR_CI_READ_ERROR                 fpi_error_code(SITA_MODULE_CI,	0x0008)
#define FPI_ERROR_CI_WRITE_ERROR                fpi_error_code(SITA_MODULE_CI,	0x0009)
#define FPI_ERROR_CI_SWITCH_TO_IOMEM_FAIL       fpi_error_code(SITA_MODULE_CI,	0x000a)

//sec error code
#define FPI_ERROR_CI_SEC_NOT_DONE               fpi_error_code(SITA_MODULE_CI,	0x000b)
#define FPI_ERROR_CI_SEC_ERROR               	fpi_error_code(SITA_MODULE_CI,	0x000c)
//desc error code
#define FPI_ERROR_CI_DESC_NOT_DONE              fpi_error_code(SITA_MODULE_CI,	0x000d)
#define FPI_ERROR_CI_DESC_ERROR                 fpi_error_code(SITA_MODULE_CI,	0x000e)

//dm error code
#define FPI_ERROR_CI_DM_LENGTH_ERROR            fpi_error_code(SITA_MODULE_CI,	0x000f)
#define FPI_ERROR_CI_DM_GET_DATA_UNKNOWN        fpi_error_code(SITA_MODULE_CI,	0x0010)
#define FPI_ERROR_CI_DM_SET_DATA_FORBIDD        fpi_error_code(SITA_MODULE_CI,	0x0011)
#define FPI_ERROR_CI_DM__PARAM_UNDEF            fpi_error_code(SITA_MODULE_CI,	0x0012)
#define FPI_ERROR_CI_DM_ERROR                   fpi_error_code(SITA_MODULE_CI,	0x0013)


//cec error code
#define FPI_ERROR_CEC_SUCCESS                              FPI_ERROR_SUCCESS
#define FPI_ERROR_CEC_FAIL                      FPI_ERROR_FAIL
#define FPI_ERROR_CEC_FRAME_ERROR                    fpi_error_code(SITA_MODULE_CEC,     0X0001)
#define FPI_ERROR_CEC_FEATURE_ABORT                fpi_error_code(SITA_MODULE_CEC,   0X0002)
#define FPI_ERROR_CEC_RX_SUCCESS                       fpi_error_code(SITA_MODULE_CEC,   0X0003)
#define FPI_ERROR_CEC_TX_SUCCESS                       fpi_error_code(SITA_MODULE_CEC,   0x0004)
#define FPI_ERROR_CEC_RF                                          fpi_error_code(SITA_MODULE_CEC,    0X0005)
#define FPI_ERROR_CEC_LOST_ATB                            fpi_error_code(SITA_MODULE_CEC,     0x0006)
#define FPI_ERROR_CEC_BIT_SHORT                          fpi_error_code(SITA_MODULE_CEC,      0x0007)
#define FPI_ERROR_CEC_BIT_LONG                            fpi_error_code(SITA_MODULE_CEC,      0x0008)
#define FPI_ERROR_CEC_NACK                                    fpi_error_code(SITA_MODULE_CEC,          0x0009)
#define FPI_ERROR_CEC_SYSTEM_BUSY                    fpi_error_code(SITA_MODULE_CEC,            0x000a)
#define FPI_ERROR_CEC_RX_FAIL                       fpi_error_code(SITA_MODULE_CEC,   0X000b)
#define FPI_ERROR_CEC_TX_FAIL                       fpi_error_code(SITA_MODULE_CEC,   0x000c)
#define FPI_ERROR_CEC_CREATED_THREAD_FAIL           fpi_error_code(SITA_MODULE_CEC,   0x000d)
#define FPI_ERROR_CEC_INVALID_PARAMETER		fpi_error_code(SITA_MODULE_CEC,	0x000e)
#define FPI_ERROR_CEC_CHECK_MESSAGE_FAIL    fpi_error_code(SITA_MODULE_CEC,	0x000f)

/*
--------channel search module error code-------------------------------------------------
*/

#define FPI_ERROR_CHANNEL_SUCCESS                    FPI_ERROR_SUCCESS
#define FPI_ERROR_CHANNEL_FAIL                       FPI_ERROR_FAIL
#define FPI_ERROR_CHANNEL_SET_INVALID_PARAMETER  fpi_error_code(SITA_MODULE_CHANNEL,		0x0001)
#define FPI_ERROR_CHANNEL_LIST_EMPTY               fpi_error_code(SITA_MODULE_CHANNEL,		0x0002) 

/*
--------event module error code-------------------------------------------------
*/

#define FPI_ERROR_EVENT_SUCCESS                         FPI_ERROR_SUCCESS
#define FPI_ERROR_EVENT_FAIL                            FPI_ERROR_FAIL

/*
--------common & system module error code-------------------------------------------------
*/


    
#define FPI_ERROR_COMMON_SUCCESS                         FPI_ERROR_SUCCESS
#define FPI_ERROR_COMMON_FAIL                            FPI_ERROR_FAIL
#define FPI_ERROR_COMMON_INVALID_PARAMETER               fpi_error_code(SITA_MODULE_COMMON,		0x0001)
#define FPI_ERROR_COMMON_INPUT_PARAMETER_POINT_NULL      fpi_error_code(SITA_MODULE_COMMON,		0x0002)

/*
--------data base module error code-------------------------------------------------
*/
#define FPI_ERROR_DATA_BASE_MISSING          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0001)
#define FPI_ERROR_DATA_BASE_INTERNAL          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0002)
#define FPI_ERROR_DATA_BASE_PERM          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0003)
#define FPI_ERROR_DATA_BASE_ABORT          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0004)
#define FPI_ERROR_DATA_BASE_BUSY          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0005)
#define FPI_ERROR_DATA_BASE_LOCKED          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0006)
#define FPI_ERROR_DATA_BASE_NOMEM          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0007)
#define FPI_ERROR_DATA_BASE_READONLY          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0008)
#define FPI_ERROR_DATA_BASE_INTERRUPT          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0009)
#define FPI_ERROR_DATA_BASE_IOERR          fpi_error_code(SITA_MODULE_DATA_BASE,	0x000a)
#define FPI_ERROR_DATA_BASE_CORRUPT          fpi_error_code(SITA_MODULE_DATA_BASE,	0x000b)
#define FPI_ERROR_DATA_BASE_NOTFOUND          fpi_error_code(SITA_MODULE_DATA_BASE,	0x000c)
#define FPI_ERROR_DATA_BASE_FULL          fpi_error_code(SITA_MODULE_DATA_BASE,	0x000d)
#define FPI_ERROR_DATA_BASE_CANTOPEN          fpi_error_code(SITA_MODULE_DATA_BASE,	0x000e)
#define FPI_ERROR_DATA_BASE_PROTOCOL          fpi_error_code(SITA_MODULE_DATA_BASE,	0x000f)
#define FPI_ERROR_DATA_BASE_EMPTY          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0010)
#define FPI_ERROR_DATA_BASE_SCHEMA          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0011)
#define FPI_ERROR_DATA_BASE_TOOBIG          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0012)
#define FPI_ERROR_DATA_BASE_CONSTRAINT          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0013)
#define FPI_ERROR_DATA_BASE_MISMATCH          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0014)
#define FPI_ERROR_DATA_BASE_MISUSE          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0015)
#define FPI_ERROR_DATA_BASE_NOLFS          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0016)
#define FPI_ERROR_DATA_BASE_AUTH          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0017)
#define FPI_ERROR_DATA_BASE_FORMAT          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0018)
#define FPI_ERROR_DATA_BASE_RANGE          fpi_error_code(SITA_MODULE_DATA_BASE,	0x0019)
#define FPI_ERROR_DATA_BASE_NOTADB          fpi_error_code(SITA_MODULE_DATA_BASE,	0x001a)


/*
--------data manage module error code-------------------------------------------------
*/
#define FPI_ERROR_DATA_MANAGE_INVALID_HANDLE          fpi_error_code(SITA_MODULE_DATA_MANAGE,	0x0001)
#define FPI_ERROR_DATA_MANAGE_INVALID_PARAMETER          fpi_error_code(SITA_MODULE_DATA_MANAGE,	0x0002)
#define FPI_ERROR_DATA_MANAGE_CREAT_TABLE_FAIL          fpi_error_code(SITA_MODULE_DATA_MANAGE,	0x0003)
#define FPI_ERROR_DATA_MANAGE_SQLITE_ERROR          fpi_error_code(SITA_MODULE_DATA_MANAGE,	0x0004)
#define FPI_ERROR_DATA_MANAGE_NO_RECORD          fpi_error_code(SITA_MODULE_DATA_MANAGE,	0x0005)


/*
--------property module error code-------------------------------------------------
*/
#define FPI_ERROR_PROPERTY_INVALID_HANDLE          fpi_error_code(SITA_MODULE_PROPERTY,	0x0001)
#define FPI_ERROR_PROPERTY_INVALID_PARAMETER          fpi_error_code(SITA_MODULE_PROPERTY,	0x0002)
#define FPI_ERROR_PROPERTY_ACCESS_DB_FAIL          fpi_error_code(SITA_MODULE_PROPERTY,	0x0003)
#define FPI_ERROR_PROPERTY_ACCESS_HASH_FAIL          fpi_error_code(SITA_MODULE_PROPERTY,	0x0004)
#define FPI_ERROR_PROPERTY_FPP_FAIL          fpi_error_code(SITA_MODULE_PROPERTY,	0x0005)

/*
--------power module error code-------------------------------------------------
*/
#define FPI_ERROR_POWER_INVALID_PARAMETER          fpi_error_code(SITA_MODULE_POWER,	0x0001)
#define FPI_ERROR_POWER_FPP_FAIL          fpi_error_code(SITA_MODULE_POWER,	0x0002)

/*
--------mhl error code--------------------------------------------------------------
*/
#define FPI_ERROR_MHL_SUCCESS                              FPI_ERROR_SUCCESS
#define FPI_ERROR_MHL_FAIL                      FPI_ERROR_FAIL
#define FPI_ERROR_MHL_INVALID_PARAMETER                    fpi_error_code(SITA_MODULE_MHL,     0X0001)
#define FPI_ERROR_MHL_CREATED_THREAD_FAIL           fpi_error_code(SITA_MODULE_MHL,   0x0002)
#define FPI_ERROR_MHL_GET_DEV_INFO_FAIL				fpi_error_code(SITA_MODULE_MHL,   0x0003)

/*
--------nscreen error code--------------------------------------------------------------
*/
#define FPI_ERROR_NSCREEN_SUCCESS                   FPI_ERROR_SUCCESS
#define FPI_ERROR_NSCREEN_FAIL                      FPI_ERROR_FAIL
#define FPI_ERROR_NSCREEN_NOT_SUPPORT               fpi_error_code(SITA_MODULE_DLNA,     0X0001)
#define FPI_ERROR_NSCREEN_NO_SERVER                 fpi_error_code(SITA_MODULE_DLNA,   0x0002)
#define FPI_ERROR_NSCREEN_NO_FILE				    fpi_error_code(SITA_MODULE_DLNA,   0x0003)

/*
--------media share error code--------------------------------------------------------------
*/
#define FPI_ERROR_MEDIA_SHARE_SUCCESS                   FPI_ERROR_SUCCESS
#define FPI_ERROR_MEDIA_SHARE_FAIL                      FPI_ERROR_FAIL
#define FPI_ERROR_MEDIA_SHARE_INVALID_HANDLE            fpi_error_code(SITA_MODULE_MEDIA_SHARE,   0X0001)
#define FPI_ERROR_MEDIA_SHARE_INVALID_PARAMETER         fpi_error_code(SITA_MODULE_MEDIA_SHARE,   0x0002)
#define FPI_ERROR_MEDIA_SHARE_NOT_ENOUGH_DATA			fpi_error_code(SITA_MODULE_MEDIA_SHARE,   0x0003)
#define FPI_ERROR_MEDIA_SHARE_FFMPEG_ERROR				fpi_error_code(SITA_MODULE_MEDIA_SHARE,   0x0004)
#define FPI_ERROR_MEDIA_SHARE_RECORD_ERROR				fpi_error_code(SITA_MODULE_MEDIA_SHARE,   0x0005)
#define FPI_ERROR_MEDIA_SHARE_NO_MEMORY					fpi_error_code(SITA_MODULE_MEDIA_SHARE,   0x0006)






/*
--------system error code-------------------------------------------------
*/
#define FPI_ERROR_SYSTEM_SUCCESS                   FPI_ERROR_SUCCESS
#define FPI_ERROR_SYSTEM_FAIL                      FPI_ERROR_FAIL
#define FPI_ERROR_SYSTEM_GET_INI_ERROR               fpi_error_code(SITA_MODULE_SYSTEM,     0X0001)

/*
--------config error code-------------------------------------------------
*/
#define FPI_ERROR_CONFIG_SUCCESS                   FPI_ERROR_SUCCESS
#define FPI_ERROR_CONFIG_FAIL                       fpi_error_code(SITA_MODULE_CONFIG,     0X0001) 
#define FPI_ERROR_CONFIG_CREATE_FAIL                       fpi_error_code(SITA_MODULE_CONFIG,     0X0002) 
#define FPI_ERROR_CONFIG_FILE_FAIL                       fpi_error_code(SITA_MODULE_CONFIG,     0X0003) 

/*
--------panel error code--------------------------------------------------------------
*/
#define FPI_ERROR_PANEL_SUCCESS                   	FPI_ERROR_SUCCESS
#define FPI_ERROR_PANEL_FAIL                      	FPI_ERROR_FAIL
#define FPI_ERROR_PANEL_ID_NOT_SUPPORT              fpi_error_code(SITA_MODULE_PANEL,     0X0001)

/*
--------FPP error code---------------------------------------------------------------
*/

#define fpp_internal_error_code(fpp_module,errID)            ((fpp_module<<8)|(errID))

/* define global error code */
#define FPP_RET_SUCCESS                                    FPI_ERROR_SUCCESS
#define FPP_RET_FAIL                                          FPI_ERROR_FAIL
#define FPP_RET_UNSUPPORT                                FPI_ERROR_UNSUPPORT		
#define FPP_RET_PARAMETER_ERROR                     FPI_ERROR_PARAMETER_ERROR
#define FPP_RET_NOT_IMPLEMENT                         FPI_ERROR_NOT_IMPLEMENT	

#define FPI_ERROR_FPP_DLOPEN_FAIL                   fpi_error_code(SITA_MODULE_FPP,     fpp_internal_error_code(FPP_ERR_MODULE_DLL,0X01))
#define FPI_CEC_RET_TX_SYNC_SUCCESS              fpi_error_code(SITA_MODULE_FPP,     fpp_internal_error_code(FPP_ERR_MODULE_CEC,0x01))

/*
--------mds error code---------------------------------------------------------------
*/
#define FPI_ERROR_MDS_SUCCESS                                    FPI_ERROR_SUCCESS
#define FPI_ERROR_MDS_FAIL                                       FPI_ERROR_FAIL
#define FPI_ERROR_MDS_NOT_REGISTE                                fpi_error_code(SITA_MODULE_MDS,     0X0001)
#define FPI_ERROR_MDS_IMAGE_EXITS								 fpi_error_code(SITA_MODULE_MDS,     0X0000)
#define FPI_ERROR_MDS_IMAGE_SERCHING						     fpi_error_code(SITA_MODULE_MDS,     0X0002)

#ifdef __cplusplus 
}
#endif


#endif

