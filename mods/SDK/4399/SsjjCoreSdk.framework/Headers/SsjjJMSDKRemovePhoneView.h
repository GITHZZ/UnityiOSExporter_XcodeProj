//
//  SsjjJMSDKRemovePhoneView.h
//  4399CoreSdk
//
//  Created by xianxian on 16/7/5.
//  Copyright © 2016年 4399. All rights reserved.
//

#import "SsjjJMContentView.h"
#import "SsjjJMSDKTextField.h"
#import "SsjjJMSDKCaptcheButton.h"

typedef void(^SsjjUnbindPhoneBlock)(NSString *phone,NSString *captcha);
typedef void(^SsjjGetsmsBlock)(NSString *phone);

@interface SsjjJMSDKRemovePhoneView : SsjjJMContentView <UITextFieldDelegate>

@property (nonatomic,strong) UILabel *phoneLabel;
@property (nonatomic,strong) UILabel *unbindLabel;
@property (nonatomic,strong) UITextField *captchaTextField;
@property (nonatomic,strong) SsjjJMSDKCaptcheButton *getCaptchaButton;
@property (nonatomic,strong) UIButton *unbindPhoneButton;

@property (nonatomic,copy) SsjjUnbindPhoneBlock unbindBlock;
@property (nonatomic,copy) SsjjGetsmsBlock getsmsBlock;

@property (nonatomic,strong) UIView *bgView;

@property (nonatomic,strong) UILabel *noticoLabel;

@property (nonatomic,copy) NSString *removePhone;

@end
