//
//  SsjjCoreChangeAccountView.h
//  4399CoreSdk
//
//  Created by 4399 on 15/5/21.
//  Copyright (c) 2015年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SsjjCoreChangeAccountView : UIView


- (instancetype)initWithFrame:(CGRect)frame isChangeButtonColor:(BOOL)isChange;

- (void)changeAccountBlock:(dispatch_block_t)block;

- (void)startTime;

@end
