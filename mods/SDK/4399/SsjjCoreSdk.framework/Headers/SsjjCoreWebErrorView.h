//
//  SsjjCoreWebErrorView.h
//  4399CoreSdk
//
//  Created by 4399 on 14-8-27.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SsjjCoreWebErrorView : UIView
{
    UIImageView *_errorImageView;
    UILabel *_pageNotRequestLabel;
    UILabel *_noNetworkLabel;
}

@property(nonatomic,retain)UIButton *reloadBtn;
@property(nonatomic,copy)dispatch_block_t reloadBtnBlock;

@end
