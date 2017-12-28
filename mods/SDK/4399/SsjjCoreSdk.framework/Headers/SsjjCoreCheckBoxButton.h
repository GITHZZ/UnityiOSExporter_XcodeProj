//
//  SsjjCoreCheckBoxButton.h
//  4399CoreSdk
//
//  Created by 4399 on 14-7-23.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^SsjjCoreCheckBoxButtonBlock)(BOOL check);
@interface SsjjCoreCheckBoxButton : UIButton
{
    BOOL isCheck;
}


@property(nonatomic,copy)SsjjCoreCheckBoxButtonBlock checkButtonBlock;
@end
