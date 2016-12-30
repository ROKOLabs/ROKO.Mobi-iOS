//
//  RLImagesCache.h
//  ROKOStickers
//
//  Created by Katerina Vinogradnaya on 7/21/14.
//  Copyright (c) 2014 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface RLImagesCache : NSObject
+ (void)clearCache;
+ (UIImage *)imageForURL:(NSString *)URLString;
+ (void)registerImage:(UIImage *)image forURL:(NSString *)URLString;
@end
