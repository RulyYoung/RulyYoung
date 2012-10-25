/*
 *  TouchInterface.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "TouchPoint.h"


TouchPoint::TouchPoint(void)
{}
TouchPoint::TouchPoint(float inX, float inY, int inIndex)
	:	m_Index( inIndex )
	,	m_X( inX )
	,	m_Y( inY )
{
}
int TouchPoint::GetIndex(void)	const
{
	return m_Index;
}
float TouchPoint::GetX(void)	const
{
	return m_X;
}
float TouchPoint::GetY(void)	const
{
	return m_Y;
}





