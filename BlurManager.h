//
//  BlurManager.h
//  Gillion-MuzApp
//
//  Created by Dugnist Vladislav on 16/04/15.
//  Copyright (c) 2015 Gillion LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIImage, UIImageView;

@interface BlurManager : NSObject

+ (void)renderBlurForImage:(UIImage *)image andSetInImageView:(UIImageView *)imageView;
+ (void)renderBlurForImage:(UIImage *)image radius:(NSNumber *)radius andSetInImageView:(UIImageView *)imageView;

/*
     If you use methods with callbacks, setting blurred image
     to imageView is on your own. 
*/
+ (void)renderBlurForImage:(UIImage *)image forImageView:(UIImageView *)imageView withCallback:(void (^)(UIImage *blurredImage))callback;
+ (void)renderBlurForImage:(UIImage *)image forImageView:(UIImageView *)imageView radius:(NSNumber *)radius withCallback:(void (^)(UIImage *blurredImage))callback;


@end
