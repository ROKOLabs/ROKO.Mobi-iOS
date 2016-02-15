//
//  ROKOLinkManager.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 21.01.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

//#import <Foundation/Foundation.h>
#import "ROKOComponent.h"
#import "ROKOLink.h"

typedef void (^ROKOCreateLinkResponseBlock)(NSString *linkURL, NSError *error);

@class ROKOLinkManager;

@protocol ROKOLinkManagerDelegate <NSObject>

@optional

- (void)linkManager:(ROKOLinkManager *)manager didOpenDeepLink:(ROKOLink *)link;
- (void)linkManager:(ROKOLinkManager *)manager didFailToOpenDeepLinkWithError:(NSError *)error;

@end

/**
 *  Manages deep and universal links
 */
@interface ROKOLinkManager : ROKOComponent

@property (nonatomic, weak) id<ROKOLinkManagerDelegate> delegate;


/**
 *  Handles deep link if the link is from ROKO
 *
 *  @param url Link to be handled
 */
- (void)handleDeepLink:(NSURL *)url;

/**
 *  Handle restoration from an NSUserActivity, returning whether or not the restoration was from a ROKO univeral link
 *
 *  @param userActivity The NSUserActivity that caused the application opening
 */
- (void)continueUserActivity:(NSUserActivity *)userActivity;

/**
 *  Generates a new link on Portal
 *
 *  @param linkName     Desired name of the link. Can be used on portal
 *  @param linkType     Type of the new link
 *  @param valityLink   Final part of the link (after domain). Request returns error if another link with the same vality already exists
 *  @param shareChannel Name of share channel that will be used to destribute the link
 *  @param settings     Additional settings
 *  @param code         Promo or referral code to be shared. Used for ROKOLinkTypePromo and ROKOLinkTypeReferral only
 *  @param block        Completion block
 */
- (void)createLinkWithName:(NSString *)linkName type:(ROKOLinkType)linkType vanityLink:(NSString*)valityLink channelName:(NSString *)shareChannel code:(NSString *)code advancedSettings:(NSDictionary *)settings completionBlock:(ROKOCreateLinkResponseBlock)block;

@end
