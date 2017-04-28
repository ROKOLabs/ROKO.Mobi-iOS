//
//  ROKOInstaBotConversationTree.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 13.09.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"
#import "ROKOInstaBotCustomProperty.h"
#import "ROKOInstaBotConversationAction.h"

typedef NS_ENUM(NSInteger, ROKOConversationTreeNodePromptType) {
	ROKOConversationTreeNodePromptTypeUndefined,
	ROKOConversationTreeNodePromptTypeStatement,
	ROKOConversationTreeNodePromptTypeFreeText,
	ROKOConversationTreeNodePromptTypeMultipleChoice,
	ROKOConversationTreeNodePromptTypeRichMediaCard
};

typedef NS_ENUM(NSInteger, ROKOConversationTreeNodeErrorAction) {
	ROKOConversationTreeNodeErrorActionEmpty,
	ROKOConversationTreeNodeErrorActionResend,
	ROKOConversationTreeNodeErrorActionContinue
};

@interface ROKOInstaBotConversationTreeNode : ROKODataObject

@property (nonatomic, assign) ROKOConversationTreeNodePromptType promptType;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, strong) NSString *image;
@property (nonatomic, strong) ROKOInstaBotCustomProperty *customProperty;
@property (nonatomic, copy) NSString *validationErrorMessage;
@property (nonatomic, assign) ROKOConversationTreeNodeErrorAction errorAction;
@property (nonatomic, strong) NSArray <ROKOInstaBotConversationAction *> *actions;

@end
