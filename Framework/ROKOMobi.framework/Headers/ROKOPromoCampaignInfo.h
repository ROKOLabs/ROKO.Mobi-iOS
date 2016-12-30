//
//  ROKOPromoCampaign.h
//  ROKOMobi
//
//  Created by Maslov Sergey on 28.12.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"

@interface ROKOPromoCampaignInfo : ROKODataObject

/**
 *  Promo code
 */
@property (nonatomic, copy, nullable) NSString *promoCode;

/**
 *  Indicates whether the campaign is active
 */
@property (nonatomic, assign) BOOL active;

/**
 *  Ref Info
 */
@property (nonatomic, copy, nullable) NSString *refInfo;

@end
