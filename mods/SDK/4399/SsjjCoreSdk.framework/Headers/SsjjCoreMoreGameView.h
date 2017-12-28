//
//  SsjjCoreMoreGameView.h
//  4399CoreSDK
//
//  Created by xianxian on 2017/3/21.
//  Copyright © 2017年 ssjjsyinner. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SsjjCoreMoreGameViewType) {
    SsjjCoreMoreGameViewTypeCollection = 0,
    SsjjCoreMoreGameViewTypeImage,
};

@protocol SsjjCoreMoreGameViewDelegate <NSObject>



@end

@interface SsjjCoreMoreGameView : UIView

-(instancetype)initWithFrame:(CGRect)frame type:(SsjjCoreMoreGameViewType)type;

- (void)reloadData;
- (void)show;

@property (nonatomic,strong) NSMutableArray *dataSource;

@end
