/**@defgroup 命令行模块
@{

@brief 通过命令行,调用中间件服务端及客户端的函数,用于中间件的调试等.

@version 1.0.0 2015/02/04 初稿
*/
#ifndef __TCLI_H__
#define __TCLI_H__


#ifdef __cplusplus
extern "C" {
#endif

#define TOS_TCLI_MAX_ARGS   10  ///< 最大参数数量,即最多支持多少个参数
    
#define TOS_TCLI_CMD_MAX_LEN    1024    ///< 一条命令的最大长度


#if defined(__GNUC__)

/**
@brief 自动添加TCLI函数命令的宏,在代码的任意位置使用该宏实现自动注册.

添加后,可通过tcli命令行工具使用该命令,执行对应的函数.
这些函数只能有int或者char*类型的参数,且参数须在argParse中描述,参数的最大个数目前为10个.

@note 调用者需保证所有的字符串一直有效.
@note 在func中的打印,建议使用tos_tcli_printf输出到TCLI工具上.

@code 示例代码
static void run_my_cmd(int i,char* s)
{
//any thing here
}
TOS_TCLI_COMMAND(mycmd,"short help of mycmd","long help\nof mycmd","is",run_my_cmd);//out of function, it will auto run.
@endcode

@param[in] name 命令名称
@param[in] shortHelp 简短帮助,使用help命令列出所有命令时,简短帮助会列到命令的后面.
@param[in] longHelp 详细帮助,使用help 命令名称命令时,会列出这些信息.
@param[in] argParse 有s(表示字符串)和i(表示整数)组成的参数描述符.如"isi"表示命令函数的第一个参数为int,第二个为const char*,第三个为int.
@param[in] func 执行此语句的函数.
*/
#define TOS_TCLI_COMMAND(name, shortHelp, longHelp, argParse, func) \
    __attribute__((constructor)) static void TCLICMD_##func(){tos_tcli_addCommand(#name, shortHelp, longHelp, argParse, (void*)func);}

/**
@brief 自动添加TCLI int型控制命令宏,在代码的任意位置使用该宏实现自动注册.

添加之后可以直接使用以下命令查看,修改这个int变量的值:
- intTarget : 查看*target的值
- intTarget = value : 将*target赋值为value

@note 调用者需保证所有的字符串一直有效.

@code 示例代码
static int s_currentValue = 0;
TOS_TCLI_INTERGER(s_currentValue,"short help of s_currentValue","long help\nof s_currentValue");
@endcode

@param[in] intTarget 待控制的变量名,必须是一个int类型(或者兼容的),且必须是静态/全局变量,即此变量要求一直有效.
@param[in] shortHelp 简短帮助,使用help命令列出所有命令时,简短帮助会列到命令的后面.
@param[in] longHelp 详细帮助,使用help 命令名称命令时,会列出这些信息.
*/
#define TOS_TCLI_INTERGER(intTarget, shortHelp, longHelp) \
    static void TCLIINTERGER_##intTarget_cmdfunc(char* opt,int value) {    \
        if(opt != NULL && strcmp(opt,"=") == 0) {   \
            tos_tcli_printf("%s:%d ==> %d\n",#intTarget,(intTarget),value);  \
            (intTarget) = value;    \
        }else { \
            tos_tcli_printf("%s=%d\n",#intTarget,(intTarget)); \
        } \
    };\
    __attribute__((constructor)) static void TCLIINTERGER_##intTarget(){tos_tcli_addCommand(#intTarget, "[int value]"shortHelp, longHelp"\nType '"#intTarget"' to show its value\nType '"#intTarget" = v' to set its value to v", "si",(void*)TCLIINTERGER_##intTarget_cmdfunc);}
#else
#error TOS_TCLI_COMMAND() for this configuration must be defined
#error TOS_TCLI_INTERGER() for this configuration must be defined
#endif

/**
@brief 交互输出回调函数定义

当命令执行时,若需要输出执行信息(如开始执行了,执行结果等),TCLI会调用此函数,用于在CLI交互时输出.
*/
typedef void (*tos_tcli_onOutput)(const char* prompt,void* userdata);

/**
@brief 在命令执行函数中,使用此接口输出执行交互过程.

实际会调用到tos_tcli_execute函数out参数执行的函数用于输出,同时也会在CLOG输出.

@note 仅能在命令执行函数中调用.

@param[in] format 日志内容,支持printf中的%d等参数
*/
void tos_tcli_printf(const char* fmt,...);

/**
@brief 添加一个命令到TCLI中

@note 调用者须保证所有参数在函数返回后一直有效，建议通过TOS_TCLI_COMMAND等调用，而不是直接使用本函数

一般情况下,请通过TOS_TCLI_COMMAND调用,不建议直接使用本接口.
@return return 成功返回0,失败返回<0的错误代码.
*/
int tos_tcli_addCommand(const char* name,const char *shortHelp,const char *longHelp,const char *argParse, void *func);


/**
@brief 执行一条TCLI命令

@param[in] cmd 命令字符串,utf8格式.
@param[in] out 交互输出回调函数,命令执行过程中需要交互时会将交互信息通过此函数发出.
@return return 成功返回0,失败返回<0的错误代码.
*/
int tos_tcli_execute(const char* cmd,tos_tcli_onOutput out,void* userdata);

/**
@brief 执行一条TCLI命令

@param[in] argc 命令参数数量
@param[in] argv 命令或参数,其中argv[0]必须为命令,后面的为参数
@param[in] out 交互输出回调函数,命令执行过程中需要交互时会将交互信息通过此函数发出.
@return return 成功返回0,失败返回<0的错误代码.
*/
int tos_tcli_executeByargs(int argc,const char* argv[],tos_tcli_onOutput out,void* userdata);



#ifdef __cplusplus
}
#endif
/** @} */
#endif
