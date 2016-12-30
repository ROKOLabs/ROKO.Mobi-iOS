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
#import "ROKOReferralDefinition.h"
#import "ROKOReferralProgramDefinition.h"
#import "ROKOReferralProgram.h"
#import "ROKOPortalManager.h"

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
 *  @param error      Error description. Contains nil in case of successful request
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

/**
 *  Intended for situation where code needs to be initiated in a middle application's flow, e.g. by user clicking on deep link with code when app is already installed
 *
 *  @param code            Referral code
 *  @param completionBlock Completion block. Called both for successful and error result.
 */
- (void)loadInfoForCode:(nonnull NSString *)code completionBlock:(nullable ROKOPortalRequestCompletionBlock)completionBlock;

/**
 *  Intended for situation where code needs to be initiated in a middle application's flow, e.g. by user clicking on deep link with code when app is already installed. Choose onlyActive and unusedOnly rewards.
 *
 *  @param code            Referral code
 *  @param onlyActive      Selection flag
 *  @param unusedOnly      Selection flag
 *  @param completionBlock Completion block. Called both for successful and error result.
 */
- (void)loadInfoForCode:(nonnull NSString *)code onlyActive:(BOOL)onlyActive unusedOnly:(BOOL)unusedOnly completionBlock:(nullable ROKOPortalRequestCompletionBlock)completionBlock;

/**
 *  Call to confirm that code was used in purchase
 *
 *  @param issueReward      If Yest - Reward will be issued to Referrer
 *  @param completionBlock  Completion block. Called both for successful and error result.
 */
- (void)redeemReferralDiscount:(BOOL)issueReward completionBlock:(nullable ROKOPortalRequestCompletionBlock)completionBlock;


/**
 *  Called if reward issuance needs to be separated from completion of transaction
 *
 *  @param completionBlock  Completion block. Called both for successful and error result.
 */
- (void)issueRewardWithcompletionBlock:(nullable ROKOPortalRequestCompletionBlock)completionBlock;

/**
 *  Returns the list of rewards. Choose onlyActive and unusedOnly rewards.
 *
 *  @param completionBlock  Completion block. Called both for successful and error result.
 */
- (void)loadReferralRewardList:(nullable ROKOPortalRequestReferralRewardListCompletionBlock)completionBlock;

/**
 *  Returns the list of rewards with selection params.
 *
 *  @param onlyActive       Selection flag
 *  @param unusedOnly       Selection flag
 *  @param completionBlock  Completion block. Called both for successful and error result.
 */
- (void)loadReferralRewardList:(BOOL)onlyActive unusedOnly:(BOOL)unusedOnly completionBlock:(nullable ROKOPortalRequestReferralRewardListCompletionBlock)completionBlock;

/**
 *  Called by Referrer side when it confirms that reward was used successfully
 *
 *  @param completionBlock  Completion block. Called both for successful and error result.
 */
- (void)redeemReferralReward:(nonnull NSNumber *)objectId completionBlock:(nullable ROKOPortalRequestCompletionBlock)completionBlock;
@end
