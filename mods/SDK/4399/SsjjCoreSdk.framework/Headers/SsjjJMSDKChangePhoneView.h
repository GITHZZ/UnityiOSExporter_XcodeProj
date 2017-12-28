//
//  SsjjJMSDKChangePhoneView.h
//  4399CoreSdk
//
//  Created by xianxian on 16/8/16.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SsjjJMContentView.h"
#import "SsjjJMAccountCell.h"

typedef void(^SsjjChangePhoneBlock)(NSString *phone);
typedef void(^SsjjChangeAccountBlock)(void);
typedef void(^SsjjLogoutPhoneBlock)(NSString *phone);

@interface SsjjJMSDKChangePhoneView : SsjjJMContentView

@property (nonatomic,strong) UILabel *titleLabel;

@property (nonatomic,strong) SsjjJMAccountCell *accountCell;
@property (nonatomic,strong) UIButton *changeButton;
@property (nonatomic,strong) UIButton *logoutButton;

@property (nonatomic,strong) UIView *bgView;
@property (nonatomic,strong) UIButton *changeAccountButton;

@property (nonatomic,copy) SsjjChangePhoneBlock changeBlock;

@property (nonatomic,copy) SsjjChangeAccountBlock changeAccountBlock;

@property (nonatomic,copy) SsjjLogoutPhoneBlock logoutBlock;

@end
