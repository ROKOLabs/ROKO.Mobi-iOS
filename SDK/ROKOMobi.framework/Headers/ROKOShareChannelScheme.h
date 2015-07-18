//
//  ROKOShareChannelScheme.h
//  ROKOShare
//
//  Created by Denis Kempest on 6/11/15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import "ROKOComponentScheme.h"

typedef NS_ENUM (NSInteger, RSActivityType) {
	kRSActivityTypeEmail = 0,
	kRSActivityTypeTwitter,
	kRSActivityTypeFacebook,
	kRSActivityTypeMessage
};

@interface ROKOShareChannelScheme : ROKOComponentScheme

@property (nonatomic, strong) NSString *bodyText;
@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, strong) ROKOImageDataObject *imageFileGroup;
@property (nonatomic, assign) RSActivityType type;

@end
