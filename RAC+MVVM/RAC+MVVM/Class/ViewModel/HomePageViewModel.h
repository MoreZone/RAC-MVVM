//
//  HomePageViewModel.h
//  RAC+MVVM
//
//  Created by More on 2018/1/15.
//  Copyright © 2018年 More. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ViewModelProtocol.h"

@interface HomePageViewModel : NSObject<ViewModelProtocol>
{
    RACCommand *_loadHomeDataCommand;
}


@property(nonatomic,strong,readonly)RACCommand *loadHomeDataCommand;





@end
