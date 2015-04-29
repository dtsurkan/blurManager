//
//  UIImage+Blur.h
//  Gillion-MuzApp
//
//  Created by Dugnist Vladislav on 21/01/15.
//  Copyright (c) 2015 Gillion LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

#define DEFAULT_RADIUS 35

@interface UIImage (Blur)

- (UIImage *)blurredImage;
- (UIImage *)blurredImageWithRadius:(NSNumber *)radius;

@end
