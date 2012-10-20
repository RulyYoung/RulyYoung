/*
 *  TouchUI.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-15.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "TouchUI.h"
#include "Engine.h"
#include "UI.h"
#include "Cell.h"

TouchUI::TouchUI(void)
{}

void TouchUI::OnDraw(void)
{}

void TouchUI::OnTend(void)
{}

void TouchUI::OnTouchBegin(ITouch* it)
{
	//	有没有人点到某按键？
	const int tp_count = it->GetCount();
	
	bool is_ui = false;
	
	for( int i = 0; i < tp_count; ++i )
	{
		float x, y;
		if( it->GetPos( x, y, i ) )
		{
			is_ui = is_ui || eg().GetUI()->ProcTouchDown( x, y );
		}
	}
	
	if( is_ui )
	{
		return;
	}
	
	
	Touch::OnTouchBegin( it );
}

void TouchUI::OnTouchEnd(ITouch* it)
{
	//	有没有人释放某按键？
	const int tp_count = it->GetCount();
	
	bool is_ui = false;
	
	for( int i = 0; i < tp_count; ++i )
	{
		float x, y;
		if( it->GetPos( x, y, i ) )
		{
			is_ui = is_ui || eg().GetUI()->ProcTouchUP( x, y );
		}
	}
	
	if( is_ui )
	{
		return;
	}
	
	Touch::OnTouchEnd( it );
}

void TouchUI::OnTouchMove(ITouch* it)
{
	Touch::OnTouchMove( it );
}

void TouchUI::OnTouchDragBegin(ITouch* it)
{
	Touch::OnTouchDragBegin( it );
}

void TouchUI::OnTouchDragEnd(ITouch* begin, ITouch* end)
{
	Touch::OnTouchDragEnd( begin, end );
}





