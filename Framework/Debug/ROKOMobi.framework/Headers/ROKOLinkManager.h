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

@end
