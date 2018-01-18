//
//  ViewController.m
//  RAC+MVVM-LOGIN
//
//  Created by More on 2018/1/18.
//  Copyright © 2018年 More. All rights reserved.
//

#import "ViewController.h"
#import "LogView.h"
#import "ViewModel.h"

@interface ViewController ()

@property(nonatomic,strong)ViewModel*viewmodel;

@end

@implementation ViewController

-(ViewModel*)viewmodel{
    if (_viewmodel==nil) {
        _viewmodel =[[ViewModel alloc]init];
    }
    return _viewmodel;
}
- (void)viewDidLoad {

    [super viewDidLoad];
    
    [self makeUI];
    
}

-(void)makeUI{
    
    LogView *views = [LogView shwoView];
    [self.view addSubview:views];
    @weakify(self);
    RAC(self.viewmodel,userName) =views.nameField.rac_textSignal;
    RAC(self.viewmodel,password) = views.passField.rac_textSignal;
    views.logButton.rac_command = self.viewmodel.logRacommand;
    [[self.viewmodel.logRacommand executionSignals]subscribeNext:^(id  _Nullable x) {
        @strongify(self);
        // command  里面还是信号 发送回来的是个信号 需要重新解析
        // 或者用另外的com的那个方法
        //NSLog(@"%@",x);
        [x subscribeNext:^(id  _Nullable x) {
            NSLog(@"%@",x);
        }];
    } error:^(NSError * _Nullable error) {
        
    }];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
