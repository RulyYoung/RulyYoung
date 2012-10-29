/*
 *  Face.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Face.h"
#include "Engine.h"

#include "RenderInterface.h"

Face::Face(void)
	:	uv( 0, 0, 1, 1 )
	,	x( 0 )
	,	y( 0 )
	,	w( 0 )
	,	h( 0 )
	,	c( 0x2fffffff )
	,	angle( 0.0f )
{}

Face::Face(float x, float y, float w, float h, UINT32 nC, float a)
	:	x( x )
	,	y( y )
	,	w( w )
	,	h( h )
	,	c( 0xffffffff )
	,	uv( 0, 0, 1, 1 )
	,	angle( a )
{
}
Face::Face(float in_x, float in_y, float in_w, float in_h, UINT32 in_c, const char* img_res, const RectF& in_uv, float in_angle)
	:	x( in_x )
	,	y( in_y )
	,	w( in_w )
	,	h( in_h )
	,	c( in_c )
	,	img( img_res )
	,	uv( in_uv )
	,	angle( in_angle )
{}

void Face::draw(void)
{
	BeginFace( *this );
	DrawFace( *this );
	EndFace();
}

bool Face::HitTest(const Vec2& pos)	const
{
	return ( x <= pos.x && y <= pos.y && pos.x <= ( x + w ) && pos.y <= ( y + h ) );
}

bool Face::HitTestI(const Vec2& pos)	const
{
	return ( 0 <= pos.x && 0 <= pos.y && pos.x <= ( w ) && pos.y <= ( h ) );
}

float Face::GetX(void)	const
{
	return x;
}
float Face::GetY(void)	const
{
	return y;
}
float Face::GetW(void)	const
{
	return w;
}
float Face::GetH(void)	const
{
	return h;
}
Color Face::GetColor(void)	const
{
	return Color( c );
}
const Image2D& Face::GetImage(void)	const
{
	return img;
}
const RectF& Face::GetUV(void)	const
{
	return uv;
}
float Face::GetAngle(void)	const
{
	return angle;
}
float Face::SetX(float in)
{
	x = in;
	return x;
}
float Face::SetY(float in)
{
	y = in;
	return y;
}
float Face::SetW(float in)
{
	w = in;
	return w;
}
float Face::SetH(float in)
{
	h = in;
	return h;
}
Color Face::SetColor(const Color& in)
{
	c = in.ToValue();
	return in;
}
const Image2D& Face::SetImage(const Image2D& in)
{
	img = in;
	return img;
}
const RectF& Face::SetUV(const RectF& in)
{
	uv = in;
	return uv;
}
float Face::SetAngle(float in)
{
	angle = in;
	return angle;
}

