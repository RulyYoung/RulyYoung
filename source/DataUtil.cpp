/*
 *  DataUtil.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-13.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */



#include "DataUtil.h"
#include <math.h>

bool LineSeg2::Intersect(const LineSeg2& o)
{
	Vec2 v;
	return v.Intersect( a, b, o.a, o.b );
}


