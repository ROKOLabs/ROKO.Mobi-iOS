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

typedef void (^ROKOReferralDiscountInfoResponseBlock)(ROKOReferralCampaignInfo * _Nullable campaignInfo, NSError * _Nullable error);
typedef void (^ROKOReferralActivateDiscountResponseBlock)(NSNumber * _Nullable discountId, NSError * _Nullable error);
typedef void (^ROKOReferralCompleteDiscountResponseBlock)(NSNumber * _Nullable discountId, NSNumber * _Nullable referrerUserId, NSError * _Nullable error);

@interface ROKOReferral : ROKOComponent

/**
 *  Loads all referral discounts are avaliable for current user
 *
 *  @param completionBlock Completion block. Items parameter contains array of ROKOReferralDiscountItem objects.
 */
- (void)loadReferralDiscountsList:(nullable ROKOItemsListCompletionBlock)completionBlock;

/**
 *  Marks referral discount object as used.
 *
 *  @param discountId      Id of discount that should be used
 *  @param completionBlock Informs caller about request result
 */
- (void)markReferralDiscountAsUsed:(nonnull NSNumber *)discountId completionBlock:(nullable ROKOMarkDiscountCompletionBlock)completionBlock;

/**
 *  Loads referral campaing info
 */
- (void)loadDiscountInfoWithCode:(nonnull NSString *)code completionBlock:(nullable ROKOReferralDiscountInfoResponseBlock)completionBlock;

/**
 *  Activates discount by the given referral code
 */
- (void)activateDiscountWithCode:(nonnull NSString *)code completionBlock:(nullable ROKOReferralActivateDiscountResponseBlock)completionBlock;

/**
 *  Completes discount with given referral code
 */
- (void)completeDiscountWithCode:(nonnull NSString *)code completionBlock:(nullable ROKOReferralCompleteDiscountResponseBlock)completionBlock;

@end
