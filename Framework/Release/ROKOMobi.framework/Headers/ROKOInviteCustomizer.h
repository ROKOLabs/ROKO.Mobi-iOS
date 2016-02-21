//
//  ROKOInviteCustomizer.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 11.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentCustomizer.h"
#import "ROKOInviteScheme.h"

typedef void (^ROKOInviteCustomizerCompletionBlock)(ROKOInviteScheme *scheme, NSError *error);

@interface ROKOInviteCustomizer : ROKOComponentCustomizer

- (void)loadSchemeWithCompletionBlock:(ROKOInviteCustomizerCompletionBlock)completionBlock;

@end
