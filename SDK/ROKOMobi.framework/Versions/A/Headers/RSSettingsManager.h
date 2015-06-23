//
//  RSSettingsManager.h
//  ROKOShareDemo
//
//  Created by Katerina Vinogradnaya on 7/31/14.
//  Copyright (c) 2014 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKOShareActivityScheme.h"

typedef void (^RSSettingsManagerCompletion)(NSError *error);

@interface RSSettingsManager : NSObject

@property (strong, nonatomic) ROKOShareScheme *promptViewAttributes;
@property (strong, nonatomic) ROKOShareScheme *messageViewAttributes;
@property (strong, nonatomic) ROKOShareScheme *backgroundViewAttributes;
@property (strong, nonatomic) NSMutableArray *enabledActivities;

+ (instancetype)sharedManager;
+ (void)buildSettingsWithCompletion:(RSSettingsManagerCompletion)completion;
+ (ROKOShareActivityScheme *)attributesForActivityType:(RSActivityType)type;
@end
