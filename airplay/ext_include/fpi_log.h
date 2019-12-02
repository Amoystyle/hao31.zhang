/*********************************************************************************************
* Filename	: app_trace.h
* Author   	: LinShunda
* Description:   
* Version:   
* Function List:	
* 1. --------- 
* History: 	
* <author>  	  <time>   			<version >   <desc>	
* LinShunda    	2013-06-11 	 		1.0    	 	build this moudle  	
* Copyright	: TCL Electronics(Shen Zhen) Co.,Ltd.
********************************************************************************************/

#ifndef _FLOG_H_
#define _FLOG_H_

#define USE_CLOG 0


#include "fpi_base_type.h"
#include "fpi_log_file.h"
#include "tos_tcli.h"
#include "clog.h"

#define LOG_LEVEL_FATAL 		6   //致命错误 同 FPI_DEBUG_LEVEL_FATAL
#define LOG_LEVEL_ERROR        5   //普通错误 同 FPI_DEBUG_LEVEL_ERROR
#define LOG_LEVEL_ALARM        4   //紧急警报，一般必须马上处理 同 FPI_DEBUG_LEVEL_ALARM
#define LOG_LEVEL_WARN         3    //警告         同 FPI_DEBUG_LEVEL_WARN
#define LOG_LEVEL_INFO         2    //信息，启动系统或者模块的打印.同 FPI_DEBUG_LEVEL_WARN
#define LOG_LEVEL_DEBUG		   1
#define LOG_LEVEL_TRACE        0    //跟踪，用于调试模块 。同 FPI_DEBUG_LEVEL_TRACE


//#if (defined LOG_TRACE_ALL) ||(defined LOG_TRACE)
//#define FDEBUG_DEFAULT_LEVEL LOG_LEVEL_TRACE 
//#else
//#ifdef DEFINE_SITA_LINUX
//#define FDEBUG_DEFAULT_LEVEL LOG_LEVEL_INFO
//#else
#define FDEBUG_DEFAULT_LEVEL LOG_LEVEL_INFO
//#endif
//#endif

#define TAG_TEST_TCLI_LOG ""

typedef struct
{
    EN_MODEL_ID_T id;
	const char *pCmdStr;
    uint8_t u8Level ;
    void (*pSubFun)( unsigned char *u8Para ) ;
}stLogList;

uint32_t fpi_get_log_list( stLogList **list ) ;

fpi_bool log_is_outfile(EN_MODEL_ID_T model_id,uint8_t level) ;
fpi_bool log_is_output(EN_MODEL_ID_T model_id,uint8_t level) ;
void set_log_level(const char *CmdStr, uint8_t *u8Para)  ;
fpi_bool log_is_outprintf( void ) ;
fpi_bool log_is_to_clog( void );
const char * log_get_cmd(EN_MODEL_ID_T model_id) ;


void tprint(const char *str,...);

//#define fpi_printf(fmt,arg...) {if(log_is_outprintf(){fpi_printfs(fmt,##arg);} }
//#define LOG_TOPC(tag,fmt,arg...) {if(log_is_topc() )clog_printf(tag,CLOG_LOGLVL_CLI,fmt,##arg);else fpi_printf(fmt, ##arg);}
//#define log_to_tlog(id,level,fmt,arg...){if(log_is_to_clog() )tos_log_printfs("sita",log_get_cmd(id),level,fmt,##arg);else fpi_printf(fmt, ##arg);} 
#define log_to_tlog(id,level,fmt,arg...){tos_log_printfs("sita",log_get_cmd(id),level,fmt,##arg);} 

//#define log_to_tlog(id,level,fmt,arg...){ printf(fmt, ##arg);} 

#define TVH_TAG //fpi_printf("[sita]")
//#ifdef DEBUG_LEVEL_TRACE

