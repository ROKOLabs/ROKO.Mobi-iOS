//
//  ROKOStickerPack.h
//  ROKOStickers
//
//  Created by Alexey Golovenkov on 12.05.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import "ROKODataObject.h"
#import "ROKOStickersWatermarkInfo.h"

/**
 *  Group of stickers
 */
@interface ROKOStickerPack : ROKODataObject

/**
 *  Image for icon in selected mode
 */
@property (nonatomic, strong) ROKOImageDataObject *selectedIcon;

/**
 *  Image for icon in unselected mode
 */
@property (nonatomic, strong) ROKOImageDataObject *unselectedIcon;

/**
 *  Indicates whether the pack should use watermark
 */
@property (nonatomic, assign) BOOL useWatermark;

/**
 *  Indicates whether the pack should use application watermark. Ignored if useWatermark is NO
 */
@property (nonatomic, assign) BOOL useApplicationWatermark;

/**
 *  Watermark image scale
 */
@property (nonatomic, assign) float watermarkScaleFactor;
@property (nonatomic, assign) NSInteger watermarkPosition;

/**
 *  Name of the pack
 */
@property (nonatomic, copy) NSString *name;

/**
 *  Stickers array. Contains ROKOSticker objects
 */
@property (nonatomic, strong) NSArray *stickers;

/**
 *  Watermark data
 */
@property (nonatomic, strong) ROKOStickersWatermarkInfo *watermark;

/**
 *  Indicates if the pack is active now
 */
@property (nonatomic, assign) BOOL isActive;

@end
