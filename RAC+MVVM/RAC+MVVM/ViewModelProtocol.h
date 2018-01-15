//
//  ViewModelProtocol.h
//  RAC+MVVM
//
//  Created by More on 2018/1/15.
//  Copyright © 2018年 More. All rights reserved.
//

@protocol ViewModelProtocol <NSObject>

@optional
- (void)bindViewModel:(UIView *)bindView;

@end
