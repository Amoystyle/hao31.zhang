#ifndef __FPI_DEBUG_HELPER_H__
#define __FPI_DEBUG_HELPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "fpi_log.h"




#if USE_CLOG
#include "clog.h"

#undef fpi_printf
//#define fpi_printf  CLOGI
#define fpi_printf(...)


#define FUNCTION_TO_BE_DONE     fpi_info("%s is to be done!!\n", __FUNCTION__)


#define fpi_trace(fmt, arg...)  TOSLOGV(fmt, ##arg)
#define fpi_debug(fmt, arg...)  TOSLOGD(fmt, ##arg)
#define fpi_info(fmt, arg...)   TOSLOGI(fmt, ##arg)
#define fpi_warn(fmt, arg...)   TOSLOGW(fmt, ##arg)
#define fpi_alarm(fmt, arg...)  TOSLOGW(fmt, ##arg)
#define fpi_err(fmt, arg...)  TOSLOGE(fmt, ##arg)
#define fpi_err_code(err_code,fmt, arg...)  TOSLOGE("<ERR:%x>"#fmt,(err_code), ##arg)
#define fpi_fatal(fmt, arg...)  TOSLOGF(fmt, ##arg)


#define PRINTF_RUN_TIME(x)		TOSLOGI(x)

#else

#undef fpi_printf
#ifdef NDK_COMPILING
#include <stdarg.h>
#include <android/log.h>
#ifndef LOG_TAG
#define LOG_TAG     "sitatvservice"
#endif

#define fpi_printf(...) //__android_log_print(ANDROID_LOG_FATAL,LOG_TAG, __VA_ARGS__)
//#define fpi_printf(fmt,arg...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG, fmt,##arg)

#else
//#define fpi_printf  printf
#define fpi_printf(...)
#endif

//#ifdef NDK_COMPILING
/*
#define fpi_trace(fmt, arg...)  fpi_printf(fmt, ##arg)
#define fpi_info(fmt, arg...)   fpi_printf(fmt, ##arg)
#define fpi_warn(fmt, arg...)   fpi_printf(fmt, ##arg)
#define fpi_alarm(fmt, arg...)  fpi_printf(fmt, ##arg)
#define fpi_err(fmt, arg...)  fpi_printf(fmt, ##arg)
#define fpi_fatal(fmt, arg...)  fpi_printf(fmt, ##arg)
*/
//#else
#ifdef USER_PRINT
#define fpi_trace(fmt, arg...)	printf(fmt, ##arg)
#define fpi_debug(fmt, arg...)  printf(fmt, ##arg)
#define fpi_info(fmt, arg...)   printf(fmt, ##arg)
#define fpi_warn(fmt, arg...)	printf(fmt, ##arg)
#define fpi_alarm(fmt, arg...)	printf(fmt, ##arg)
#define fpi_err(fmt, arg...)  printf(fmt, ##arg)
#define fpi_err_code(err_code,fmt, arg...) printf("<ERR:%x>"#fmt,(err_code), ##arg)
#define fpi_fatal(fmt, arg...)	printf(fmt, ##arg)
#else
#define fpi_trace(fmt, arg...)  log_trace(g_model_id,fmt, ##arg)
#define fpi_debug(fmt, arg...)  log_debug(g_model_id,fmt, ##arg)
#define fpi_info(fmt, arg...)  log_info(g_model_id,fmt, ##arg)
#define fpi_warn(fmt, arg...)   log_warn(g_model_id,fmt, ##arg)
#define fpi_alarm(fmt, arg...)  log_alarm(g_model_id,fmt, ##arg)
#define fpi_err(fmt, arg...)  log_error(g_model_id,fmt, ##arg)
#define fpi_err_code TOSLOGE_WITHCODE//log_error(g_model_id,"<ERR:%x>"#fmt,(err_code), ##arg)
#define fpi_fatal(fmt, arg...)  log_fatal(g_model_id,fmt, ##arg)
#endif
//#endif /*#ifdef NDK_COMPILING*/
#define FPI_ASSERT(expr) log_assert(g_model_id,expr)

#define CURRENT_MODEL_NAME() log_get_cmd(CURRENT_MODEL_ID)

#define FUNCTION_TO_BE_DONE     fpi_info("%s is to be done!!\n", __FUNCTION__)

