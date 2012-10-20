#include "orb.h"
// OrbMath implement
// author: DanTong
namespace orb
{
	// ==========================================================
	// ************************* Vec2 Members ****************
	// ==========================================================
	const Vec2& Vec2::Normalize()
	{
		float len = Length();
		if(len != 0)
		{
			x /= len;
			y /= len;
		}
		return *this;
	}
	const Vec2& Transform(Vec2& v, const Mat4& m)
	{
		Vec4 r(v.x , v.y, 0, 1);
		Transform(r, m);
		r.x /= r.w;
		r.y /= r.w;

		v.x = r.x;
		v.y = r.y;

		return v;
	}

	const Vec2& Transform(Vec2& v, const Mat3& m)
	{
		Vec3 r(v.x , v.y, 0);
		Transform(r, m);
		v.x = r.x;
		v.y = r.y;

		return v;
	}


	// ==========================================================
	// ************************* Vec3 Members ****************
	// ==========================================================
	const Vec3& Vec3::Normalize()
	{
		float len = Length();
		if(len != 0)
		{
			x /= len;
			y /= len;
			z /= len;
		}
		return *this;
	}
	const Vec3& Transform(Vec3& v, const Mat4& m)
	{
		Vec4 r(v.x , v.y, v.z, 1);
		Transform(r, m);
		r.x /= r.w;
		r.y /= r.w;
		r.z /= r.w;
		
		v.x = r.x;
		v.y = r.y;
		v.z = r.z;
		return v;
	}
	const Vec3& Transform(Vec3& v, const Mat3& m)
	{
		float x,y,z;
		x = v.x * m(0, 0) + v.y * m(1, 0) + v.z * m(2, 0);
		y = v.x * m(0, 1) + v.y * m(1, 1) + v.z * m(2, 1);
		z = v.x * m(0, 2) + v.y * m(1, 2) + v.z * m(2, 2);
		
		v.x = x;
		v.y = y;
		v.z = z;
		return v;
	}
	
	// ==========================================================
	// ************************* Vec4 Members ****************
	// ==========================================================
	const Vec4& Vec4::Normalize()
	{
		float len = Length();
		if(len != 0)
		{
			x /= len;
			y /= len;
			z /= len;
			w /= len;
		}
		return *this;
	}
	const Vec4& Transform(Vec4& v, const Mat4& m)
	{
		float x,y,z,w;
		x = v.x * m(0, 0) + v.y * m(1, 0) + v.z * m(2, 0) + v.w * m(3, 0);
		y = v.x * m(0, 1) + v.y * m(1, 1) + v.z * m(2, 1) + v.w * m(3, 1);
		z = v.x * m(0, 2) + v.y * m(1, 2) + v.z * m(2, 2) + v.w * m(3, 2);
		w = v.x * m(0, 3) + v.y * m(1, 3) + v.z * m(2, 3) + v.w * m(3, 3);
		v.x = x;
		v.y = y;
		v.z = z;
		v.w = w;
		return v;
	}

	// ==========================================================
	// ************************* Mat4 ***********************
	// ==========================================================

	const Mat4& Mat4::operator*=(const Mat4& other)
	{
		*this = *this * other;
		return *this;
	}
	const Mat4& Mat4::Transpose()
	{
		#define swap(x, y) {float tmp = x; x = y; y = tmp;}
		swap(m12, m21);
		swap(m13, m31);
		swap(m14, m41);
		swap(m23, m32);
		swap(m24, m42);
		swap(m34, m43);
		return *this;
	}
	Mat4::Mat4(const Quat& quat)
	{
		float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;

		x2 = quat.x + quat.x;
		y2 = quat.y + quat.y;
		z2 = quat.z + quat.z;
		xx = quat.x * x2;
		xy = quat.x * y2;
		xz = quat.x * z2;
		yy = quat.y * y2;
		yz = quat.y * z2;
		zz = quat.z * z2;
		wx = quat.w * x2;
		wy = quat.w * y2;
		wz = quat.w * z2;

		m11 = 1.0f - (yy + zz);
		m21 = xy - wz;
		m31 = xz + wy;
		m41 = 0.0f;

		m12 = xy + wz;
		m22 = 1.0f - (xx + zz);
		m32 = yz - wx;
		m42 = 0.0f;

		m13 = xz - wy;
		m23 = yz + wx;
		m33 = 1.0f - (xx + yy);
		m43 = 0.0f;
		
		m14 = 0.0f;
		m24 = 0.0f;
		m34 = 0.0f;
		m44 = 1.0f;
	}
	
	Mat4 operator*(const Mat4& m1, const Mat4& m2)
	{
		Mat4 res;
		int i,j,k;
		
		for (i=0; i<4; i++) 
		{
			for (j=0; j<4; j++) 
			{
				res[i*4+j] = 0.0f;
				for (k=0; k<4; k++) 
				{
					res[i*4+j] += m1[i*4+k]*m2[k*4+j];
				}
			}
		}
		return res;
	}

