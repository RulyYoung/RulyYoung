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

static App* g_app = NULL;
App::App(void)
	:	m_engine_ptr( NEW Engine() )
{
	ASSERT( NULL == g_app );
	g_app = this;
}
App::~App(void)
{
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

