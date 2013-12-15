//
//  DLCImagePickerController.h
//  DLCImagePickerController
//
//  Created by Dmitri Cherniak on 8/14/12.
//  Copyright (c) 2012 Dmitri Cherniak. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GPUImage.h"
#import "DLCBlurOverlayView.h"

@class DLCImagePickerController;

@protocol DLCImagePickerDelegate <NSObject>
@optional
- (void)imagePickerController:(DLCImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info;
- (void)imagePickerControllerDidCancel:(DLCImagePickerController *)picker;
@end

@interface DLCImagePickerController : UIViewController <UINavigationControllerDelegate,UIImagePickerControllerDelegate> 

@property (nonatomic, weak) IBOutlet GPUImageView *imageView;
@property (nonatomic, weak) id <DLCImagePickerDelegate> delegate;
@property (nonatomic, weak) IBOutlet UIButton *photoCaptureButton;
@property (nonatomic, weak) IBOutlet UIButton *cancelButton;

@property (nonatomic, weak) IBOutlet UIButton *cameraToggleButton;
@property (nonatomic, weak) IBOutlet UIButton *blurToggleButton;
@property (nonatomic, weak) IBOutlet UIButton *filtersToggleButton;
@property (nonatomic, weak) IBOutlet UIButton *libraryToggleButton;
@property (nonatomic, weak) IBOutlet UIButton *flashToggleButton;
@property (nonatomic, weak) IBOutlet UIButton *retakeButton;
@property (weak, nonatomic) IBOutlet UIButton *watermarkButton;

@property (weak, nonatomic) IBOutlet UIPageControl *pageControl;

@property (nonatomic, weak) IBOutlet UIScrollView *filterScrollView;
@property (nonatomic, weak) IBOutlet UIImageView *filtersBackgroundImageView;
@property (nonatomic, weak) IBOutlet UIView *photoBar;
@property (nonatomic, weak) IBOutlet UIView *topBar;
@property (nonatomic, strong) DLCBlurOverlayView *blurOverlayView;
@property (nonatomic, strong) UIImageView *focusView;

@property (nonatomic, assign) CGFloat outputJPEGQuality;
@property (nonatomic, assign) CGSize requestedImageSize;

#pragma mark - waterMark
@property(nonatomic) NSInteger waterMarkIndex;
@property(nonatomic, strong) NSMutableArray *waterMarkArray;
@property(nonatomic, strong)  UIImageView *waterMark;
@property(nonatomic, strong)  UIImage *waterMarkImage;

//@property(nonatomic, strong) NSMutableArray *waterMarkImageViewArray;
//@property(nonatomic, strong) UIImageView *waterMarkImageView;
@property(nonatomic) BOOL hasWaterMark;
@end
