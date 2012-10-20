/*
 *  RenderInterface.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __RENDERINTERFACE_H__
#define __RENDERINTERFACE_H__
#include "Face.h"
void BeginFace(const Face&);
void EndFace(void);
void DrawFace(const Face& face);
#endif	//	__RENDERINTERFACE_H__