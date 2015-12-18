//
//  ROKOUserObject.h
//  ROKOMobi
//
//  Created by Maslov Sergey on 18.08.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import <ROKOMobi/ROKOMobi.h>
#import "ROKODataObject.h"

/**
 *  Stores information about ROKO Portal user
 */
@interface ROKOUserObject : ROKODataObject

@property (nonatomic, copy) NSString *createDate;
@property (nonatomic, strong) ROKODataObject *developmentCompany;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *firstLoginTime;
@property (nonatomic, copy) NSString *lastLoginTime;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *photoFile;
@property (nonatomic, copy) NSString *referralCode;
@property (nonatomic, strong) NSDictionary *systemProperties;
@property (nonatomic, copy) NSString *updateDate;
@property (nonatomic, copy) NSString *username;

@end
