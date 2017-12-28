//
//  SsjjCoreButtonContainerView.h
//  SsjjCoreViewDemo
//
//  Created by ChrisXu on 13/9/25.
//  Copyright (c) 2013年 ChrisXu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SsjjCoreView.h"

@interface SsjjCoreButtonContainerView : UIScrollView

@property (nonatomic, strong) NSMutableArray *buttons;
@property (nonatomic) BOOL defaultTopLineVisible;

- (void)addButtonWithTitle:(NSString *)title type:(SsjjCoreViewButtonType)type handler:(SsjjCoreButtonHandler)handler;

@end
