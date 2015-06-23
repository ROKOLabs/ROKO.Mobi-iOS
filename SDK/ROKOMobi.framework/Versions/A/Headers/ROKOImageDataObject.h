//
//  ROKOImageDataObject.h
//  ROKOComponents
//
//  Created by Alexey Golovenkov on 21.04.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ROKODataObject.h"

@interface ROKOImageDataObject : ROKODataObject

@property (nonatomic, strong) NSString *imageURL;
@property (nonatomic, strong) UIImage *image;

@end
