#ifndef __ORBMATH__HEADER
#define __ORBMATH__HEADER
#include <cmath>
#include <limits>
#include <memory.h>
#include <iostream>

//! namespace orb
/*!
	 namespace orb is used throughout engine orb, as a subset of engine orb, this lib uses
	 namespace orb,too.
	 @date 05/12/2003
	 @version 1.0
	 @author Dan Tong
	 @author mail: Lythm@citiz.net
*/
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
//#include "mat2.h"
#include "mat3.h"
#include "mat4.h"
#include "Plane.h"
namespace orb
{
	//! output to stream
	 std::ostream& operator<<(std::ostream& o, const Mat4& m);

	//! output to stream
	 std::ostream& operator<<(std::ostream& o, const Mat3& m);
	
	//! output to stream
	 std::ostream& operator<<(std::ostream& o, const Vec2& v);

	//! output to stream
	 std::ostream& operator<<(std::ostream& o, const Vec3& v);

	//! output to stream
	 std::ostream& operator<<(std::ostream& o, const Vec4& v);

	//! output to stream
	 std::ostream& operator<<(std::ostream& o, const Quat& q);

	//! output to stream
	 std::ostream& operator<<(std::ostream& o, const Plane& p);

#include "orb.inl.h"
}
#endif