	Mat4 Mat4::Translation(float x, float y, float z)
	{
		Mat4 ret;
		ret.SetIdentity();
		ret(3, 0) = x;
		ret(3, 1) = y;
		ret(3, 2) = z;

		return ret;
	}

	Mat4 Mat4::Scale(float sx, float sy, float sz)
	{
		Mat4 ret;
		ret.SetIdentity();
		ret(0,0) = sx;
		ret(1,1) = sy;
		ret(2,2) = sz;

		return ret;
	}
	
	Mat4 Mat4::PerspectiveLH(float nvp, float fvp, float fov, float aspect)
	{
		float h = 1 / tan(fov/2);	
		float w = h / aspect;


		return Mat4(w,	0,	0,	0,
						0,       h,       0,               0,
						0,       0,       fvp/(fvp-nvp),      1,
						0,       0,       -nvp*fvp/(fvp-nvp),  0);
	}
	Mat4 Mat4::PerspectiveRH(float nvp, float fvp, float fov, float aspect)
	{
		float h = 1 / tan(fov/2);	
		float w = h / aspect;


		return Mat4(w,	0,	0,	0,
						0,       h,       0,               0,
						0,       0,       fvp/(nvp-fvp),      -1,
						0,       0,       nvp*fvp/(nvp-fvp),  0);
	}
	Mat4 Mat4::LookAtLH(const Vec3& eye, const Vec3& at, const Vec3& up)
	{
		Vec3 zaxis = (at - eye).GetNormalized();
		Vec3 xaxis = (Cross(up, zaxis)).GetNormalized();
		Vec3 yaxis = Cross(zaxis, xaxis);

		return Mat4(	
			xaxis.x,				yaxis.x,				zaxis.x,				0,
			xaxis.y,				yaxis.y,				zaxis.y,				0,
			xaxis.z,				yaxis.z,				zaxis.z,				0,
			-Dot(xaxis, eye),	-Dot(yaxis, eye),	-Dot(zaxis, eye),	1);
	}
	Mat4 Mat4::LookAtRH(const Vec3& eye, const Vec3& at, const Vec3& up)
	{
		Vec3 zaxis = (eye - at).GetNormalized();
		Vec3 xaxis = (Cross(up, zaxis)).GetNormalized();
		Vec3 yaxis = Cross(zaxis, xaxis);

		return Mat4(	
			xaxis.x,				yaxis.x,				zaxis.x,				0,
			xaxis.y,				yaxis.y,				zaxis.y,				0,
			xaxis.z,				yaxis.z,				zaxis.z,				0,
			-Dot(xaxis, eye),	-Dot(yaxis, eye),	-Dot(zaxis, eye),	1);
	}
	const Mat4& Mat4::Invert()
	{
		float d = Determinant();
	
		if (fabs(d) < std::numeric_limits<float>::epsilon())
		{
			SetIdentity();
		}
		else
		{
			d = 1.f / d;

			Mat4 temp;
			temp.m11 = ( d * ((m22 * m33) - (m23 * m32)));
			temp.m12 = (-d * ((m12 * m33) - (m13 * m32)));
			temp.m13 = ( d * ((m12 * m23) - (m13 * m22)));
			temp.m14 = 0.0f;

			temp.m21 = (-d * ((m21 * m33) - (m23 * m31)));
			temp.m22 = ( d * ((m11 * m33) - (m13 * m31)));
			temp.m23 = (-d * ((m11 * m23) - (m13 * m21)));
			temp.m24 = 0.0f;

			temp.m31 = ( d * ((m21 * m32) - (m22 * m31)));
			temp.m32 = (-d * ((m11 * m32) - (m12 * m31)));
			temp.m33 = ( d * ((m11 * m22) - (m12 * m21)));
			temp.m34 = 0.0f;

			temp.m41 = -((m41 * temp.m11) + (m42 * temp.m21) + (m43 * temp.m31));
			temp.m42 = -((m41 * temp.m12) + (m42 * temp.m22) + (m43 * temp.m32));
			temp.m43 = -((m41 * temp.m13) + (m42 * temp.m23) + (m43 * temp.m33));
			temp.m44 = 1.0f;
			*this = temp;
		}
		return *this;
	}
	
	// =============================== end ====================
	// ==========================================================
	// ************************* Mat3 Members ***************
	// ==========================================================

	const Mat3& Mat3::operator*=(const Mat3& other)
	{
		(*this) = (*this) * other;
		return *this;
	}
	const Mat3& Mat3::Transpose()
	{
		#define __swap(x, y) {float tmp = x; x = y; y = tmp;}
		__swap(m12, m21);
		__swap(m13, m31);
		__swap(m23, m32);
		return *this;
	}
	