#define log_trace(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_TRACE) ){ \
                                 log_to_tlog(model,TOSLOG_LOGLVL_VERBOSE,fmt,##arg);} \
                                 if(log_is_outfile(model,LOG_LEVEL_TRACE) ){fpi_log_printf(log_get_cmd(model),LOG_LEVEL_TRACE,fmt, ##arg);} } 
#define log_debug(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_DEBUG) ){ \
                                 log_to_tlog(model,TOSLOG_LOGLVL_DEBUG,fmt,##arg);} \
                                 if(log_is_outfile(model,LOG_LEVEL_DEBUG) ){fpi_log_printf(log_get_cmd(model),LOG_LEVEL_DEBUG,fmt, ##arg);} } 								 
#define log_info(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_INFO) ){ \
                                log_to_tlog(model,TOSLOG_LOGLVL_INFO,fmt,##arg);} \
                                if(log_is_outfile(model,LOG_LEVEL_INFO) ){fpi_log_printf(log_get_cmd(model),LOG_LEVEL_INFO,fmt, ##arg);}}

#define log_warn(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_WARN) ){ \
                                log_to_tlog(model,TOSLOG_LOGLVL_WARN,fmt,##arg) ;}\
                                if(log_is_outfile(model,LOG_LEVEL_WARN) ){fpi_log_printf(log_get_cmd(model),LOG_LEVEL_WARN,fmt, ##arg); }}
#define log_alarm(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_ALARM) ){\
                                log_to_tlog(model,TOSLOG_LOGLVL_WARN,fmt,##arg);} \
                                if(log_is_outfile(model,LOG_LEVEL_ALARM) ){fpi_log_printf(log_get_cmd(model),LOG_LEVEL_ALARM,fmt, ##arg); }}
#define log_error(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_ERROR) ){ \
                                log_to_tlog(model,TOSLOG_LOGLVL_ERROR,fmt,##arg) ;}\
                                if(log_is_outfile(model,LOG_LEVEL_ERROR) ){fpi_log_printf(log_get_cmd(model),LOG_LEVEL_ERROR,fmt, ##arg); }}
#define log_fatal(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_FATAL) ){\
                                log_to_tlog(model,TOSLOG_LOGLVL_FATAL,fmt,##arg);} \
                                if(log_is_outfile(model,LOG_LEVEL_FATAL) ){fpi_log_printf(log_get_cmd(model),LOG_LEVEL_FATAL,fmt, ##arg); }}

#define soc_log_trace(tag,fmt,arg){ if(log_is_output(SITA_MODULE_SOC,LOG_LEVEL_TRACE) ){ \
                                 tos_log_vprintfs("sita.soc",tag,TOSLOG_LOGLVL_VERBOSE,fmt,arg);} } 

#define soc_log_debug(tag,fmt,arg){ if(log_is_output(SITA_MODULE_SOC,LOG_LEVEL_DEBUG) ){ \
                                 tos_log_vprintfs("sita.soc",tag,TOSLOG_LOGLVL_DEBUG,fmt,arg);} } 

#define soc_log_info(tag,fmt,arg){ if(log_is_output(SITA_MODULE_SOC,LOG_LEVEL_INFO) ){ \
                                 tos_log_vprintfs("sita.soc",tag,TOSLOG_LOGLVL_INFO,fmt,arg);} } 

#define soc_log_warn(tag,fmt,arg){ if(log_is_output(SITA_MODULE_SOC,LOG_LEVEL_WARN) ){ \
                                 tos_log_vprintfs("sita.soc",tag,TOSLOG_LOGLVL_WARN,fmt,arg);} } 

#define soc_log_error(tag,fmt,arg){ if(log_is_output(SITA_MODULE_SOC,LOG_LEVEL_ERROR) ){ \
                                 tos_log_vprintfs("sita.soc",tag,TOSLOG_LOGLVL_ERROR,fmt,arg);} } 

#define soc_log_fatal(tag,fmt,arg){ if(log_is_output(SITA_MODULE_SOC,LOG_LEVEL_FATAL) ){ \
                                 tos_log_vprintfs("sita.soc",tag,TOSLOG_LOGLVL_FATAL,fmt,arg);}  } 
								 
#define log_assert(model,expr)  \
    if (!(expr)) { \
        tos_log_printfs("sita",log_get_cmd(model),TOSLOG_LOGLVL_ERROR,"Assertion FAILED in '%s', line %d, func %s ('%s')\n", \
               __FILE__, __LINE__,__FUNCTION__, #expr);  \
    }do{}while(0)


//#endif

/*
#ifdef DEBUG_LEVEL_INFO
#define log_trace(model, fmt, arg...) (void)0
#define log_info(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_INFO) )fpi_printf(fmt, ##arg);}
#define log_warn(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_WARN) )fpi_printf(fmt, ##arg);}
#define log_alarm(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_ALARM) )fpi_printf(fmt, ##arg);}
#define log_error(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_ERROR) )fpi_printf(fmt, ##arg);}
#define log_fatal(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_FATAL) )fpi_printf(fmt, ##arg);}
#endif

#ifdef DEBUG_LEVEL_WARN
#define log_trace(model, fmt, arg...) (void)0
#define log_info(model, fmt, arg...) (void)0
#define log_warn(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_WARN) )fpi_printf(fmt, ##arg);}
#define log_alarm(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_ALARM) )fpi_printf(fmt, ##arg);}
#define log_error(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_ERROR) )fpi_printf(fmt, ##arg);}
#define log_fatal(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_FATAL) )fpi_printf(fmt, ##arg);}
#endif

#ifdef DEBUG_LEVEL_ALARM
#define log_trace(model, fmt, arg...) (void)0
#define log_info(model, fmt, arg...)  (void)0
#define log_warn(model, fmt, arg...)  (void)0
#define log_alarm(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_ALARM) )fpi_printf(fmt, ##arg);}
#define log_error(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_ERROR) )fpi_printf(fmt, ##arg);}
#define log_fatal(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_FATAL) )fpi_printf(fmt, ##arg);}
#endif

#ifdef DEBUG_LEVEL_ERROR
#define log_trace(model, fmt, arg...) (void)0
#define log_info(model, fmt, arg...)  (void)0
#define log_warn(model, fmt, arg...)  (void)0
#define log_alarm(model, fmt, arg...) (void)0
#define log_error(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_ERROR) )fpi_printf(fmt, ##arg);}
#define log_fatal(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_FATAL) )fpi_printf(fmt, ##arg);}

#endif

#ifdef DEBUG_LEVEL_FATAL
#define log_trace(model, fmt, arg...) (void)0
#define log_info(model, fmt, arg...)  (void)0
#define log_warn(model, fmt, arg...) (void)0
#define log_alarm(model, fmt, arg...) (void)0
#define log_error(model, fmt, arg...) (void)0
#define log_fatal(model, fmt, arg...) { if(log_is_output(model,LOG_LEVEL_FATAL) )fpi_printf(fmt, ##arg);}

#endif

#ifdef DEBUG_LEVEL_OFF
#define log_trace(model, fmt, arg...) (void)0
#define log_info(model, fmt, arg...)  (void)0
#define log_warn(model, fmt, arg...) (void)0
#define log_alarm(model, fmt, arg...) (void)0
#define log_error(model, fmt, arg...) (void)0
#define log_fatal(model, fmt, arg...) (void)0
#endif

*/

//-----------------sbinder log-----------------------
/*
#ifdef DEBUG_LEVEL_TRACE
#define slog_trace(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_info(fmt, arg...)  fpi_printf(fmt, ##arg)
#define slog_warn(fmt, arg...)  fpi_printf(fmt, ##arg)
#define slog_alarm(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_error(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_fatal(fmt, arg...) fpi_printf(fmt, ##arg)
#endif

#ifdef DEBUG_LEVEL_INFO
#define slog_trace(fmt, arg...) (void)0

#define slog_info(fmt, arg...)  fpi_printf(fmt, ##arg)
#define slog_warn(fmt, arg...)  fpi_printf(fmt, ##arg)
#define slog_alarm(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_error(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_fatal(fmt, arg...) fpi_printf(fmt, ##arg)

#endif  

#ifdef DEBUG_LEVEL_WARN
#define slog_trace(fmt, arg...) (void)0
#define slog_info(fmt, arg...)  (void)0
#define slog_warn(fmt, arg...)  fpi_printf(fmt, ##arg)
#define slog_alarm(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_error(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_fatal(fmt, arg...) fpi_printf(fmt, ##arg)

#endif

#ifdef DEBUG_LEVEL_ALARM
#define slog_trace(fmt, arg...) (void)0
#define slog_info(fmt, arg...)  (void)0
#define slog_warn(fmt, arg...)  (void)0
#define slog_alarm(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_error(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_fatal(fmt, arg...) fpi_printf(fmt, ##arg)

#endif

#ifdef DEBUG_LEVEL_ERROR
#define slog_trace(fmt, arg...) (void)0
#define slog_info(fmt, arg...)  (void)0
#define slog_warn(fmt, arg...)  (void)0
#define slog_alarm(fmt, arg...) (void)0
#define slog_error(fmt, arg...) fpi_printf(fmt, ##arg)
#define slog_fatal(fmt, arg...) fpi_printf(fmt, ##arg)


#endif

#ifdef DEBUG_LEVEL_FATAL
#define slog_trace(fmt, arg...) (void)0
#define slog_info(fmt, arg...)  (void)0
#define slog_warn(fmt, arg...)  (void)0
#define slog_alarm(fmt, arg...) (void)0
#define slog_error(fmt, arg...) (void)0
#define slog_fatal(fmt, arg...) fpi_printf(fmt, ##arg)


#endif

#ifdef DEBUG_LEVEL_OFF
#define slog_trace(fmt, arg...) (void)0
#define slog_info(fmt, arg...)  (void)0
#define slog_warn(fmt, arg...)  (void)0
#define slog_alarm(fmt, arg...) (void)0
#define slog_error(fmt, arg...) (void)0
#define slog_fatal(fmt, arg...) (void)0
#endif
*/




uint8_t sub_log_subtitle_get_level( void ) ;





typedef struct
{
	const char *pCmdStr;
    void (*pSubFun)( unsigned char *u8Para ) ;
}stTestList;

void tvh_add_test_model(EN_MODEL_ID_T id, stTestList *cmd) ;

//静态局部变量在程序一运行就分配空间，不占用堆栈空间 
#define ADD_TEST(x,y) {static stTestList st_cmd = {x,y};tvh_add_test_model(g_model_id, &st_cmd);}



void soc_log_printf(const char* tag,int level,const char* format,...);







#endif
