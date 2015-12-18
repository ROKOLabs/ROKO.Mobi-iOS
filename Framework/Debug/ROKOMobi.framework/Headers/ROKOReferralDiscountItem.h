//
//  ROKOReferralDiscountItem.h
//  
//
//  Created by Alexey Golovenkov on 02.10.15.
//
//

#import "ROKODiscountItem.h"

/**
 *  Referral discount object
 */
@interface ROKOReferralDiscountItem : ROKODiscountItem

/**
 *  Discount creation date
 */
@property (nonatomic, strong) NSDate *createDate;

/**
 *  Last update date
 */
@property (nonatomic, strong) NSDate *updateDate;

@end
