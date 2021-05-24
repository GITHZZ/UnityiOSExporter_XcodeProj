//
//  GDSeed.h
//  GDSeed
//
//  Created by zzfb on 2021/4/8.
//

#import <Foundation/Foundation.h>
#import <GDSeed/GD_Seed_RoleInfo.h>//GD_Seed_RoleInfo.h>
@interface GDSeed : NSObject
///共享单例
+ (instancetype)sharedInstance;

///初始化SDK
-(void)initsdk;

-(void)sdklogin;

-(void)sdklogout;

-(void)submit_creat_role:(GD_Seed_RoleInfo *)roleInfo;

-(void)submit_enter_game:(GD_Seed_RoleInfo *)roleInfo;

-(void)submit_select_server:(GD_Seed_RoleInfo *)roleInfo;

-(void)submit_rolelevle_change:(GD_Seed_RoleInfo *)roleInfo;

- (void)IAPWithProductId:(GD_Seed_productInfo *)GD_Seed_productInfo;
@end
