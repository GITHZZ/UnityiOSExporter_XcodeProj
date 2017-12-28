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
#import "ComboBoxView.h"
#import "SsjjCoreContentView.h"

@interface SsjjCorePhoneRegisterView : SsjjCoreContentView{
    BOOL isOpened;
    NSTimer *timer;
    NSInteger _timeCount;
}

@property (strong, nonatomic)  JYTextField          *phoneNumberTextField;
//@property (strong, nonatomic)  JYTextField          *passwordTextField;
//@property (strong, nonatomic)  JYTextField          *identifyingCodeTextField;
@property (retain, nonatomic)  UIButton             *getIdentifyingCodeButton;
@property (retain, nonatomic)  UIButton             *showPassworkTextButton;
@property (retain, nonatomic)  UIImageView             *showPassworkTextImage;
@property (copy, nonatomic)    dispatch_block_t         getIdentifyingCodeButtonBlock;


@property(copy ,nonatomic)  dispatch_block_t userNameRegisterBlock;
@property (copy, nonatomic)  dispatch_block_t phoneRegBlock;
//
//- (void)setLoginHander:(SsjjCoreCxButtonHandler)loginHandler;
//- (void)clearTextField;
//- (void)hideRegisterViewKeyboard;

@end
