//
//  ComboBoxView.h
//  comboBox
//
//  Created by duansong on 10-7-28.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//



typedef void(^TouchCellBlock)(NSString *userName,NSInteger indexPath);
typedef void (^DeleteAccountBlcok)(NSInteger indexPath,NSString *userName);


typedef NS_ENUM(NSInteger, ComboBoxViewAnimationType) {
    ComboBoxViewZoomInAnimation = 0,
    ComboBoxViewZoomOutAnimation = 1,
};


@interface ComboBoxView : UIView < UITableViewDelegate, UITableViewDataSource > {
	
	NSMutableArray			*_comboBoxDatasource;
	BOOL			_showComboBox;
}

@property(nonatomic,retain)UITableView		*comboBoxTableView;
@property (nonatomic, retain) NSMutableArray *comboBoxDatasource;

//先不要删掉这行
//@property(nonatomic,assign,setter = setComboBoxViewAnimationType:) ComboBoxViewAnimationType comboBoxViewAnimationType;

//点击Cell传入值
@property (nonatomic, copy)  TouchCellBlock     touchCellBlock;
@property (nonatomic, copy)  DeleteAccountBlcok deleteAccountBlock;

- (void)initVariables;
- (void)initCompentWithFrame:(CGRect)frame;
- (void)setContent:(NSString *)content;
- (void)show;
- (void)hidden;
- (void)drawListFrameWithFrame:(CGRect)frame withContext:(CGContextRef)context;

//初始化放大动画
- (void)initZoomInAnimation;

//初始化缩小动画
- (void) initZoomOutAnimation;
@end
