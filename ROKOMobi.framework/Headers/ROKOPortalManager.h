//
//  ROKOPortalManager.h
//  ROKODoodles
//
//  Created by Maslov Sergey on 03.08.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKOComponent.h"


@class ROKOUserObject;
@class ROKOPortalManager;

@protocol ROKOPortalManagerDelegate
@optional
- (void)portalManagerDidLogin:(nonnull ROKOPortalManager *)manager;
- (void)portalManagerDidLogout:(nonnull ROKOPortalManager *)manager;
- (void)portalManagerDidSignup:(nonnull ROKOPortalManager *)manager;
- (void)portalManagerDidReceive:(nonnull ROKOPortalManager *)manager allowedApplications:(nullable NSArray *)apps;

- (void)portalManager:(nonnull ROKOPortalManager *)manager didFailLoginWithError:(nonnull NSError *)error;
- (void)portalManager:(nonnull ROKOPortalManager *)manager didFailLogoutWithError:(nonnull NSError *)error;
- (void)portalManager:(nonnull ROKOPortalManager *)manager didFailSignupWithError:(nonnull NSError *)error;
- (void)portalManager:(nonnull ROKOPortalManager *)manager didFailReceiveAllowedApps:(nonnull NSError *)error;
@end

#import "ROKOUserObject.h"

/**
 *  Provides API for login/logout/signup to ROKO Portal. Uses ROKOHTTPClient.
 */
@interface ROKOPortalManager : ROKOComponent

/**
 *  Delegate which accept ROKOPortalManagerDelegate protocol
 */
@property (nullable, weak, nonatomic) id <ROKOPortalManagerDelegate> delegate;

@property (nonatomic, readonly) BOOL isLogin;
@property (nullable, nonatomic, strong) NSString *sessionKey;
@property (nullable, nonatomic, strong) ROKOUserObject *userInfo;

- (void)loginWithUser:(nonnull NSString *)name andPassword:(nonnull NSString *)password;
- (void)logout;
- (void)getApplicationsUsingEmail:(nonnull NSString *)email;
- (void)signupUser:(nonnull NSString *)name andPassword:(nonnull NSString *)password;
@end
