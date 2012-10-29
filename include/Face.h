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
#include "Color.h"

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

	float GetX(void)	const;
	float GetY(void)	const;
	float GetW(void)	const;
	float GetH(void)	const;
	Color GetColor(void)	const;
	const Image2D& GetImage(void)	const;
	const RectF& GetUV(void)	const;
	float GetAngle(void)	const;
	float SetX(float);
	float SetY(float);
	float SetW(float);
	float SetH(float);
	Color SetColor(const Color&);
	const Image2D& SetImage(const Image2D&);
	const RectF& SetUV(const RectF&);
	float SetAngle(float);
private:
	float x, y, w, h;
	UINT32 c;
	Image2D img;
	RectF uv;
	float angle;
};


#endif	//	__FACE_H__



