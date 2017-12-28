//
//  SsjjJMSDKLoginView.h
//  4399CoreSdk
//
//  Created by xianxian on 16/7/5.
//  Copyright © 2016年 4399. All rights reserved.
//

#import "SsjjJMContentView.h"
#import "SsjjJMSDKTextField.h"
#import "SsjjJMSDKCaptcheButton.h"

typedef void(^SsjjPhoneLoginBlock)(NSString *phone,NSString *captcha);
typedef void(^SsjjGetsmsBlock)(NSString *phone);

@interface SsjjJMSDKLoginView : SsjjJMContentView<UITextFieldDelegate>

@property (nonatomic,strong) UITextField *phoneTextField;
@property (nonatomic,strong) UITextField *captchaTextField;
@property (nonatomic,strong) UILabel *phoneLabel;
@property (nonatomic,strong) SsjjJMSDKCaptcheButton *getCaptchaButton;
@property (nonatomic,strong) UIButton *phoneLoginButton;

@property (nonatomic,strong) UIView *bgView;
@property (nonatomic,strong) UILabel *captchaLabel;
@property (nonatomic,strong) UILabel *noticeLabel;

@property (nonatomic,copy) SsjjPhoneLoginBlock loginBlock;
@property (nonatomic,copy) SsjjGetsmsBlock getsmsBlock;

@end
