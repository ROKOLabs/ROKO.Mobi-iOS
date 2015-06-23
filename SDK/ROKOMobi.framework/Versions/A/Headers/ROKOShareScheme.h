//
//  ROKOShareButtonScheme.h
//  ROKOShareDemo
//
//  Created by Katerina Vinogradnaya on 7/31/14.
//  Copyright (c) 2014 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ROKOComponentScheme.h"
#import "ROKOShareNavigationScheme.h"
#import "ROKOSharePreviewScheme.h"

@interface ROKOShareScheme : ROKOComponentScheme

@property (strong, nonatomic) NSMutableArray *channels;
@property (strong, nonatomic) UIColor *backgroundColor;
@property (strong, nonatomic) ROKOShareNavigationScheme *navigationScheme;
@property (strong, nonatomic) ROKOSharePreviewScheme *preivewScheme;

@end
