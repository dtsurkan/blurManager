//
//  UIImage+Blur.m
//  Gillion-MuzApp
//
//  Created by Dugnist Vladislav on 21/01/15.
//  Copyright (c) 2015 Gillion LLC. All rights reserved.
//

#import "UIImage+Blur.h"
#import <Accelerate/Accelerate.h>

@implementation UIImage (Blur)

- (UIImage *)blurredImage
{
    return [self blurredImageWithRadius:@(DEFAULT_RADIUS)];
}

- (UIImage *)blurredImageWithRadius:(NSNumber *)radius
{
    CIFilter *gaussianBlurFilter = [CIFilter filterWithName:@"CIGaussianBlur"];
    [gaussianBlurFilter setDefaults];
    [gaussianBlurFilter setValue:[CIImage imageWithCGImage:[self CGImage]] forKey:kCIInputImageKey];
    [gaussianBlurFilter setValue:radius forKey:kCIInputRadiusKey];
    
    CIImage *outputImage = [gaussianBlurFilter outputImage];
    CIContext *context   = [CIContext contextWithOptions:nil];
    CGRect rect          = [outputImage extent];
    
    rect = CGRectMake(0, 0, rect.size.width + rect.origin.x * 2, rect.size.height + rect.origin.y * 2);
 
    CGImageRef cgimg     = [context createCGImage:outputImage fromRect:rect];
    UIImage *image = [UIImage imageWithCGImage:cgimg];
    CGImageRelease(cgimg);
    
    return image;
}

@end
