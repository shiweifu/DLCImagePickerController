//
//  DLCBlurOverlayView.h
//  Backspaces
//
//  Created by Dmitri Cherniak on 11/18/12.
//  Copyright (c) 2012 DLC Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DLCBlurOverlayView : UIView

@property (nonatomic, assign) CGFloat radius;
@property (nonatomic, assign) CGPoint circleCenter;

@property(nonatomic) CGFloat topPoint;
@property(nonatomic) CGFloat bottomPoint;

- (void)setTopPoint:(CGFloat)topPoint
        bottomPoint:(CGFloat)bottomPoint;

@end
