/**@defgroup iicgpio iicgpio
@{

@brief -iicgpioģ����غ�������

@file  fpp_iic_gpio.h

@author zhangwb 

@version 1.0.0 2014/09/15 ����

*/
#ifndef __FPP_IIC_GPIO_H__
#define __FPP_IIC_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "fpi_base_type.h"
//#include "fpi_debug_helper.h"
#include "fpi_error_code.h"



/** 
@brief ��ƽ״̬����
*/
typedef enum
{   
	EN_GPIO_LOW_STATUS,							/**<�͵�ƽ*/
	EN_GPIO_HIGH_STATUS,						/**<�ߵ�ƽ*/
	EN_GPIO_STATUS_MAX             /**<�Ƿ��ж�*/
} EN_FPP_GPIO_PINSTATUS_T;

/** 
@brief IO���������ģʽ
*/
typedef enum
{
	EN_FPP_GPIO_DIRECTION_INPUT,      	/**<����ģʽ*/			 
	EN_FPP_GPIO_DIRECTION_OUTPUT,      /**<���ģʽ*/
	EN_FPP_GPIO_BIDIRECTIONAL,         /**<˫��*/
	EN_FPP_GPIO_DIRECTION_MAX          /**<�Ƿ��ж�*/
} EN_FPP_GPIO_DIRECTION_T;

/** 
@brief IO���ж�ģʽ
*/
typedef enum 
{    
	EN_FPP_GPIO_INT_DISABLED,	        /**<���ж�ģʽ*/
	EN_FPP_GPIO_INT_RISING_EDGE,       /**<�������ж�ģʽ*/
	EN_FPP_GPIO_INT_FALLING_EDGE,      /**<�½������ж�ģʽ*/
	EN_FPP_GPIO_INT_BOTH_EDGES,        /**<�����½��ض������ж�ģʽ*/
	EN_FPP_GPIO_INT_HIGH_LEVEL,        /**<�ߵ�ƽ�ж�ģʽ*/
	EN_FPP_GPIO_INT_LOW_LEVEL,         /**<�͵�ƽ�ж�ģʽ*/
	EN_FPP_GPIO_INT_MODE_MAX           /**<�Ƿ��ж�*/
} EN_FPP_GPIO_INTERRUPTMODE_T;

/** 
@brief IO�ڹ���ģʽ
*/
typedef struct 
{
	EN_FPP_GPIO_DIRECTION_T  direction;               /**<IO�ڵ��������ģʽ*/
	EN_FPP_GPIO_INTERRUPTMODE_T  interrupt_mode;      /**<IO�ڵ��ж�ģʽ*/
	void	(*Callback)(uint32_t para);     						/**<�жϻص�����*/
} ST_FPP_GPIO_CONFIG_T;

