/*
 *  Render.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Render.h"
#include "RenderInterface.h"
#include "Engine.h"

RenderSetting::RenderSetting(void)
	:	cBGC( 0xff336699 )
{}
////////////////////////////////////////////////////////////

Render::Render(void)
	:	m_setting( NEW RenderSetting() )
{}

Render::~Render(void)
{
	SAFE_DELETE( m_setting );
}
const RenderSetting* Render::GetSetting(void)	const
{
	return m_setting;
}












