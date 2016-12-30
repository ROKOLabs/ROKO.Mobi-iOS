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
@class ROKOPortalInfo;
@class ROKOSessionInfo;
@class ROKOReferralDiscountItem;

typedef void(^ROKOPortalRequestCompletionBlock)(NSError * __nullable error);
typedef void(^ROKOPortalRequestApplicationsCompletionBlock)(NSArray * __nullable applications, NSError * __nullable error);
typedef void(^ROKOPortalRequestReferralRewardListCompletionBlock)(NSArray <ROKOReferralDiscountItem *>* __nullable rewards, NSError * __nullable error);
typedef void(^ROKOPortalInfoRequestCompletionBlock)(ROKOPortalInfo * __nullable info, NSError *__nullable error);
typedef void(^ROKOSessionInfoRequestCompletionBlock)(ROKOSessionInfo * __nullable info, NSError *__nullable error);

#import "ROKOUserObject.h"
#import "ROKOPortalInfo.h"
#import "ROKOSessionInfo.h"

/**
 *  Provides API for login/logout/signup to ROKO Portal. Uses ROKOHTTPClient.
 */
@interface ROKOPortalManager : ROKOComponent

/**
 *  Checks if user is logged in
 */
@property (nonatomic, readonly) BOOL isLogin;

/**
 *  Session key
 */
@property (nullable, nonatomic, strong) NSString *sessionKey;

/**
 *  Information about user. Contains nil if user is not logged in
 */
@property (nullable, nonatomic, strong) ROKOUserObject *userInfo;

/**
 *  Attempts to login with specified credentials
 *
 *  @param name            user name
 *  @param password        user password
 *  @param completionBlock Completion block. Called both for successful and error result.
 */
- (void)loginWithUser:(nonnull NSString *)name andPassword:(nonnull NSString *)password completionBlock:(nullable ROKOPortalRequestCompletionBlock)completionBlock;

/**
 *  Attempts to login as a referral user
 *
 *  @param userName        User name
 *  @param code            Referral code (if necessary)
 *  @param shareChannel    Use this parameter to specify share channel in case if user signs up via deep link
 *  @param completionBlock Completion block. Called both for successful and error result.
 */
- (void)setUserWithName:(nonnull NSString *)userName referralCode:(nullable NSString *)code linkShareChannel:(nullable NSString *)shareChannel completionBlock:(nullable ROKOPortalRequestCompletionBlock)completionBlock;

/**
 *  Logs out from portal
 *
 *  @param completionBlock Calls on response received
 */
- (void)logoutWithCompletionBlock:(nullable ROKOPortalRequestCompletionBlock)completionBlock;
- (void)getApplicationsUsingEmail:(nonnull NSString *)email completionBlock:(nullable ROKOPortalRequestApplicationsCompletionBlock)completionBlock;

/**
 *  Registers new portal user
 *
 *  @param name            User name
 *  @param email           User e-mail address
 *  @param password        User password
 *  @param ambassadorCode  Referral code
 *  @param shareChannel    Use this parameter to specify share channel in case if user signs up via deep link
 *  @param completionBlock Completion block. Called when server response is received. Contains error description in case of fail
 */
- (void)signupUser:(nonnull NSString *)name email:(nonnull NSString *)email andPassword:(nonnull NSString *)password ambassadorCode:(nullable NSString *)ambassadorCode linkShareChannel:(nullable NSString *)shareChannel completionBlock:(nullable ROKOPortalRequestCompletionBlock)completionBlock;

/**
 *  Loads information about portal application
 *
 *  @param completionBlock Completion block. Called when server response is received. Contains ROKOPortalInfo object or error in case of fail
 */
- (void)getPortalInfoWithCompletionBlock:(nonnull ROKOPortalInfoRequestCompletionBlock)completionBlock;

/**
 *  Loads information about current user session
 *
 *  @param completionBlock Completion block. Called when server response is received. Contains ROKOSessionInfo object or error in case of fail
 */
- (void)getSessionInfoWithCompletionBlock:(nonnull ROKOSessionInfoRequestCompletionBlock)completionBlock;

/**
 Sets new custom property for the current user
 
 @param newValue New parameter value
 @param name  Name of parameter to be changed
 @param block Completion block to be called when request is finished
 */
- (void)setUserCustomProperty:(nullable id)newValue forKey:(nonnull NSString *)name completionBlock:(nullable ROKOPortalRequestCompletionBlock)block;

@end