/** 
@brief ����ö������
*/
typedef enum
{
  	EN_FPP_GPIO_INDEX_TEST, 						///<û��ʹ��
	EN_FPP_GPIO_INDEX_DEMOD_DTMB_RESET,				///<demod  ��λ��
	EN_FPP_GPIO_INDEX_DEMOD_DVB_S_RESET,			///<demod  ��λ��
	EN_FPP_GPIO_INDEX_DEMOD_DVB_C_T_RESET,			///<demod  ��λ��
	EN_FPP_GPIO_INDEX_TUNER_DVB_C_T_IF_AGC_SWITCH,	///<�л�AGC
	EN_FPP_GPIO_INDEX_AMP_RESET,					///<���� ��λ��
	EN_FPP_GPIO_INDEX_AMP_STANBY,					///<û��ʹ��
	EN_FPP_GPIO_INDEX_WIFI_POWER_ON,				///<Wifi �Ƿ񹩵�
	EN_FPP_GPIO_INDEX_HEADPHONE_PLUGIN,				///<�����Ƿ����
	EN_FPP_GPIO_INDEX_3D_ENABLE,					///<3D ����
	EN_FPP_GPIO_INDEX_2D_120HZ_ENABLE,				///<120HZ ����
	EN_FPP_GPIO_INDEX_LOCAL_DIMMING_ENABLE,			///<local dimming ����
	EN_FPP_GPIO_INDEX_BACKLIGHT_ON_OFF,				///<���⿪��
	EN_FPP_GPIO_INDEX_ADIM_ON_OFF,					///<ADIM �Ƿ�ɵ�
	EN_FPP_GPIO_INDEX_FP_LED,    					///<���LED ����
	EN_FPP_GPIO_INDEX_HAMON_DETECT,  				///<��������̽��GPIO
	EN_FPP_GPIO_INDEX_ADIM_FUNCTION, 				///<��IO ���ó�input , 1��ֻ����ϵ����ADIM  2D 100%   ;  0����Ϊ3D/ADIM�Ļ��ʹ�� 3d״̬100%��2D״̬��50%
	EN_FPP_GPIO_INDEX_HDMI_ARC_PLUGIN,     			///< ���ڼ��HDMI ARC GPIO
	EN_FPP_GPIO_INDEX_EXTERNAL_RTC_POWER,			///< �ⲿʱ��ģ���Դ�ܽ�
	EN_FPP_GPIO_INDEX_AUDIO_OUTPUT_CONVERT_RESET, 	///< ��Ƶ���ת������ģ�鸴λ�ܽ�
	EN_FPP_GPIO_INDEX_PANEL_PWR,					///<����panel ����
	EN_FPP_GPIO_INDEX_TCON_PMU_WR,					///<����Tcon pmu ic ��дʹ��
	EN_FPP_GPIO_INDEX_TCON_GAMMA_WR,				///<����Tcon gamma ic��дʹ��
	EN_FPP_GPIO_INDEX_LED_SIDE,               		///<LED�ư������2��LED�ƿ�������
	EN_FPP_GPIO_INDEX_LED_MIDDLE,             		///<LED�ư忿�м�2��LED�ƿ�������
	
	EN_FPP_GPIO_INDEX_DLP_FUNC_START = 0x1000,		///<���������Ŀʹ�õ�GPIO ������ʼֵ
	EN_FPP_GPIO_INDEX_DLP_FUNC_END = 0x2000,		///<���������Ŀʹ�õ�GPIO �������ֵ,�Ժ󼤹������ص� GPIO ��������EN_FPP_GPIO_INDEX_DLP_FUNC_START ��EN_FPP_GPIO_INDEX_DLP_FUNC_END ��Χ��

	EN_FPP_GPIO_INDEX_EXTERNAL_MEMC_RESET,			///<����MEMCоƬ��λ��
	EN_FPP_GPIO_INDEX_LOCALDIMMING_UPG_SELECT,		///<��Ӳ��ƽ̨������Localdimming mcuʱ������ʱʹ�ø�IO ��ѡ�������Ŀ�MCU
	EN_FPP_GPIO_INDEX_AMP_PD,						///<���� PD ��

	EN_FPP_GPIO_INDEX_CAMERA_HW_ON_OFF_DETECT,		///<����ͷӲ�����ؼ���ź�
	EN_FPP_GPIO_INDEX_CAMERA_POWER_ON,				///<����ͷ���翪��

	EN_FPP_GPIO_INDEX_MOTOR_FUNC_START = 0x3000,	///<������ʹ�õ�GPIO ������ʼֵ
	EN_FPP_GPIO_INDEX_MOTOR_FUNC_END = 0x4000,		///<������ʹ�õ�GPIO �������ֵ���Ժ���������GPIO ��������EN_FPP_GPIO_INDEX_MOTOR_FUNC_START ��EN_FPP_GPIO_INDEX_MOTOR_FUNC_END֮��, �ο�EN_FPP_GPIO_INDEX_MOTOR_T
	EN_FPP_GPIO_INDEX_MICROWAVE_DETECT, 			///<΢����Ӧ����ź�,��Ӧ�ܱ��Ƿ������忿��
	EN_FPP_GPIO_INDEX_MAX,
} EN_FPP_GPIO_INDEX_T;

