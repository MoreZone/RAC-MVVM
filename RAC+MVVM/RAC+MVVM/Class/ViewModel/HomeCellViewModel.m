//
//  HomeCellViewModel.m
//  RAC+MVVM
//
//  Created by More on 2018/1/15.
//  Copyright © 2018年 More. All rights reserved.
//

#import "HomeCellViewModel.h"
#import "TableViewCell.h"
#import "UIImageView+WebCache.h"


@implementation HomeCellViewModel

-(void)bindViewModel:(id)bindView{
    
    TableViewCell*cell = bindView;
    [cell.imageViews sd_setImageWithURL:[NSURL URLWithString:_items.courseImage]];
    cell.titleLabel.text = _items.courseName;
    [cell.buttons setTitle:_items.studentNum forState:UIControlStateNormal];
}

@end
