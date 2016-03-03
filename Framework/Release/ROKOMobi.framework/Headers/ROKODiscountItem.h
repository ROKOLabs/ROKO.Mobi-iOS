//
//  ROKODiscountItem.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 03.10.15.
//  Copyright © 2015 ROKO Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKODataObject.h"

typedef void(^ROKOMarkDiscountCompletionBlock)(NSError *error);
typedef void(^ROKOItemsListCompletionBlock)(NSArray *items, NSError *error);


/**
 *  Discount types
 */
typedef NS_ENUM(NSInteger, ROKODiscountType) {
	/**
	 *  Unknown discount type.
	 */
	ROKODiscountTypeUnspecified,
	/**
	 *  Percent discount
	 */
	ROKODiscountTypePercent,
	/**
	 *  The discount value is fixed
	 */
	ROKODiscountTypeFixed,
	/**
	 *  The goods are absolutely free
	 */
	ROKODiscountTypeFree,
	/**
	 *	Matching discount
	 */
	ROKODiscountTypeMatching
};

/**
 *  Base class for discount data objects
 */
@interface ROKODiscountItem : ROKODataObject

/**
 *  Value of discount
 *  @see type
 */
@property (nonatomic, strong) NSNumber *value;

/**
 *  Limit of discount. Applicable for ROKODiscountTypeMatching only
 *  @see type
 */
@property (nonatomic, strong) NSNumber *limit;

/**
 *  Type of discount
 */
@property (nonatomic, assign) ROKODiscountType type;

/**
 *  Indicates whether the discount can be used
 */
@property (nonatomic, assign) BOOL canBeUsed;

@end
