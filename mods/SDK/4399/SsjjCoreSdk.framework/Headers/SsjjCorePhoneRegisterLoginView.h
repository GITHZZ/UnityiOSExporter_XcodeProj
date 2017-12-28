//
//  SsjjCorePhoneRegisterLoginView.h
//  4399CoreSdk
//
//  Created by 巨凯波 on 15/4/9.
//  Copyright (c) 2015年 4399. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SsjjCoreButtonItem.h"
#import "JYTextField.h"
#import "ComboBoxView.h"
#import "SsjjCoreContentView.h"

@interface SsjjCorePhoneRegisterLoginView : SsjjCoreContentView{
    BOOL isOpened;
    NSTimer *timer;
    NSInteger _timeCount;
}
@property (strong, nonatomic)  UITextView           *title;
@property (strong, nonatomic)  JYTextField          *passwordTextField;
@property (strong, nonatomic)  JYTextField          *identifyingCodeTextField;
//获取验证码按钮
@property (retain, nonatomic)  UIButton             *getIdentifyingCodeButton;
//显示密码
@property (retain, nonatomic)  UIButton             *showPassworkTextButton;
//密码框图片
@property (retain, nonatomic)  UIImageView             *showPassworkTextImage;
//重新获取验证码按钮
@property (copy, nonatomic)    dispatch_block_t         getIdentifyingCodeButtonBlock;
//登录
@property (retain, nonatomic)  SsjjCoreButtonItem   *loginButtonItem;
//用户名注册代码块
@property(copy ,nonatomic)dispatch_block_t userNameRegisterBlock;
//设置登录管理
- (void)setLoginHander:(SsjjCoreCxButtonHandler)loginHandler;
//清除文本框
- (void)clearTextField;

- (void)hideRegisterViewKeyboard;

//初始化定时器
-(void)initTimer:(NSInteger )timeCount;
@end
