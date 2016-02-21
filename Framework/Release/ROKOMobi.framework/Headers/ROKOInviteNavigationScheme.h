//
//  ROKOInviteNavigationScheme.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 12.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentScheme.h"
#import "ROKOFontDataObject.h"

@interface ROKOInviteNavigationScheme : ROKOComponentScheme

@property (nonatomic, copy) NSString *bannerText;
@property (nonatomic, strong) ROKOFontDataObject *bannerFont;

@end
