//
//  ROKOShareActivityScheme.h
//  ROKOShareDemo
//
//  Created by Katerina Vinogradnaya on 8/1/14.
//  Copyright (c) 2014 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKOShareScheme.h"
#import "ROKOShareChannelScheme.h"

@interface ROKOShareActivityScheme : ROKOShareScheme
@property (assign, nonatomic) RSActivityType type;
@property (assign, nonatomic) NSInteger index;
@property (assign, nonatomic) CGSize size;

- (instancetype)initWithType:(RSActivityType)type;

@end
