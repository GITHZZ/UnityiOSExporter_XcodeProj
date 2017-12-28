//
//  SsjjCoreUti.h
//  SsjjHwSdk
//
//  Created by 4399sy-tangwu on 14-3-21.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface SsjjCoreUtil : NSObject

/**
 获取屏幕比例
 */
+ (float)screenScale;

//判断一个对象是否是block对象
+ (BOOL) isBlock: (id) pBlock;

+ (NSString *)getPhoneModel;

+ (NSString *) getScreenDisplayMetics;

+ (id) ifNull: (id) str
      default: (id) defaultStr;

+ (NSString *) getNetWork;

+ (NSString*)getCarrier;

+ (NSString*)getMacAddress;

//判断字符串是否是空串
+ (BOOL) isEmptyString:(NSString *) str;

+ (double) systemVersion;

+ (void) observeOrientationChanged:(id)observer
                          selector:(SEL)selector;

+ (NSString *)encodeMd5:(NSString *)value;

// 返回当前的时间戳,秒为单位
+ (NSString *) time;

// 获取视图方向的名称
+ (NSString *) getInterfaceOrientationName: (UIInterfaceOrientation) interfaceOrientation;

+ (BOOL) interfaceOrientationIsPortrait;

+ (void) removeAllSubview: (UIView *) view;
+ (BOOL) osVersionLessThan: (NSString *) version;

+(BOOL)installThirdKeyboard;

+(BOOL)isiPad;

+(void)showToast:(NSString *)message;

@end

@interface UIImage (Tint)

- (UIImage *) imageWithTintColor:(UIColor *)tintColor;
- (UIImage *) imageWithGradientTintColor:(UIColor *)tintColor;

@end
