//
//  ROKOPortalInfo.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 07.11.15.
//  Copyright © 2015 ROKO Labs. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Information about API
 */
@interface ROKOPortalInfo : NSObject

/**
 *  API version
 */
@property (nonatomic, copy) NSString *version;

/**
 *  Application name
 */
@property (nonatomic, copy) NSString *applicationName;

@end
