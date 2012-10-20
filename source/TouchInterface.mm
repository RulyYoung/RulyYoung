/*
 *  TouchInterface.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "TouchInterface.h"
#import "TouchInstance.h"



TouchInstance::TouchInstance(NSSet* touchs, UIView* view)
	:	m_touchs( touchs )
	,	m_view( view )
{}

int TouchInstance::GetCount(void)	const
{
	NSArray* firstTouchArr = [ m_touchs allObjects ];
	return [ firstTouchArr count ];
}

bool TouchInstance::GetPos(float& x, float& y, int index)	const
{
	NSArray* firstTouchArr = [ m_touchs allObjects ];
	if( index < [ firstTouchArr count ] )
	{
		UITouch* pos;
		pos = [firstTouchArr objectAtIndex : index ];
		CGPoint point = [ pos locationInView : m_view ];
		x = point.x;
		y = point.y;
		return true;
	}
	return false;
}


int GetTouchCount(void)
{
	return 0;
}

bool GetTouchPos(int* x, int* y,int index)
{
	return false;
}
