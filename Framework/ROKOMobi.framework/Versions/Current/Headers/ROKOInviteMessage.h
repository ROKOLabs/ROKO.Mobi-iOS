//
//  ROKOInviteMessage.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 27.02.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKOComponentScheme.h"

/**
 *  Invite message that will be sent by Invite Friends component
 */
@interface ROKOInviteMessage : ROKOComponentScheme

/**
 *  SMS message
 */
@property (nonatomic, copy) NSString *smsText;

/**
 *  Email message subject
 */
@property (nonatomic, copy) NSString *mailSubject;

/**
 *  Email message body
 */
@property (nonatomic, copy) NSString *mailText;

@end
