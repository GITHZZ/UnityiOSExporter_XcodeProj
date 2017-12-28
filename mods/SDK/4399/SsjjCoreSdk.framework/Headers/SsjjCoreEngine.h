//
//  SsjjCoreEngine.h
//  4399CoreSdk
//
//  Created by 4399sy-tangwu on 14-7-7.
//  Copyright (c) 2014年 tangwu. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SsjjCoreViewCenter.h"
#import "SsjjCoreConfig.h"

@interface SsjjCoreEngine : NSObject
{
    SsjjCoreViewCenter  *viewCenter;
}
@property (nonatomic, retain) SsjjCoreViewCenter  *viewCenter;

- (id)initWithAppKey: (NSString *)appKey
           appSecret: (NSString *)appSecret
           channelId: (NSString *)channelId
  andEnvironmentType: (kSsjjCoreRunEnvironmentType)environmentType
           andRegion: (kSsjjCoreRegion)region;

@end
