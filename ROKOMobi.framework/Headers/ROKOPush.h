//
//  ROKOPush.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 28.07.15.
//  Copyright (c) 2015 ROKO Labs. All rights reserved.
//

#import "ROKOComponent.h"

@interface ROKOPush : ROKOComponent

- (void)registerWithAPNToken:(NSData *)apnToken;
- (void)handleNotification:(NSDictionary *)notification;

@end
