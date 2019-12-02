/**@defgroup 定义SITA中的基本类型及错误代码
@{

@version 1.0.0 2015/01/08 初稿
*/
#ifndef __SITA_ERROR_H__
#define __SITA_ERROR_H__


#ifdef __cplusplus
extern "C" {
#endif

#define SITA_ERROR_COMMON   0       ///< 通用模块错误段
#define SITA_ERROR_CEC      100       ///< CEC模块通用段

#define SITA_SUCCESS        (0)     ///< 成功
#define SITA_FAILED         (-(SITA_ERROR_COMMON)-1)   ///< 通用错误或者其它错误
#define SITA_ASSERT         (-(SITA_ERROR_COMMON)-2)    ///< 代码错误,产生了断言
#define SITA_ENOMEM         (-(SITA_ERROR_COMMON)-3)    ///< 内存不足错误
#define SITA_ETIMEDOUT      (-(SITA_ERROR_COMMON)-4)    ///< 超时错误
#define SITA_EINVAL         (-(SITA_ERROR_COMMON)-5)    ///< 参数错误
#define SITA_EAGAIN         (-(SITA_ERROR_COMMON)-6)    ///< 请稍后重试错误
#define SITA_ESTATUS        (-(SITA_ERROR_COMMON)-7)    ///< 状态错误


#define SITA_CEC_EFRAME     (-(SITA_ERROR_CEC)-1)       ///< CEC模块帧错误



#define SITA_MIN(a,b) (((a)<(b))?(a):(b)) ///< Get the min
#define SITA_MAX(a,b) (((a)>(b))?(a):(b)) ///< Get the max

#ifdef __cplusplus
}
#endif
/** @} */
#endif
