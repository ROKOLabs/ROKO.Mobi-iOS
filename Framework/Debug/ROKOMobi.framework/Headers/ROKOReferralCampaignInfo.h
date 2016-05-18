//
//  ROKOReferralCampaignInfo.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 28.12.15.
//  Copyright © 2015 ROKO Labs. All rights reserved.
//

#import "ROKODiscountItem.h"

/**
 *  Describes referral discount
 */
@interface ROKOReferralDiscountInfo : NSObject <NSCoding>

/**
 *  Indicates whether the discount applying is possible
 */
@property (nonatomic, assign) BOOL enabled;

/**
 *  Discount value
 */
@property (nonatomic, strong) NSNumber *value;

/**
 *  Discount limit. Applicable for ROKODiscountTypeMatching only
 */
@property (nonatomic, strong) NSNumber *limit;

/**
 *  Discount type
 */
@property (nonatomic, assign) ROKODiscountType type;

@end


/**
 *  Information about Referral Campaign (Incentive)
 */
@interface ROKOReferralCampaignInfo : ROKODataObject

/**
 *  Indicates whether the campaign is active
 */
@property (nonatomic, assign) BOOL active;

/**
 *  Company name
 */
@property (nonatomic, copy) NSString *name;

/**
 *  Information about the current user discount
 */
@property (nonatomic, strong) ROKOReferralDiscountInfo *recipientDiscount;

/**
 *  Information about the user who owns the referral code
 */
@property (nonatomic, strong) ROKOReferralDiscountInfo *rewardDiscount;

@end
