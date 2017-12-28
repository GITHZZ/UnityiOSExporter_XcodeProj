//
//  SsjjCoreNavBarLeftView.h
//  4399CoreSdk
//
//  Created by 4399 on 14-8-26.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SsjjCoreNavBarLeftViewBtnType) {
    SsjjCoreNavBarLeftViewBtnTypeBack,
    SsjjCoreNavBarLeftViewBtnTypeForward,
    SsjjCoreNavBarLeftViewBtnTypeRefresh,
    SsjjCoreNavBarLeftViewBtnTypeHome,
};

@protocol SsjjCoreNavBarLeftViewDelegate <NSObject>

- (void)webViewNavBarLeftViewEvent:(SsjjCoreNavBarLeftViewBtnType)buttonType;

@end

@interface SsjjCoreNavBarLeftView : UIView


@property(nonatomic,retain)UIButton *backBtn;
@property(nonatomic,retain)UIButton *forwardBtn;
@property(nonatomic,retain)UIButton *refreshBtn;
@property(nonatomic,retain)UIButton *homeBtn;

@property(nonatomic,assign)id<SsjjCoreNavBarLeftViewDelegate> navBarEventDelegate;

- (void)validateNavBarLeftViewItem:(SsjjCoreNavBarLeftViewBtnType)buttonType;
- (void)invalidateNavBarLeftViewItem:(SsjjCoreNavBarLeftViewBtnType)buttonType;

- (void)startRefreshAnimation:(BOOL)isAnimation;

@end
