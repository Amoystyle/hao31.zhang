/**@defgroup iicgpio iicgpio
@{

@brief -iicgpio模块相关函数定义

@file  fpp_iic_gpio.h

@author zhangwb 

@version 1.0.0 2014/09/15 初稿

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
@brief 电平状态定义
*/
typedef enum
{   
	EN_GPIO_LOW_STATUS,							/**<低电平*/
	EN_GPIO_HIGH_STATUS,						/**<高电平*/
	EN_GPIO_STATUS_MAX             /**<非法判断*/
} EN_FPP_GPIO_PINSTATUS_T;

/** 
@brief IO口输入输出模式
*/
typedef enum
{
	EN_FPP_GPIO_DIRECTION_INPUT,      	/**<输入模式*/			 
	EN_FPP_GPIO_DIRECTION_OUTPUT,      /**<输出模式*/
	EN_FPP_GPIO_BIDIRECTIONAL,         /**<双向*/
	EN_FPP_GPIO_DIRECTION_MAX          /**<非法判断*/
} EN_FPP_GPIO_DIRECTION_T;

/** 
@brief IO口中断模式
*/
typedef enum 
{    
	EN_FPP_GPIO_INT_DISABLED,	        /**<非中断模式*/
	EN_FPP_GPIO_INT_RISING_EDGE,       /**<上升沿中断模式*/
	EN_FPP_GPIO_INT_FALLING_EDGE,      /**<下降升沿中断模式*/
	EN_FPP_GPIO_INT_BOTH_EDGES,        /**<上升下降沿都产生中断模式*/
	EN_FPP_GPIO_INT_HIGH_LEVEL,        /**<高电平中断模式*/
	EN_FPP_GPIO_INT_LOW_LEVEL,         /**<低电平中断模式*/
	EN_FPP_GPIO_INT_MODE_MAX           /**<非法判断*/
} EN_FPP_GPIO_INTERRUPTMODE_T;

/** 
@brief IO口工作模式
*/
typedef struct 
{
	EN_FPP_GPIO_DIRECTION_T  direction;               /**<IO口的输入输出模式*/
	EN_FPP_GPIO_INTERRUPTMODE_T  interrupt_mode;      /**<IO口的中断模式*/
	void	(*Callback)(uint32_t para);     						/**<中断回调函数*/
} ST_FPP_GPIO_CONFIG_T;

