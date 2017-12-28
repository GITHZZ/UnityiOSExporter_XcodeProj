//
//  SsjjJMColor.h
//  4399CoreSdk
//
//  Created by xianxian on 2016/12/1.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SsjjJMColorInstance [SsjjJMColor shareInstance]

@interface SsjjJMColor : NSObject

//根据运营给的配色对控件做配对
@property (nonatomic,assign) unsigned long bgColor1;
@property (nonatomic,assign) unsigned long bgColor2;
@property (nonatomic,assign) unsigned long btnColor1;
@property (nonatomic,assign) unsigned long btnColor2;
@property (nonatomic,assign) unsigned long textColor1;
@property (nonatomic,assign) unsigned long textColor2;
@property (nonatomic,assign) unsigned long textColor3;

+(instancetype)shareInstance;

@end
