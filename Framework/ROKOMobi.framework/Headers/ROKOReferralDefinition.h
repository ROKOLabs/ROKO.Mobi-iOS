//
//  ROKOReferralDefinition.h
//  ROKOMobi
//
//  Created by Maslov Sergey on 26.12.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKODiscountItem.h"

/**
 *  Describes referral discount
 */
@interface ROKOReferralDefinition : NSObject <NSCoding>

/**
 *  Indicates whether the discount applying is possible
 */
@property (nonatomic, assign) BOOL enabled;

/**
 *  Discount value
 */
@property (nonatomic, strong, nonnull) NSNumber *value;

/**
 *  Discount type
 */
@property (nonatomic, assign) ROKODiscountType type;

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
