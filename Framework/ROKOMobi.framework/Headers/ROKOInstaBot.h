//
//  ROKOInstaBot.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 06.09.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ROKOInstaBotViewController.h"
#import "ROKOInstaBotScheme.h"
#import "ROKOInstaBotConversationTreeNode.h"
#import "ROKOComponent.h"

@class ROKOInstaBotConversation;

typedef void (^ROKOInstaBotLoadCompletionBlock)(ROKOInstaBotViewController * _Nullable controller, NSError * _Nullable error);

/**
 *  ROKO InstaBot class
 */
@interface ROKOInstaBot : ROKOComponent

/**
 *  Id of the current conversation
 */
@property (nonatomic, assign, readonly) NSInteger conversationId;

+ (nullable ROKOInstaBot *)presentingBot;

- (void)loadConversationWithId:(NSInteger)conversationId completionBlock:(nonnull ROKOInstaBotLoadCompletionBlock)completionBlock;

- (nullable ROKOInstaBotViewController *)showBotWithScheme:(nonnull ROKOInstaBotConversation *)scheme;

+ (void)markSchemeAsShown:(nonnull ROKOInstaBotConversation *)scheme;

/**
 *  Starts conversation from the begining
 *
 *  @return First question in the conversation
 */
- (nullable ROKOInstaBotConversationTreeNode *)firstQuestion;

- (nullable ROKOInstaBotConversationTreeNode *)nextQuestionForAnswerWithIndex:(NSInteger)answerIndex;

- (nullable ROKOInstaBotConversationTreeNode *)currentQuestion;

/**
 *  All the conversation in the current state
 *
 *  @return All bot questions and user answers
 */
- (nonnull NSArray <NSString *> *)conversationHistory;

- (nullable ROKOInstaBotScheme *)uiScheme;

- (nullable NSString *)applicationName;

@end
