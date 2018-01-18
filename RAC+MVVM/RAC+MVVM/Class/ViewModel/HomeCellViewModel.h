//
//  HomeCellViewModel.h
//  RAC+MVVM
//
//  Created by More on 2018/1/15.
//  Copyright © 2018年 More. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ViewModelProtocol.h"

#import "cellItem.h"

@interface HomeCellViewModel : NSObject<ViewModelProtocol>

@property(nonatomic,strong)cellItem *items;

@end
