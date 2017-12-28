//
//  SsjjCoreWebToolBar.h
//  4399CoreSdk
//
//  Created by 4399 on 14-8-25.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SsjjCoreToolBarItem.h"

@protocol SsjjCoreWebToolBarEventDelegate <NSObject>

- (void)webViewToolBarEvent:(SsjjCoreToolBarItemType)buttonType;

@end
@interface SsjjCoreWebToolBar : UIToolbar


@property(nonatomic,retain)SsjjCoreToolBarItem *backItem;
@property(nonatomic,retain)SsjjCoreToolBarItem *forwardItem;
@property(nonatomic,retain)SsjjCoreToolBarItem *refreshItem;
@property(nonatomic,retain)SsjjCoreToolBarItem *homeItem;
@property(nonatomic,assign)id<SsjjCoreWebToolBarEventDelegate> toolBarEventDelegate;

- (void)validateToolBarItem:(SsjjCoreToolBarItemType)buttonType;
- (void)invalidateToolBarItem:(SsjjCoreToolBarItemType)buttonType;


- (void)startRefreshAnimation:(BOOL)isAnimation;
@end
