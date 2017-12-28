//
//  SsjjCoreLoginView.h
//  SsjjCoreViewDemo
//
//  Created by 4399 on 6/11/14.
//  Copyright (c) 2014 ChrisXu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SsjjCoreButtonItem.h"
#import "JYTextField.h"
#import "SsjjCoreContentView.h"

@interface SsjjCoreLoginbindAccountView : SsjjCoreContentView

@property (strong, nonatomic)  JYTextField          *userNameTextField;
@property (strong, nonatomic)  JYTextField          *passwordTextField;

@property (retain, nonatomic)  UIButton             *showPassworkTextButton;
@property (retain, nonatomic)  UIImageView             *showPassworkTextImage;

@property (retain, nonatomic)  SsjjCoreButtonItem   *loginBindButtonItem;

@property (nonatomic, copy)  dispatch_block_t     registerBindButtonBlock;

//登录事件处理按钮事件处理
- (void)setLoginBindHander:(SsjjCoreCxButtonHandler)bindHander;

- (void)clearTextField;

- (void)hideLoginbindAccountViewKeyboard;



@end
