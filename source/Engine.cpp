/*
 *  Engine.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Engine.h"
#include "Face.h"
#include "TextureInterface.h"
#include "UI.h"
#include "Cell.h"
#include "Touch.h"
#include "TouchUI.h"
#include "Render.h"

Engine::Engine(void)
	:	m_clock( 0 )
	,	m_ui_ptr( NEW UI() )
	,	m_touch_ptr( NEW TouchUI() )
	,	m_render_ptr( NEW Render() )
{
	GetRender()->setting.cBGC = Color( 0xff336699 );
	OnInit();
}
void Engine::OnInit(void)
{
	GetUI()->OnInit();
}
Engine::~Engine(void)
{
	SAFE_DELETE( m_render_ptr );
	SAFE_DELETE( m_touch_ptr );
	SAFE_DELETE( m_ui_ptr );
	GetUI()->OnFini();
}
Render* Engine::GetRender(void)	const
{
	return m_render_ptr;
}
void Engine::OnDraw(void)
{
	GetUI()->OnDraw();
}
void Engine::OnFrameMove(void)
{
	{
		const static double lf = 1.0f / 60.0f;
		m_clock += lf;
	}
	//	Tend
	GetUI()->OnTend();
}
double Engine::GetCurrentTime(void)	const
{
	return m_clock;
}
Engine& eg(void)
{
	static Engine g;
	return g;
}
Cell* GetRoot(void)
{
	return eg().GetUI()->GetRoot();
}
UI* Engine::GetUI(void)	const
{
	return m_ui_ptr;
}
TouchUI* Engine::GetTouch(void)	const
{
	return m_touch_ptr;
}