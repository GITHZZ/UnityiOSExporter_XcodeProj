//
//  SsjjSaveAccountView.h
//  4399CoreSdk
//
//  Created by xianxian on 16/7/6.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^SaveAccountBlock)();
typedef void (^EnterGameBlock)();

@interface SsjjSaveAccountView : UIView

@property (nonatomic,strong) UILabel *titleLabel;
@property (nonatomic,strong) UILabel *nameLabel;
@property (nonatomic,strong) UILabel *pswLabel;
@property (nonatomic,strong) UILabel *remindtextLabel;
@property (nonatomic,strong) UIButton *saveAccountButton;
@property (nonatomic,strong) UIButton *enterGameButton;

@property (nonatomic,copy) SaveAccountBlock saveAccountBlock;
@property (nonatomic,copy) EnterGameBlock   enterGameBlock;

- (instancetype)initWithFrame:(CGRect)frame;
- (void)setConstrains;

@end
