//
//  RSActivityViewController.h
//  ROKOShare
//
//  Created by Katerina Vinogradnaya on 08.05.14.
//  Copyright (c) 2014 ROKOLabs LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ROKOShareScheme.h"

@class ROKOShare;

/**
 *  Possible values of sharing process
 */
typedef NS_ENUM(NSInteger, ROKOSharingResult){
	/**
	 *  Content was successfully shared
	 */
	ROKOSharingResultDone = 0,
	/**
	 *  Sharing was cancelled by used
	 */
	ROKOSharingResultCancelled,
	/**
	 *  Content was not shared because of error
	 */
	ROKOSharingResultFailed
};


@class ROKOShareViewController;


/**
 *  Share view controller
 */
@interface ROKOShareViewController : UIViewController

/**
 *  ROKOShare object that incapsulates sharing logic. Lazy-loading property.
 */
@property (nonatomic, strong) ROKOShare *shareManager;

/**
 *  shouldLoadSchemeFromPortal if YES load scheme from portal, if NO scheme should be configured locally
 */
@property (assign, nonatomic) BOOL shouldLoadSchemeFromPortal;

/**
 *  Default comment for sharing content
 */
@property (copy, nonatomic) NSString *displayMessage;

/**
 *  Background image for share view
 */
@property (weak, nonatomic) UIImage *backgroundImage;

/**
 *  Creates a new instance of RSActivityViewController
 *
 *  @return New RSActivityViewController object
 */
+ (instancetype)buildController;

/**
 *  Creates a RSActivityViewController object for referral code sharing. Works for registered user only
 *
 *  @return New RSActivityViewController object or nil if user is not logged in
 */
+ (instancetype)buildReferralShareController;

@end
