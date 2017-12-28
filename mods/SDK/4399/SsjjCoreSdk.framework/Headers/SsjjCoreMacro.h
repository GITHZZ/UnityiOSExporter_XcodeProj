//
//  SsjjCoreMacro.h
//  ShouJiMiLing
//
//  Created by 4399sy-tangwu on 14-4-15.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#ifndef SsjjCoreSdk_SsjjCoreMacro_h
#define SsjjCoreSdk_SsjjCoreMacro_h

#import <objc/runtime.h>

#define SsjjCoreDescription \
({  unsigned int        propertyNum = 0; \
NSString            *propertyName; \
NSString            *propertyValue; \
objc_property_t     *propertyList = class_copyPropertyList([self class], &propertyNum); \
NSString            *desc = @"[\n"; \
for (int i = 0 ; i < propertyNum; i++) { \
propertyName = [NSString stringWithUTF8String: property_getName(propertyList[i])]; \
propertyValue = [self valueForKey:propertyName]; \
if([desc isEqualToString:@"["]){ \
desc = [NSString stringWithFormat:@"%@ %@:%@\n", desc, propertyName, propertyValue]; \
}else{ \
desc = [NSString stringWithFormat:@"%@ %@:%@\n", desc, propertyName, propertyValue]; \
} \
} \
desc = [desc stringByAppendingString:@"]"]; \
desc; \
})

#define SsjjCoreSharedInstance \
({static id sharedInstance = nil; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
    sharedInstance = [[self alloc] init]; \
}); \
sharedInstance; \
})

#define SsjjCoreSwap(a, b) \
a = a + b; \
b = a - b; \
a = a - b;

#define RGB(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]

#endif
