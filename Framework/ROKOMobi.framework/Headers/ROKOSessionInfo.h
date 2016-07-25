//
//  ROKOSessionInfo.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 18.03.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ROKOUserObject;

@interface ROKOSessionInfo : NSObject

@property (nonatomic, strong) NSString *sessionKey;
@property (nonatomic, strong) NSDate *expirationDate;
@property (nonatomic, strong) ROKOUserObject *user;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
