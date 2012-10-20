/*
 *  Vec2.cpp
 *  test
 *
 *  Created by Ruly on 2010-4-18.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Vec2.h"
#include "Vec4.h"
#include <cmath>
#include "Base.h"
namespace orb
{
	const Vec2& Vec2::operator=(const Vec4& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	float Vec2::Cross(const Vec2& a, const Vec2& b, const Vec2& c)
	{
		return ( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
	}

	//确定两条线段是否相交	
	bool Vec2::Intersect(const Vec2& ua, const Vec2& ub, const Vec2& va, const Vec2& vb)	
	{
		return(	(MAX(ua.x,ub.x)>=MIN(va.x,vb.x))&&	
				(MAX(va.x,vb.x)>=MIN(ua.x,ub.x))&&	
				(MAX(ua.y,ub.y)>=MIN(va.y,vb.y))&&	
				(MAX(va.y,vb.y)>=MIN(ua.y,ub.y))&&	
				(Cross(va,ub,ua)*Cross(ub,vb,ua)>=0)&&	
				(Cross(ua,vb,va)*Cross(vb,ub,va)>=0)
				);	
	}
	void Vec2::Dir(float angle)
	{
		angle = ( angle - 90.0f ) * ANGLE;
		y = sin( angle );
		x = cos( angle );
		this->Normalize();
	}
	float Vec2::Dot(const Vec2& a, const Vec2& b)
	{
		return a.x * b.x + a.y * b.y;
	}
	float Vec2::Angle(const Vec2& a, const Vec2& b)
	{
		Vec2 ta = a;
		Vec2 tb = b;
		ta.Normalize();
		tb.Normalize();
		const float cos_angle = Dot( ta, tb );
		return acos( cos_angle ) / ANGLE;
	}
	float Vec2::Angle(void)	const
	{
		return Vec2::Angle( *this, Vec2( 0, -1 ) );
	}


};



















