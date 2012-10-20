//
//  App.cpp
//  D10
//
//  Created by Ruly on 2012-10-20.
//
//

#include "App.h"
#include "Base.h"

App::App(void)
	:	m_engine_ptr( NULL )
{
}
App::~App(void)
{}
Engine* App::GetEngine(void)
{
	return m_engine_ptr;
}