/** 
@brief 常用枚举索引
*/
typedef enum
{
  	EN_FPP_GPIO_INDEX_TEST, 						///<没有使用
	EN_FPP_GPIO_INDEX_DEMOD_DTMB_RESET,				///<demod  复位脚
	EN_FPP_GPIO_INDEX_DEMOD_DVB_S_RESET,			///<demod  复位脚
	EN_FPP_GPIO_INDEX_DEMOD_DVB_C_T_RESET,			///<demod  复位脚
	EN_FPP_GPIO_INDEX_TUNER_DVB_C_T_IF_AGC_SWITCH,	///<切换AGC
	EN_FPP_GPIO_INDEX_AMP_RESET,					///<功放 复位脚
	EN_FPP_GPIO_INDEX_AMP_STANBY,					///<没有使用
	EN_FPP_GPIO_INDEX_WIFI_POWER_ON,				///<Wifi 是否供电
	EN_FPP_GPIO_INDEX_HEADPHONE_PLUGIN,				///<耳机是否插入
	EN_FPP_GPIO_INDEX_3D_ENABLE,					///<3D 开关
	EN_FPP_GPIO_INDEX_2D_120HZ_ENABLE,				///<120HZ 开关
	EN_FPP_GPIO_INDEX_LOCAL_DIMMING_ENABLE,			///<local dimming 开关
	EN_FPP_GPIO_INDEX_BACKLIGHT_ON_OFF,				///<背光开关
	EN_FPP_GPIO_INDEX_ADIM_ON_OFF,					///<ADIM 是否可调
	EN_FPP_GPIO_INDEX_FP_LED,    					///<面板LED 开关
	EN_FPP_GPIO_INDEX_HAMON_DETECT,  				///<哈曼音箱探测GPIO
	EN_FPP_GPIO_INDEX_ADIM_FUNCTION, 				///<该IO 配置成input , 1：只做混合调光的ADIM  2D 100%   ;  0：作为3D/ADIM的混合使用 3d状态100%，2D状态下50%
	EN_FPP_GPIO_INDEX_HDMI_ARC_PLUGIN,     			///< 用于检测HDMI ARC GPIO
	EN_FPP_GPIO_INDEX_EXTERNAL_RTC_POWER,			///< 外部时钟模块电源管脚
	EN_FPP_GPIO_INDEX_AUDIO_OUTPUT_CONVERT_RESET, 	///< 音频输出转换处理模块复位管脚
	EN_FPP_GPIO_INDEX_PANEL_PWR,					///<控制panel 供电
	EN_FPP_GPIO_INDEX_TCON_PMU_WR,					///<控制Tcon pmu ic 读写使能
	EN_FPP_GPIO_INDEX_TCON_GAMMA_WR,				///<控制Tcon gamma ic读写使能
	EN_FPP_GPIO_INDEX_LED_SIDE,               		///<LED灯板最外边2颗LED灯控制引脚
	EN_FPP_GPIO_INDEX_LED_MIDDLE,             		///<LED灯板靠中间2颗LED灯控制引脚
	
	EN_FPP_GPIO_INDEX_DLP_FUNC_START = 0x1000,		///<激光电视项目使用的GPIO 定义起始值
	EN_FPP_GPIO_INDEX_DLP_FUNC_END = 0x2000,		///<激光电视项目使用的GPIO 定义最大值,以后激光电视相关的 GPIO 均定义在EN_FPP_GPIO_INDEX_DLP_FUNC_START 与EN_FPP_GPIO_INDEX_DLP_FUNC_END 范围内

	EN_FPP_GPIO_INDEX_EXTERNAL_MEMC_RESET,			///<外置MEMC芯片复位脚
	EN_FPP_GPIO_INDEX_LOCALDIMMING_UPG_SELECT,		///<当硬件平台有两组Localdimming mcu时，升级时使用该IO 口选择升级哪颗MCU
	EN_FPP_GPIO_INDEX_AMP_PD,						///<功放 PD 脚

	EN_FPP_GPIO_INDEX_CAMERA_HW_ON_OFF_DETECT,		///<摄像头硬件开关检测信号
	EN_FPP_GPIO_INDEX_CAMERA_POWER_ON,				///<摄像头供电开关

	EN_FPP_GPIO_INDEX_MOTOR_FUNC_START = 0x3000,	///<电机马达使用的GPIO 定义起始值
	EN_FPP_GPIO_INDEX_MOTOR_FUNC_END = 0x4000,		///<电机马达使用的GPIO 定义最大值，以后电机马达相关GPIO 均定义在EN_FPP_GPIO_INDEX_MOTOR_FUNC_START 与EN_FPP_GPIO_INDEX_MOTOR_FUNC_END之间, 参考EN_FPP_GPIO_INDEX_MOTOR_T
	EN_FPP_GPIO_INDEX_MICROWAVE_DETECT, 			///<微波感应检测信号,感应周边是否有物体靠近
	EN_FPP_GPIO_INDEX_MAX,
} EN_FPP_GPIO_INDEX_T;

/*激光电视使用GPIO 定义*/
typedef enum 
{
	EN_FPP_GPIO_INDEX_DLP_POWER_EN = EN_FPP_GPIO_INDEX_DLP_FUNC_START,		///<激光电视，DLP 电源使能
	EN_FPP_GPIO_INDEX_DLP_PROJ_ON,											///<激光电视，DLP 模块使能工作
	EN_FPP_GPIO_INDEX_DLP_EXT_LD_EN, 										///<激光电视，激光器开关光源
	EN_FPP_GPIO_INDEX_DLP_DRVER_EN_B,										///<激光电视，是否能开启激光器的指示信号
	EN_FPP_GPIO_INDEX_DLP_M_PLUS,											///< 激光电视，DLP 电动对焦电机正转
	EN_FPP_GPIO_INDEX_DLP_M_SUB,											///< 激光电视，DLP 电动对焦电机反转
	EN_FPP_GPIO_INDEX_DLP_M_EN,												///< 激光电视，DLP 电动对焦电机驱动使能
	EN_FPP_GPIO_INDEX_DLP_FAN_LOK,											///< 激光电视，风扇转/停转状态反馈
	EN_FPP_GPIO_INDEX_DLP_IR_DETECT1,										///<激光电视，人体感应球检测1
	EN_FPP_GPIO_INDEX_DLP_IR_DETECT2,										///<激光电视，人体感应球检测2
	EN_FPP_GPIO_INDEX_DLP_INI_IRQ,											///<激光电视，DLP运行状态指示信号
	EN_FPP_GPIO_INDEX_DLP_EE_WP,											///<激光电视，DLP 控制EEPROM的写保护引脚
	EN_FPP_GPIO_INDEX_DLP_MAX = EN_FPP_GPIO_INDEX_DLP_FUNC_END,
}EN_FPP_GPIO_INDEX_DLP_T;

