//
//  ROKODataObject.h
//  ROKOComponents
//
//  Created by Alexey Golovenkov on 21.04.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ROKODataObject : NSObject <NSCoding>

@property (nonatomic, strong) NSNumber *objectId;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (void)loadFromDictionary:(NSDictionary *)dictionary;

@end
