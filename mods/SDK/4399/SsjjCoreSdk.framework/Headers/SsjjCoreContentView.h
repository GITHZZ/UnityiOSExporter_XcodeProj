//
//  SsjjCoreBaseView.h
//  4399CoreSdk
//
//  Created by 4399sy-tangwu on 14-7-9.
//  Copyright (c) 2014年 4399. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^clickedBlock)(id sender);

@interface SsjjCoreContentView : UIView
@property (nonatomic, retain) NSString  *titleImgPath;  //标题图标的路径

- (void) defaultSetting;
@end
