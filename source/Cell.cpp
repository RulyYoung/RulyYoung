/*
 *
 *  Created by Ruly on 10-2-18.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Cell.h"
#include "Engine.h"
#include "RenderInterface.h"
#include "orb.h"
#include "UI.h"

#define NEW new

using namespace orb;
#define FLOAT_E 0.00001f


void transfrom_pos(Vec2& out,const ViewController* view_controller)
{
	Vec4 v( out.x, out.y, 0, 1 );
	if( FLOAT_E > view_controller->GetAngle() &&
		-FLOAT_E < view_controller->GetAngle() )//	优化
	{
		v.x -= view_controller->GetX();
		v.y -= view_controller->GetY();
	}
	else
	{
		Mat4 m( Mat3::RotationZ( 3.1415926 / 180 * view_controller->GetAngle() ));
		m = m * Mat4::Translation( view_controller->GetX(),
		 view_controller->GetY(),0 );
		m.Invert();
		v = Transform( v, m );
	}
	out.x = v.x;
	out.y = v.y;
}

bool Cell::PickList(std::vector<Cell*>& vtrOut, const Vec2& p) const
{
	if( !GetEnable() )
	{
		return false;
	}
	
	Vec2 pos = p;
	transfrom_pos( pos, GetViewController() );
	
	bool is_return = false;
	const auto func = [&](Cell* p)
	{
		if( !is_return )
		{
			is_return = p->PickList( vtrOut, pos );
		}
	};
	GetMemberController()->ForEach( func );
	if( is_return )
	{
		return true;
	}
	
	if( GetViewController()->HitTest( pos ) )
	{
		vtrOut.push_back( const_cast<Cell*>( this ) );
	}
	else
	{
		return false;
	}

	return true;
}


Cell::Cell(void)
	:	m_is_visible( true )
	,	m_enable( true )
	,	m_event_controller( NULL )
	,	m_face_controller( NULL )
	,	m_member_controller( NULL )
{
	m_event_controller = NEW EventController();
	m_face_controller = NEW ViewController();
	m_member_controller = NEW MemberController( this );
}
Cell::~Cell(void)
{
	SAFE_DELETE( m_face_controller );
	SAFE_RELEASE( m_event_controller );

	if( GetMemberController()->GetParent() )
	{
		GetMemberController()->GetParent()->GetMemberController()->RemoveChild( this );
	}

	GetMemberController()->Clear();
	GetViewController()->SetColor( 0xffff0000 );
	SAFE_DELETE( m_member_controller );
}
Vec2 Cell::GetCursorPos(void)	const
{
	const Vec2 pos( GetEngine()->GetUI()->GetMousePos() );
	Vec2 v( pos.x, pos.y );
	GetLocalPos( v );
	return v;
}
void Cell::GetLocalPos(Vec2& pos)	const
{
	for( const Cell* p = this; p; p = p->GetMemberController()->GetParent() )
	{
		pos.x -= p->GetViewController()->GetX();
		pos.y -= p->GetViewController()->GetX();
	}
}
Vec2 Cell::GetRealPos(void)	const
{
	Vec2 pos( GetViewController()->GetX(),
		GetViewController()->GetY() );
	for( const Cell* p = GetMemberController()->GetParent();
	 p; p = p->GetMemberController()->GetParent() )
	{
		pos.x += p->GetViewController()->GetX();
		pos.y += p->GetViewController()->GetY();
	}
	return pos;
}
bool Cell::GetEnable(void)	const
{
	return m_enable;
}
bool Cell::SetEnable(bool is_enable)
{
	m_enable = is_enable;
	return m_enable;
}
void Cell::Draw(void)
{
	if( !m_is_visible )
	{
		return;
	}

	GetViewController()->BeginDraw();
	
	OnDraw();

	GetMemberController()->ForEach([](Cell* p){
		if( p )
		{
			p->Draw();
		}
	});
	
	GetViewController()->EndDraw();
}
EventController* Cell::GetEventController(void)
{
	return m_event_controller;
}
MemberController* Cell::GetMemberController(void)	const
{
	return m_member_controller;
}
ViewController* Cell::GetViewController(void)	const
{
	return m_face_controller;
}
void Cell::OnEventNotify(EVENT event)
{
	if( m_event_controller )
	{
		m_event_controller->EventNotify( event, this );
	}
}
void Cell::OnFrameMove(void)
{
	OnEventNotify( EVENT_FRAMEMOVE );
}
void Cell::OnDraw(void)
{
	GetViewController()->Draw();
}
bool Cell::HitTest(const Cell& other)	const
{
	if( 0 == (int)other.GetViewController()->GetAngle()
	 && 0 == (int)GetViewController()->GetAngle() )
	{
		if(
			( GetViewController()->GetW()
				+ other.GetViewController()->GetW() ) / 2
			 > abs( GetViewController()->GetX() - other.GetViewController()->GetX() ) )
		{
			return true;
		}
		else if( ( GetViewController()->GetH() + other.GetViewController()->GetH() ) / 2
		 > abs( GetViewController()->GetY() - other.GetViewController()->GetY() ) )
		{
			return true;
		}
	}
	return false;
}

void Cell::OnTouchDown(void)
{
}
void Cell::OnTouchUp(void)
{}
void Cell::OnTouchClick(void)
{}
bool Cell::GetVisible(void)	const
{
	return m_is_visible;
}
bool Cell::SetVisible(bool is_visible)
{
	m_is_visible = is_visible;
	return m_is_visible;
}







