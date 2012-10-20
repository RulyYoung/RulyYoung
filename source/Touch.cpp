/*
 *  Touch.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Touch.h"
#include "Engine.h"
#include <math.h>
#include "DataUtil.h"
#include <stdio.h>


Touch::Touch(void)
	:	m_bUITouch( false )
{}

void Touch::OnTouchBegin(ITouch* touch)
{
	char cbBuffer[ 0x200 ];
	sprintf( cbBuffer, "%d", touch->GetCount() );

	float x, y;
	if( touch->GetPos( x, y, 0 ) )
	{
		m_posStart.x = x;
		m_posStart.y = y;
	}
}

void Touch::OnTouchEnd(ITouch* touch)
{}

void Touch::OnTouchMove(ITouch* touch)
{
	for( UINT32 nIndex = 0; nIndex < touch->GetCount(); ++nIndex )
	{
		
	}
}

void Touch::OnTouchDragBegin(ITouch*)
{
}

void Touch::OnTouchDragEnd(ITouch* begin, ITouch* end)
{
}






