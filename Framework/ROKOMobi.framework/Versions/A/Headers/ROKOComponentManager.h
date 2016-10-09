//
//  ROKOComponentManager.h
//  ROKOComponents
//
//  Created by Katerina Vinogradnaya on 6/27/14.
//  Copyright (c) 2014 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, ROKOStatusCode) {
	ROKOStatusCodeSuccess = 0,
	ROKOStatusCodeAuthenticationFailed,
	ROKOStatusCodeAccessDenied,
	ROKOStatusCodeObjectNotFound,
	ROKOStatusCodeBadRequest,
	ROKOStatusCodeObjectAlreadyExists,
	ROKOStatusCodeBadParameterValue,
	ROKOStatusCodeAPIKeyMissed,
	ROKOStatusCodeAPIKeyInvalid,
	ROKOStatusCodePushNotificationScheduleInvalid,
	ROKOStatusCodeObjectInUse,
	ROKOStatusCodeDevCompanyAlreadyExists,
	ROKOStatusCodeUserTypeInvalid,
	ROKOStatusCodeDeepLinkConfigurationInvalid,
    ROKOStatusCodeDeepLinkIncorrectDomainOrScheme,
	ROKOStatusCodeIncentiveProgramIsNotActive,
	ROKOStatusCodeDiscountIsNotEnabled,
	ROKOStatusCodeUnknownError
};

extern NSString *const kROKOPushPageNotification;
extern NSString *const kROKOPushPageIndexKey;

@class ROKOHTTPClient;
@class ROKOPortalManager;

typedef void (^ROKOComponentManagerCompletion)(ROKOStatusCode statusCode, NSError *error);

/**
 *  Manages instances of ROKOComponent inheritors
 */
@interface ROKOComponentManager : NSObject

/**
 *  Path to server API. Sample: "api.roko.mobi/v1/". Default value loads from ROKOMobiAPIURL value of application's info.plist file
 */
@property (nonatomic, copy) NSString *baseURL;

/**
 *  API token of the application to work with. Default value loads from ROKOMobiAPIToken value of application's info.plist file
 */
@property (nonatomic, copy) NSString *apiToken;

/**
 *  Indicates if token and base URL are correct and components can be used without limitations
 */
@property (nonatomic, assign) BOOL isApiTokenValid;

/**
 *  Default instance of ROKOComponentManager
 */
+ (instancetype)sharedManager;

/**
 *  Initializes a new instance of component manager.
 *
 *  @param baseURL Path to API
 *
 *  @return Initialized manager
 */
- (instancetype)initWithURL:(NSString *)baseURL;

/**
 *  @return HTTP client associated with current manager
 */
- (ROKOHTTPClient *)baseHTTPClient;

/**
 *  @return Portal manager associated with current manager
 */
- (ROKOPortalManager *)portalManager;

/**
 *  Registers an object to be accessed by name
 *
 *  @param object     Object to be stored
 *  @param objectName String that identifies the object
 */
- (void)registerObject:(NSObject *)object withName:(NSString *)objectName;

/**
 *  Finds an object in the list of registered objects by it's name.
 *
 *  @param objectName Object identifier
 *
 *  @return Found object or nil if there is no objects for given objectName
 */
- (NSObject *)objectWithName:(NSString *)objectName;

/**
 *  Removes the given object from the list of registered objects
 *
 *  @param object Object to be forgotten
 */
- (void)unregisterObject:(NSObject *)object;

/**
 *  Removes object with the given identifier from the list of registered object
 *
 *  @param objectName Identifier of object to be forgotten
 */
- (void)unregisterObjectWithName:(NSString *)objectName;

/**
 *  Asks server if the current session is valid
 *
 *  @param completion Block to be called when response is received
 */
- (void)checkApiTokenWithCompletion:(ROKOComponentManagerCompletion)completion;

/**
 *  Notify application to open page
 *
 *  @param linkTarget Describes page
 */
- (void)notififyDeveloperToOpenPage:(NSString*)linkTarget;

/**
 Notify appplication to open page. Notification name is stores in kROKOPushPageNotification constant.

 @param parameters Parameters to be stored in userInfo property of the sending notification
 */
+ (void)notifyDeveloperToOpenPageWithParameters:(NSDictionary *)parameters;

@end