/*�������ʹ��GPIO ����*/
typedef enum 
{
	EN_FPP_GPIO_INDEX_DLP_POWER_EN = EN_FPP_GPIO_INDEX_DLP_FUNC_START,		///<������ӣ�DLP ��Դʹ��
	EN_FPP_GPIO_INDEX_DLP_PROJ_ON,											///<������ӣ�DLP ģ��ʹ�ܹ���
	EN_FPP_GPIO_INDEX_DLP_EXT_LD_EN, 										///<������ӣ����������ع�Դ
	EN_FPP_GPIO_INDEX_DLP_DRVER_EN_B,										///<������ӣ��Ƿ��ܿ�����������ָʾ�ź�
	EN_FPP_GPIO_INDEX_DLP_M_PLUS,											///< ������ӣ�DLP �綯�Խ������ת
	EN_FPP_GPIO_INDEX_DLP_M_SUB,											///< ������ӣ�DLP �綯�Խ������ת
	EN_FPP_GPIO_INDEX_DLP_M_EN,												///< ������ӣ�DLP �綯�Խ��������ʹ��
	EN_FPP_GPIO_INDEX_DLP_FAN_LOK,											///< ������ӣ�����ת/ͣת״̬����
	EN_FPP_GPIO_INDEX_DLP_IR_DETECT1,										///<������ӣ������Ӧ����1
	EN_FPP_GPIO_INDEX_DLP_IR_DETECT2,										///<������ӣ������Ӧ����2
	EN_FPP_GPIO_INDEX_DLP_INI_IRQ,											///<������ӣ�DLP����״ָ̬ʾ�ź�
	EN_FPP_GPIO_INDEX_DLP_EE_WP,											///<������ӣ�DLP ����EEPROM��д��������
	EN_FPP_GPIO_INDEX_DLP_MAX = EN_FPP_GPIO_INDEX_DLP_FUNC_END,
}EN_FPP_GPIO_INDEX_DLP_T;

/*������ʹ��GPIO ����*/
typedef enum 
{
	EN_FPP_GPIO_INDEX_MOTOR_INA1 = EN_FPP_GPIO_INDEX_MOTOR_FUNC_START,	///<�����������ź�
	EN_FPP_GPIO_INDEX_MOTOR_INB1,										///<�����������ź�
	EN_FPP_GPIO_INDEX_MOTOR_INA2,										///<�����������ź�
	EN_FPP_GPIO_INDEX_MOTOR_INB2,										///<�����������ź�
	EN_FPP_GPIO_INDEX_MOTOR_UP_LIMIT_DETECT,							///<������������λ����ź�
	EN_FPP_GPIO_INDEX_MOTOR_DOWN_LIMIT_DETECT, 							///<�������½���λ����ź�
	EN_FPP_GPIO_INDEX_MOTOR_UP,											///<����������
	EN_FPP_GPIO_INDEX_MOTOR_DOWN, 										///<�������½�
	EN_FPP_GPIO_INDEX_MOTOR_CW, 										///<��������ת��˳ʱ����ת
	EN_FPP_GPIO_INDEX_MOTOR_CCW, 										///<�����ﷴת����ʱ����ת
	EN_FPP_GPIO_INDEX_MOTOR_CW_LIMIT_DETECT,							///<��������ת��λ����ź�
	EN_FPP_GPIO_INDEX_MOTOR_CCW_LIMIT_DETECT,							///<�����ﷴת��λ����ź�
	EN_FPP_GPIO_INDEX_MOTOR_UP_DOWN_POWER,								///<��������������
	EN_FPP_GPIO_INDEX_MOTOR_ROTATE_POWER,								///<��ת����������
	
	EN_FPP_GPIO_INDEX_MOTOR_MAX = EN_FPP_GPIO_INDEX_MOTOR_FUNC_END,
}EN_FPP_GPIO_INDEX_MOTOR_T;

/**
@brief IICͨ����(����豸��)
*/
typedef enum
{										
	EN_FPP_IIC_CHANNEL0,
	EN_FPP_IIC_CHANNEL1,
	EN_FPP_IIC_CHANNEL2,
	EN_FPP_IIC_CHANNEL3,
	EN_FPP_IIC_CHANNEL4,
	EN_FPP_IIC_CHANNEL_MAX
} EN_FPP_IIC_CHANNEL_NUM_T;

