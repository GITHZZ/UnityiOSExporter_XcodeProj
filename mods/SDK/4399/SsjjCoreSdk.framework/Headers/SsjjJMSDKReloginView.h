//
//  SsjjJMSDKReloginView.h
//  4399CoreSdk
//
//  Created by xianxian on 16/9/2.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <SsjjCoreSdk/4399CoreSdk.h>
#import "SsjjJMContentView.h"
#import "SsjjJMSDKTextField.h"
#import "SsjjJMSDKCaptcheButton.h"

typedef void(^SsjjPhoneReloginBlock)(NSString *captcha);
typedef void(^SsjjReloginGetsmsBlock)(void);
typedef void(^SsjjAnotherAccountLoginBlock)(void);

@interface SsjjJMSDKReloginView : SsjjJMContentView

@property (nonatomic,strong) UIView *bgView;
@property (nonatomic,strong) UILabel *bindPhoneLabel;
@property (nonatomic,strong) UILabel *phoneLabel;
@property (nonatomic,strong) UILabel *captchaLabel;
@property (nonatomic,strong) UITextField *captchaTextField;
@property (nonatomic,strong) SsjjJMSDKCaptcheButton *getCaptchaButton;
@property (nonatomic,strong) UIButton *phoneLoginButton;
@property (nonatomic,strong) UIButton *anotherLoginButton;

@property (nonatomic,copy) SsjjPhoneReloginBlock loginBlock;
@property (nonatomic,copy) SsjjReloginGetsmsBlock getsmsBlock;
@property (nonatomic,copy) SsjjAnotherAccountLoginBlock anotherAcountLoginBlock;

@end
