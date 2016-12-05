//
//  ROKOStickers.h
//  ROKOStickers
//
//  Created by Alexey Golovenkov on 16.06.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for ROKOStickers.
FOUNDATION_EXPORT double ROKOStickersVersionNumber;

//! Project version string for ROKOStickers.
FOUNDATION_EXPORT const unsigned char ROKOStickersVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import "PublicHeader.h>

#import <Foundation/Foundation.h>

@class RLStickerInfo;
@class RLStickerPackInfo;
@class ROKOStickersEventItem;

@interface ROKOStickers : NSObject

+ (void)logStickerSelection:(RLStickerInfo *)sticker inPack:(RLStickerPackInfo *)pack withImageId:(NSString *)imageId;
+ (void)logSavingWithStickers:(NSArray <ROKOStickersEventItem *> *)stickers onImageWithId:(NSString *)imageId fromCamera:(BOOL)fromCamera;
+ (void)logEnteredStickersPanel;
+ (void)logExitedStickersPanel;
+ (void)logSharedImageWithId:(NSString *)imageId;

@end
