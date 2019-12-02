/**@defgroup ������ģ��
@{

@brief ͨ��������,�����м������˼��ͻ��˵ĺ���,�����м���ĵ��Ե�.

@version 1.0.0 2015/02/04 ����
*/
#ifndef __TCLI_H__
#define __TCLI_H__


#ifdef __cplusplus
extern "C" {
#endif

#define TOS_TCLI_MAX_ARGS   10  ///< ����������,�����֧�ֶ��ٸ�����
    
#define TOS_TCLI_CMD_MAX_LEN    1024    ///< һ���������󳤶�


#if defined(__GNUC__)

/**
@brief �Զ����TCLI��������ĺ�,�ڴ��������λ��ʹ�øú�ʵ���Զ�ע��.

��Ӻ�,��ͨ��tcli�����й���ʹ�ø�����,ִ�ж�Ӧ�ĺ���.
��Щ����ֻ����int����char*���͵Ĳ���,�Ҳ�������argParse������,������������ĿǰΪ10��.

@note �������豣֤���е��ַ���һֱ��Ч.
@note ��func�еĴ�ӡ,����ʹ��tos_tcli_printf�����TCLI������.

@code ʾ������
static void run_my_cmd(int i,char* s)
{
//any thing here
}
TOS_TCLI_COMMAND(mycmd,"short help of mycmd","long help\nof mycmd","is",run_my_cmd);//out of function, it will auto run.
@endcode

@param[in] name ��������
@param[in] shortHelp ��̰���,ʹ��help�����г���������ʱ,��̰������е�����ĺ���.
@param[in] longHelp ��ϸ����,ʹ��help ������������ʱ,���г���Щ��Ϣ.
@param[in] argParse ��s(��ʾ�ַ���)��i(��ʾ����)��ɵĲ���������.��"isi"��ʾ������ĵ�һ������Ϊint,�ڶ���Ϊconst char*,������Ϊint.
@param[in] func ִ�д����ĺ���.
*/
#define TOS_TCLI_COMMAND(name, shortHelp, longHelp, argParse, func) \
    __attribute__((constructor)) static void TCLICMD_##func(){tos_tcli_addCommand(#name, shortHelp, longHelp, argParse, (void*)func);}

/**
@brief �Զ����TCLI int�Ϳ��������,�ڴ��������λ��ʹ�øú�ʵ���Զ�ע��.

���֮�����ֱ��ʹ����������鿴,�޸����int������ֵ:
- intTarget : �鿴*target��ֵ
- intTarget = value : ��*target��ֵΪvalue

@note �������豣֤���е��ַ���һֱ��Ч.

@code ʾ������
static int s_currentValue = 0;
TOS_TCLI_INTERGER(s_currentValue,"short help of s_currentValue","long help\nof s_currentValue");
@endcode

@param[in] intTarget �����Ƶı�����,������һ��int����(���߼��ݵ�),�ұ����Ǿ�̬/ȫ�ֱ���,���˱���Ҫ��һֱ��Ч.
@param[in] shortHelp ��̰���,ʹ��help�����г���������ʱ,��̰������е�����ĺ���.
@param[in] longHelp ��ϸ����,ʹ��help ������������ʱ,���г���Щ��Ϣ.
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
@brief ��������ص���������

������ִ��ʱ,����Ҫ���ִ����Ϣ(�翪ʼִ����,ִ�н����),TCLI����ô˺���,������CLI����ʱ���.
*/
typedef void (*tos_tcli_onOutput)(const char* prompt,void* userdata);

/**
@brief ������ִ�к�����,ʹ�ô˽ӿ����ִ�н�������.

ʵ�ʻ���õ�tos_tcli_execute����out����ִ�еĺ����������,ͬʱҲ����CLOG���.

@note ����������ִ�к����е���.

@param[in] format ��־����,֧��printf�е�%d�Ȳ���
*/
void tos_tcli_printf(const char* fmt,...);

/**
@brief ���һ�����TCLI��

@note �������뱣֤���в����ں������غ�һֱ��Ч������ͨ��TOS_TCLI_COMMAND�ȵ��ã�������ֱ��ʹ�ñ�����

һ�������,��ͨ��TOS_TCLI_COMMAND����,������ֱ��ʹ�ñ��ӿ�.
@return return �ɹ�����0,ʧ�ܷ���<0�Ĵ������.
*/
int tos_tcli_addCommand(const char* name,const char *shortHelp,const char *longHelp,const char *argParse, void *func);


/**
@brief ִ��һ��TCLI����

@param[in] cmd �����ַ���,utf8��ʽ.
@param[in] out ��������ص�����,����ִ�й�������Ҫ����ʱ�Ὣ������Ϣͨ���˺�������.
@return return �ɹ�����0,ʧ�ܷ���<0�Ĵ������.
*/
int tos_tcli_execute(const char* cmd,tos_tcli_onOutput out,void* userdata);

/**
@brief ִ��һ��TCLI����

@param[in] argc �����������
@param[in] argv ��������,����argv[0]����Ϊ����,�����Ϊ����
@param[in] out ��������ص�����,����ִ�й�������Ҫ����ʱ�Ὣ������Ϣͨ���˺�������.
@return return �ɹ�����0,ʧ�ܷ���<0�Ĵ������.
*/
int tos_tcli_executeByargs(int argc,const char* argv[],tos_tcli_onOutput out,void* userdata);



#ifdef __cplusplus
}
#endif
/** @} */
#endif
