//
//  RSActivityViewController.h
//  ROKOShare
//
//  Created by Katerina Vinogradnaya on 08.05.14.
//  Copyright (c) 2014 ROKOLabs LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RSSettingsManager.h"

typedef NS_ENUM (NSInteger, RSActivityViewControllerResult) {
	kRSActivityViewControllerResultDone = 0,
	kRSActivityViewControllerResultCancelled,
	kRSActivityViewControllerResultFailed
};


@class RSActivityViewController;

@protocol RSActivityViewControllerDelegate <NSObject>

@optional
- (void)activityController:(RSActivityViewController *)controller didFinishWithActivityType:(RSActivityType)activityType result:(RSActivityViewControllerResult)result;
- (void)activityControllerDidCancel:(RSActivityViewController *)controller;

@end


@interface RSActivityViewController : UIViewController

@property (weak, nonatomic) id<RSActivityViewControllerDelegate>delegate;

/**
 *  ROKOShareScheme for customizing appearence of view
 */
@property (strong, nonatomic) ROKOShareScheme *shareScheme;
/**
 *  shouldLoadSchemeFromPortal if YES load scheme from portal, if NO scheme should be configured locally
 */
@property (assign, nonatomic) BOOL shouldLoadSchemeFromPortal;

+ (instancetype)buildController;

- (void)addSubject:(NSString *)subject;
- (void)addShareMessage:(NSString *)shareMessage;
- (void)addDisplayMessage:(NSString *)displayMessage;
- (void)addURL:(NSURL *)URL;
- (void)addBackgroundImage:(UIImage *)image;

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, copy) NSString *contentId;

@end
