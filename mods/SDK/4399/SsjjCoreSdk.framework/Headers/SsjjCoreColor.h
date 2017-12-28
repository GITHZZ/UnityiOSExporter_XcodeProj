//
//  SsjjSyColor.h
//  SliderTab
//
//  Created by 4399sy-tangwu on 14-4-26.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface SsjjCoreColor : UIColor

/*
 * @method 通过16进制计算颜色
 * @abstract
 * @discussion
 * @param 16机制
 * @result 颜色对象
 * @例子 获取红色 [UIColor colorFromHexRGB:@"FF0000"]
 */
+ (UIColor *)colorFromHexRGB:(NSString *)inColorString
                       alpha:(CGFloat)alpha;

+ (UIColor *)colorFromHexRGB:(NSString *)inColorString ;

+ (UIColor *)colorWithRed:(CGFloat)red
                    green:(CGFloat)green
                     blue:(CGFloat)blue
                    alpha:(CGFloat)alpha;
@end
