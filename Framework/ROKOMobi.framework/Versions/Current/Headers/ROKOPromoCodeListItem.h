//
//  ROKOPromoCodeListItem.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 29.08.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"
#import "ROKOPromoDiscountItem.h"

/**
 *  Response item for get all promo code response
 */
@interface ROKOPromoCodeListItem : ROKODataObject

/**
 *  Promo code
 */
@property (nonatomic, copy) NSString *promoCode;

/**
 *  Discount description
 */
@property (nonatomic, strong) ROKOPromoDiscountItem *discountItem;

@end
