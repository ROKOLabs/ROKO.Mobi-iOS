//
//  ROKOLogger.h
//  ROKOComponents
//
//  Created by Alexey Golovenkov on 16.03.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKOComponent.h"

/**
 *  Allows developer to send analytic events
 */
@interface ROKOLogger : ROKOComponent

/**
 *  Singleton ROKOLogger object
 *
 *  @return Default logger linked to default component manager
 */
+ (ROKOLogger *)sharedLogger;

/**
 *  Sends analytic event to ROKO Analytics. Stores message in local db if server is not avaliable
 *
 *  @param eventTitle      Event name
 *  @param eventParameters Optional parameters for the event. Can be nil.
 */
- (void)addEvent:(NSString *)eventTitle withParameters:(NSDictionary *)eventParameters;

@end
