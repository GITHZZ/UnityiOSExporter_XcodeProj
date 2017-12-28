//
//  SsjjCoreLog.h
//  SsjjCoreSDK
//
//  Created by 4399sy-tangwu on 14-2-28.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 * @brief 宏SsjjCoreLog，用法和NSLog一样,使用前要先调用"[NeibuSyLog setDebugMode:YES];"开启debug模式，
 *         默认情况下debug模式是关闭的
 *
 */
#define SsjjSyLog(format, ...) [SsjjCoreLog logDeatil: \
[[NSString stringWithUTF8String: __FILE__] lastPathComponent]\
lineNum: [NSNumber numberWithInt:__LINE__] \
funcName: [NSString stringWithUTF8String: __PRETTY_FUNCTION__] \
formatstring: format, ##__VA_ARGS__ \
]

@interface SsjjCoreLog : NSObject

+ (void) log: (id)formatstring,...;
+ (void) logDeatil: (NSString *)fileName
           lineNum: (NSNumber *)lineNum
          funcName: (NSString *)funcName
      formatstring: (id)formatstring,...;
+ (void) setIsDebugMode: (BOOL) theIsDebugMode;
+ (BOOL) getIsDebugMode;
@end
