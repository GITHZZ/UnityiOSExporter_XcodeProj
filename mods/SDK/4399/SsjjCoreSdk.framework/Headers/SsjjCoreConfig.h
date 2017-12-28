//
//  SsjjCoreConfig.h
//  4399CoreSdk
//
//  Created by 4399sy-tangwu on 14-7-8.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#ifndef _399CoreSdk_SsjjCoreConfig_h
#define _399CoreSdk_SsjjCoreConfig_h

//4399CoreSdk的版本号
#define kSsjjCoreSdkVersion     @"1.0.0"

typedef enum
{
	kSsjjCoreRunEnvironmentDevelope = 1, //开发环境(测试环境)
    kSsjjCoreRunEnvironmentDeploy   = 2, //发布环境(正式环境)
}kSsjjCoreRunEnvironmentType;  //api的类型

typedef enum
{
	kSsjjCoreRegionChina    = 1, //中国大陆
    kSsjjCoreRegionTaiwan   = 2, //中国台湾
    kSsjjCoreRegionKorea    = 3, //韩国
}kSsjjCoreRegion;  //接入sdk的游戏面向的玩家所在地区


#endif
