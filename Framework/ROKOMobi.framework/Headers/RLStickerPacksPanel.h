//
//  RLStickerPacksPanel.h
//  ROKOMobi
//
//  Created by Artem Usachov on 8/30/15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RLPhotoComposerDataSource.h"
#import "ROKOStickersTrayScheme.h"

@class RLStickersCollectionView, RLStickerInfo, RLStickersPanel;

@protocol RLStickerPacksPanelDelegate <NSObject>
@optional
/**
 *  Will be called after user did select pack in packs collection
 *
 *  @param selectedPackIndex selected index
 */
- (void)didSelectPackAtIndex:(NSInteger)selectedPackIndex;

@end

@interface RLStickerPacksPanel : UIView <UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

@property (nonatomic, weak) IBOutlet id <RLPhotoComposerDataSource> dataSource;
@property (nonatomic, weak) RLPhotoComposerController *composer;
@property (nonatomic, weak) IBOutlet id <RLStickerPacksPanelDelegate> delegate;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *fontColor;

/**
 *  Base configuration of RLStickerPacksPanel
 *
 *  @param dataSource    Data source that be used to build RLStickerPacksCollectionView
 *  @param stickersPanel Stickers panel that will be updated with selected stickers pack
 *  @param composer      Composer
 */
- (void)configureWithDatasource:(id<RLPhotoComposerDataSource>)dataSource stickersPanel:(RLStickersPanel *)stickersPanel andComposer:(RLPhotoComposerController *)composer;
/**
 *  Changes background color of RLStickerPacksCollectionView
 *
 *  @param color background color of RLStickerPacksCollectionView
 */
- (void)updateBackgroundColorWithColor:(UIColor *)color;
/**
 *  Changes display type of RLStickerPacksCollectionView
 *
 *  @param displayType tray display type
 */
- (void)updateDisplayType:(ROKOStickersTrayDisplayType)displayType;
/**
 *  Reload stickers packs collection
 */
- (void)reloadData;

@end
