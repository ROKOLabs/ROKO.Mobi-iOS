//
//  ROKOPromo.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 29.09.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import "ROKOComponent.h"
#import "ROKOPromoDiscountItem.h"
#import "ROKOPromoCodeListItem.h"
#import "ROKOPromoCampaignInfo.h"

/**
 *  Possible delivery ways for promo code
 */
typedef NS_ENUM(NSInteger, ROKOPromoDeliveryType) {
	
	/**
	 *  Unknown or custom way
	 */
	ROKOPromoDeliveryTypeUnknown,
	
	/**
	 *  Push notification
	 */
	ROKOPromoDeliveryTypePush,
	
	/**
	 *  Event-based notification
	 */
	ROKOPromoDeliveryTypeEvent,
	
	/**
	 *  Deep link
	 */
	ROKOPromoDeliveryTypeLink
};

typedef void(^ROKOPromoCodeListCompletionBlock)(NSArray <ROKOPromoCodeListItem *> * _Nullable promoCodes, NSError * _Nullable error);

typedef void(^ROKOPromoDiscountCompletionBlock)(ROKOPromoDiscountItem * _Nullable discount, NSError * _Nullable error);
typedef void(^ROKOPromoCampaignInfoCompletionBlock)(ROKOPromoCampaignInfo * _Nullable info, NSError * _Nullable error);

/**
 *  Helps to handle promo codes and campaigns
 */
@interface ROKOPromo : ROKOComponent

/**
 *  Receives information about promo code
 *
 *  @param promoCode       Promo code to get information about
 *  @param completionBlock Block that will be called when request is completed. Block definition: void(ROKOPromoDiscountItem *discount, NSError *error)
 */
- (void)loadPromoDiscountWithPromoCode:(nonnull NSString *)promoCode completionBlock:(nonnull ROKOPromoDiscountCompletionBlock)completionBlock;

/**
 *  Loads all valid promo codes avaliable for the current user
 *
 *  @param completionBlock completion block to be called on finish
 */
- (void)loadUserPromoCodesWithCompletionBlock:(nonnull ROKOPromoCodeListCompletionBlock)completionBlock;

/**
 *  Marks promo code as used by the current user.
 *
 *  @param promoCode       Promo code to be marked
 *  @param valueOfPurchase Purchase value. Needed for analytics
 *  @param valueOfDiscount Total discount. Needed for analytics
 *  @param deliveryType    The way this promo code was obtained
 *  @param completionBlock Block to be called on request is finished. Format: void(NSError *error)
 */
- (void)markPromoCodeAsUsed:(nonnull NSString *)promoCode
			valueOfPurchase:(nullable NSNumber *)valueOfPurchase
			valueOfDiscount:(nullable NSNumber *)valueOfDiscount
			   deliveryType:(ROKOPromoDeliveryType)deliveryType
			completionBlock:(nullable ROKOMarkDiscountCompletionBlock)completionBlock;

// Analytics methods
- (void)promoSentForPromoCampaign:(NSInteger)promoCampaign
					withPromoCode:(nonnull NSString *)promoCode
				isInitiatedByPush:(BOOL)isInitiatedByPush;
- (void)promoOpenedForPromoCampaign:(NSInteger)promoCampaignId;
- (void)promoClosedForPromoCampaign:(NSInteger)promoCampaignId;
- (void)promoSaved;

/**
 *  Receives information about promo campaign
 *
 *  @param promoCampaign   Promo campaign identifier
 *  @param completionBlock Block that will be called when request is completed. Block definition: void(ROKOPromoCampaignInfo *info, NSError *error)
 */
- (void)loadPromoCampaignInfo:(NSInteger)promoCampaign completionBlock:(nonnull ROKOPromoCampaignInfoCompletionBlock)completionBlock;
@end
