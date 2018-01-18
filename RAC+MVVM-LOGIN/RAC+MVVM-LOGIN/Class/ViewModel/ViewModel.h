//
//  ViewModel.h
//  RAC+MVVM-LOGIN
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ViewModel : NSObject

@property(nonatomic, copy) NSString *userName;
@property(nonatomic, copy) NSString *password;

@property(nonatomic,strong)RACCommand*logRacommand;


@end
