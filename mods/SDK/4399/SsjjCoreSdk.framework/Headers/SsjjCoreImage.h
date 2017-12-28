//
//  SsjjSyImage.h
//  ShouJiMiLing
//
//  Created by 4399sy-tangwu on 14-5-20.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SsjjCoreImage : NSObject

//改变图片的尺寸
+(UIImage*)scaleToSize: (UIImage*) img
                  size: (CGSize) size;
@end
