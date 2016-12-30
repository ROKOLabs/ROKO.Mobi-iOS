//
//  ROKOReferralProgramDefinition.h
//  ROKOMobi
//
//  Created by Maslov Sergey on 26.12.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKOReferralDefinition.h"

@interface ROKOReferralProgramDefinition : NSObject <NSCoding>

/**
 *  Program name
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 *  Discount definition
 */
@property (nonatomic, strong, nonnull) ROKOReferralDefinition *discount;

/**
 *  Reward definition
 */
@property (nonatomic, strong, nonnull) ROKOReferralDefinition *reward;


/**
 *  Initializes a new object with given dictionary.
 *
 *  @param dictionary Dictionary with information about the object
 *
 *  @return An initialized object, or nil if an object could not be created
 *
 *	@see loadFromDictionary:
 */
- (nullable instancetype)initWithDictionary:(nullable NSDictionary *)dictionary;

/**
 *  Initializes existing object with new data from given dictionary
 *
 *  @param dictionary Dictionary with information about the object
 */
- (void)loadFromDictionary:(nullable NSDictionary *)dictionary;

@end