/**
@brief	IICƬ�ڵ�ַ��������
*/
typedef enum 
{										
	EN_FPP_IIC_ZERO_BYTE_ADDRESSING,
	EN_FPP_IIC_ONE_BYTE_ADDRESSING,
	EN_FPP_IIC_TWO_BYTE_ADDRESSING,  
	EN_FPP_IIC_THREE_BYTE_ADDRESSING,
	EN_FPP_IIC_FOUR_BYTE_ADDRESSING,
	EN_FPP_IIC_NOACK,
	EN_FPP_IIC_NOADDR_AND_NOACK,
	EN_FPP_IIC_SUB_ADDRESS_BYTES_MAX
} EN_FPP_IIC_SUB_ADDRESS_BYTES_T;

/**
@brief	IIC��Ϣ����
*/
typedef struct
{										
	EN_FPP_IIC_CHANNEL_NUM_T  channel_num;	            /**<IIC�豸��*/
	uint8_t u8_chip_id;			                /**<оƬ��ַ*/
	uint32_t u32_sub_addr;				        /**<Ƭ�ڵ�ַ*/
    EN_FPP_IIC_SUB_ADDRESS_BYTES_T  sub_addr_bytes_num;	/**<Ƭ�ڵ�ַ��������*/
	uint8_t *pdata;				                /**<����bufferָ��*/
	uint32_t u32_length;				        /**<���ݳ���*/
	uint32_t u32_time_out;				        /**<�ȴ�ʱ��*/	
} ST_FPP_IIC_SET_INFO_T;



/**
@brief	 		iic д��ӿں���
@param[in]  pwrite_info->->channel_num      ��ʾ�������ڵڼ�·IIC
                    ->u8_chip_id        оƬ��������ַ
                    ->u32_sub_addr      �Ĵ�����ַ
                    ->sub_addr_bytes_num  �Ĵ�����ַ�Ǽ����ֽڵ�
                    ->pdata             ��Ҫд�������
                    ->u32_length        д�����ݵĳ���
                    ->u32_time_out      IIC д��ʱʱ��
                    
@param[out] NONE
@return     FPI_ERROR_SUCCESS   -- iic д��ɹ�
            FPI_ERROR_FAIL      -- iic д��ʧ��
            FPI_ERROR_IIC_INVALID_PARAM -- iic д���������
*/
fpi_error fpp_iic_write(ST_FPP_IIC_SET_INFO_T *pwrite_info);

/**
@brief	 			iic ���ӿں���
@param[in]    NONE
@param[out]   pread_info ��IIC�����������õ�ַ�ɵ��������루malloc�����ײ�ʵ��ʱ�����ͷţ�free�����������£�
							read_info->pdata   IIC��ȡ��������ŵ�BUF
							->channel_num      ��ʾ�������ڵڼ�·IIC��
	 						->u8_chip_id        оƬ��������ַ
	 						->u32_sub_addr      �Ĵ����ĵ�ַ
              ->sub_addr_bytes_num  �Ĵ�����ַ�Ǽ����ֽڵ�
							->u32_length        ��Ҫ��ȡ������BUF����
							->u32_time_out      IIC��ȡ��ʱ��ʱ��
@return    	FPI_ERROR_SUCCESS   -- iic ��ȡ�ɹ�
            FPI_ERROR_FAIL      -- iic ��ȡʧ��
*/
fpi_error fpp_iic_read(ST_FPP_IIC_SET_INFO_T *pread_info);


/**
@brief		  iic ��λ�ӿں���
@param[in]  iic_channel         ��Ҫ��λ��IICͨ��
@param[out] NONE
@return	    FPI_ERROR_SUCCESS   -- iic ��λ�ɹ�
            FPI_ERROR_FAIL      -- iic ��λʧ��
*/
fpi_error fpp_iic_reset(EN_FPP_IIC_CHANNEL_NUM_T iic_channel);

