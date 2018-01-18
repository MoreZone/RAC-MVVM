//
//  LogView.m
//  RAC+MVVM-LOGIN
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import "LogView.h"

@implementation LogView

+(instancetype)shwoView{
    
    return [[[NSBundle mainBundle]loadNibNamed:@"LogView" owner:nil options:nil]firstObject];
}

-(void)layoutSubviews{
    
    [super layoutSubviews];
}

-(void)awakeFromNib{
    
    [super awakeFromNib];
    
}

@end
