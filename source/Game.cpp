/*
 *  Engine_SubSystem.cpp
 *  test
 *
 *  Created by Ruly on 2010-4-18.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Engine.h"
#include <iostream>
#include "PathTool.h"
#include "LogTool.h"
#include <assert.h>
#include "MemberController.h"
#include "UI.h"
#include "Cell.h"
#include "Material.h"
#include "PathTool.h"
#include "App.h"

void game(void)
{
	NEW App();
	GetApp();

	LuaLoader<int> loader;

	std::string filename;
	loader.LoadFile( Path::GetRes( "Test.app/Test.lua" ) );

	
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
