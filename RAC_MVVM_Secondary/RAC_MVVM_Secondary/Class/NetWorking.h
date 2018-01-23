//
//  NetWorking.h
//  RAC_MVVM_Secondary
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>



/**
 下载进度

 @param bytesRead 已经下载多少
 @param totalBytesRead 文件 总大小

 */
typedef void (^DownloadProgress)(int64_t bytesRead,int64_t totalBytesRead);

typedef DownloadProgress GetProgress;
typedef DownloadProgress PostProgress;

//上传进度
typedef void(^UploadProgress)(int64_t bytesWritten,int64_t totalBytesWritten);

typedef NS_ENUM(NSInteger,ResponseType){
    kResponseTypeJSON =1 ,
    kResponseTypeXML =2,
    kResponseTypeData =3
};

typedef NS_ENUM(NSInteger,RequestType) {
    kRequestTypeJSON = 1,
    kRequestTypePlainText = 2,
};

@class NSURLSessionTask;

typedef  NSURLSessionTask  URLSessionTask;


/**
 请求成功的回调

 @param response  服务端返回的数据类型,通常是字典
 */
typedef void(^ResponseSuccess)(id response);


/**
 网络响应失败的回调

 @param error  错误信息
 */
typedef void(^ResponseFail)(NSError *error);



@interface Networking:NSObject


/**
 用于指定网络请求接口的基础url

 @param baseUrl 网络接口基础url
 */
+(void)updateBaseUrl:(NSString*)baseUrl;


/**

 对外公开可获取当前所设置的网络接口基础url

 @return 当前基础url
 */
+(NSString*)baseUrl;

/**
 开启或关闭接口打印
 */
+(void)enableInterfaceDebug:(BOOL)isDebug;

/**
 配置返回的格式  默认JSON
 */
+(void)configResponseType:(ResponseType)responseType;

/**
 配置请求的格式
 */
+(void)configRequestType:(ResponseType)requestType;

/**
 *  开启或关闭是否自动将URL使用UTF8编码，用于处理链接中有中文时无法请求的问题

 */
+(void)shouldAutoEncodeUrl:(BOOL)shouldAutoEncode;

/**
     配置公共请求头 只调用一次
 *  @param httpHeaders 只需要将与服务器商定的固定参数设置即可

 */
+(void)configCommonHttpHeaders:(NSDictionary*)httpHeaders;



/**
 GET 请求  不指定baseurl 可传完整url

 @param url 接口路径
 @param success 接口成功请求到数据回调
 @param fail 接口请求数据失败的回调
 @return 返回对象中有可取消请求的API
 
 */
+(URLSessionTask*)getWithUrl:(NSString*)url
                     success:(ResponseSuccess)success
                        fail:(ResponseFail)fail;


+(URLSessionTask*)getWithUrl:(NSString*)url
                      params:(NSDictionary*)params
                     success:(ResponseSuccess)success
                        fail:(ResponseFail)fail;

+ (URLSessionTask *)getWithUrl:(NSString *)url
                        params:(NSDictionary *)params
                      progress:(GetProgress)progress
                       success:(ResponseSuccess)success
                          fail:(ResponseFail)fail;

// POST


/**
 POST 请求 不指定BaseURL 可传入完整url

 @param url 接口路径
 @param params 接口中参数
 @param success 接口成功请求到的数据回调
 @param fail 接口请求数据失败的回调
 @return  返回的对象中可取消请求的API
 */
+(URLSessionTask*)postWithUrl:(NSString*)url
                       params:(NSDictionary*)params
                      success:(ResponseSuccess)success
                         fail:(ResponseFail)fail;

+(URLSessionTask*)postWithUrl:(NSString*)url
                       params:(NSDictionary*)params
                     progress:(PostProgress)progress
                      success:(ResponseSuccess)success
                         fail:(ResponseFail)fail;

// 上传下载

/**
 图片上传接口

 @param image      图片对象
 @param url        上传图片接口的路径
 @param filename   图片名称
 @param name       后端指定名称
 @param mimeType   默认为image/jpeg
 @param parameters 参数
 @param progress   上传进度
 @param success    上传成功
 @param fail       失败回调
 @return           返回请求
 */
+ (URLSessionTask *)uploadWithImage:(UIImage *)image
                                url:(NSString *)url
                           filename:(NSString *)filename
                               name:(NSString *)name
                           mimeType:(NSString *)mimeType
                         parameters:(NSDictionary *)parameters
                           progress:(UploadProgress)progress
                            success:(ResponseSuccess)success
                               fail:(ResponseFail)fail;

 // 上传文件

/**
 上传文件

 @param url              文件路径
 @param uploadingFile    待上传文件路径
 @param progress         上传进度
 @param success          上传成功回调
 @param fail             上传失败回调
 @return                 返回URLSessionTask对象
 */
+ (URLSessionTask *)uploadFileWithUrl:(NSString *)url
                        uploadingFile:(NSString *)uploadingFile
                             progress:(UploadProgress)progress
                              success:(ResponseSuccess)success
                                 fail:(ResponseFail)fail;

/**
 下载文件

 @param url             下载URL
 @param saveToPath      下载到哪个路径下
 @param progressBlock   下载进度
 @param success         下载成功后的回调
 @param failure         下载失败后的回调
 @return  返回
 */
+ (URLSessionTask *)downloadWithUrl:(NSString *)url
                         saveToPath:(NSString *)saveToPath
                           progress:(DownloadProgress)progressBlock
                            success:(ResponseSuccess)success
                            failure:(ResponseFail)failure;

-(void)appendParWithFileData:(NSData*)data
                        name:(NSString*)name
                    fileName:(NSString*)fileName
                    mimeType:(NSString*)mimeType;

@end
