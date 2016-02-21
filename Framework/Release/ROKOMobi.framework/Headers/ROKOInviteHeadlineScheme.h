//
//  ROKOInviteHeadlineScheme.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 12.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentScheme.h"
#import "ROKOFontDataObject.h"

@interface ROKOInviteHeadlineScheme : ROKOComponentScheme

@property (nonatomic, copy) NSString *text;
@property (nonatomic, strong) ROKOFontDataObject *font;

@end
