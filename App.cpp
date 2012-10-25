//
//  App.cpp
//  D10
//
//  Created by Ruly on 2012-10-20.
//
//

#include "App.h"
#include "Base.h"
#include "Engine.h"
#include "SceneMngr.h"
#include "LuaLoader.h"
#include "Path.h"
#include "Log.h"
#include "ViewController.h"
#include "Cell.h"

static App* g_app = NULL;
App::App(void)
	:	m_engine_ptr( NEW Engine() )
	,	m_scene_mngr_ptr( NEW SceneMngr() )
{
	ASSERT( NULL == g_app );
	g_app = this;
}
App::~App(void)
{
	DELETE( m_scene_mngr_ptr );
	DELETE( m_engine_ptr );
	g_app = NULL;
}
Engine* App::GetEngine(void)
{
	return m_engine_ptr;
}
App* GetApp(void)
{
	return g_app;
}
void App::OnAppBegin(void)
{

	LuaLoader<int> loader;

	std::string filename;
	loader.LoadFile( Path( "Test.app/Test.lua" ).GetResFilename() );

	
	Log( "game start!\n" );

	{
		ViewController* fc = GetRoot()->GetViewController();
		fc->SetColor( 0xff336699 );
		fc->SetX( 320 / 2 );
		fc->SetY( 480 / 2 );
	}
	////////////////////////////////////////////////////////
	Cell* obj = new Cell();
	{
		ViewController* fc = obj->GetViewController();
		fc->SetW( 320 );
		fc->SetH( 320 );
		fc->SetX( 0 );
		fc->SetY( 0 );
		fc->SetAngle( 0 );
		fc->SetColor( 0xffffffff );
		fc->SetImage( "pic01.jpg" );
		GetRoot()->GetMemberController()->AddChild( obj );
	}
	////////////////////////////////////////////////////////
	LISTENER_BEGIN( obj, EVENT_FRAMEMOVE )
		obj->GetViewController()->SetX
			( obj->GetViewController()->GetX() + 1 );
	LISTENER_END()

	LISTENER_BEGIN( obj, EVENT_FRAMEMOVE )
		obj->GetViewController()->SetAngle
			( obj->GetViewController()->GetAngle() - 1 );
	LISTENER_END()

	Log( "game over!" );
}
void App::OnAppLost(void)
{
}
void App::OnAppRestore(void)
{
}
void App::OnAppEnd(void)
{
}
