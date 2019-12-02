/*********************************************************************************************
* Filename	: fpi_log_file.h
* Author   	: LinShunda
* Description:   
* Version:   
* Function List:	
* 1. --------- 
* History: 	
* <author>  	  <time>   			<version >   <desc>	
* LinShunda    	2013-09-16 	 		1.0    	 	build this moudle  	
* Copyright	: TCL Electronics(Shen Zhen) Co.,Ltd.
********************************************************************************************/



#ifndef _FPI_FILE_LOG_H_
#define _FPI_FILE_LOG_H_




#ifdef __cplusplus
extern "C"
{
#endif


int fpi_log_file_init( void) ;
int fpi_log_file_close( void ) ;
void fpi_log_file_rm_all( void ) ;

int32_t fpi_log_file_set_path(char* str_path, int32_t i_len);
int32_t fpi_log_printf(const char* tag,int level,const char *format, ... );


#ifdef __cplusplus
}
#endif





#endif
