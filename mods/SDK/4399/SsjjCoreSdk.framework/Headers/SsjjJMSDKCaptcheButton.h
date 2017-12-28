//
//  SsjjJMSDKCaptcheButton.h
//  4399CoreSdk
//
//  Created by xianxian on 16/8/29.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SsjjJMSDKCaptcheButton : UIButton

@property (nonatomic, copy) NSString *identifyKey;
@property (nonatomic, strong) UIColor *disabledBackgroundColor;
@property (nonatomic, strong) UIColor *disabledTitleColor;

- (void)fire;

@end
