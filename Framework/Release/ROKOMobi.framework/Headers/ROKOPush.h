//
//  ROKOPush.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 28.07.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import "ROKOComponent.h"
#import "ROKOHTTPClient.h"

/**
 *  Manages push notifications
 */
@interface ROKOPush : ROKOComponent

/**
 *  Registers device token on ROKO Portal
 *
 *  @param apnToken Token from application:didRegisterForRemoteNotificationsWithDeviceToken: method of UIApplicationDelegate object
 *  @param completion Block to be call when response is received (or error occurred)
 */
- (void)registerWithAPNToken:(NSData *)apnToken withCompletion:(ROKOHTTPClientCompletion)completion;

/**
 *  Default handler for push notification
 *
 *  @param notification Notification that comes to application:didReceiveRemoteNotification: method of UIApplicationDelegate object
 */
- (void)handleNotification:(NSDictionary *)notification;

/**
 *  Check ROKO-Portal status for push notification registration
 *
 *  @param completion Block to be call when response is received (or error occurred)
 */
- (void)checkRegistrationWithCompletion:(ROKOHTTPClientCompletion)completion;

/**
 *  Remove ROKO-Portal registration for push notification
 *
 *  @param completion Block to be call when response is received (or error occurred)
 */
- (void)removeRegistrationWithCompletion:(ROKOHTTPClientCompletion)completion;

/**
 *  Analyzes push notification and returns promo code in case if the notification is promo
 *
 *  @param notification JSON
 *
 *  @return Promo code or nil
 */
- (NSString *)promoCodeFromNotification:(NSDictionary *)notification;

- (void)showOverlayWithId:(NSInteger)overlayId;

- (void)showPromoCampaignWithId:(NSInteger)campaignId;

@end
