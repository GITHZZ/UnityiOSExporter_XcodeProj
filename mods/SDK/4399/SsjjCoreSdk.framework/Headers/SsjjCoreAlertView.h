//
//  SsjjCoreAlertView.h
//  4399CoreSdk
//
//  Created by 4399 on 14-8-20.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SsjjCoreAlertView;
@interface SsjjCoreAlertView : UIAlertView


- (instancetype)initWithTitle:(NSString *)title
            message:(NSString *)message
         confirmBlcok:(dispatch_block_t)confirmBlock
       cancelBlcok:(dispatch_block_t)cancelBlcok
  cancelButtonTitle:(NSString *)cancelButtonTitle
  otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;


@property(copy,nonatomic)dispatch_block_t confirmBlock;
@property(copy,nonatomic)dispatch_block_t cancelBlcok;

@end