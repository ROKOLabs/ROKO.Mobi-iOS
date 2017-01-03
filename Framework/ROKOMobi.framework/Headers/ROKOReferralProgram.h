//
//  ROKOReferralProgram.h
//  ROKOMobi
//
//  Created by Maslov Sergey on 20.12.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOReferralDiscountItem.h"
#import "ROKOReferralProgramDefinition.h"

/**
 *  Referral program definition
 */
@interface ROKOReferralProgram : NSObject <NSCoding>

/**
 *  Referral Program Definition
 */
@property (nonatomic, strong, nullable) ROKOReferralProgramDefinition *info;

/**
 *  Information about the current user discount
 */
@property (nonatomic, strong, nullable) ROKOReferralDiscountItem *discount;

/**
 *  Information about user reward
 */
@property (nonatomic, strong, nullable) NSArray <ROKOReferralDiscountItem *> *rewards;

/**
 *  Error Message
 */
@property (nonatomic, copy, nullable) NSString *errorMessage;

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
