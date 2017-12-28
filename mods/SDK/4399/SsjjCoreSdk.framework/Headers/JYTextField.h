//
//  JYTextField.h
//  meetingManager
//
//  Created by kinglate on 13-1-22.
//  Copyright (c) 2013年 joyame. All rights reserved.
//


@interface JYTextField : UITextField
{
	CGFloat     _cornerRadio;
	CGFloat     _borderWidth;
	CGFloat     _lightSize;
	UIColor     *lightBorderColor;
    UIColor     *lightColor;
    UIColor     *borderColor;
}
@property (nonatomic, retain) UIColor   *lightBorderColor;
@property (nonatomic, retain) UIColor   *lightColor;
@property (nonatomic, retain) UIColor   *borderColor;

- (id)initWithFrame:(CGRect)frame
		cornerRadio:(CGFloat)radio
		borderColor:(UIColor*)bColor
		borderWidth:(CGFloat)bWidth
		 lightColor:(UIColor*)lColor
		  lightSize:(CGFloat)lSize
   lightBorderColor:(UIColor*)lbColor;
@end
