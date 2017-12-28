//
//  SsjjCoreViewCenter.h
//  4399CoreSdk
//
//  Created by 4399sy-tangwu on 14-7-8.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SsjjCoreDialog.h"
#import "SsjjCoreLoginView.h"
#import "SsjjCoreRegisterView.h"
#import "SsjjCorePhoneRegisterView.h"
#import "SsjjCoreRegisterOptionView.h"
#import "SsjjCoreVerificationView.h"
#import "SsjjCoreLoginbindAccountView.h"
#import "SsjjCoreRegbindAccountView.h"
#import "SsjjCorePhoneRegisterLoginView.h"

@interface SsjjCoreViewCenter : NSObject
{
    SsjjCoreDialog              *view;
    SsjjCoreLoginView           *loginView;
    SsjjCoreRegisterView        *registerView;
    SsjjCorePhoneRegisterView   *phoneRegisterView;
    SsjjCoreRegisterOptionView  *optionView;
    SsjjCoreVerificationView    *verificationView;
    SsjjCoreLoginbindAccountView   *loginBindView;
    SsjjCoreRegbindAccountView    *regBindView;
    NSMutableArray              *viewStack;
  
}
@property (nonatomic, retain) SsjjCoreDialog                *view;
@property (nonatomic, retain) SsjjCoreLoginView             *loginView;
@property (nonatomic, retain) SsjjCoreRegisterView          *registerView;
@property (nonatomic, retain) SsjjCorePhoneRegisterView     *phoneRegisterView;
@property (nonatomic, retain) SsjjCoreRegisterOptionView    *optionView;
@property (nonatomic, retain) SsjjCoreVerificationView      *verificationView;
@property (nonatomic, retain) SsjjCoreRegbindAccountView    *regBindView;
@property (nonatomic, retain) SsjjCorePhoneRegisterLoginView   *phoneRegisterLoginView;
@property (nonatomic, retain) SsjjCoreLoginbindAccountView  *loginBindView;
@property (nonatomic, retain) NSMutableArray                *viewStack;
@property(nonatomic,assign)BOOL isHideTryBtn;
@property(nonatomic,assign)BOOL isChangeFrame;

- (void)changeFrameStatus:(BOOL)isChangeFrame;

- (void) showLoginView;

- (void) showRegisterView;

- (void) showPhoneRegisterView;

- (void) showRegisterOptionView;

- (void) showRegBindView;

- (void) showLoginBindView;

- (void) showVerificationViewWithCodeUrl:(NSString *)codeURL;

- (void) showPhoneRegisterLoginView;

- (void) removeGetIdentifyingCodeButton;

//- (void) hideLoginViewTryBtn:(BOOL)isHide;


/*
 * 弹出一个视图
 */
- (void) popView;

// 关闭sdk
- (void) closeSdk;


- (void)hideSsjjCoreViewCenter:(BOOL)isHide;
/*
 * @param position是位置，如果是负数则表示从后往前数的位置,例如-1表示栈顶的视图
 */
- (SsjjCoreContentView *) viewFromStack: (int) position;

+ (instancetype)sharedInstance;
@end
