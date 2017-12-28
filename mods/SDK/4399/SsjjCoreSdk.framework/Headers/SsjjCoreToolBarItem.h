//
//  SsjjCoreToolBarItem.h
//  4399CoreSdk
//
//  Created by 4399 on 14-8-25.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SsjjCoreToolBarItemType) {
    SsjjCoreToolBarItemBack,
    SsjjCoreToolBarItemForward,
    SsjjCoreToolBarItemRefresh,
    SsjjCoreToolBarItemHome,
};
@interface SsjjCoreToolBarItem : UIButton


-(instancetype)initWithSsjjCoreToolBarItem:(SsjjCoreToolBarItemType)buttonType
                           selector:(SEL)selector
                             target:(id)target;
@end
