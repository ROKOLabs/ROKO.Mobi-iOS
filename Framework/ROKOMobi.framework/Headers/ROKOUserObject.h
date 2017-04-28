//
//  ROKOUserObject.h
//  ROKOMobi
//
//  Created by Maslov Sergey on 18.08.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import "ROKOUserIcon.h"
#import "ROKOReferralProgram.h"

/**
 *  Stores information about ROKO Portal user
 */
@interface ROKOUserObject : ROKODataObject

/**
 *  Date when user signed up
 */
@property (nonatomic, copy, nullable) NSString *createDate;

/**
 *  User email
 */
@property (nonatomic, copy, nullable) NSString *email;

/**
 *  Date when user log into app at the first time
 */
@property (nonatomic, copy, nullable) NSString *firstLoginTime;

/**
 *  Previous login time
 */
@property (nonatomic, copy, nullable) NSString *lastLoginTime;

/**
 *  Phone number
 */
@property (nonatomic, copy, nullable) NSString *phone;

/**
 *  User avatar image object
 */
@property (nonatomic, strong, nullable) ROKOUserIcon *photoFile;

/**
 *  Referral code
 */
@property (nonatomic, copy, nullable) NSString *referralCode;

/**
 *  Additional properties that was set to user on the portal
 */
@property (nonatomic, strong, nullable) NSDictionary *systemProperties;

/**
 *  Date when user data was updated
 */
@property (nonatomic, copy, nullable) NSString *updateDate;

/**
 *  Login name
 */
@property (nonatomic, copy, nullable) NSString *username;

/**
 *  Referral Program Info
 */
@property (nonatomic, strong, nullable) ROKOReferralProgram *referralProgram;

/**
 * 	Subscripting
 */
- (nullable id)objectForKeyedSubscript:(nonnull NSString *)key;
- (void)setObject:(nonnull id)obj forKeyedSubscript:(nonnull NSString *)key;
@end