/**
@brief	��ȡ�ײ�ʵ��iic�ӿ�ʱiic ��ַ��bit λ��
@param[in] NONE
@param[out] pIic_addr_bits ---�ײ��IIC ��ַλ������ʵ��8bit ��ַ�ͷ���8��ʵ��7bit ��ַ�ͷ���7.
@return FPI_ERROR_SUCCESS   -- �ɹ�; FPI_ERROR_FAIL   --ʧ��;FPI_ERROR_NOT_IMPLEMENT --δʵ��
@note ����ýӿ�δʵ�֣�Ĭ�ϰ�8 bit ����
*/
fpi_error fpp_iic_get_addr_bits(uint8_t* pIic_addr_bits);

/**
@brief		  GPIO���ýӿں���
@param[in]  gpio_index         ��Ҫ���õ�GPIO���������������Ӧ��Chip��GPIO ����Ҫ��ӳ��
            pin_config ��      GPIO��Ҫ���õ����ԣ����Ƿ�Ϊ�жϽŻ���ͨ��GPIO�ţ������뷽�����������
                               �����жϽŻ��������жϴ�����ģʽ����CALLBACK����
@param[out] NONE
@return     FPI_ERROR_SUCCESS      	IO�����óɹ�
            FPI_ERROR_FAIL         	IO������ʧ��
            FPI_ERROR_GPIO_NOT_INIT   IO��û�г�ʼ��
*/
fpi_error fpp_gpio_configure(EN_FPP_GPIO_INDEX_T gpio_index, ST_FPP_GPIO_CONFIG_T* pin_config);


/**
@brief		  ���ڷ���Ϊ�����GPIO�ڣ�����GPIO�ڵĸߵ͵�ƽ״̬��
@param[in]  gpio_index��		GPIO���������ţ������Ӧ��Chip��GPIO ����Ҫ��ӳ��
						set_status  ��	GPIO��ƽ״̬��
						EN_GPIO_LOW_STATUS 	�͵�ƽ
						EN_GPIO_HIGH_STATUS	�ߵ�ƽ
@param[out] NONE
@return	    FPI_ERROR_SUCCESS      					GPIO�����ƽ���óɹ�
						FPI_ERROR_GPIO_NOT_INIT     		GPIOģ��û�г�ʼ��
						FPI_ERROR_GPIO_INVALID_PARAM  	GPIO��������
						FPI_ERROR_FAIL         					GPIO��ƽ����ʧ��
*/
fpi_error fpp_gpio_set(EN_FPP_GPIO_INDEX_T gpio_index, EN_FPP_GPIO_PINSTATUS_T set_status);


/**
@brief 			��ȡĳ��GPIO�����������Ի���������ԣ�
@param[in]  gpio_index��		GPIO���������ţ������Ӧ��Chip��GPIO ����Ҫ��ӳ��
						
@param[out] pGpioAttr,GPIO���ԣ�����ֵ���£�
						EN_GPIO_DIRECTION_INPUT 	��������
				  	EN_GPIO_DIRECTION_OUTPUT	�������
            ��ָ��ָ��һ�������������ά�����ڴ棬�ײ�ֱ��������ݼ��ɣ��Ҳ����ͷ�

@return    	FPI_ERROR_SUCCESS      		GPIO����������Ի�ȡ�ɹ�
						FPI_ERROR_FAIL         		GPIO����������Ի�ȡʧ��
*/
fpi_error fpp_gpio_getdirection(EN_FPP_GPIO_INDEX_T gpio_index, EN_FPP_GPIO_DIRECTION_T  *pGpioAttr);


/**
@brief		  ��ȡĳ��������Ե�GPIO�����״̬���ߵ�ƽ��͵�ƽ��
@param[in]  gpio_index: gpio�����ţ������Ӧ��chip������Ҫӳ��
@param[out] IO�ڵ��������ģʽ:
						EN_GPIO_LOW_STATUS -�͵�ƽ
						EN_GPIO_HIGH_STATUS -�ߵ�ƽ
@return    	FPI_ERROR_SUCCESS      		GPIO����������Ի�ȡ�ɹ�
						FPI_ERROR_FAIL         		GPIO����������Ի�ȡʧ��
*/

fpi_error fpp_gpio_get(EN_FPP_GPIO_INDEX_T gpio_index, EN_FPP_GPIO_PINSTATUS_T * status );

#ifdef __cplusplus
}
#endif
/** @} */

#endif
