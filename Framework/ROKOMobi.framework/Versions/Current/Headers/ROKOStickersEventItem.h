//
//  ROKOStickersEventItem.h
//  ROKOStickers
//
//  Created by Alexey Golovenkov on 26.05.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ROKOStickersEventItem : NSObject

@property (nonatomic, assign) NSInteger stickerId;
@property (nonatomic, assign) NSInteger stickerPackId;
@property (nonatomic, copy) NSString *stickerPackName;
@property (nonatomic, assign) BOOL isResized;
@property (nonatomic, assign) NSInteger positionInPack;
@property (nonatomic, strong) NSUUID *imageId;

@end