	Mat3 operator*(const Mat3& m1, const Mat3& m2)
	{
		Mat3 res;
		int i,j,k;
		for ( i = 0; i < 3; i++ ) 
		{
			for ( j = 0; j < 3; j++ ) 
			{
				res[ i * 3 + j ] = 0.0f;
				for ( k = 0; k < 3; k++ ) 
				{
					res[ i * 3 + j ] += m1[ i * 3 + k ] * m2[ k * 3 + j ];
				}
			}
		}
		return res;
	}

	Mat3 Mat3::RotationAxis(const Vec3& axis, float radian)
	{
		Mat3 ret;
		Vec3 axis_n = axis;
		axis_n.Normalize();
		float c = (float)cos(radian);
		float s = (float)sin(radian);
		float omc = (1 - c);
								
		float x = axis_n.x;
		float y = axis_n.y;
		float z = axis_n.z;	
		float xs = x * s;
		float ys = y * s;
		float zs = z * s;
		float xyomc = x * y * omc;
		float xzomc = x * z * omc;
		float yzomc = y * z * omc;
		
		ret[0] = x*x*omc + c;
		ret[1] = xyomc + zs;
		ret[2] = xzomc - ys;
				
		ret[3] = xyomc - zs;
		ret[4] = y*y*omc + c;
		ret[5] = yzomc + xs;
				
		ret[6] = xzomc + ys;
		ret[7] = yzomc - xs;
		ret[8] = z*z*omc + c;
		return ret;
	}
	Mat3 Mat3::RotationX(float radian)
	{
		return Mat3::RotationAxis(Vec3(1.0f, 0.0f, 0.0f), radian);
	}
	Mat3 Mat3::RotationY(float radian)
	{
		return Mat3::RotationAxis(Vec3(0.0f, 1.0f, 0.0f), radian);
	}
	Mat3 Mat3::RotationZ(float radian)
	{
		return Mat3::RotationAxis(Vec3(0.0f, 0.0f, 1.0f), radian);
	}

	const Mat3& Mat3::Invert()
	{
		float d = Determinant();
	
		if (fabs(d) < std::numeric_limits<float>::epsilon())
		{
			SetIdentity();
		}
		else
		{
			d = 1.f / d;

			Mat3 temp;
			temp.m11 = ( d * ((m22 * m33) - (m23 * m32)));
			temp.m12 = (-d * ((m12 * m33) - (m13 * m32)));
			temp.m13 = ( d * ((m12 * m23) - (m13 * m22)));
			

			temp.m21 = (-d * ((m21 * m33) - (m23 * m31)));
			temp.m22 = ( d * ((m11 * m33) - (m13 * m31)));
			temp.m23 = (-d * ((m11 * m23) - (m13 * m21)));
			

			temp.m31 = ( d * ((m21 * m32) - (m22 * m31)));
			temp.m32 = (-d * ((m11 * m32) - (m12 * m31)));
			temp.m33 = ( d * ((m11 * m22) - (m12 * m21)));
			

			*this = temp;
		}
		return *this;
	}

	// ============================== end ====================

	// ==========================================================
	// ************************* Quat Members *************
	// ==========================================================

	const Quat& Quat::Normalize()
	{
		float len = Length();
		if(len != 0)
			*this /= len;	
		return *this;
	}

	Quat Quat::RotationAxis(const Vec3& axis, float radian)
	{
		Vec3 axis_n = axis;
		axis_n.Normalize();
		return Quat((float)(sin(radian/2) * axis_n.x), 
			(float)(sin(radian/2) * axis_n.y), 
			(float)(sin(radian/2) * axis_n.z), 
			(float)cos(radian/2));
	}
	Quat& Quat::operator*=(const Quat& other)
	{
		*this = *this * other;
		return *this;
	}
	Quat operator * ( const Quat& q1 , const Quat& q2)
	{
		float w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
		float x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y;
		float y = q1.w*q2.y + q1.y*q2.w + q1.z*q2.x - q1.x*q2.z;
		float z = q1.w*q2.z + q1.z*q2.w + q1.x*q2.y - q1.y*q2.x;
		return Quat(x, y, z, w);
	}

