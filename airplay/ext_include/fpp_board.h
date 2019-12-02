/**@defgroup board board
@{

@brief -boardģ����غ�������

@file fpp_board.h

@author zhangwb 

@version 1.0.0 2014/09/15 ����

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
@brief ��ʼ����������
*/
typedef struct _ST_FPP_BOARD_DRIVER_PARAMETERS_T
{
	EN_FPP_BOARD_OS_T un8_os_type; /**<OS����*/
	EN_FPP_BOARD_AREA_T area; /**<����*/
	void *p_extend; /**<��չ*/
}ST_FPP_BOARD_DRIVER_PARAMETERS_T;

/** 
@brief ������оƬ���
*/	
typedef enum
{
	EN_FPP_BOARD_3RD_CHIP_MEMC, 	///<������MEMC оƬ
	EN_FPP_BOARD_3RD_CHIP_MAX
}EN_FPP_BOARD_3RD_CHIP_TYPE_T;

/** 
@brief ������memc оƬ�ͺ�
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
@brief ������memc оƬ��ʼ������
*/	
typedef struct
{
	EN_FPP_BOARD_3RD_MEMC_TYPE_T enMemcType; 	///<������MEMC оƬ�ͺ�
	int32_t sMemcIicChannel;					///<������MEMC оƬiic ͨ��
	uint8_t sMemcIicddr;						///<������MEMC оƬiic ��ַ�����Ϊ0�������Զ�ʶ��iic��ַ
}ST_FPP_BOARD_3RD_MEMC_PARAM_T;

/**
@brief 				�������ģ��ĳ�ʼ��������IIC��GPIO��video��audio��tuner��demod��demux��decoder��������
							�������ģ�飨������SCART��VBI_TTX��3D��MHL���ܣ���Ŀ����Ϊ��ʵ�ֿ����Ŀ��ٲ��ţ��ú���
							�������������ѡ���Գ�ʼ��ָ��������ģ�飻
@param[in]    para���������������Ĳ���ϵͳ�������Լ���չ��Ϣ��
@param[out]		NONE     
@return    		FPI_ERROR_SUCCESS��	base��ʼ���ɹ���
							FPI_ERROR_FAIL��	base��ʼ��ʧ�ܣ�
*/
fpi_error  fpp_board_base_init (ST_FPP_BOARD_DRIVER_PARAMETERS_T * para);

/**
@brief 				��base init�Ļ����Ͻ���socģ��������������SCART��VBI_TTX��3D��MHL���ܣ��ĳ�ʼ����
							��Щģ��Ӧ��Ӱ�쿪��ͼ����������ţ�
@param[in]		para:��ʼ������       
@param[out]		NONE     
@return   		FPI_ERROR_SUCCESS��external��ʼ���ɹ���
							FPI_ERROR_FAIL��	external��ʼ��ʧ�ܣ�
*/
fpi_error  fpp_board_external_init ();

/**
@brief 				�ýӿ����ڻ�ȡfpp��svn�汾���������ڣ�SVN·����Ϣ��
@param[in]		NONE      
@param[out]		info:������ĸ�ʽ������汾��;����;·��  ����r0001;20140908;https://aaa/data;
@return   		FPI_ERROR_SUCCESS��ִ�гɹ���
							FPI_ERROR_FAIL��	ִ��ʧ�ܣ�
*/
fpi_error fpp_board_get_soft_svn_info(const char** info );

/**
@brief  ������оƬ�ĳ�ʼ����
@param[in] enChipType��������оƬ���
@param[in] pstParam:��ʼ������,����enChipType оƬ���Ͳ�ͬ�����Ĳ���Ҳ��ͬ:
				    EN_FPP_BOARD_3RD_MEMC_TYPE_T -----��Ӧ����ΪST_FPP_BOARD_3RD_MEMC_PARAM_T
@param[out]	NONE     
@return    	FPI_ERROR_SUCCESS����ʼ���ɹ���FPI_ERROR_FAIL����ʼ��ʧ�ܣ�FPI_ERROR_UNSUPPORT -��֧�֣�FPI_ERROR_NOT_IMPLEMENT-ûʵ��
@note  ���������оƬ������TCL ʵ�֣���ýӿ�ʵ��ʱ��Ҫ����tcl ʵ�ֵĵ�����оƬ��ʼ���ӿ�
*/
fpi_error  fpp_board_3rd_chip_init (EN_FPP_BOARD_3RD_CHIP_TYPE_T enChipType, void* pstParam);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
