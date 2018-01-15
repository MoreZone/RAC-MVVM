//
//  ViewController.m
//  RAC+MVVM
//
//  Created by More on 2018/1/15.
//  Copyright © 2018年 More. All rights reserved.
//

#import "ViewController.h"
#import "HomePageViewModel.h"

@interface ViewController ()

@property(nonatomic,strong)HomePageViewModel*models;

@end

@implementation ViewController

-(HomePageViewModel*)models{
    if (_models ==nil) {
        _models = [[HomePageViewModel alloc]init];
    }
    return _models;
}

- (void)viewDidLoad {

    [super viewDidLoad];

    [self makeData];
    
}

-(void)makeData{
    
    @weakify(self);
    [[self.models.loadHomeDataCommand execute:nil]subscribeNext:^(id  _Nullable x) {
        @strongify(self);
        [self.tableView reloadData];
    } error:^(NSError * _Nullable error) {
        
    }];
    [self.models bindViewModel:self.tableView];
    
}

- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];
}


@end
