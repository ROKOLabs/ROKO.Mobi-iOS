//
//  ROKOInviteButtonScheme.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 11.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentScheme.h"
#import "ROKOFontDataObject.h"

/**
 *  UI Scheme for a button on Invite Friends screen
 */
@interface ROKOInviteButtonScheme : ROKOComponentScheme

/**
 *  Background color of the button
 */
@property (nonatomic, strong) UIColor *color;

/**
 *  Title of the button
 */
@property (nonatomic, strong) NSString *title;

/**
 *  Title font description
 */
@property (nonatomic, strong) ROKOFontDataObject *font;

/**
 *  Image for the button
 */
@property (nonatomic, strong) ROKOImageDataObject *imageInfo;

/**
 *  Indicates whether the button exists on the Invite screen
 */
@property (nonatomic, assign) BOOL enabled;

/**
 *  The button should display text only if value of this property is YES. Otherwise The button should display an image
 */
@property (nonatomic, assign) BOOL textButton;

@end