#define fpi_assert(x)	\
	if(!(x))\
	{\
		fpi_err("FILE: %s, LINE: %d, function: %s, assert failed\n", __FILE__, __LINE__, __FUNCTION__);\
		while(1);\
	}

#define PRINTF_RUN_TIME(x)  {struct timespec times;\
        clock_gettime(CLOCK_MONOTONIC, &times); \
        fpi_info("*%s*times(s)=%ld.%06ld\n",x,times.tv_sec,times.tv_nsec/1000 );}


#define FPI_CIPLUS 1
#define MHEG5_ENABLED 1
#define HBBTV_IWEDIA_ENABLED 1
#define SUBTITLE_ENABLED 1
#define FPI_CIPLUS 1
#define CIPLUS_HSS_INCLUDED 1   //CIPUS 需要，CI 不需要
#define CIPLUS_AMMI_INCLUDED 1  //CIPUS 需要，CI 不需要

#if 0

#define FPI_DEBUG_LEVEL_TRACE		0
#define FPI_DEBUG_LEVEL_WARN		1
#define FPI_DEBUG_LEVEL_ALARM		2
#define FPI_DEBUG_LEVEL_ERROR		3
#define FPI_DEBUG_LEVEL_FATAL		4

//#define FPI_DEBUG_LEVEL 0



#if (FPI_DEBUG_LEVEL==FPI_DEBUG_LEVEL_TRACE)
	/*fpi_trace level */
	#define fpi_trace(fmt, arg...)  fpi_printf(fmt, ##arg)
	#define fpi_warn(fmt, arg...)   fpi_printf(fmt, ##arg)
	#define fpi_alarm(fmt, arg...)  fpi_printf(fmt, ##arg)
	#define fpi_err(fmt, arg...)  fpi_printf(fmt, ##arg)
	#define fpi_fatal(fmt, arg...)  fpi_printf(fmt, ##arg)
#elif (FPI_DEBUG_LEVEL==FPI_DEBUG_LEVEL_WARN)
	/*fpi_warn  level */
	#define fpi_trace(fmt, arg...)  (void)0
	#define fpi_warn(fmt, arg...)   fpi_printf(fmt, ##arg)
	#define fpi_alarm(fmt, arg...)  fpi_printf(fmt, ##arg)
	#define fpi_err(fmt, arg...)  fpi_printf(fmt, ##arg)
	#define fpi_fatal(fmt, arg...)  fpi_printf(fmt, ##arg)

#elif (FPI_DEBUG_LEVEL==FPI_DEBUG_LEVEL_ALARM)
	/*fpi_alarm  level */
	#define fpi_trace(fmt, arg...)  (void)0
	#define fpi_warn(fmt, arg...)   (void)0
	#define fpi_alarm(fmt, arg...)  fpi_printf(fmt, ##arg)
	#define fpi_err(fmt, arg...)  fpi_printf(fmt, ##arg)
	#define fpi_fatal(fmt, arg...)  fpi_printf(fmt, ##arg)

#elif (FPI_DEBUG_LEVEL==FPI_DEBUG_LEVEL_ERROR)
	/*fpi_error  level */
	#define fpi_trace(fmt, arg...)  (void)0
	#define fpi_warn(fmt, arg...)   (void)0
	#define fpi_alarm(fmt, arg...)  (void)0
	#define fpi_err(fmt, arg...)  fpi_printf(fmt, ##arg)
	#define fpi_fatal(fmt, arg...)  fpi_printf(fmt, ##arg)

#elif (FPI_DEBUG_LEVEL==FPI_DEBUG_LEVEL_FATAL)
	/*fpi_fatal  level */
	#define fpi_trace(fmt, arg...)  (void)0
	#define fpi_warn(fmt, arg...)   (void)0
	#define fpi_alarm(fmt, arg...)  (void)0
	#define fpi_err(fmt, arg...)  (void)0
	#define fpi_fatal(fmt, arg...)  fpi_printf(fmt, ##arg)
				
#else
	#define fpi_trace(fmt, arg...)  (void)0
	#define fpi_warn(fmt, arg...)   (void)0
	#define fpi_alarm(fmt, arg...)  (void)0
	#define fpi_err(fmt, arg...)  (void)0
	#define fpi_fatal(fmt, arg...)  (void)0
#endif 

#endif

#endif





#ifdef __cplusplus
}
#endif


#endif
