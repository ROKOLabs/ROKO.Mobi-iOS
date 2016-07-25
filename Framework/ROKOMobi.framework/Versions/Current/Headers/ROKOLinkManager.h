//
//  ROKOLinkManager.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 21.01.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKOComponent.h"
#import "ROKOLink.h"

typedef void (^ROKOCreateLinkResponseBlock)(NSString * __nullable linkURL, NSNumber * __nullable linkId, NSError * __nullable error);

@class ROKOLinkManager;

@protocol ROKOLinkManagerDelegate <NSObject>

@optional

- (void)linkManager:(nonnull ROKOLinkManager *)manager didOpenDeepLink:(nonnull ROKOLink *)link;
- (void)linkManager:(nonnull ROKOLinkManager *)manager didFailToOpenDeepLinkWithError:(nullable NSError *)error;

@end

/**
 *  Manages deep and universal links
 */
@interface ROKOLinkManager : ROKOComponent

/**
 *  Delegate of ROKOLink manager object
 */
@property (nonatomic, weak) _Nullable id<ROKOLinkManagerDelegate> delegate;

/**
 *  Handles deep link if the link is from ROKO
 *
 *  @param url Link to be handled
 */
- (void)handleDeepLink:(nonnull NSURL *)url;

/**
 *  Handle restoration from an NSUserActivity, returning whether or not the restoration was from a ROKO universal link
 *
 *  @param userActivity The NSUserActivity that caused the application opening
 */
- (void)continueUserActivity:(nonnull NSUserActivity *)userActivity;

/**
 *  Generates a new link on Portal
 *
 *  @param linkName     Desired name of the link. Can be used on portal
 *  @param linkType     Type of the new link
 *  @param sourceURL    Final part of the link (after domain). Request returns error if another link with the same vanity already exists
 *  @param shareChannel Name of share channel that will be used to distribute the link
 *  @param settings     Additional settings
 *  @param sharingCode  Promo or referral code to be shared. Used for ROKOLinkTypePromo and ROKOLinkTypeReferral only
 *  @param block        Completion block
 */
- (void)createLinkWithName:(nullable NSString *)linkName type:(ROKOLinkType)linkType sourceURL:(nullable NSString*)sourceURL channelName:(nullable NSString *)shareChannel sharingCode:(nullable NSString *)sharingCode advancedSettings:(nullable NSDictionary *)settings completionBlock:(nullable ROKOCreateLinkResponseBlock)block;

@end
