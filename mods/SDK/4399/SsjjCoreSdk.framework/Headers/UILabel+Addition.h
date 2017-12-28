//
//  UILabel+Addition.h
//  4399CoreSdk
//
//  Created by 4399 on 14-7-9.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (Addition)

@property(nonatomic,setter = setAutoResize:) BOOL autoResize;

//下划线
-(NSAttributedString*) getAttributedString:(NSAttributedString*) attributedString isUnderline:(BOOL) isUnderline;

//设置label内容某段范围文字不同颜色
-(void)labelTextRangeColor:(UIColor *)color range:(NSRange)range;

//Label文字居顶部
- (void)alignTop ;

//Label文字居底部
- (void)alignBottom;
@end
