//
//  ROKOInviteHeadlineScheme.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 12.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentScheme.h"
#import "ROKOFontDataObject.h"

/**
 *  UI scheme for headline of Invite Friends view
 */
@interface ROKOInviteHeadlineScheme : ROKOComponentScheme

/**
 *  Headline text
 */
@property (nonatomic, copy) NSString *text;

/**
 *  Headline font
 */
@property (nonatomic, strong) ROKOFontDataObject *font;

@end
