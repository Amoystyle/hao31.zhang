/**@defgroup board board
@{

@brief -board模块相关函数定义

@file fpp_board.h

@author zhangwb 

@version 1.0.0 2014/09/15 初稿

*/

#ifndef __FPP_BOARD_H__
#define __FPP_BOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "fpi_base_type.h"
//#include "fpi_debug_helper.h"
#include "fpi_error_code.h"

/** 
@brief 初始化参数定义
*/
typedef struct _ST_FPP_BOARD_DRIVER_PARAMETERS_T
{
	EN_FPP_BOARD_OS_T un8_os_type; /**<OS类型*/
	EN_FPP_BOARD_AREA_T area; /**<区域*/
	void *p_extend; /**<扩展*/
}ST_FPP_BOARD_DRIVER_PARAMETERS_T;

/** 
@brief 第三方芯片类别
*/	
typedef enum
{
	EN_FPP_BOARD_3RD_CHIP_MEMC, 	///<第三方MEMC 芯片
	EN_FPP_BOARD_3RD_CHIP_MAX
}EN_FPP_BOARD_3RD_CHIP_TYPE_T;

/** 
@brief 第三方memc 芯片型号
*/	
typedef enum
{
	EN_FPP_BOARD_3RD_MEMC_NVT318B,  ///<NTK nt72318b
	EN_FPP_BOARD_3RD_MEMC_NVT353,	///<NTK nt72353
	EN_FPP_BOARD_3RD_MEMC_NVT334,	///<NTK nt72334
	EN_FPP_BOARD_3RD_MEMC_NVT315,	///<NTK nt72315
	EN_FPP_BOARD_3RD_MEMC_RT2893,	///<RT2893
	EN_FPP_BOARD_3RD_MEMC_MAX
}EN_FPP_BOARD_3RD_MEMC_TYPE_T;

/** 
@brief 第三方memc 芯片初始化参数
*/	
typedef struct
{
	EN_FPP_BOARD_3RD_MEMC_TYPE_T enMemcType; 	///<第三方MEMC 芯片型号
	int32_t sMemcIicChannel;					///<第三方MEMC 芯片iic 通道
	uint8_t sMemcIicddr;						///<第三方MEMC 芯片iic 地址，如果为0，则需自动识别iic地址
}ST_FPP_BOARD_3RD_MEMC_PARAM_T;

/**
@brief 				软件基本模块的初始化，包括IIC，GPIO，video，audio，tuner，demod，demux，decoder开机播放
							所必需的模块（不包括SCART，VBI_TTX，3D，MHL功能），目的是为了实现开机的快速播放，该函数
							根据输入参数，选择性初始化指定的驱动模块；
@param[in]    para：用于描述方案的操作系统，区域以及扩展信息；
@param[out]		NONE     
@return    		FPI_ERROR_SUCCESS：	base初始化成功；
							FPI_ERROR_FAIL：	base初始化失败；
*/
fpi_error  fpp_board_base_init (ST_FPP_BOARD_DRIVER_PARAMETERS_T * para);

/**
@brief 				在base init的基础上进行soc模块其他（不包括SCART，VBI_TTX，3D，MHL功能）的初始化，
							这些模块应不影响开机图像和声音播放；
@param[in]		para:初始化参数       
@param[out]		NONE     
@return   		FPI_ERROR_SUCCESS：external初始化成功；
							FPI_ERROR_FAIL：	external初始化失败；
*/
fpi_error  fpp_board_external_init ();

/**
@brief 				该接口用于获取fpp的svn版本、编译日期，SVN路径信息，
@param[in]		NONE      
@param[out]		info:以下面的格式输出，版本号;日期;路径  例如r0001;20140908;https://aaa/data;
@return   		FPI_ERROR_SUCCESS：执行成功；
							FPI_ERROR_FAIL：	执行失败；
*/
fpi_error fpp_board_get_soft_svn_info(const char** info );

/**
@brief  第三方芯片的初始化；
@param[in] enChipType：第三方芯片类别
@param[in] pstParam:初始化参数,根据enChipType 芯片类型不同，传的参数也不同:
				    EN_FPP_BOARD_3RD_MEMC_TYPE_T -----对应参数为ST_FPP_BOARD_3RD_MEMC_PARAM_T
@param[out]	NONE     
@return    	FPI_ERROR_SUCCESS：初始化成功；FPI_ERROR_FAIL：初始化失败；FPI_ERROR_UNSUPPORT -不支持；FPI_ERROR_NOT_IMPLEMENT-没实现
@note  如果第三方芯片驱动由TCL 实现，则该接口实现时需要调用tcl 实现的第三方芯片初始化接口
*/
fpi_error  fpp_board_3rd_chip_init (EN_FPP_BOARD_3RD_CHIP_TYPE_T enChipType, void* pstParam);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
