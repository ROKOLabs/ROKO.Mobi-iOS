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
#import "ROKOInviteMessage.h"

/**
 *  UI scheme for Invite Friends view
 */
@interface ROKOInviteScheme : ROKOComponentScheme

/**
 *  Invite button scheme
 */
@property (nonatomic, strong) ROKOInviteButtonScheme *inviteButton;

/**
 *  Share button scheme
 */
@property (nonatomic, strong) ROKOInviteButtonScheme *shareButton;

/**
 *  Close button scheme
 */
@property (nonatomic, strong) ROKOInviteButtonScheme *closeButton;

/**
 *  Backgound color of the view
 */
@property (nonatomic, strong) UIColor *backgroundColor;

/**
 *  Headline scheme
 */
@property (nonatomic, strong) ROKOInviteHeadlineScheme *headline;

/**
 *  Navigation bar UI description
 */
@property (nonatomic, strong) ROKOInviteNavigationScheme *navigationInfo;

/**
 *  Invite message. May contain different messages for SMS and Email
 */
@property (nonatomic, strong) ROKOInviteMessage *inviteMessage;

@end
