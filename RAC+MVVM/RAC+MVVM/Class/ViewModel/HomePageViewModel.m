//
//  HomePageViewModel.m
//  RAC+MVVM
//
//  Created by More on 2018/1/15.
//  Copyright © 2018年 More. All rights reserved.
//

#import "HomePageViewModel.h"

#import "XMGHttpManager.h"
#import "XMGNetworkManager.h"
#import "cellItem.h"
#import "MJExtension.h"
#import "TableViewCell.h"
#import "HomeCellViewModel.h"


static NSString*const ID  =@"home";
@interface HomePageViewModel()<UITableViewDelegate,UITableViewDataSource>

@property(nonatomic,strong)NSArray *recommandCellVMs;



@end


@implementation HomePageViewModel

-(RACCommand*)loadHomeDataCommand{
    
    if (_loadHomeDataCommand == nil) {
        
        _loadHomeDataCommand = [[RACCommand alloc]initWithSignalBlock:^RACSignal * _Nonnull(id  _Nullable input) {
            return [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber){
                
                NSString*url = [XMGNetworkManager urlWithHome];
                
                NSDictionary *param = [XMGNetworkManager paramWithHome];
                
                [XMGHttpManager POST:url parameters:param progress:nil success:^(NSURLSessionDataTask *task, id responseObject) {
                    
                    NSDictionary *result = responseObject[@"result"];
                    NSDictionary *recommendDic = result[@"recommends"];
                    NSArray *recommends;
                    recommends = [cellItem mj_objectArrayWithKeyValuesArray:recommendDic[@"courses"]];
                    
                    _recommandCellVMs =[[recommends.rac_sequence map:^id _Nullable(id  _Nullable value) {
                       HomeCellViewModel *cellVM = [[HomeCellViewModel alloc]init];
                        cellVM.items = value;
                        return cellVM;
                    }]array];
                    
                    [subscriber sendNext:recommends];
                    [subscriber sendCompleted];
                    
                    
                    
                } failure:^(NSURLSessionDataTask *task, NSError *error) {
                    
                    [subscriber sendError:error];
                }];
                
                return nil;
            }];
        }];
        
    }
    return _loadHomeDataCommand;
}


-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return  self.recommandCellVMs.count;
}
-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    TableViewCell*cell = [tableView dequeueReusableCellWithIdentifier:ID];
    HomeCellViewModel*cellVm = self.recommandCellVMs[indexPath.row];
    [cellVm bindViewModel:cell];
    return  cell;
}
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 100;
}

-(void)bindViewModel:(UIView *)bindView{
    
    UITableView *tableView =(UITableView*)bindView;
    [tableView registerNib:[UINib nibWithNibName:@"TableViewCell" bundle:nil] forCellReuseIdentifier:ID];
    tableView.dataSource = self;
    tableView.delegate =self;
}
@end
