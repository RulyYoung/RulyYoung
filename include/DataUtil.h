/*
 *  DataUtil.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __DATAUTIL_H__
#define __DATAUTIL_H__
#include <vector>
#include <map>
#include <list>
#include <string>
#include "orb.h"
using namespace orb;


struct RectF
{
public:

	RectF(void)
		:	l( 0.0f ), t( 0.0f ), r( 0.0f ), b( 0.0f )
	{}
	
	RectF(float _l, float _t, float _r, float _b)
		:	l( _l ), t( _t ), r( _r ), b( _b )
	{}
	
	RectF(const float in[4])
	:	l( in[ 0 ] )
	,	t( in[ 1 ] )
	,	r( in[ 2 ] )
	,	b( in[ 3 ] )
	{}

	inline float width(void)	const
	{
		return r - l;
	}
	
	inline float height(void)	const
	{
		return b - t;
	}

	float l, t, r, b;
};
struct LineSeg2
{
public:
	bool Intersect(const LineSeg2& line);
	Vec2 a, b;
};

template<typename T>
void CleanNull(T& t, T& mirror)
{
	mirror.swap( t );
	while( !mirror.empty() )
	{
		if( mirror.back() )
		{
			t.push_back( mirror.back() );
		}
		mirror.pop_back();
	}
}
template<typename T>
void CleanNull(T& t)
{
	T mirror;
	CleanNull( t, mirror );
}

#endif	//	__DATAUTIL_H__








