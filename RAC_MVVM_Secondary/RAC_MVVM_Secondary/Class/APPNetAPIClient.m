//
//  APPNetAPIClient.m
//  RAC_MVVM_Secondary
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import "APPNetAPIClient.h"

@implementation APPNetAPIClient
+(instancetype)sharedClient{
    static APPNetAPIClient *_sharedClient =nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedClient =[[APPNetAPIClient alloc]init];
        _sharedClient.securityPolicy = [AFSecurityPolicy policyWithPinningMode:AFSSLPinningModeNone];
    });
    return _sharedClient;
}

@end
