//
//  ROKOShareCustomizer.h
//  ROKOShare
//
//  Created by Denis Kempest on 6/10/15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import "ROKOComponentCustomizer.h"
#import "ROKOShareScheme.h"

typedef void (^ROKOShareCustomizerCompletionBlock)(ROKOShareScheme *scheme, NSError *error);

typedef NS_ENUM(NSInteger, ROKOShareCustomizerType) {
	ROKOShareCustomizerTypeUniversal,
	ROKOShareCustomizerTypeReferral
};

@interface ROKOShareCustomizer : ROKOComponentCustomizer

@property (nonatomic, assign) ROKOShareCustomizerType customizerType;

- (void)loadSchemeWithCompletionBlock:(ROKOShareCustomizerCompletionBlock)completionBlock;

@end
