//
//  SsjjJMSDKDialogView.h
//  4399CoreSdk
//
//  Created by xianxian on 16/7/12.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SsjjJMSDKDialogViewController.h"
#import "SsjjJMContentView.h"
#import "SsjjJMSDKDialogWindow.h"

typedef NS_ENUM(NSInteger,SsjjJMAnimationDirection) {
    SsjjJMAnimationNone = 0,
    SsjjJMAnimationToLeft = 1,
    SsjjJMAnimationToRight = 2
};

typedef void (^SsjjCloseBlock)(void);

@interface SsjjJMSDKDialogView : UIView

@property (nonatomic,strong) SsjjJMSDKDialogWindow *dialogWindow;
@property (nonatomic,strong) UIView *containerView;
@property (nonatomic,strong) UIScrollView *topScrollView;
@property (nonatomic,strong) UIView *topScrollContainerView;
@property (nonatomic,strong) UIButton *backButton;
@property (nonatomic,strong) UILabel *titleLabel;
@property (nonatomic,strong) UIButton *closeButton;
@property (nonatomic,strong) UIView *topSeparateView;
@property (nonatomic,strong) UILabel *warnView;
@property (nonatomic,strong) UILabel *msgLabel;
@property (nonatomic,strong) SsjjJMContentView *contentView;
@property (nonatomic,strong) UIScrollView *contentScrollView;
@property (nonatomic,strong) SsjjJMSDKDialogViewController *dialogController;
@property (nonatomic,assign) SsjjJMAnimationDirection animationDirecton;
@property (nonatomic,copy) SsjjCloseBlock closeBlock;

-(void)show;

-(void)showWarn:(NSString *)warnMsg;

-(void)showMsg:(NSString *)msg;

-(void)showHub;

-(void)hideHub;

-(CGRect)contentRect;

@end
