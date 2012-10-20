/*
 *  Vec4.cpp
 *  test
 *
 *  Created by Ruly on 2010-4-18.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Vec4.h"
#include "Vec2.h"
namespace orb
{
	const Vec4& Vec4::operator=(const Vec2& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}

};