//
//  ROKOPush.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 28.07.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import "ROKOComponent.h"

/**
 *  Manages push notifications
 */
@interface ROKOPush : ROKOComponent

/**
 *  Registers device token on ROKO Portal
 *
 *  @param apnToken Token from application:didRegisterForRemoteNotificationsWithDeviceToken: method of UIApplicationDelegate object
 */
- (void)registerWithAPNToken:(NSData *)apnToken;

/**
 *  Default handler for push notification
 *
 *  @param notification Notification that comes to application:didReceiveRemoteNotification: method of UIApplicationDelegate object
 */
- (void)handleNotification:(NSDictionary *)notification;

@end
