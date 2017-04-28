//
//  ROKOInstaBotCustomProperty.h
//  ROKOMobi
//
//  Created by Igor Sova on 10/04/2017.
//  Copyright © 2017 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"

typedef  NS_ENUM(NSInteger, ROKOConversationFieldType) {
	ROKOConversationFieldTypeString,
	ROKOConversationFieldTypeInteger,
	ROKOConversationFieldTypeDateTime
};

typedef  NS_ENUM(NSInteger, ROKOConversationValueFormat) {
	ROKOConversationValueFormatUndefined,
	ROKOConversationValueFormatEmailAddress,
	ROKOConversationValueFormatPhoneNumber
};

@interface ROKOInstaBotCustomProperty : ROKODataObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) ROKOConversationFieldType fieldType;
@property (nonatomic, assign) ROKOConversationValueFormat valueFormat;

@end
