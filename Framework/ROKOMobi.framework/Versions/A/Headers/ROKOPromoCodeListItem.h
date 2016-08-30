//
//  ROKOPromoCodeListItem.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 29.08.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"
#import "ROKOPromoDiscountItem.h"

@interface ROKOPromoCodeListItem : ROKODataObject

@property (nonatomic, copy) NSString *promoCode;
@property (nonatomic, strong) ROKOPromoDiscountItem *discountItem;

@end
