//
//  ROKOReferral.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 10.12.15.
//  Copyright © 2015 ROKO Labs. All rights reserved.
//

#import "ROKOComponent.h"
#import "ROKOReferralDiscountItem.h"

@interface ROKOReferral : ROKOComponent

- (void)loadReferralDiscountsList:(ROKOItemsListCompletionBlock)completionBlock;
- (void)markReferralDiscountAsUsed:(NSNumber *)discountId completionBlock:(ROKOMarkDiscountCompletionBlock)completionBlock;

@end
