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

struct FaceRN
	: public Face
{
public:
	FaceRN(void)
		:	pNext( 0 )
	{}
	FaceRN* pNext;
};

struct RenderSetting
{
public:
	Color cBGC;
};

class Render
{
	friend struct Face;
public:
	Render(void);
	~Render(void);
	
	void OnRestore(void);
	void OnLost(void);
	void OnDrawFace(const Face&);

	RenderSetting setting;

private:

	void _PushFace(const Face&);
	bool _PopFace(void);
	FaceRN* _AllocRN(void);
	void _PopRN(void);
	
private:
	FaceRN* m_pFaceStart;
	FaceRN* m_pFaceEnd;
};

#endif	//	__RENDER_H__