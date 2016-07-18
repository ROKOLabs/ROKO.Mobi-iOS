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

/**
 *  Completion block for loadDiscountInfoWithCode:completionBlock: method
 *
 *  @param campaignInfo Information about referral campaign
 *  @param error        Contains error description in case of failed request
 */
typedef void (^ROKOReferralDiscountInfoResponseBlock)(ROKOReferralCampaignInfo * _Nullable campaignInfo, NSError * _Nullable error);

/**
 *  Completion block for activateDiscountWithCode request
 *
 *  @param discountId id of the discount object
 *  @param error      Error description. Contains nil in case of successfull request
 */
typedef void (^ROKOReferralActivateDiscountResponseBlock)(NSNumber * _Nullable discountId, NSError * _Nullable error);

typedef void (^ROKOReferralCompleteDiscountResponseBlock)(NSNumber * _Nullable discountId, NSNumber * _Nullable referrerUserId, NSError * _Nullable error);

/**
 *  Manages Referral campaigns and discounts 
 */
@interface ROKOReferral : ROKOComponent

/**
 *  Loads all referral discounts are available for current user
 *
 *  @param completionBlock Completion block. Items parameter contains array of ROKOReferralDiscountItem objects.
 */
- (void)loadReferralDiscountsList:(nullable ROKOItemsListCompletionBlock)completionBlock;

/**
 *	Marks referral discount object as used.
 *
 *	@param discountId      Id of discount that should be used
 *	@param completionBlock Informs caller about request result
 */
- (void)markReferralDiscountAsUsed:(nonnull NSNumber *)discountId completionBlock:(nullable ROKOMarkDiscountCompletionBlock)completionBlock;

/**
 * Loads referral campaign info
 *
 * 	@param code            Referral code to get information about
 * 	@param completionBlock Informs caller about request result
 */
- (void)loadDiscountInfoWithCode:(nonnull NSString *)code completionBlock:(nullable ROKOReferralDiscountInfoResponseBlock)completionBlock;

/**
 *  Activates discount by the given referral code.
 *
 * 	@param code            Referral code that user attempts to activate
 * 	@param completionBlock Informs caller about request result
 */
- (void)activateDiscountWithCode:(nonnull NSString *)code completionBlock:(nullable ROKOReferralActivateDiscountResponseBlock)completionBlock;

/**
 *  Completes discount with given referral
 *
 *	@param code            Referral code that user attempts to activate
 *	@param completionBlock Block that will be called when request is completed
 */
- (void)completeDiscountWithCode:(nonnull NSString *)code completionBlock:(nullable ROKOReferralCompleteDiscountResponseBlock)completionBlock;

@end
