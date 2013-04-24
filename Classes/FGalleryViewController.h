//
//  FGalleryViewController.h
//  FGallery
//
//  Created by Grant Davis on 5/19/10.
//  Copyright 2011 Grant Davis Interactive, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "FGalleryPhotoView.h"
#import "FGalleryPhoto.h"

#import "FGalleryDelegates.h"


@interface FGalleryViewController : UIViewController <UIScrollViewDelegate,FGalleryPhotoDelegate,FGalleryPhotoViewDelegate> {
	
	BOOL _isActive;
	BOOL _isFullscreen;
	BOOL _isScrolling;
	BOOL _isThumbViewShowing;
    BOOL _isEditing;
	
	UIStatusBarStyle _prevStatusStyle;
	CGFloat _prevNextButtonSize;
	CGRect _scrollerRect;
	NSString *galleryID;
	NSUInteger _currentIndex;
	
	UIView *_container; // used as view for the controller
	UIView *_innerContainer; // sized and placed to be fullscreen within the container
	UIToolbar *_toolbar;
	UIScrollView *_thumbsView;
	UIScrollView *_scroller;
	UIView *_captionContainer;
	UILabel *_caption;
	
	NSMutableDictionary *_photoLoaders;
	NSMutableArray *_barItems;
	NSMutableArray *_photoThumbnailViews;
	NSMutableArray *_photoViews;
	
	NSObject <FGalleryViewControllerDelegate> *__unsafe_unretained _photoSource;
    
	UIBarButtonItem *_rightBarButton;
    
	UIBarButtonItem *_nextButton;
	UIBarButtonItem *_prevButton;
    UIBarButtonItem *_homeButton;
    
    NSTimer *_enterFullScreenTimer;
}

- (id)initWithPhotoSource:(NSObject<FGalleryViewControllerDelegate>*)photoSrc;
- (id)initWithPhotoSource:(NSObject<FGalleryViewControllerDelegate>*)photoSrc barItems:(NSArray*)items;

- (void)enterFullScreenTimerFire:(NSTimer*)timer;

- (void)next;
- (void)previous;
- (void)gotoImageByIndex:(NSUInteger)index animated:(BOOL)animated;
- (void)removeImageAtIndex:(NSUInteger)index;
- (void)reloadGallery;
- (FGalleryPhoto*)currentPhoto;

@property NSUInteger currentIndex;
@property NSUInteger startingIndex;
@property (nonatomic,unsafe_unretained) NSObject<FGalleryViewControllerDelegate> *photoSource;
@property (nonatomic,readonly) UIToolbar *toolBar;
@property (nonatomic,readonly) UIView* thumbsView;
@property (nonatomic,strong) NSString *galleryID;
@property (nonatomic) BOOL useThumbnailView;
@property (nonatomic) BOOL beginsInThumbnailView;
@property (nonatomic) BOOL hideTitle;
@property (nonatomic) BOOL hideCloseButtonInThumbnailsView;
@property (nonatomic) BOOL useTranslucentStatusBar;
@property (nonatomic, strong) UIBarButtonItem *refreshButton;
@property (nonatomic, strong) UIBarButtonItem *activityIndicatorButton;

@end

