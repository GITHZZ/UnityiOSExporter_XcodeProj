//
//  SsjjJMSDKImageCaptchaView.h
//  4399CoreSdk
//
//  Created by xianxian on 16/9/1.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <SsjjCoreSdk/4399CoreSdk.h>
#import "SsjjJMContentView.h"

typedef void(^SsjjJMSDKSubmitImageCaptcha)(NSString *imageCaptcha);

@interface SsjjJMSDKImageCaptchaView : SsjjJMContentView

@property (nonatomic,strong) UITextField *imageCaptchaTextField;
@property (nonatomic,strong) UIImageView *imageCatcha;
@property (nonatomic,strong) UIButton *submitButton;

@property (nonatomic,strong) UIView *bgView;
@property (nonatomic,strong) UIButton *refreshButton;
@property (nonatomic,strong) UILabel *imageCaptchaLabel;

@property (nonatomic,copy) SsjjJMSDKSubmitImageCaptcha submitBlock;

@property (nonatomic,copy) NSString *captchaUrl;

-(void)refreshCaptcha;

@end
