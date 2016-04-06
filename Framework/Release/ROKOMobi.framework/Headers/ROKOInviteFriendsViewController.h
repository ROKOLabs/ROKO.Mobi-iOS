//
//  ROKOInviteFriendsViewController.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 16.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ROKOInviteScheme.h"

/**
 *  Allows user to invite his friends to your application
 */
@interface ROKOInviteFriendsViewController : UIViewController

/**
 *  Current UI scheme
 */
@property (nonatomic, strong) ROKOInviteScheme *scheme;

/**
 *  Creates new instance of the controller. Works for logged in user only
 *
 *  @return New controller or nil if user is not logged in
 */
+ (ROKOInviteFriendsViewController *)buildController;

@end
