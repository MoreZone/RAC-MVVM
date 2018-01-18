//
//  showMessageView.h
//  RAC_MVVM_Secondary
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface showMessageView : NSObject

/** 展示错误信息*/
+(void)showErrorWithMessage:(NSString*)message;

/** 展示成功信息*/
+(void)showSuccessWithMessage:(NSString*)message;

/** 展示提交状态*/
+(void)showStatusWithMessage:(NSString*)message;


+(void)dismissSuccessView:(NSString*)message;
+(void)dismissErrorView:(NSString*)message;












@end
