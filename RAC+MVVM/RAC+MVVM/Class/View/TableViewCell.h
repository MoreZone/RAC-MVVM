//
//  TableViewCell.h
//  RAC+MVVM
//
//  Created by More on 2018/1/15.
//  Copyright © 2018年 More. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *imageViews;
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet UILabel *specLabel;
@property (weak, nonatomic) IBOutlet UIButton *buttons;

@end
