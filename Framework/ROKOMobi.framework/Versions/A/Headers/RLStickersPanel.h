//
//  RLStickersPanel.h
//  ROKOMobi
//
//  Created by Artem Usachov on 6/30/15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RLPhotoComposerDataSource.h"

@class RLStickersCollectionView, RLStickerInfo;

@protocol RLStickersPanelDelegate <NSObject>
@optional
/**
 *  Will be called after sticker added to layer
 *
 *  @param selectedImage UIImage
 *  @param selectedPack  RLStickerPackInfo
 *  @param stickerInfo   RLStickerInfo
 */
- (void)didSelectImage:(UIImage *)selectedImage inPack:(RLStickerPackInfo *)selectedPack withStickerInfo:(RLStickerInfo *)stickerInfo;
/**
 *  Will be called after sticker added to layer
 *
 *  @param sticker RLStickerInfo
 */
- (void)didAddSticker:(RLStickerInfo *)sticker;

@end

@interface RLStickersPanel : UIView <UICollectionViewDelegate, UICollectionViewDataSource>
@property (weak, nonatomic) IBOutlet RLStickersCollectionView *stickersCollection;
@property (weak, nonatomic) IBOutlet UIPageControl *pageControl;
@property (weak, nonatomic) IBOutlet id <RLPhotoComposerDataSource>  dataSource;
@property (weak, nonatomic) RLPhotoComposerController *composer;
@property (weak, nonatomic) IBOutlet id <RLStickersPanelDelegate> delegate;
@property (assign, nonatomic) NSInteger selectedPackIndex;

/**
 *  Base configuration of RLStickersPanel
 *
 *  @param dataSource Data source that be used to build RLStickerPacksCollectionView
 *  @param composer   Composer
 */
- (void)configureWithDatasource:(id<RLPhotoComposerDataSource>)dataSource andComposer:(RLPhotoComposerController *)composer;
/**
 *  Reload collection with stickers
 */
- (void)reloadCollection;
/**
 *  Updates number of in collection flow layout also update number of pages in page control
 *  Max for 1 page is 12
 */
- (void)layoutStickers;
/**
 *  Changes background color of RLStickersCollectionView
 *
 *  @param color UIColor that will be set as a background color for RLStickersCollectionView
 */
- (void)updateBackgroundColorWithColor:(UIColor *)color;

@end
