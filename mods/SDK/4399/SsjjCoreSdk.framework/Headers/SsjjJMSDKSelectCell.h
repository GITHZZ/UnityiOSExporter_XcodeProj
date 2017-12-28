//
//  SsjjJMSDKSelectCell.h
//  4399CoreSdk
//
//  Created by xianxian on 16/8/24.
//  Copyright © 2016年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SsjjJMSDKAccountModel.h"

@interface SsjjJMSDKSelectCell : UITableViewCell

@property (nonatomic,strong) UIImageView *avatar;
@property (nonatomic,strong) UILabel *accountLabel;
@property (nonatomic,strong) UIImageView *checkboxImage;

@property (nonatomic,strong) SsjjJMSDKAccountModel *model;

@property (nonatomic,copy) NSDictionary *accountDictionary;

@end
