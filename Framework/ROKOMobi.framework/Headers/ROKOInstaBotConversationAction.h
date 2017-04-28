//
//  ROKOInstaBotConversationAction.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 14.09.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"

typedef NS_ENUM (NSInteger, ROKOInstaBotConversationActionType) {
	ROKOInstaBotConversationActionTypeTextPrompt,
	ROKOInstaBotConversationActionTypeLink,
	ROKOInstaBotConversationActionTypeAppPage,
	ROKOInstaBotConversationActionTypeShare,
	ROKOInstaBotConversationActionTypeClose
};

@class ROKOInstaBotConversationTreeNode;
@class ROKOImageDataObject;

@interface ROKOInstaBotConversationAction : ROKODataObject

@property (nonatomic, assign) ROKOInstaBotConversationActionType type;
@property (nonatomic, assign) ROKOInstaBotConversationActionType postActionType;
@property (nonatomic, copy) NSString *buttonText;
@property (nonatomic, strong) ROKOInstaBotConversationTreeNode *childNode;
@property (nonatomic, strong) NSDictionary *pageSettings;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, strong) NSString *cardImageURL;
@property (nonatomic, copy) NSString *cardDescription;

@end
