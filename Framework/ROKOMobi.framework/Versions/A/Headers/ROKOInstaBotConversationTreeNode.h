//
//  ROKOInstaBotConversationTree.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 13.09.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"
#import "ROKOInstaBotConversationAction.h"

@interface ROKOInstaBotConversationTreeNode : ROKODataObject

@property (nonatomic, copy) NSString *message;
@property (nonatomic, strong) NSArray <ROKOInstaBotConversationAction *> *actions;

@end
