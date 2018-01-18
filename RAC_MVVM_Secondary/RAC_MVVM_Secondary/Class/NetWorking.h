//
//  NetWorking.h
//  RAC_MVVM_Secondary
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/** 下载进度*/
typedef void(^DownLoadProgress)(int64_t bytesRead,int64_t totalBytesRead);


typedef DownLoadProgress GetProgress;
typedef DownLoadProgress PostPorgress;


/** 上传进度*/
typedef void(^UploadProgress)(int64_t bytesWritten,int64_t totalBytesWriteen);

typedef NS_ENUM(NSInteger,ResponseType){
    kResponseTypeJSON = 1,
    kResponseTypeXML =2,
    kResponseTypeData =3
};

typedef NS_ENUM(NSInteger,RequestType){
    kRequestTypeJSON =1,
    kRequestTypePlainText =2,
};

typedef NS_ENUM(NSInteger,NetworkStatus){
    kNetworkStatusUnknown = -1,
    kNetworkStatusNotReachable =0,
    kNetworkStatusReachableViaWWAN =1,// 2,3,4网络
    kNetworkStatusReachableViaWiFi =2//wifi
};

typedef NSURLSessionTask  URLSessionTask;

/** 请求成功回调*/
typedef void(^ResponseSuccess)(id response);

/** 失败回调*/
 typedef void(^ResponseFail)(NSError*error);

@interface NetWorking : NSObject

/** 设置默认网络接口*/
+(void)updateBaseUrl:(NSString*)baseUrl;
+(NSString*)baseUrl;

/** 设置请求时间*/
+(void)setTimeout:(NSTimeInterval)timeout;

/** 设置是否加载上次缓存*/
+ (void)obtainDataFromLocalWhenNetworkUnconnected:(BOOL)shouldObtain;

/** 默认请求不缓存  需要手动设置*/
+(void)cacheGetRequest:(BOOL)isCacheGet shoulCachePost:(BOOL)shouldCachePost;

/** 获取缓存大小*/
+(unsigned long long)totalCacheSize;

/**  清除缓存*/
+(void)clearCaches;

/** 开启或关闭接口打印信息*/
+(void)enableInterfaceDebug:(BOOL)isDebug;




/**
配置请求格式

 @param requestType  请求格式 默认JSON
 @param responseType  响应格式 默认JSON
 @param shouldAutoEncode  是否自动 url
 @param shouldCallbackOnCancelRequest   当取消请求时候 是否要回调 默认YES
 */
+(void)configRequestType:(RequestType)requestType
            responseType:(ResponseType)responseType
     shouldAutoEncodeUrl:(BOOL)shouldAutoEncode
 callbaceOnCancelRequest:(BOOL)shouldCallbackOnCancelRequest;
















@end
