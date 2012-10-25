/*
 *  Touch.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "TouchPointTable.h"


TouchPointTable::TouchPointTable(NSSet* touchs, UIView* view)
{
	NSArray* firstTouchArr = [ touchs allObjects ];
	
	for( int index = 0; index < [ firstTouchArr count ]; ++index )
	{
		UITouch* pos;
		pos = [firstTouchArr objectAtIndex : index ];
		CGPoint point = [ pos locationInView : view ];
		push_back( TouchPoint( point.x, point.y, index ) );
	}
}
