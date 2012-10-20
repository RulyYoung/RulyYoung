//
//  OGL002AppDelegate.m
//  OGL002
//
//  Created by Ruly on 09-10-25.
//  Copyright __MyCompanyName__ 2009. All rights reserved.
//

#import "OGL002AppDelegate.h"
#import "EAGLView.h"
#import "Engine.h"

@implementation OGL002AppDelegate

@synthesize window;
@synthesize glView;
@synthesize bu_reset;
@synthesize point_show;

- (void)applicationDidFinishLaunching:(UIApplication *)application {
    
	glView.animationInterval = 1.0 / 60.0;
	[glView startAnimation];
	game();
	[application setStatusBarHidden:YES];
}


- (void)applicationWillResignActive:(UIApplication *)application {
	glView.animationInterval = 1.0 / 5.0;
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
	glView.animationInterval = 1.0 / 60.0;
}
- (IBAction)click:(id)sender {
	point_show.text = @"abc";
}


- (void)dealloc {
	[window release];
	[glView release];
    [bu_reset release];
	[point_show release];
	[super dealloc];
}
@end














