//
//  SsjjCoreItem.h
//  SsjjCoreViewDemo
//
//  Created by ChrisXu on 13/9/12.
//  Copyright (c) 2013年 ChrisXu. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "SsjjCoreView.h"
typedef NS_ENUM(NSInteger, SsjjCoreViewButtonType) {
    SsjjCoreViewButtonTypeDefault = 0,
    SsjjCoreViewButtonTypeCustom = 1,
    SsjjCoreViewButtonTypeCancel = 2
};

@class SsjjCoreView;
@class SsjjCoreButtonItem;
typedef void(^SsjjCoreButtonHandler)(SsjjCoreView *alertView, SsjjCoreButtonItem *button);
typedef void(^SsjjCoreCxButtonHandler)();
@interface SsjjCoreButtonItem : UIButton


@property (nonatomic, copy) NSString *title;
@property (nonatomic, assign) SsjjCoreViewButtonType type;
@property (nonatomic, copy) SsjjCoreButtonHandler action;
@property (nonatomic, copy) SsjjCoreCxButtonHandler buttonAction;
@property (nonatomic) BOOL defaultRightLineVisible;

@end
