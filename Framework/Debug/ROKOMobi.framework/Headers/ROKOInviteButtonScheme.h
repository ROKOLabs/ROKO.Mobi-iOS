//
//  ROKOInviteButtonScheme.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 11.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentScheme.h"
#import "ROKOFontDataObject.h"

@interface ROKOInviteButtonScheme : ROKOComponentScheme

@property (nonatomic, strong) UIColor *color;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) ROKOFontDataObject *font;
@property (nonatomic, assign) BOOL enabled;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary prefix:(NSString *)prefix;

@end
