//
//  ROKOShareChannelScheme.h
//  ROKOShare
//
//  Created by Denis Kempest on 6/11/15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import "ROKOComponentScheme.h"

/**
 *  Possible share channels
 */
typedef NS_ENUM(NSInteger, ROKOShareChannelType){
	
	/**
	 *  Unspecified channel
	 */
	ROKOShareChannelTypeUnknown = 0,
	/**
	 *  E-mail share channel
	 */
	ROKOShareChannelTypeEmail,
	/**
	 *  Twitter share channel
	 */
	ROKOShareChannelTypeTwitter,
	/**
	 *  Facebook share channel
	 */
	ROKOShareChannelTypeFacebook,
	/**
	 *  Message share channel. Can be used to send SMS/MMS
	 */
	ROKOShareChannelTypeMessage,
    /**
     *  Copy share channel. Used for referral code sharing.
     *  Copies referral code to clipboard
     */
    ROKOShareChannelTypeCopy
};

/**
 *  Describes share cannel
 */
@interface ROKOShareChannelScheme : ROKOComponentScheme

/**
 *  Default text to comment share item
 */
@property (nonatomic, copy) NSString *bodyText;

/**
 *  Subject of e-mail message. For mail sharing only.
 */
@property (nonatomic, copy) NSString *subjectText;

/**
 *  Header of e-mail message. For mail sharing only.
 */
@property (nonatomic, copy) NSString *headerText;

/**
 *  Footer of e-mail message. For mail sharing only
 */
@property (nonatomic, copy) NSString *footerText;

/**
 *  Indicates if e-mail bodyText property should be used as subject of message. For mail sharing only
 */
@property (nonatomic, assign) BOOL subjectFromSource;

/**
 *  Indicates if the current channel is enabled
 */
@property (nonatomic, assign) BOOL enabled;

/**
 *  Icon of the channel
 */
@property (nonatomic, strong) ROKOImageDataObject *imageFileGroup;

/**
 *  Type of the channel
 */
@property (nonatomic, assign) ROKOShareChannelType type;

@end
