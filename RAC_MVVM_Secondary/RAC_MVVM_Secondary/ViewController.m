//
//  ViewController.m
//  RAC_MVVM_Secondary
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import "ViewController.h"

#import "showMessageView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    
   
    
    [showMessageView showSuccessWithMessage:@"加载失败"];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        
        [showMessageView dismissSuccessView:@"加载成功..."];
       
    });

   
    
    

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
