//
//  RLComposerWorkflowController.h
//  ROKOStickers
//
//  Created by Alexey Golovenkov on 08.03.15.
//  Copyright (c) 2015 ROKOLabs. All rights reserved.
//

/// @name ROKOStickers

#import <UIKit/UIKit.h>

@class RLPhotoComposerController;
@class RLComposerWorkflowController;

typedef NS_ENUM (NSInteger, RLComposerWorkflowType) {
	kRLComposerWorkflowTypeCamera = 0,
	kRLComposerWorkflowTypePhotoPicker,
	kRLComposerWorkflowTypeStickersSelector
};

@protocol RLComposerWorkflowControllerDelegate <NSObject>

@optional

- (void)composerWorkflow:(RLComposerWorkflowController *)workflowController didOpenImagePicker:(UIViewController *)picker;
- (void)composerWorkflow:(RLComposerWorkflowController *)workflowController didSelectImage:(UIImage *)image;
- (void)composerWorkflow:(RLComposerWorkflowController *)workflowController didCloseImagePicker:(UIViewController *)picker;

@end

@interface RLComposerWorkflowController : UINavigationController

@property (strong, nonatomic) RLPhotoComposerController *composer;

@property (nonatomic, weak) IBOutlet id<RLComposerWorkflowControllerDelegate> workflowDelegate;
@property (nonatomic, assign, readonly) RLComposerWorkflowType type;

+ (instancetype)buildComposerWorkflowWithType:(RLComposerWorkflowType)type;

@end
