//
//  FGalleryDelegates.h
//  FGallery
//
//  Created by rominet on 24/10/12.
//
//

#import <Foundation/Foundation.h>

@class FGalleryViewController;
@class FGalleryPhotoView;
@class FGalleryPhoto;


//********** SOURCE TYPES AND SIZES **************//
typedef enum
{
	FGalleryPhotoSizeThumbnail,
	FGalleryPhotoSizeFullsize
} FGalleryPhotoSize;

typedef enum
{
	FGalleryPhotoSourceTypeNetwork,
	FGalleryPhotoSourceTypeLocal
} FGalleryPhotoSourceType;


//********** VIEW CONTROLLER DELEGATE **************//
@protocol FGalleryViewControllerDelegate
@required
- (uint)numberOfPhotosForPhotoGallery:(FGalleryViewController*)gallery;
- (FGalleryPhotoSourceType)photoGallery:(FGalleryViewController*)gallery
              sourceTypeForPhotoAtIndex:(NSUInteger)index;
- (NSString*)photoGallery:(FGalleryViewController*)gallery
      uuidForPhotoAtIndex:(NSUInteger)index;
@optional
- (NSString*)photoGallery:(FGalleryViewController*)gallery
   captionForPhotoAtIndex:(NSUInteger)index;

// the photosource must implement one of these methods depending on which FGalleryPhotoSourceType is specified
- (NSString*)photoGallery:(FGalleryViewController*)gallery
 absolutePathForPhotoSize:(FGalleryPhotoSize)size atIndex:(NSUInteger)index;
- (NSString*)photoGallery:(FGalleryViewController*)gallery
          urlForPhotoSize:(FGalleryPhotoSize)size atIndex:(NSUInteger)index;
@end


//********** PHOTO SCROLLVIEW DELEGATE **************//
@protocol FGalleryPhotoViewDelegate
@required
// indicates single touch and allows controller repsond and go toggle fullscreen
- (void)didTapPhotoView:(FGalleryPhotoView*)photoView;
- (BOOL)photoGalleryIsInEditMode;
@end

//********** PHOTO DELEGATE **************//
@protocol FGalleryPhotoDelegate
@required
- (void)galleryPhoto:(FGalleryPhoto*)photo didLoadThumbnail:(UIImage*)image;
- (void)galleryPhoto:(FGalleryPhoto*)photo didLoadFullsize:(UIImage*)image;
@optional
- (void)galleryPhoto:(FGalleryPhoto*)photo willLoadThumbnailFromUrl:(NSString*)url;
- (void)galleryPhoto:(FGalleryPhoto*)photo willLoadFullsizeFromUrl:(NSString*)url;
- (void)galleryPhoto:(FGalleryPhoto*)photo willLoadThumbnailFromPath:(NSString*)path;
- (void)galleryPhoto:(FGalleryPhoto*)photo willLoadFullsizeFromPath:(NSString*)path;

@end