/*电机马达使用GPIO 定义*/
typedef enum 
{
	EN_FPP_GPIO_INDEX_MOTOR_INA1 = EN_FPP_GPIO_INDEX_MOTOR_FUNC_START,	///<电机马达驱动信号
	EN_FPP_GPIO_INDEX_MOTOR_INB1,										///<电机马达驱动信号
	EN_FPP_GPIO_INDEX_MOTOR_INA2,										///<电机马达驱动信号
	EN_FPP_GPIO_INDEX_MOTOR_INB2,										///<电机马达驱动信号
	EN_FPP_GPIO_INDEX_MOTOR_UP_LIMIT_DETECT,							///<电机马达上升到位检测信号
	EN_FPP_GPIO_INDEX_MOTOR_DOWN_LIMIT_DETECT, 							///<电机马达下降到位检测信号
	EN_FPP_GPIO_INDEX_MOTOR_UP,											///<电机马达上升
	EN_FPP_GPIO_INDEX_MOTOR_DOWN, 										///<电机马达下降
	EN_FPP_GPIO_INDEX_MOTOR_CW, 										///<电机马达正转或顺时针旋转
	EN_FPP_GPIO_INDEX_MOTOR_CCW, 										///<电机马达反转或逆时针旋转
	EN_FPP_GPIO_INDEX_MOTOR_CW_LIMIT_DETECT,							///<电机马达正转到位检测信号
	EN_FPP_GPIO_INDEX_MOTOR_CCW_LIMIT_DETECT,							///<电机马达反转到位检测信号
	EN_FPP_GPIO_INDEX_MOTOR_UP_DOWN_POWER,								///<升降电机供电控制
	EN_FPP_GPIO_INDEX_MOTOR_ROTATE_POWER,								///<旋转电机供电控制
	
	EN_FPP_GPIO_INDEX_MOTOR_MAX = EN_FPP_GPIO_INDEX_MOTOR_FUNC_END,
}EN_FPP_GPIO_INDEX_MOTOR_T;

/**
@brief IIC通道号(或称设备号)
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
@brief	IIC片内地址长度类型
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
@brief	IIC信息配置
*/
typedef struct
{										
	EN_FPP_IIC_CHANNEL_NUM_T  channel_num;	            /**<IIC设备号*/
	uint8_t u8_chip_id;			                /**<芯片地址*/
	uint32_t u32_sub_addr;				        /**<片内地址*/
    EN_FPP_IIC_SUB_ADDRESS_BYTES_T  sub_addr_bytes_num;	/**<片内地址长度类型*/
	uint8_t *pdata;				                /**<数据buffer指针*/
	uint32_t u32_length;				        /**<数据长度*/
	uint32_t u32_time_out;				        /**<等待时间*/	
} ST_FPP_IIC_SET_INFO_T;



/**
@brief	 		iic 写入接口函数
@param[in]  pwrite_info->->channel_num      表示该器件在第几路IIC
                    ->u8_chip_id        芯片的器件地址
                    ->u32_sub_addr      寄存器地址
                    ->sub_addr_bytes_num  寄存器地址是几个字节的
                    ->pdata             需要写入的数据
                    ->u32_length        写入数据的长度
                    ->u32_time_out      IIC 写超时时间
                    
@param[out] NONE
@return     FPI_ERROR_SUCCESS   -- iic 写入成功
            FPI_ERROR_FAIL      -- iic 写入失败
            FPI_ERROR_IIC_INVALID_PARAM -- iic 写入参数出错
*/
fpi_error fpp_iic_write(ST_FPP_IIC_SET_INFO_T *pwrite_info);

/**
@brief	 			iic 读接口函数
@param[in]    NONE
@param[out]   pread_info ：IIC读出参数；该地址由调用者申请（malloc），底层实现时不得释放（free）。具体如下：
							read_info->pdata   IIC读取数据所存放的BUF
							->channel_num      表示该器件在第几路IIC上
	 						->u8_chip_id        芯片的器件地址
	 						->u32_sub_addr      寄存器的地址
              ->sub_addr_bytes_num  寄存器地址是几个字节的
							->u32_length        需要读取的数据BUF长度
							->u32_time_out      IIC读取超时的时间
@return    	FPI_ERROR_SUCCESS   -- iic 读取成功
            FPI_ERROR_FAIL      -- iic 读取失败
*/
fpi_error fpp_iic_read(ST_FPP_IIC_SET_INFO_T *pread_info);


