//
//  ViewModel.m
//  RAC+MVVM-LOGIN
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import "ViewModel.h"

@implementation ViewModel

-(instancetype)init{
    
    if (self = [super init]) {
        
        RACSignal *userNameLengthSig = [RACObserve(self, userName)
                                        map:^id(NSString *value) {
                                            if (value.length > 6) return @(YES);
                                            return @(NO);
                                        }];
        RACSignal *passwordLengthSig = [RACObserve(self, password)
                                        map:^id(NSString *value) {
                                            if (value.length > 6) return @(YES);
                                            return @(NO);
                                        }];
        
        RACSignal *loginBtnEnable = [RACSignal combineLatest:@[userNameLengthSig,passwordLengthSig]reduce:^id (NSNumber*userName,NSNumber*password){
            return @([userName boolValue]&&[password boolValue]);
        }];
        
        _logRacommand = [[RACCommand alloc]initWithEnabled:loginBtnEnable signalBlock:^RACSignal * _Nonnull(id  _Nullable input) {
            return [NetWork loginWithUserName:self.userName password:self.password];
        }];
        
        
    }
    return self;
}



@end
