//
//  ROKOInviteCustomizer.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 11.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentCustomizer.h"
#import "ROKOInviteScheme.h"

/**
 *  Completion block for load Invite Friends UI scheme request
 *
 *  @param scheme Loaded and parsed scheme
 *  @param error  Error. Contains null if request is finished successully
 */
typedef void (^ROKOInviteCustomizerCompletionBlock)(ROKOInviteScheme * __nullable scheme, NSError * __nullable error);

/**
 *  UI customizer for ROKOInviteFriendsViewController
 */
@interface ROKOInviteCustomizer : ROKOComponentCustomizer

/**
 *  Loads UI Scheme from Portal
 *
 *  @param completionBlock Block to be called when scheme is loaded
 */
- (void)loadSchemeWithCompletionBlock:(ROKOInviteCustomizerCompletionBlock __nullable)completionBlock;

@end
