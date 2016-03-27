//
//  ROKOPromo.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 29.09.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import "ROKOComponent.h"
#import "ROKOPromoDiscountItem.h"

typedef NS_ENUM(NSInteger, ROKOPromoDeliveryType) {
    ROKOPromoDeliveryTypeUnknown,
    ROKOPromoDeliveryTypePush,
    ROKOPromoDeliveryTypeEvent,
    ROKOPromoDeliveryTypeLink
};

typedef void(^ROKOPromoDiscountCompletionBlock)(ROKOPromoDiscountItem *discount, NSError *error);

@interface ROKOPromo : ROKOComponent

- (void)loadPromoDiscountWithPromoCode:(NSString *)promoCode completionBlock:(ROKOPromoDiscountCompletionBlock)completionBlock;
- (void)markPromoCodeAsUsed:(NSString *)promoCode
            valueOfPurchase:(NSNumber *)valueOfPurchase
            valueOfDiscount:(NSNumber *)valueOfDiscount
               deliveryType:(ROKOPromoDeliveryType)deliveryType
            completionBlock:(ROKOMarkDiscountCompletionBlock)completionBlock;

// Logging methods
- (void)promoSentForPromoCampaign:(NSInteger)promoCampaign
                    withPromoCode:(NSString *)promoCode
                isInitiatedByPush:(BOOL)isInitatedByPush;
- (void)promoOpenedForPromoCampaign:(NSInteger)promoCampaign;
- (void)promoClosed;
- (void)promoSaved;

- (void)promoNotificationOpenedWithPromoCampaign:(NSInteger)promoCampaign;

@end
