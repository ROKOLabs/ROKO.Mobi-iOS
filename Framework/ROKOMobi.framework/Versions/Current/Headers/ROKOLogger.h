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
+ (nonnull ROKOLogger *)sharedLogger;

/**
 Sends analytic event to ROKO Analytics. Stores message in local db if server is not avaliable
 
 @param eventTitle      Event name
 @param eventParameters Optional parameters for the event.
 @note Deprecated. Use +addEvent:withParameters: instead
 */
- (void)addEvent:(nonnull NSString *)eventTitle withParameters:(nullable NSDictionary *)eventParameters __deprecated_msg("Use +addEvent:withParameters: instead.");

/**
 Sends analytic event to ROKO Analytics. Stores message in local db if server is not avaliable

 @param eventTitle      Event name
 @param eventParameters Optional parameters for the event.
 */
+ (void)addEvent:(nonnull NSString *)eventTitle withParameters:(nullable NSDictionary *)eventParameters;

@end
