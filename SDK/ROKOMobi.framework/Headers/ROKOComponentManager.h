//
//  ROKOComponentManager.h
//  ROKOComponents
//
//  Created by Katerina Vinogradnaya on 6/27/14.
//  Copyright (c) 2014 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ROKOHTTPClient;

@interface ROKOComponentManager : NSObject

@property (nonatomic, copy) NSString *baseURL;
@property (nonatomic, copy) NSString *apiToken;
@property (nonatomic, readwrite) BOOL isActivityEnabled;

+ (instancetype)sharedManager;

- (instancetype)initWithURL:(NSString *)baseURL;

- (ROKOHTTPClient *)baseHTTPClient;

- (void)registerObject:(NSObject *)object withName:(NSString *)objectName;
- (NSObject *)objectWithName:(NSString *)objectName;
- (void)unregisterObject:(NSObject *)object;
- (void)unregisterObjectWithName:(NSString *)objectName;

@end
