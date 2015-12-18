//
//  ROKOPromoDiscountItem.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 04.10.15.
//  Copyright © 2015 ROKO Labs. All rights reserved.
//

#import "ROKODiscountItem.h"

typedef NS_ENUM(NSInteger, ROKOPromoDiscountApplicability) {
	ROKOPromoDiscountApplicabilityUnspecified,
	ROKOPromoDiscountApplicabilityAllUsers,
	ROKOPromoDiscountApplicabilityRecipients,
	ROKOPromoDiscountApplicabilitySegments
};

@interface ROKOPromoDiscountItem : ROKODiscountItem

@property (nonatomic, assign) ROKOPromoDiscountApplicability applicability;
@property (nonatomic, strong) NSDate *startDate;
@property (nonatomic, strong) NSDate *endDate;
@property (nonatomic, assign) BOOL isAlwaysActive;
@property (nonatomic, assign) BOOL isSingleUseOnly;
@property (nonatomic, assign) BOOL autoApplyOnAppOpen;
@property (nonatomic, assign) BOOL cannotBeCombined;

@end
