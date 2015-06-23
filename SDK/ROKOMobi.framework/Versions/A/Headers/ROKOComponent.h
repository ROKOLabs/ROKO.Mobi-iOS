//
//  ROKOComponent.h
//  ROKOComponents
//
//  Created by Alexey Golovenkov on 01.06.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ROKOComponentManager;

/**
 *  Base class for all components
 */
@interface ROKOComponent : NSObject

@property (nonatomic, weak) IBOutlet ROKOComponentManager *manager;

/**
 *  Initializes new component with specified manager;
 *
 *  @param manager Manager for the new component. Method uses [ROKOComponentManager sharedManager] if value of this parameter is nil
 *
 *  @return Initialized object
 */
- (id)initWithManager:(ROKOComponentManager *)manager;

- (NSString *)baseURL;
- (NSString *)apiToken;

@end
