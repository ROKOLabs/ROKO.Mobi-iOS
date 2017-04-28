//
//  ROKOPromoDiscountItem.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 04.10.15.
//  Copyright © 2015 ROKO Labs. All rights reserved.
//

#import "ROKODiscountItem.h"

/**
 *  Who can use discount
 */
typedef NS_ENUM(NSInteger, ROKOPromoDiscountApplicability) {
	/**
	 *  No information
	 */
	ROKOPromoDiscountApplicabilityUnspecified,
	
	/**
	 *  Any user
	 */
	ROKOPromoDiscountApplicabilityAllUsers,
	
	/**
	 *  Users from a special segment
	 */
	ROKOPromoDiscountApplicabilitySegments
};

/**
 *  Information about prmo discount
 */
@interface ROKOPromoDiscountItem : ROKODiscountItem

/**
 *  Describes who can use this promo
 */
@property (nonatomic, assign) ROKOPromoDiscountApplicability applicability;

/**
 *  When the promo campain starts
 */
@property (nonatomic, strong) NSDate *startDate;

/**
 *  When the promo campaign finishes
 */
@property (nonatomic, strong) NSDate *endDate;

/**
 *  Indicates the promo campaign is forever. If this property is YES, values of startDate and endDate are not important
 */
@property (nonatomic, assign) BOOL isAlwaysActive;

/**
 *  Indicates if the discount should be applied automatically on app start
 */
@property (nonatomic, assign) BOOL autoApplyOnAppOpen;

/**
 *  Indicates if the discount can be combined with other discounts
 */
@property (nonatomic, assign) BOOL cannotBeCombined;

@end
