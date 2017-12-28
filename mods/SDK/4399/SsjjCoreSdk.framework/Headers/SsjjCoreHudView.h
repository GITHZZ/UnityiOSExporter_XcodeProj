//
//  SsjjCoreHudView.h
//  4399CoreSdk
//
//  Created by 4399 on 14-7-16.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MBProgressHUD.h"

typedef void(^SsjjCoreHudViewChangeAcountBlock)();

//typedef NS_ENUM(NSInteger, SsjjCoreHudViewType) {
//    SsjjCoreHudViewTypeLoginComplete = 0,       //登录成功后的HUD
//    SsjjCoreHudViewTypeLoginWaiting = 1,        //登录等待的HUD
//};

@interface SsjjCoreHudView : NSObject


@property(nonatomic,copy)SsjjCoreHudViewChangeAcountBlock acountBlock;

-(MBProgressHUD *)loginCompleteHUD:(UIView *)view
                              userName:(NSString *)userName;

-(MBProgressHUD *)loginWaitingHUD:(UIView *)view userName:(NSString *)userName isTempAccount:(BOOL)isTempAccount;

- (MBProgressHUD *)defaultProgressHud:(UIView *)view title:(NSString *)title;

@end
