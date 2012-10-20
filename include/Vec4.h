/*
 *  vec4.h
 *  cmdline_cpp
 *
 *  Created by Ruly on 2010-4-11.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
 
#ifndef __VEC4_H__
#define __VEC4_H__
namespace orb
{
	struct Quat;
	struct Vec2;
	struct Mat4;
	struct Vec4
	{
	public:
		Vec4(void);
		Vec4(float _x, float _y, float _z, float _w);

		bool operator==(const Vec4& other) const;
		bool operator!=(const Vec4& other) const;
		Vec4 operator+() const;
		Vec4 operator-() const;
		float Length() const;
		const Vec4& Normalize();
		Vec4 GetNormalized() const;

		const Vec4& operator +=(const Vec4& other);
		const Vec4& operator -=(const Vec4& other);
		const Vec4& operator *=(float s);
		const Vec4& operator /=(float s);
		const Vec4& operator =(const Vec2&);

		float x, y, z, w;
	};

	Vec4 operator+(const Vec4& v1, const Vec4& v2);
	Vec4 operator-(const Vec4& v1, const Vec4& v2);
	Vec4 operator*(const Vec4& v, float s);
	Vec4 operator*(float s, const Vec4& v);
	const Vec4& Transform(Vec4& v, const Mat4& m);
	float Dot(const Quat& q1, const Quat& q2);
	float Dot(const Vec4& v1, const Vec4& v2);

//	Vec4 Cross(const Vec4& v1, const Vec4& v2, const Vec4& v3);


}

#endif	//	#ifndef __VEC4_H__