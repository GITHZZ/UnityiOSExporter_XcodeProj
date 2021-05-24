//
//  GD_Seed_RoleInfo.h
//  GDSeed
//
//  Created by zzfb on 2021/5/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface GD_Seed_productInfo : NSObject
@property (nonatomic, copy) NSString *userID;//用户id
@property (nonatomic, copy) NSString *serverID;//区服id
@property (nonatomic, copy) NSString *roleID;//角色id
@property (nonatomic, copy) NSString *gqpName;//产品名称
@property (nonatomic, copy) NSString *servername;//区服名称
@property (nonatomic, copy) NSString *gqp;//价格
@property (nonatomic, copy) NSString *cpData;//透传参数
@property (nonatomic, copy) NSString *roleName;//角色名称
@property (nonatomic, copy) NSString *roleLevel;//角色等级
@property (nonatomic,copy)  NSString *productID;
@end
@interface GD_Seed_RoleInfo : NSObject
@property (nonatomic, copy) NSString *userID;//用户id
@property (nonatomic, copy) NSString *serverID;//区服id
@property (nonatomic, copy) NSString *serverName;//区服名称
@property (nonatomic, copy) NSString *roleName;//角色名称
@property (nonatomic, copy) NSString *roleLevel;//角色等级
@property (nonatomic, copy) NSString *roleID;//角色id
@property (nonatomic, copy) NSString *balance;// 游戏内金币
@property (nonatomic, copy) NSString *power;// 战斗力
@end


