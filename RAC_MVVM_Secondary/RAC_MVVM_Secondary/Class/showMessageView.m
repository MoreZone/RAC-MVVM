//
//  showMessageView.m
//  RAC_MVVM_Secondary
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import "showMessageView.h"
#import<MMProgressHUD/MMProgressHUD.h>

@implementation showMessageView

+(void)showErrorWithMessage:(NSString *)message{
    
    [MMProgressHUD setPresentationStyle:MMProgressHUDPresentationStyleSwingRight];
    [MMProgressHUD setDisplayStyle:MMProgressHUDDisplayStyleBordered];
    [MMProgressHUD dismissWithError:nil title:message afterDelay:2.0];
}
+(void)showSuccessWithMessage:(NSString *)message{
    
    [MMProgressHUD setPresentationStyle:MMProgressHUDPresentationStyleSwingRight];
    [MMProgressHUD setDisplayStyle:MMProgressHUDDisplayStyleBordered];
    [MMProgressHUD dismissWithSuccess:nil title:message afterDelay:2.0];
}

+(void)showStatusWithMessage:(NSString *)message{
    
    [MMProgressHUD setPresentationStyle:MMProgressHUDPresentationStyleDrop];
    [MMProgressHUD showWithTitle:nil status:message];
}
+(void)dismissSuccessView:(NSString *)message{
    [MMProgressHUD dismissWithSuccess:message];
}
+(void)dismissErrorView:(NSString *)message{
    [MMProgressHUD dismissWithError:message];
}


@end
