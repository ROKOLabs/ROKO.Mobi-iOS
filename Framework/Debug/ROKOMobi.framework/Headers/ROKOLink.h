//
//  ROKOLink.h
//  ROKOMobi
//
//  Created by Alexey Golovenkov on 21.01.16.
//  Copyright © 2016 ROKO Labs. All rights reserved.
//

#import "ROKODataObject.h"

/**
 *  ROKO Deep Link.
 */
@interface ROKOLink : ROKODataObject

/**
 *  Name of the link
 */
@property (nonatomic, copy) NSString *name;

/**
 *  Advanced settings of the link. Come from portal.
 */
@property (nonatomic, strong) NSDictionary *settings;

/**
 *  Date when the link was created
 */
@property (nonatomic, strong) NSDate *createDate;

/**
 *  Date when the link was updated on Portal
 */
@property (nonatomic, strong) NSDate *updateDate;

/**
 *  Share channel name
 */
@property (nonatomic, copy) NSString *shareChannel;

/**
 *  Link with custom scheme
 */
@property (nonatomic, copy) NSString *customURLSchemeLink;

/**
 *  Meaningful part of the link url (after the domain)
 */
@property (nonatomic, copy) NSString *targetPath;

@end
