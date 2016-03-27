//
//  ROKOLink.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 21.01.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"

/**
 *  Possible types of link
 */
typedef NS_ENUM(NSInteger, ROKOLinkType) {
	
	/**
	 *  Manual created link. Can be created on portal only, not thru mobile SDK
	 */
	ROKOLinkTypeManual,

	/**
	 *  Link to share promo code
	 */
	ROKOLinkTypePromo,
	
	/**
	 *  Referral code link
	 */
	ROKOLinkTypeReferral,
	
	/**
	 *  Link for shared content
	 */
	ROKOLinkTypeShare
};

/**
 *  ROKO Deep Link.
 */
@interface ROKOLink : ROKODataObject

/**
 *  Name of the link
 */
@property (nonatomic, copy) NSString *name;

/**
 *  Advanced settings of the link. Come from portal.
 */
@property (nonatomic, strong) NSDictionary *settings;

/**
 *  Date when the link was created
 */
@property (nonatomic, strong) NSDate *createDate;

/**
 *  Date when the link was updated on Portal
 */
@property (nonatomic, strong) NSDate *updateDate;

/**
 *  Share channel name
 */
@property (nonatomic, copy) NSString *shareChannel;

/**
 *  Meaningful part of the link url (after domain)
 */
@property (nonatomic, copy) NSString *vanityLink;

/**
 *  Link with custom domain. For example, yourapp://link
 */
@property (nonatomic, copy) NSString *customDomainLink;

/**
 *  Type of the link
 */
@property (nonatomic, assign) ROKOLinkType type;

/**
 *  Referral code this link is targeted to
 */
@property (nonatomic, copy) NSString *referralCode;

/**
 *  Promo code this link is targeted to
 */
@property (nonatomic, copy) NSString *promoCode;

@end
