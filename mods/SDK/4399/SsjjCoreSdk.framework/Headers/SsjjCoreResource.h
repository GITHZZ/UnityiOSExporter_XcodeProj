//
//  SsjjSyResource.h
//  SsjjAdsSdk
//
//  Created by 4399sy-tangwu on 14-6-7.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SsjjCoreConfig.h"

@interface SsjjCoreResource : NSObject

+ (void) initializeWithRegion: (kSsjjCoreRegion) region;

// 获取png图片
+ (UIImage *) pngWithName: (NSString *) imgName;

+ (UIImage *) imgWithName: (NSString *) imgName
                     type: (NSString *) type;

+ (UIImage *) imgWithName: (NSString *) imgName
                     type: (NSString *) type
                     size: (CGSize) size;

+ (NSBundle *) resourceBundle;

// 获取本地语言
+ (NSString *) localizedString : (NSString *) key;

// 获取本地语言
+ (NSString *) localizedString : (NSString *) key
                   defaultValue: (NSString *) defaultValue;

+ (NSString *) localizedStringWithGlue: (NSString *) glue, ...;
@end
