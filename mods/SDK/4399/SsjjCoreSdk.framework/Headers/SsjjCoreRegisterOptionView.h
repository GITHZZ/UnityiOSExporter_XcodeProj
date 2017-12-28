//
//  SsjjCoreLoginView.h
//  SsjjCoreViewDemo
//
//  Created by 4399 on 6/11/14.
//  Copyright (c) 2014 ChrisXu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SsjjCoreButtonItem.h"
#import "SsjjCoreContentView.h"

@interface SsjjCoreRegisterOptionView : SsjjCoreContentView

@property (retain, nonatomic)  SsjjCoreButtonItem     *phoneRegisterButton;
@property (retain, nonatomic)  SsjjCoreButtonItem     *userNameRegisterButton;
@property (retain, nonatomic)  UILabel               *registerProtocalAgreementLabel;
@property (nonatomic, copy)  dispatch_block_t       existAccountButtonBlock;
@property (nonatomic, copy)  dispatch_block_t       protoButtonBlock;
@property(nonatomic,assign)BOOL isSelect;

// 对注册选择的按钮事件处理
- (void)setPhoneRegisterHander:(SsjjCoreCxButtonHandler)phoneHandler;
- (void)setUserNameRegisterHander:(SsjjCoreCxButtonHandler)userNameHandler;


@end