/**
@brief		  iic 复位接口函数
@param[in]  iic_channel         需要复位的IIC通道
@param[out] NONE
@return	    FPI_ERROR_SUCCESS   -- iic 复位成功
            FPI_ERROR_FAIL      -- iic 复位失败
*/
fpi_error fpp_iic_reset(EN_FPP_IIC_CHANNEL_NUM_T iic_channel);

/**
@brief	获取底层实现iic接口时iic 地址的bit 位数
@param[in] NONE
@param[out] pIic_addr_bits ---底层的IIC 地址位数，如实现8bit 地址就返回8，实现7bit 地址就返回7.
@return FPI_ERROR_SUCCESS   -- 成功; FPI_ERROR_FAIL   --失败;FPI_ERROR_NOT_IMPLEMENT --未实现
@note 如果该接口未实现，默认按8 bit 处理
*/
fpi_error fpp_iic_get_addr_bits(uint8_t* pIic_addr_bits);

/**
@brief		  GPIO配置接口函数
@param[in]  gpio_index         需要配置的GPIO数字索引，具体对应于Chip的GPIO 号需要有映射
            pin_config ：      GPIO需要配置的属性；如是否为中断脚或普通的GPIO脚，是输入方向还是输出方向，
                               如是中断脚还需配置中断触发的模式，和CALLBACK函数
@param[out] NONE
@return     FPI_ERROR_SUCCESS      	IO口配置成功
            FPI_ERROR_FAIL         	IO口配置失败
            FPI_ERROR_GPIO_NOT_INIT   IO口没有初始化
*/
fpi_error fpp_gpio_configure(EN_FPP_GPIO_INDEX_T gpio_index, ST_FPP_GPIO_CONFIG_T* pin_config);


/**
@brief		  对于方向为输出的GPIO口，设置GPIO口的高低电平状态；
@param[in]  gpio_index：		GPIO引脚索引号，具体对应于Chip的GPIO 号需要有映射
						set_status  ：	GPIO电平状态；
						EN_GPIO_LOW_STATUS 	低电平
						EN_GPIO_HIGH_STATUS	高电平
@param[out] NONE
@return	    FPI_ERROR_SUCCESS      					GPIO输出电平设置成功
						FPI_ERROR_GPIO_NOT_INIT     		GPIO模块没有初始化
						FPI_ERROR_GPIO_INVALID_PARAM  	GPIO参数错误
						FPI_ERROR_FAIL         					GPIO电平设置失败
*/
fpi_error fpp_gpio_set(EN_FPP_GPIO_INDEX_T gpio_index, EN_FPP_GPIO_PINSTATUS_T set_status);


/**
@brief 			获取某个GPIO口是输入属性还是输出属性；
@param[in]  gpio_index：		GPIO引脚索引号，具体对应于Chip的GPIO 号需要有映射
						
@param[out] pGpioAttr,GPIO属性，具体值如下：
						EN_GPIO_DIRECTION_INPUT 	输入属性
				  	EN_GPIO_DIRECTION_OUTPUT	输出属性
            该指针指向一个调用者申请和维护的内存，底层直接填充数据即可，且不得释放

@return    	FPI_ERROR_SUCCESS      		GPIO输入输出属性获取成功
						FPI_ERROR_FAIL         		GPIO输入输出属性获取失败
*/
fpi_error fpp_gpio_getdirection(EN_FPP_GPIO_INDEX_T gpio_index, EN_FPP_GPIO_DIRECTION_T  *pGpioAttr);


/**
@brief		  获取某个输出属性的GPIO的输出状态（高电平或低电平）
@param[in]  gpio_index: gpio索引号，具体对应的chip引脚需要映射
@param[out] IO口的输入输出模式:
						EN_GPIO_LOW_STATUS -低电平
						EN_GPIO_HIGH_STATUS -高电平
@return    	FPI_ERROR_SUCCESS      		GPIO输入输出属性获取成功
						FPI_ERROR_FAIL         		GPIO输入输出属性获取失败
*/

fpi_error fpp_gpio_get(EN_FPP_GPIO_INDEX_T gpio_index, EN_FPP_GPIO_PINSTATUS_T * status );

#ifdef __cplusplus
}
#endif
/** @} */

#endif
