//
//  ROKOInviteNavigationScheme.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 12.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentScheme.h"
#import "ROKOFontDataObject.h"

/**
 *  Describes navigation bar of Invite Friends screen
 */
@interface ROKOInviteNavigationScheme : ROKOComponentScheme

/**
 *  Navigation bar title
 */
@property (nonatomic, copy) NSString *title;

/**
 *  Navigation bar font
 */
@property (nonatomic, strong) ROKOFontDataObject *font;

@end
