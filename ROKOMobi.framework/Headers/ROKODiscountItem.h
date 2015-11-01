//
//  ROKODiscountItem.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 03.10.15.
//  Copyright © 2015 ROKO Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKODataObject.h"

typedef NS_ENUM(NSInteger, ROKODiscountType) {
	ROKODiscountTypeUnspecified,
	ROKODiscountTypePercent,
	ROKODiscountTypeFixed,
	ROKODiscountTypeFree
};

@interface ROKODiscountItem : ROKODataObject

@property (nonatomic, strong) NSNumber *value;
@property (nonatomic, assign) ROKODiscountType type;
@property (nonatomic, assign) BOOL canBeUsed;

@end
