/*
 *  Mat4.h
 *  cmdline_cpp
 *
 *  Created by Ruly on 2010-4-11.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __MAT4_H__
#define __MAT4_H__

namespace orb
{
	struct Mat4
	{
		Mat4();
		Mat4(const Mat3& other);
		explicit Mat4(float _m[16]);
		Mat4(float _m11, float _m12, float _m13, float _m14, 
			float _m21, float _m22, float _m23, float _m24,
			float _m31, float _m32, float _m33, float _m34,
			float _m41, float _m42, float _m43, float _m44);
		explicit Mat4(const Quat& quat);
		operator float*() const;
		float& operator()(int row, int col);
		const float& operator()(int row, int col) const;
		const Mat4& operator+=(const Mat4& other);
		float& operator[](int nIndex);
		const float& operator[](int nIndex) const;
		const Mat4& operator-=(const Mat4& other);
		const Mat4& operator*=(const Mat4& other);
		bool operator==(const Mat4& other) const;
		bool operator!=(const Mat4& other) const;
		const Mat4& SetIdentity();
		bool isIdentity() const;
		const Mat4& Transpose();
		Mat4 GetTranspose() const;
		const Mat4& Invert();
		Mat4 GetInverse() const;
		float Determinant() const;
		Vec4 GetRow(int row) const;
		Vec4 GetLine(int line) const;
		void SetLine(int line, const Vec4& v);
		void SetRow(int row, const Vec4& v);

		static Mat4 LookAtLH(const Vec3& eye, const Vec3& at, const Vec3& up);
		static Mat4 LookAtRH(const Vec3& eye, const Vec3& at, const Vec3& up);
		static Mat4 PerspectiveLH(float nvp, float fvp, float fov, float aspect);
		static Mat4 PerspectiveRH(float nvp, float fvp, float fov, float aspect);
		static Mat4 Scale(float sx, float sy, float sz);
		static Mat4 Translation(float x, float y, float z);
	public:
		union
		{
			float	m[ 16 ];
			struct	
			{
				float	m11, m12, m13, m14;
				float	m21, m22, m23, m24;
				float	m31, m32, m33, m34;
				float	m41, m42, m43, m44;
			};										
		};
	};
	Mat4 operator-(const Mat4& m1, const Mat4& m2);
	Mat4 operator*(const Mat4& m1, const Mat4& m2);
	Mat4 operator+(const Mat4& m1, const Mat4& m2);
	Mat4 operator*(const Mat4& mat, float s);
	Mat4 operator*(float s, const Mat4& mat);
}

#endif	//	#ifndef __MAT4_H__