	Quat Quat::Slerp(const Quat& qs , const Quat& qf, float s)
	{
		#define DELTA 0.0001f
		float  to1[4];
		float  omega, cosom, sinom, scale0, scale1;

		cosom = qs.x * qf.x + qs.y * qf.y + qs.z * qf.z + qs.w * qf.w;

		// adjust signs (if necessary)
		if ( cosom < 0.0 )
		{ 
			cosom = -cosom; 
			to1[0] = - qf.x;
			to1[1] = - qf.y;
			to1[2] = - qf.z;
			to1[3] = - qf.w;
		} 
		else
		{
			to1[0] = qf.x;
			to1[1] = qf.y;
			to1[2] = qf.z;
			to1[3] = qf.w;
		}

		// calculate coefficients
		if ( (1.0f - cosom) > DELTA ) 
		{
			// standard case (slerp)
			omega = acosf(cosom);
			sinom = sinf(omega);
			scale0 = sinf((1.0f - s) * omega) / sinom;
			scale1 = sinf(s * omega) / sinom;
		} 
		else 
		{        
			// "from" and "to" quaternions are very close 
			//  ... so we can do a linear interpolation
			scale0 = 1.0f - s;
			scale1 = s;
		}
		// calculate final values
		
		return Quat(scale0 * qs.x + scale1 * to1[0], 
				scale0 * qs.y + scale1 * to1[1],
				scale0 * qs.z + scale1 * to1[2],
				scale0 * qs.w + scale1 * to1[3]);
	}

	Quat::Quat(const Mat3& mat)
	{
		float trace = mat(0,0) + mat(1,1) + mat(2,2);

		if (trace > 0.f)
		{
			float s = sqrtf(trace + 1.f);
			
			w = s * 0.5f;
			
			s = 0.5f / s;

			x = (mat(1,2) - mat(2,1)) * s;
			y = (mat(2,0) - mat(0,2)) * s;
			z = (mat(0,1) - mat(1,0)) * s;
		}
		else
		{
			int nxt[] = {1, 2, 0};
			int i = 0;

			if (mat(1,1) > mat(0,0))
				i = 1;

			if (mat(2,2) > mat(i,i))
				i = 2;

			int j = nxt[i];
			int k = nxt[j];
			float s = sqrtf((mat(i,i) - (mat(j,j) + mat(k,k)) + 1.f));
			float q[4];

			q[i] = s * 0.5f;

			s = 0.5f / s;

			q[3] = (mat(j,k) - mat(k,j)) * s;
			q[j] = (mat(i,j) + mat(j,i)) * s;
			q[k] = (mat(i,k) + mat(k,i)) * s;

			x = q[0];
			y = q[1];
			z = q[2];
			w = q[3];
		}
	}
	
	Quat::Quat(const Mat4& mat)
	{
		float trace = mat(0,0) + mat(1,1) + mat(2,2);

		if (trace > 0.f)
		{
			float s = sqrtf(trace + 1.f);
			
			w = s * 0.5f;
			
			s = 0.5f / s;

			x = (mat(1,2) - mat(2,1)) * s;
			y = (mat(2,0) - mat(0,2)) * s;
			z = (mat(0,1) - mat(1,0)) * s;
		}
		else
		{
			int nxt[] = {1, 2, 0};
			int i = 0;

			if (mat(1,1) > mat(0,0))
				i = 1;

			if (mat(2,2) > mat(i,i))
				i = 2;

			int j = nxt[i];
			int k = nxt[j];
			float s = sqrtf((mat(i,i) - (mat(j,j) + mat(k,k)) + 1.f));
			float q[4];

			q[i] = s * 0.5f;

			s = 0.5f / s;

			q[3] = (mat(j,k) - mat(k,j)) * s;
			q[j] = (mat(i,j) + mat(j,i)) * s;
			q[k] = (mat(i,k) + mat(k,i)) * s;

			x = q[0];
			y = q[1];
			z = q[2];
			w = q[3];
		}
	}
	// ==================================== end =================
	
	// ==========================================================
	// ************************* Plane Members ******************
	// ==========================================================

	const Plane& Plane::Normalize()
	{
		float len = get_normal().Length();
		if(len != 0)
			d = d/ len;
		get_normal().Normalize();
		return *this;
	}
	
	float Dot(const Plane& plane, const Vec4& v)
	{
		return plane.a * v.x + plane.b * v.y + plane.c * v.z + plane.d * v.w;
	}
	float Dot(const Plane& plane, const Vec3& v)
	{
		return plane.a * v.x + plane.b * v.y + plane.c * v.z + plane.d;
	}
	float Plane::DotNormal(const Plane& plane, const Vec3& v)
	{
		return plane.a * v.x + plane.b * v.y + plane.c * v.z;
	}
	const Plane& Transform(Plane& plane, const Mat4& m)
	{
		Vec4 *pv = (Vec4*)&plane;
		return *((Plane*)&(Transform(*(pv), m)));
	}
	Vec3 Plane::LineIntersection(const Plane& plane, const Vec3& start, const Vec3& end)
	{
		float d1 = plane.PointDistance( start );
		float d2 = plane.PointDistance( end );
		float ui = d1 / ( d1 - d2 );
		Vec3 v = ( 1 - ui ) * start + ui * end;
		return v;
	}
	// ===================== end ==================================
}
