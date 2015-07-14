 
namespace cpp org.ssdut.sipesc.network.types



// =============================== typedefs ====================================

/**
 * 时间戳，从以下时间到现在的秒数，
 *    January 1, 1970, 00:00:00 GMT
 *
 *
 */
typedef i64 Timestamp

typedef i64 Timespan

typedef string Text

typedef binary Bytes

typedef i32 ID


/**
 * 传送文件的大小限制，单个任务的输入输出文件不应该超出此大小的。
 * 目前是16M
 */
const i64 FILE_LEN_LIMIT = 16777216;


/**
* 函数调用的返回结果的状态码。
*/
enum ResultCode {
  Success = 0,
  TryLater=1,
  Error=2
}

/**
*函数调用的返回结果
*/
struct CallResult
{
    1: required ResultCode resultCode, /** 状态码*/
    2: optional Text message,  /** 可选的消息*/
    3: optional bool boolResult,  /** 函数返回是bool 类型*/
    4: optional byte byteResult,  /** 返回byte 类型*/
    5: optional i16  i16Result, /** 返回 i16 类型*/
    6: optional i32 i32Result, /** 返回 i32 类型*/
    7: optional i64 i64Result, /** 返回 i64 类型*/
    8: optional double doubleResult, /** 返回 double 类型*/
    9: optional string strResult, /** 返回 string 类型*/
    10: optional binary binResult /** 返回字节数组 类型*/
}


/**
* 函数调用异常 的错误码
*/
enum SipescErrorCode {
  UNKNOWN = 1,
  PERMISSION_DENIED = 2,
  DATA_REQUIRED = 3,
  INVALID_AUTH = 4,
  AUTH_EXPIRED = 5,
  UNSUPPORTED_OPERATION = 6
}

/**
*函数调用异常
*/
exception SipescException {
  1:  required  SipescErrorCode errorCode,
  2:  optional  Text  why
}

/**
*用户的权限级别
*/
enum PrivilegeLevel {
  NORMAL = 1,
  MANAGER = 3,
  ADMIN = 5
}



/**
*二进制数据
*/
struct Data {
  1:  optional  i64 size, /** 字节数*/
  2:  optional  Bytes content /** 内容*/
}

/**
*用户信息
*/
struct User {
  1:  optional  ID id,
  2:  required  string userName,
  3:  optional  string email,
  4:  optional  string name,
  5:  optional  PrivilegeLevel privilege, /** 用户权限级别*/
  6:  optional  Timestamp created,  
  8:  optional  string address,
  7:  optional  Text comments
}

/**
*用户信息
*/
struct PublicUserInfo {
  1:  required  ID userId,
  2:  optional  string username
}

/**
**认证结果
*/
struct AuthenticationResult {
  1:  required Timestamp currentTime, /** 服务器当前时间 */
  2:  required string authenticationToken, /** 认证的 token, 在执行其他操作时，用于验证身份 或者 权限*/
  3:  required Timestamp expiration,
  4:  optional User user
}


/**
*文件信息。
*/
/*
struct File {
  1:  required  string fileName,
  2:  optional  ID ownerId,
  3:  optional  ID taskId, //
  4:  optional  string serverFilePath,
  5:  optional  string clientFilePath,
  6:  optional  Timestamp created,
  7:  optional  i64 totalSize
}
*/

/**
*任务状态，有部分状态码留作将来使用。
*/
enum TaskStatus{
 NEW= 1, /** 新创建*/
 RUNNING = 2, /** 正在执行*/
 WAITTING = 3, /** 等待执行*/
 CANCELED = 4, /** 已取消*/
 DEAD=5, /** 已死亡*/
 SUCC=6, /** 成功*/
 ERROR=7, /** 出错*/
 WARNING= 8 /** 警告*/
}


/**
*任务结构体
*/
struct Task {
  1:  optional  ID taskId,  
  2:  optional  ID userId, /** 创建用户的id*/
  3:  optional  Timestamp createdTime,
  4:  optional  Timestamp startedTime,
  5:  optional  Timestamp stopedTime,
  6:  optional  Timestamp currentTime,
  7:  required  string rawCommand, /** 用户输入的原始命令，必需。*/
  8:  optional  list<string> inputFileNames, /**输入文件列表 */
  9:  optional  list<string> outputFileNames, /**输出文件列表 */
  10: optional  Text description,  /** 任务描述*/
  11: optional  TaskStatus status, /** 任务状态码*/
  12: optional  Text  statusComments, /** 针对状态的描述*/
  13: optional  ID previousTask, /**根据需要可以设计成list */
  14: optional  ID nextTask /**根据需要可以设计成list */
}

