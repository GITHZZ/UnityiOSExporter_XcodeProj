//
//  SsjjCoreMoreGameModel.h
//  4399CoreSDK
//
//  Created by xianxian on 2017/7/7.
//  Copyright © 2017年 ssjjsyinner. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SsjjCoreMoreGameModel : NSObject

@property (nonatomic,copy) NSString *client_id;
@property (nonatomic,copy) NSString *murl;
@property (nonatomic,copy) NSString *rurl;
@property (nonatomic,copy) NSString *game_name;

- (instancetype)initModelWith:(NSDictionary *)dictionary;

@end
