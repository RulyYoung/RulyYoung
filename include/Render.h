/*
 *  Render.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __RENDER_H__
#define __RENDER_H__
#include "Face.h"
#include "Color.h"

/////////////////////////////////////////////////////////////
struct RenderSetting
{
public:
	RenderSetting(void);
	Color cBGC;
};
/////////////////////////////////////////////////////////////
class Render
{
	friend struct Face;
public:
	Render(void);
	~Render(void);
	const RenderSetting* GetSetting(void)	const;
private:
	RenderSetting* m_setting;
};

#endif	//	__RENDER_H__