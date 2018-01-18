//
//  APPNetAPIClient.h
//  RAC_MVVM_Secondary
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>


@interface APPNetAPIClient : AFHTTPSessionManager

+(instancetype)sharedClient;



@end
