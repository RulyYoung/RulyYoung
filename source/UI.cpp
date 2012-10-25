/*
 *  UI.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-15.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "UI.h"
#include "Engine.h"
#include <vector>
#include "MemberController.h"
#include "TouchPoint.h"

UI::UI(void)
	:	m_root( NULL )
{
	m_root = new Cell();
	auto ctrl = m_root->GetViewController();
	ctrl->SetColor( 0xffffffff );
	ctrl->SetW( 320 );
	ctrl->SetH( 480 );
	ctrl->SetX( m_root->GetViewController()->GetW() / 2 );
	ctrl->SetY( m_root->GetViewController()->GetH() / 2 );
}
UI::~UI(void)
{
	SAFE_RELEASE( m_root );
}

bool UI::ProcTouchDown(float x, float y)
{
	SetMousePos( Vec2( x, y ) );
	std::vector<Cell*>& vtrOut = m_vtrDrag;
	vtrOut.clear();
	const bool bResult = m_root->PickList( vtrOut, Vec2( x, y ) );
	if( !vtrOut.empty() )
	{
		Cell* const p = *vtrOut.begin();
		p->OnTouchClick();
	}

	return bResult;
}
void UI::OnDraw(void)
{
	m_root->Draw();
}
void UI::OnTend(void)
{
	//	通过SmartPtr持有对象
	//	使可能的释放操作集中在OnFrameMove全部结束时产生
	std::vector<SmartPtr<Cell*>> pool;
	const auto FuncAdd = [&](Cell* ptr)
	{
		pool.push_back( SmartPtr<Cell*>( ptr ) );
		ptr->OnFrameMove();
	};
	m_root->GetMemberController()->ForEachTree( FuncAdd, true );
}

Cell* UI::GetRoot(void)	const
{
	return m_root;
}
const Vec2& UI::GetMousePos(void)	const
{
	return mouse_pos;
}
const Vec2& UI::SetMousePos(const Vec2& in)
{
	mouse_pos = in;
	return mouse_pos;
}


void UI::OnTouch(const std::vector<TouchPoint>& touch_table)
{
	auto Func = [this](const TouchPoint& point)
	{
		this->ProcTouchDown( point.GetX(), point.GetY() );
	};
	std::for_each( touch_table.begin(), touch_table.end(), Func );
}
