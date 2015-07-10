 


include "Types.thrift"


 
namespace cpp  org.ssdut.sipesc.network.service


/**
 * Service: 
 */
service NetworkService {
    
     /**
     测试能否通信。
     */
    Types.CallResult ping(),
    
    
  /** 登录到服务器
  */
  Types.AuthenticationResult login(1: string username, 2: string password) throws (1: Types.SipescException ex ),

  /**
  退出登录
  */
  void logout(1: string authenticationToken)
    throws (1: Types.SipescException ex ),
 
   /**
   更新会话
   */
  Types.AuthenticationResult refreshAuthentication(1: string authenticationToken)
    throws (1: Types.SipescException ex),

  /**
   获得当前账户信息
   */
  Types.User getUser(1: string authenticationToken)
    throws (1: Types.SipescException ex ),

   /**
   获得用户公开信息
   */
  Types.PublicUserInfo getPublicUserInfo(1: string username)
   throws (1: Types.SipescException ex ),
   
    
   /**
    *获得用户的指定任务信息。
   */
   Types.Task getTask(1: string authenticationToken, 2: Types.ID taskId)
     throws (1: Types.SipescException ex),
                
  
  /**
   * 获得当前用户的所有任务。
   */
   list<Types.Task> listTasks(1: string authenticationToken)
    throws (1: Types.SipescException ex),
    
    
    /**
    *提交一个任务
    */
  Types.CallResult postTask(1: string authenticationToken, 2: string rawCommand)
    throws (1: Types.SipescException ex ), 

  /**
  *上传一部分文件数据到服务器，用户目录下，这个版本用于不大的文件
  */
  i64 uploadFile(1: string authenticationToken, 2: string fileName, 3:i64 size, 4: Types.Bytes data)
   throws (1: Types.SipescException ex ), 
   
 
   /**
   删除服务器文件
   */
  Types.CallResult deleteFile(1: string authenticationToken, 2: string fileName)
    throws (1: Types.SipescException ex ),
    

    /**
    下载文件
    */
  Types.Bytes downloadFile(1: string authenticationToken, 2: string fileName)
      throws (1: Types.SipescException ex ), 

 
}
