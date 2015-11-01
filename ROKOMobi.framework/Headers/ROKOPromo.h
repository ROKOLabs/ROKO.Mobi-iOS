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
typedef void(^ROKOPromoCategoryCompletionBlock)(ROKODataObject *discount, NSError *error);

@interface ROKOPromo : ROKOComponent

- (void)loadRefferalDiscountsList:(ROKOPromoItemsListCompletionBlock)completionBlock;
- (void)markRerrefalDiscountAsUsed:(NSNumber *)discountId completionBlock:(ROKOMarkDiscountCompletionBlock)completionBlock;

- (void)loadPromoDiscountWithPromoCode:(NSString *)promoCode completionBlock:(ROKOPromoDiscountCompletionBlock)completionBlock;
- (void)markPromoCodeAsUsed:(NSString *)promoCode completionBlock:(ROKOMarkDiscountCompletionBlock)completionBlock;
//- (void)loadPromoCategories:(ROKOPromoItemsListCompletionBlock)completionBlock;
//- (void)loadPromoCategoryWithId:(NSNumber *)categoryId completionBlock:(ROKOPromoCategoryCompletionBlock)completionBlock;

@end
