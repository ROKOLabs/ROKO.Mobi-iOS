//
//  ROKOShareCustomizer.h
//  ROKOShare
//
//  Created by Denis Kempest on 6/10/15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import "ROKOComponentCustomizer.h"
#import "ROKOShareScheme.h"


/**
 *  Completion block for share customizer
 *
 *  @param scheme UI scheme to be applied on share view
 *  @param error  Error object. Contains nill if loading finished successfully
 */
typedef void (^ROKOShareCustomizerCompletionBlock)(ROKOShareScheme *scheme, NSError *error);

/**
 *  Possible share customizer types
 */
typedef NS_ENUM(NSInteger, ROKOShareCustomizerType) {
	/**
	 *  Regular share customizer
	 */
	ROKOShareCustomizerTypeUniversal,
	/**
	 *  Referral customizer
	 */
	ROKOShareCustomizerTypeReferral
};

/**
 *  Customizer for Share view
 */
@interface ROKOShareCustomizer : ROKOComponentCustomizer

/**
 *  Type of customizer
 */
@property (nonatomic, assign) ROKOShareCustomizerType customizerType;

/**
 *  Loads UI scheme from Portal
 *
 *  @param completionBlock Calls when loading is finished
 */
- (void)loadSchemeWithCompletionBlock:(ROKOShareCustomizerCompletionBlock)completionBlock;

@end