//
//  ROKOPromo.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 29.09.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import "ROKOComponent.h"
#import "ROKOPromoDiscountItem.h"

typedef void(^ROKOPromoDiscountCompletionBlock)(ROKOPromoDiscountItem *discount, NSError *error);

@interface ROKOPromo : ROKOComponent

- (void)loadPromoDiscountWithPromoCode:(NSString *)promoCode completionBlock:(ROKOPromoDiscountCompletionBlock)completionBlock;
- (void)markPromoCodeAsUsed:(NSString *)promoCode completionBlock:(ROKOMarkDiscountCompletionBlock)completionBlock;

@end
