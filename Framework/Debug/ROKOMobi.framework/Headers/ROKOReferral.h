//
//  ROKOReferral.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 10.12.15.
//  Copyright © 2015 ROKO Labs. All rights reserved.
//

#import "ROKOComponent.h"
#import "ROKOReferralDiscountItem.h"
#import "ROKOReferralCampaignInfo.h"

typedef void (^ROKOReferralDiscountInfoResponseBlock)(ROKOReferralCampaignInfo *campaignInfo, NSError *error);
typedef void (^ROKOReferralActivateDiscountResponseBlock)(NSNumber *discountId, NSError *error);
typedef void (^ROKOReferralCompleteDiscountResponseBlock)(NSNumber *discountId, NSNumber *referrerUserId, NSError *error);

@interface ROKOReferral : ROKOComponent

- (void)loadReferralDiscountsList:(ROKOItemsListCompletionBlock)completionBlock;
- (void)markReferralDiscountAsUsed:(NSNumber *)discountId completionBlock:(ROKOMarkDiscountCompletionBlock)completionBlock;

/**
 *  Loads referral campaing info
 */
- (void)loadDiscountInfoWithCode:(NSString *)code completionBlock:(ROKOReferralDiscountInfoResponseBlock)completionBlock;

/**
 *  Activates discount by the given referral code
 */
- (void)activateDiscountWithCode:(NSString *)code completionBlock:(ROKOReferralActivateDiscountResponseBlock)completionBlock;

/**
 *  Completes discount with given referral code
 */
- (void)completeDiscountWithCode:(NSString *)code completionBlock:(ROKOReferralCompleteDiscountResponseBlock)completionBlock;

@end
