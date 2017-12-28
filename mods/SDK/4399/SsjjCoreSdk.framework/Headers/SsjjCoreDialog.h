//
//  SsjjCoreDialog.h
//  SsjjAdsSdk
//
//  Created by 4399sy-tangwu on 14-6-9.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "SsjjCoreContentView.h"
//#import "SsjjCoreDialogViewController.h"

typedef NS_ENUM(NSInteger, SsjjCoreDialogTransitionStyle) {
    SsjjCoreDialogTransitionStyleSliderFromBottom = 0,
};

typedef NS_ENUM(NSInteger, SsjjCoreContentTransition) {
    SsjjCoreContentTransitionNone = 0,      //没有动画
    SsjjCoreContentTransitionFromLeft = 1,  //从左边滑动到右边
    SsjjCoreContentTransitionFromRight = 2, //从左边滑动到右边
};

@class SsjjCoreDialogViewController;
typedef void(^CloseSDKBlock)(void);
@interface SsjjCoreDialog : UIView
{
    UIWindow                        *dialogWindow;
    SsjjCoreDialogTransitionStyle   transitionStyle;
    UIView                          *containerView;
    float                           boundWidth;     //对话框和屏幕边框的距离
    BOOL                            isSteup;        //标记是否已经构建过
    UIScrollView                    *topScrollView;
    UILabel                         *topHintLabel;
    
    UIButton *closeSDKBtn;
    UIImageView *closeSDKImageView;
    
}


@property (nonatomic, retain) UIWindow                      *dialogWindow;
@property (nonatomic, assign) SsjjCoreDialogTransitionStyle transitionStyle;
@property (nonatomic, retain) UIView                        *containerView;
@property (nonatomic, assign) float                         boundWidth;
@property (nonatomic, assign) BOOL                          isSteup;
@property (nonatomic, retain) UIScrollView                  *topScrollView;
@property (nonatomic, retain) UILabel                       *topHintLabel;      // 顶部指示条
@property (nonatomic, retain) UIButton                      *backViewButton;    // 返回按钮
@property (nonatomic, retain) UIImageView                   *titleImage;        // 标题图片
@property (nonatomic, retain) SsjjCoreContentView           *contentView;
@property (nonatomic, retain) UIScrollView                  *contentScrollView; //包含contentView
@property (nonatomic, assign) SsjjCoreContentTransition     contentTransition;
@property (nonatomic, retain) SsjjCoreDialogViewController  *viewController;
@property(nonatomic,copy)CloseSDKBlock  closeSDKBlock;
- (void) defaultSetting;

- (void) show;

//判断弹框是否可见
- (BOOL) isVisible;

- (void) setup;

- (void) setSubViewLocation;

- (CGRect) contentRect;

//- (void)initBackToAutoLoginBlcok:(BackToAutoLoginBlcok)backToAutoLoginBlcok;

- (void)hideCloseSDKBtn:(BOOL)isHide;
- (void)initCloseSDKBtn:(CloseSDKBlock)closeSDKBlock;



@end
