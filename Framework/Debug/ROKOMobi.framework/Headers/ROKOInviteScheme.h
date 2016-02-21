//
//  ROKOInviteScheme.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 11.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentScheme.h"
#import "ROKOInviteButtonScheme.h"
#import "ROKOInviteHeadlineScheme.h"
#import "ROKOInviteNavigationScheme.h"

@interface ROKOInviteScheme : ROKOComponentScheme

@property (nonatomic, strong) ROKOInviteButtonScheme *inviteButton;
@property (nonatomic, strong) ROKOInviteButtonScheme *shareButton;
@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) ROKOInviteHeadlineScheme *headline;
@property (nonatomic, strong) ROKOInviteNavigationScheme *navigationInfo;
@property (nonatomic, copy) NSString *inviteMessageText;

@end
