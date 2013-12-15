//
//  DLCBlurOverlayView.m
//  Backspaces
//
//  Created by Dmitri Cherniak on 11/18/12.
//  Copyright (c) 2012 DLC Inc. All rights reserved.
//

#import "DLCBlurOverlayView.h"

@implementation DLCBlurOverlayView {
    CGRect holeRect;
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        _radius = 80.0f;
        // Initialization code
        self.userInteractionEnabled = NO;
        self.opaque = NO;
        CGPoint center = CGPointMake(CGRectGetMidX(frame),CGRectGetMidY(frame));
        holeRect = CGRectMake(center.x-self.radius, center.y-self.radius, self.radius*2, self.radius*2);
    }
    return self;
}

-(void) setCircleCenter:(CGPoint)circleCenter{
    _circleCenter = circleCenter;
    holeRect = CGRectMake(circleCenter.x-self.radius, circleCenter.y-self.radius,
                          self.radius*2,
                          self.radius*2);
    [self setNeedsDisplay];
}

-(void) setRadius:(CGFloat)radius{
    _radius = radius;
    CGPoint center = CGPointMake(CGRectGetMidX(holeRect),CGRectGetMidY(holeRect));
    holeRect = CGRectMake(center.x-self.radius, center.y-self.radius,
                          self.radius*2,
                          self.radius*2);
    [self setNeedsDisplay];
}

- (void)drawRect:(CGRect)rect {
  CGContextRef context = UIGraphicsGetCurrentContext();

  // Drawing lines with a white stroke color
  CGContextSetRGBStrokeColor(context, 1.0, 1.0, 1.0, 1.0);
  // Draw them with a 2.0 stroke width so they are a bit more visible.
  CGContextSetLineWidth(context, 1.0);

  // Draw a connected sequence of line segments
  CGPoint addLines[] =
          {
                  CGPointMake(0.0, self.topPoint),
                  CGPointMake(320.0, self.topPoint),
                  CGPointMake(0.0, self.bottomPoint),
                  CGPointMake(320.0, self.bottomPoint),
          };
  CGContextStrokeLineSegments(context, addLines, sizeof(addLines)/sizeof(addLines[0]));
  CGContextStrokePath(context);
}


- (void)setTopPoint:(CGFloat)topPoint
        bottomPoint:(CGFloat)bottomPoint
{
  _topPoint = topPoint;
  _bottomPoint = bottomPoint;
  [self setNeedsDisplay];
}


@end

