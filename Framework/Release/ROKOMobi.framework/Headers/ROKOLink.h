//
//  ROKOLink.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 21.01.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"

@interface ROKOLink : ROKODataObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSDictionary *settings;

@end
