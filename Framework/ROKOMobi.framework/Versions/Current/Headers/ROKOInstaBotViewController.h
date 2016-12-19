//
//  ROKOInstaBotViewController.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 06.09.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ROKOInstaBot;

@interface ROKOInstaBotViewController : UIViewController

+ (instancetype)buildControllerWithBot:(ROKOInstaBot *)bot;

- (void)showAsOverlay;

@end
