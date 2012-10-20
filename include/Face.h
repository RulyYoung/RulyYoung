/*
 *  Face.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __FACE_H__
#define __FACE_H__
#include "DataUtil.h"
#include "Image.h"

class Face
{
public:

	Face(void);
	Face(float x, float y, float w, float h,
		UINT32 nC,float = 0.0f);
	Face(float in_x, float in_y, float in_w,
		float in_h, UINT32 in_c, const char* img_res,
		const RectF& in_uv, float in_angle);
	bool HitTest(const Vec2& pos)	const;
	bool HitTestI(const Vec2& pos)	const;	
	void draw(void);
	
	float x, y, w, h;
	UINT32 c;
	Image2D img;
	RectF uv;
	float angle;
};


#endif	//	__FACE_H__



