//
//  SsjjJMSDKSelectView.h
//  4399CoreSdk
//
//  Created by xianxian on 16/7/5.
//  Copyright © 2016年 4399. All rights reserved.
//

#import "SsjjJMContentView.h"
#import "SsjjJMSDKSelectCell.h"

typedef void(^SsjjJMSDKAddAccountBlock)(void);
typedef void(^SsjjJMSDKChangeAccountBlock)(NSDictionary *accountDictionary);

@interface SsjjJMSDKSelectView : SsjjJMContentView<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic,strong) UITableView *accountTableView;

@property (nonatomic,strong) UIView *bgView;

@property (nonatomic,copy) NSMutableArray *accountArray;//帐号数据源

@property (nonatomic,copy) SsjjJMSDKAddAccountBlock addAccountBlock;

@property (nonatomic,copy) SsjjJMSDKChangeAccountBlock changeAccountBlock;

@end
