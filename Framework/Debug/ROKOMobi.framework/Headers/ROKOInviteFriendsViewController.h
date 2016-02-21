//
//  ROKOInviteFriendsViewController.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 16.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ROKOInviteCustomizer.h"
#import "ROKOInviteScheme.h"

@interface ROKOInviteFriendsViewController : UIViewController

@property (nonatomic, strong) ROKOInviteScheme *scheme;
@property (nonatomic, strong) ROKOInviteCustomizer *customizer;

+ (ROKOInviteFriendsViewController *)buildController;

@end
