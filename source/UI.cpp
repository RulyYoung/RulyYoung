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

UI::UI(void)
	:	m_root( 0 )
{}

bool UI::ProcTouchDown(float x, float y)
{
	SetMousePos(Vec2(x,y));
	std::vector<Cell*>& vtrOut = m_vtrDrag;
	vtrOut.clear();
	Mat4 m;
	m.SetIdentity();
	const bool bResult = m_root->PickList( vtrOut, Vec2( x, y ) );
	if( !vtrOut.empty() )
	{
		Cell* const p = *vtrOut.begin();
		p->OnTouchDown();
	}

	return bResult;
}

bool UI::ProcTouchUP(float x, float y)
{
	SetMousePos(Vec2( x, y ));
	std::vector<Cell*> vtrOut;
	Mat4 m;
	m.SetIdentity();
	const bool bResult = m_root->PickList( vtrOut, Vec2( x, y ) );
	if( !vtrOut.empty() )
	{
		Cell* const p = *vtrOut.begin();
		p->OnTouchUp();
		p->OnTouchClick();
	}
	return bResult;
}

void UI::OnInit(void)
{
	SAFE_RELEASE( m_root );
	m_root = new Cell();
	m_root->GetViewController()->SetColor( 0xffffffff );
	m_root->GetViewController()->SetW( 320 );
	m_root->GetViewController()->SetH( 480 );
	m_root->GetViewController()->SetX( m_root->GetViewController()->GetW() / 2 );
	m_root->GetViewController()->SetY( m_root->GetViewController()->GetH() / 2 );
}

void UI::OnFini(void)
{
	SAFE_RELEASE( m_root );
}

void UI::OnDraw(void)
{
	m_root->Draw();
}

void UI::OnTend(void)
{
	//	每帧都通过SmartPtr持有对象引用
	//	然后在帧结束时集中释放

	std::vector<SmartPtr<Cell*> >
		recover_pool;

	struct FrameMoveRecover
	{
		FrameMoveRecover(std::vector<SmartPtr<Cell*> >& in_cache)
			:	cache( in_cache )
		{}
		void operator()(Cell* p)
		{
			cache.push_back( SmartPtr<Cell*>( p ) );
			p->OnFrameMove();
		}
		std::vector<SmartPtr<Cell*> >& cache;
	};

	m_root->GetMemberController()->
		ForEachTree<FrameMoveRecover>
		( FrameMoveRecover( recover_pool ), true );
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


