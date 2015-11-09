//
//  ROKOPromo.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 29.09.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import "ROKOComponent.h"
#import "ROKOReferralDiscountItem.h"
#import "ROKOPromoDiscountItem.h"

typedef void(^ROKOPromoDiscountCompletionBlock)(ROKOPromoDiscountItem *discount, NSError *error);
typedef void(^ROKOMarkDiscountCompletionBlock)(NSError *error);
typedef void(^ROKOPromoItemsListCompletionBlock)(NSArray *items, NSError *error);

@interface ROKOPromo : ROKOComponent

- (void)loadReferralDiscountsList:(ROKOPromoItemsListCompletionBlock)completionBlock;
- (void)markReferralDiscountAsUsed:(NSNumber *)discountId completionBlock:(ROKOMarkDiscountCompletionBlock)completionBlock;

- (void)loadPromoDiscountWithPromoCode:(NSString *)promoCode completionBlock:(ROKOPromoDiscountCompletionBlock)completionBlock;
- (void)markPromoCodeAsUsed:(NSString *)promoCode completionBlock:(ROKOMarkDiscountCompletionBlock)completionBlock;

@end
