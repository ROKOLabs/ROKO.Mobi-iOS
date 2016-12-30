//
//  ROKOShare.h
//  ROKOShare
//
//  Created by Alexey Golovenkov on 16.06.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <AvailabilityMacros.h>

#import "ROKOComponent.h"
#import "ROKOShareViewController.h"
#import "ROKOShareCustomizer.h"

#define SHARE_CHANNEL_EMAIL @"Email"
#define SHARE_CHANNEL_FACEBOOK @"Facebook"
#define SHARE_CHANNEL_TWITTER @"Twitter"
#define SHARE_CHANNEL_SMS @"SMS"
#define SHARE_CHANNEL_COPY @"Copy"
#define SHARE_CHANNEL_UNKNOWN @"Unknown"

@class ROKOShare;

/**
 *  Delegate for ROKOShare object
 */
@protocol ROKOShareDelegate <NSObject>

@optional

/**
 *  Calls when activity controller shared it's content or closed by user
 *
 *  @param manager      Share manager that has finished sharing process
 *  @param activityType Sharing channel. Contains ROKOShareChannelTypeUknown if controller was closed
 *  @param result       Sharing result
 */
- (void)shareManager:(ROKOShare *)manager didFinishWithActivityType:(ROKOShareChannelType)activityType result:(ROKOSharingResult)result;

/**
 *  Calls before applying the share scheme. Delegate can use this method to change the cheme on the fly.
 *
 *  @param shareManager Manager that will use the scheme
 *  @param scheme       Scheme to be applied
 */
- (void)shareManager:(ROKOShare *)shareManager willApplyScheme:(ROKOShareScheme *)scheme;

/**
 *  Calls before show show final message composer. Delegate may implement this method, for example, to set recipient list.
 *
 *  @param shareManager    ROKOShare object that will show message composer
 *  @param messageComposer Message composer. Type of this composer depends on channel type:
 * 		MFMailComposeViewController for ROKOShareChannelTypeEmail
 * 		MFMessageComposeViewController for ROKOShareChannelTypeMessage
 * 		SLComposeViewController for ROKOShareChannelTypeFacebook and ROKOShareChannelTypeTwitter
 *  @param channelType     Current sharing channel
 */
- (void)shareManager:(ROKOShare *)shareManager willShowSharingMessageComposer:(id)messageComposer forShareChannelType:(ROKOShareChannelType)channelType;

@end

/**
 *  Incapsulates share logic
 */
@interface ROKOShare: ROKOComponent

/**
 *  Delegate of the Share component
 */
@property (weak, nonatomic) id<ROKOShareDelegate> delegate;

@property (strong, nonatomic) ROKOShareCustomizer *shareCustomizer;

@property (nonatomic, weak) UIViewController *presentingController;

/**
 Shows if deep link showld be generated on share. Ignored if link is already set
 */
@property (nonatomic, assign) BOOL needsDeepLink;

/**
 *  ROKOShareScheme for customizing appearence of view
 */
@property (strong, nonatomic) ROKOShareScheme *shareScheme;

/**
 *  Image to be shared
 */
@property (nonatomic, strong) UIImage *image;

/**
 *  Unique identifier of sharing content. May be nil
 */
@property (nonatomic, copy) NSString *contentId;

/**
 *  Identifier of sharing portal link. Set this property if you share deep link to get correct reports on ROKO portal
 */
@property (nonatomic, strong) NSNumber *linkId;

/**
 *  Type of sharing content. Used for analytic
 */
@property (nonatomic, copy) NSString *contentType;

/**
 *  Title of sharing content
 */
@property (nonatomic, copy) NSString *contentTitle;

/**
 *  Video data to be shared
 */
@property (nonatomic, strong) NSData *videoData;

/**
 *  PDF data to be shared
 */
@property (nonatomic, strong) NSData *pdfData;

/**
 *  URL of sharing content
 */
@property (strong, nonatomic) NSURL *contentURL;

/**
 *  Text to be shared
 */
@property (nonatomic, copy) NSString *text;

/**
 *  Shares content with specified channel
 *
 *  @param channelType Share channel to be used
 *
 *  @return nil if sharing composer created successfully or NSError object in case of issues
 */
- (NSError *)shareWithChannelType:(ROKOShareChannelType)channelType;

/**
 *  Sets special text for given share channel only
 *
 *  @param text        Text to be shared
 *  @param channelType Channel type for given text
 */
- (void)setText:(NSString *)text forShareChannel:(ROKOShareChannelType)channelType;

/**
 *  Blocks adding link to sharing text for specified channel
 *
 *  @param channelType Sharing channel that should not share link
 */
- (void)excludeLinkForShareChannel:(ROKOShareChannelType)channelType;

/**
 *  Allows to prefill recipients list for specified channel. Works for E-mail and SMS channles only
 *
 *  @param recipients  Recipients to be set to message composer. Array of strings.
 *  @param channelType Share channel to use the recipient list.
 */
- (void)setRecipients:(NSArray *)recipients forChannel:(ROKOShareChannelType)channelType;

/**
 *  Returns recipient list set for the specified channel
 *
 *  @param channelType Share channel
 *
 *  @return Array of strings set in setRecipients:forChannel:
 */
- (NSArray *)recipientsForChannel:(ROKOShareChannelType)channelType;

/**
 *  Load share scheme from Portal
 */
- (void)loadSchemeFromPortal;

- (void)addShareCompletionBlock:(void (^)(ROKOShareChannelType type, ROKOSharingResult result))completionBlock;

- (void)shareBegin;

- (void)shareClose;

/**
 *  Sends analytic event about successful finish of sharing process
 *
 *  @param channelType Share channel
 * 
 *  @return Method returns error if contentId field is not set. Event can not be sent in this case
 */
- (NSError *)shareCompleteForChannel:(ROKOShareChannelType)channelType;

- (void)shareOfLinkWithId:(NSNumber *)linkId completeForChannel:(ROKOShareChannelType)channelType DEPRECATED_ATTRIBUTE;

/**
 *  Sends analytic event about successful finish of promo code sharing
 *
 *  @param channelType Share channel
 */
- (void)promoSharedWithChannelType:(ROKOShareChannelType)channelType;

@end
