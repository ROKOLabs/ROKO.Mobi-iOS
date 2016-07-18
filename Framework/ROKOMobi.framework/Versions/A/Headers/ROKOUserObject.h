//
//  ROKOUserObject.h
//  ROKOMobi
//
//  Created by Maslov Sergey on 18.08.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"

/**
 *  Stores information about ROKO Portal user
 */
@interface ROKOUserObject : ROKODataObject

/**
 *  Date when user signed up
 */
@property (nonatomic, copy) NSString *createDate;

/**
 *  User email
 */
@property (nonatomic, copy) NSString *email;

/**
 *  Date when user log into app at the first time
 */
@property (nonatomic, copy) NSString *firstLoginTime;

/**
 *  Previous login time
 */
@property (nonatomic, copy) NSString *lastLoginTime;

/**
 *  Phone number
 */
@property (nonatomic, copy) NSString *phone;

/**
 *  URL to user avatar
 */
@property (nonatomic, copy) NSString *photoFile;

/**
 *  Referral code
 */
@property (nonatomic, copy) NSString *referralCode;

/**
 *  Additional properties that was set to user on the portal
 */
@property (nonatomic, strong) NSDictionary *systemProperties;

/**
 *  Date when user data was updated
 */
@property (nonatomic, copy) NSString *updateDate;

/**
 *  Login name
 */
@property (nonatomic, copy) NSString *username;

@end
