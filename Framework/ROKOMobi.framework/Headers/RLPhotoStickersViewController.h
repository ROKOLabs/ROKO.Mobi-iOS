//
//  RLPhotoStickersViewController.h
//  ROKOStickers
//
//  Created by Katerina Vinogradnaya on 22.04.14.
//  Copyright (c) 2014 ROKOLabs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RLPhotoComposerController.h"

@interface RLPhotoStickersViewController : RLPhotoComposerController

+ (instancetype)buildPhotoStickersController;
- (NSArray *)usedStickers;

@end
