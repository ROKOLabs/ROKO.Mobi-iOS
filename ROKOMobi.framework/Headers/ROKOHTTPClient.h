//
//  ROKOHTTPClient.h
//  ROKOComponents
//
//  Created by Katerina Vinogradnaya on 6/27/14.
//  Copyright (c) 2014 ROKOLabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ROKOComponent.h"

typedef void(^ROKOHTTPClientCompletion)(id responseObject, NSError *error);
typedef void(^ROKOHTTPClientCompletionWithURL)( NSURL *url, id responseObject, NSError *error);

@interface ROKOHTTPClient : ROKOComponent

- (void)getDataWithURL:(NSString *)URLString parameters:(NSDictionary *)parameters completion:(ROKOHTTPClientCompletion)completion;

- (void)getDataWithURL:(NSString *)URLString parameters:(NSDictionary *)parameters customHeaders:(NSDictionary *)headers completion:(ROKOHTTPClientCompletion)completion;

- (void)postDataWithURL:(NSString *)URLString parameters:(NSDictionary *)parameters body:(NSData *)body completion:(ROKOHTTPClientCompletion)completion;

- (void)downloadImageWithURL:(NSURL *)url completion:(ROKOHTTPClientCompletionWithURL)completion;



@end
