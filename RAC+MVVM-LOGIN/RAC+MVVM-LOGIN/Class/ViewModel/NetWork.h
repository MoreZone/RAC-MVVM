//
//  NetWork.h
//  RAC+MVVM-LOGIN
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetWork : NSObject

+ (RACSignal *)loginWithUserName:(NSString *) name password:(NSString *)password;

@end
