//
//  SsjjCoreLoginView.h
//  SsjjCoreViewDemo
//
//  Created by 4399 on 6/11/14.
//  Copyright (c) 2014 ChrisXu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SsjjCoreButtonItem.h"
#import "MHTextField.h"
#import "JYTextField.h"
#import "ComboBoxView.h"
#import "SsjjCoreContentView.h"

@interface SsjjCoreLoginView : SsjjCoreContentView{
    BOOL isOpened;
    
    
}

@property (strong, nonatomic)  JYTextField          *userNameTextField;
@property (strong, nonatomic)  JYTextField          *passwordTextField;
@property (retain, nonatomic)  UIButton             *dropDownUserAccountListButton;
@property (retain, nonatomic)  UIImageView          *dropListImageView;

@property (retain, nonatomic)  UIButton             *showPassworkTextButton;
@property (retain, nonatomic)  UIImageView             *showPassworkTextImage;

@property (retain, nonatomic)  UITextField          *inputTextField;
@property (retain, nonatomic)  ComboBoxView         *userAccountTable;
@property (retain, nonatomic)  UIButton             *tryButton;         //马上试玩
@property (retain, nonatomic)  UIButton             *registerButton;    //注册按钮
@property (retain, nonatomic)  SsjjCoreButtonItem   *thirdPartyLoginBtn;    //第三方登录按钮,台湾,韩国会用到
@property (retain, nonatomic)  SsjjCoreButtonItem   *loginButtonItem;
@property (nonatomic, copy)  dispatch_block_t       registerButtonBlock;
@property (nonatomic, copy)  dispatch_block_t       guestButtonBlock;

@property(nonatomic,retain)NSMutableArray *comboBoxDatasource;
@property(nonatomic,assign)NSInteger objectIndex;

@property(nonatomic,copy)TouchCellBlock touchBlcok;
@property(nonatomic,copy)DeleteAccountBlcok deleteAccountBlcok;

//登录事件处理按钮事件处理
- (void)setLoginHander:(SsjjCoreCxButtonHandler)loginHander;

-(void)initWithDeleteAccountBlock:(DeleteAccountBlcok)deleteAccountBlock;
-(void)initWithTouchCellBlock:(TouchCellBlock)touchCellBlock; //处理登录出错后的账户密码显示。（清除自动登陆船不显示*）

- (void)setUserTextFeild:(NSString *)userName passTextField:(NSString *)passWord;
- (void)hideLoginKeyBoard;
- (void)clearTextField;
- (void)hideUserAccountTable;
- (void)addThirdPartyLoginBtn;
- (void)hideDropDownBtn:(BOOL)isHide;
- (void)changeUserTexifieldFrame:(BOOL)isChange;

- (void)hideshowPassworkTextButton:(BOOL)isHide;

/**
 *  还原明暗文切换按钮的初始状态
 */
- (void)returnPassworkBtnToOriginalStatus;

- (void)changeOpenStatus;

@end
