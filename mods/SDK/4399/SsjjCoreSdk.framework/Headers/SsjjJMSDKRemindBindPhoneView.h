//
//  SsjjJMSDKRemindBindPhoneView.h
//  4399CoreSdk
//
//  Created by xianxian on 16/7/13.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <SsjjCoreSdk/4399CoreSdk.h>
#import "SsjjJMContentView.h"
#import "SsjjJMAccountCell.h"

typedef void(^SsjjJMBindBlock)(void);
typedef void(^SsjjJMChangeAccountBlock)(void);

@interface SsjjJMSDKRemindBindPhoneView : SsjjJMContentView

@property (nonatomic,strong) UILabel *titleLabel;
@property (nonatomic,strong) UIView *topSeparateView;
@property (nonatomic,strong) SsjjJMAccountCell *accountCell;
@property (nonatomic,strong) UIButton *changeAccountButton;
@property (nonatomic,strong) UIButton *bindButton;
@property (nonatomic,strong) UIView *bgView;

@property (nonatomic,copy) SsjjJMBindBlock bindBlock;
@property (nonatomic,copy) SsjjJMChangeAccountBlock changeAccountBlock;

@end
