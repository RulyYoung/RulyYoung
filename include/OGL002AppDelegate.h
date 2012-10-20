//
//  OGL002AppDelegate.h
//  OGL002
//
//  Created by Ruly on 09-10-25.
//  Copyright __MyCompanyName__ 2009. All rights reserved.
//

#import <UIKit/UIKit.h>

@class EAGLView;

@interface OGL002AppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    EAGLView *glView;
	UILabel* point_show;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet EAGLView *glView;
@property (retain, nonatomic) IBOutlet UIButton *bu_reset;
@property (retain, nonatomic) IBOutlet UILabel *point_show;


@end

