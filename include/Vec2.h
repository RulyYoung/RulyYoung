/*
 *  vec2.h
 *  cmdline_cpp
 *
 *  Created by Ruly on 2010-4-11.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __VEC2_H__
#define __VEC2_H__



#ifndef MIN
#define MIN(A,B) ((A<B)?A:B)
#endif

#ifndef MAX
#define MAX(A,B) ((A<B)?B:A)
#endif

namespace orb
{
	struct Mat4;
	struct Mat3;
	struct Vec4;
	struct Vec2
	{
	public:
		Vec2(void);
		Vec2(float _x, float _y);
		bool operator==(const Vec2& other) const;
		bool operator!=(const Vec2& other) const;
		Vec2 operator+(void) const;
		Vec2 operator-(void) const;
		float Length(void) const;
		const Vec2& Normalize(void);
		Vec2 GetNormalized(void) const;
		const Vec2& operator +=(const Vec2& other);
		const Vec2& operator -=(const Vec2& other);
		const Vec2& operator *=(float s);
		const Vec2& operator /=(float s);
		const Vec2& operator=(const Vec4&);
		static float Cross(const Vec2& a, const Vec2& b, const Vec2& c);
		static float Dot(const Vec2& a, const Vec2& b);
		//	置与Y轴正方向的夹角(单位:角度)
		void Dir(float);
		float Angle(void)	const;
		//	求两向量夹角(单位:角度)
		static float Angle(const Vec2& a, const Vec2& b);
		//确定两条线段是否相交	
		static bool Intersect(const Vec2& ua, const Vec2& ub, const Vec2& va, const Vec2& vb);
		float x, y;
	};
	Vec2 operator+(const Vec2& v1, const Vec2& v2);
	Vec2 operator-(const Vec2& v1, const Vec2& v2);
	Vec2 operator*(const Vec2& v, float s);
	Vec2 operator*(float s, const Vec2& v);
	const Vec2& Transform(Vec2& v, const Mat4& m);
	Vec2 operator*(const Vec2& v, const Mat4& m);
	Vec2 operator*(const Mat4& m, const Vec2& v);
	Vec2 operator*(const Vec2& v, const Mat3& m);
	Vec2 operator*(const Mat3& m, const Vec2& v);
	const Vec2& Transform(Vec2& v, const Mat3& m);


}


#endif	//	#ifndef __VEC2_H__


