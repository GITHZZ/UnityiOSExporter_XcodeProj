//
//  SsjjSyJMSDKViewCenter.h
//  4399CoreSdk
//
//  Created by xianxian on 16/7/5.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SsjjJMSDKDialogView.h"
#import "SsjjJMSDKRemindBindPhoneView.h"
#import "SsjjJMSDKChangePhoneView.h"
#import "SsjjJMSDKBindPhoneView.h"
#import "SsjjJMSDKRemovePhoneView.h"
#import "SsjjJMSDKSelectView.h"
#import "SsjjJMSDKLoginView.h"
#import "SsjjJMSDKRebindPhoneView.h"
#import "SsjjJMSDKImageCaptchaView.h"
#import "SsjjJMSDKReloginView.h"

@interface SsjjJMSDKViewCenter : NSObject

@property (nonatomic,strong) SsjjJMSDKDialogView *view;
@property (nonatomic,strong) SsjjJMSDKRemindBindPhoneView *remindBindView;
@property (nonatomic,strong) SsjjJMSDKChangePhoneView *changePhoneView;
@property (nonatomic,strong) SsjjJMSDKBindPhoneView *bindPhoneView;
@property (nonatomic,strong) SsjjJMSDKRemovePhoneView *unbindPhoneView;
@property (nonatomic,strong) SsjjJMSDKSelectView *selectView;
@property (nonatomic,strong) SsjjJMSDKLoginView *loginView;
@property (nonatomic,strong) SsjjJMSDKRebindPhoneView *rebindPhoneView;
@property (nonatomic,strong) SsjjJMSDKImageCaptchaView *imageCaptchaView;
@property (nonatomic,strong) SsjjJMSDKReloginView *reloginView;

@property (nonatomic,strong) NSMutableArray *viewStack;

+(instancetype)shareInstance;

-(void)showRemindBindPhoneView;

-(void)showChangePhoneView;

-(void)showBindPhoneView;

-(void)showUnbindPhontView;

-(void)showChangeSelectView;

-(void)showLoginView;

-(void)showRebindPhoneView;

-(void)showImageCaptchaView;

-(void)showReloginView;

-(void)popView;

-(void)closeView;

@end
