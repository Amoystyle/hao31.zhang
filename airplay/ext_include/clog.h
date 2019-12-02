/**@defgroup 日志输出模块
@{

@brief 用于日志输出

@deprecated 废弃，请使用tos_log模块,同时删除所有说明

@version 1.0.0 2015/01/04 初稿
@version 1.0.1 2015/10/10 废弃
*/
#ifndef __CLOG_H__
#define __CLOG_H__

#include "sita_defines.h"
#include <stdarg.h>
#include "tos_log.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CLOGV(...)   (TOSLOGV(__VA_ARGS__))
#define CLOGD(...)   (TOSLOGD(__VA_ARGS__))
#define CLOGI(...)   (TOSLOGI(__VA_ARGS__))
#define CLOGW(...)   (TOSLOGW(__VA_ARGS__))
#define CLOGE(...)   (TOSLOGE(__VA_ARGS__))
#define CLOGF(...)   (TOSLOGF(__VA_ARGS__))
#define CLOGCLI(...)   (TOSLOGI(__VA_ARGS__))

#define CLOGW_WITHCODE(...)  (TOSLOGW_WITHCODE(__VA_ARGS__))  
#define CLOGE_WITHCODE(...)  (TOSLOGE_WITHCODE(__VA_ARGS__))  
#define CLOGF_WITHCODE(...)  (TOSLOGF_WITHCODE(__VA_ARGS__))  
#define CLOG_ASSERT(...)  	 TOSLOG_ASSERT(__VA_ARGS__)

typedef enum CLOG_LOGLEVEL{
	CLOG_LOGLVL_UNKNOWN,
    CLOG_LOGLVL_VERBOSE,            
    CLOG_LOGLVL_DEBUG,              
    CLOG_LOGLVL_INFO,               
    CLOG_LOGLVL_WARN,               
    CLOG_LOGLVL_ERROR,              
    CLOG_LOGLVL_FATAL,              
    CLOG_LOGLVL_CLI,                
    CLOG_LOGLVL_SILENT = 0xFF       
} CLOG_LOGLEVEL;

//#define clog_printf(...)		(tos_log_printf(__VA_ARGS__))

#define clog_vprintf(...)		(tos_log_vprintf(__VA_ARGS__))

#ifdef __cplusplus
}
#endif
/** @} */
#endif
