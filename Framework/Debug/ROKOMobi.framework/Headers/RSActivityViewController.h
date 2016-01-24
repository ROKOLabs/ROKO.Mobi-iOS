//
//  RSActivityViewController.h
//  ROKOShare
//
//  Created by Katerina Vinogradnaya on 08.05.14.
//  Copyright (c) 2014 ROKOLabs LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ROKOShareScheme.h"

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


@class RSActivityViewController;

/**
 *  Delegate for RSActivityViewController object
 */
@protocol RSActivityViewControllerDelegate <NSObject>

@optional

/**
 *  Calls when activity controller shared it's content or closed by user
 *
 *  @param controller   Closed controller
 *  @param activityType Sharing channel. Contains ROKOShareChannelTypeUknown if controller was closed
 *  @param result       Sharing result
 */
- (void)activityController:(RSActivityViewController *)controller didFinishWithActivityType:(ROKOShareChannelType)activityType result:(ROKOSharingResult)result;

/**
 *  Calls before applying the share scheme. Delegate can use this method to change the cheme on the fly.
 *
 *  @param controller Controller that will use the scheme
 *  @param scheme     Scheme to be applied
 */
- (void)activityController:(RSActivityViewController *)controller willApplyScheme:(ROKOShareScheme *)scheme;

/**
 *  Calls before show show final message composer. Delegate may implement this method, for example, to set recipient list.
 *
 *  @param controller      Active sharing controller
 *  @param messageComposer Message composer. Type of this composer depends on channel type:
 * 		MFMailComposeViewController for ROKOShareChannelTypeEmail
 * 		MFMessageComposeViewController for ROKOShareChannelTypeMessage
 * 		SLComposeViewController for ROKOShareChannelTypeFacebook and ROKOShareChannelTypeTwitter
 *  @param channelType     Current sharing channel
 */
- (void)activityController:(RSActivityViewController *)controller willShowSharingMessageComposer:(id)messageComposer forShareChannelType:(ROKOShareChannelType)channelType;

@end


/**
 *  Share view controller
 */
@interface RSActivityViewController : UIViewController

/**
 *  Delegate of the Share controller
 */
@property (weak, nonatomic) id<RSActivityViewControllerDelegate>delegate;

/**
 *  ROKOShareScheme for customizing appearence of view
 */
@property (strong, nonatomic) ROKOShareScheme *shareScheme;

/**
 *  shouldLoadSchemeFromPortal if YES load scheme from portal, if NO scheme should be configured locally
 */
@property (assign, nonatomic) BOOL shouldLoadSchemeFromPortal;

/**
 *  Image to be shared
 */
@property (nonatomic, strong) UIImage *image;

/**
 *  Background image for share view
 */
@property (weak, nonatomic) UIImage *backgroundImage;

/**
 *  Unique identifier of sharing content. May be nill
 */
@property (nonatomic, copy) NSString *contentId;

/**
 *  Type of sharing content. Used for analytic.
 */
@property (nonatomic, copy) NSString *contentType;

/**
 *  Default comment for sharing content
 */
@property (copy, nonatomic) NSString *displayMessage;

/**
 *  Video data to be shared
 */
@property (nonatomic, strong) NSData *videoData;

/**
 *  URL of sharing content
 */
@property (strong, nonatomic) NSURL *URL;

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
