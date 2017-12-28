//
//  SsjjCoreVerificationView.h
//  4399CoreSdk
//
//  Created by 4399 on 14-7-9.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import "SsjjCoreContentView.h"
#import "JYTextField.h"
#import "SsjjCoreContentView.h"
#import "SsjjCoreButtonItem.h"



@interface SsjjCoreVerificationView : SsjjCoreContentView

@property (strong, nonatomic)  JYTextField          *verficationCodeTextField;
@property (retain, nonatomic)  SsjjCoreButtonItem   *comfirmButtonItem;
@property(nonatomic,strong)    UIImageView          *verificationCode;
@property (nonatomic, copy)  dispatch_block_t       changeVerficationBlock;

- (instancetype)initWithFrame:(CGRect)frame VerificationCodeURL:(NSString *)codeURL;

//点击确认事件的方法
- (void)setComfirmHander:(SsjjCoreCxButtonHandler)comfirmHander;

//刷新验证码
- (void) refreshCodeImg;

//刷新验证码
- (void) refreshCodeImg: (NSString *)codeURL;

- (void)hideVerificationViewKeyboard;

@end
