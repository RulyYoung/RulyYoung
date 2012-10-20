#ifndef __ORB_MATH_INL__
#define __ORB_MATH_INL__

//================================================
// Vec2 inline implement
//================================================
inline 
Vec2::Vec2():x(0), y(0)
{
}
inline 
Vec2::Vec2(float _x, float _y):x(_x), y(_y)
{
}
inline 
bool Vec2::operator==(const Vec2& other) const
{
	return x == other.x && y == other.y;
}
inline
bool Vec2::operator!=(const Vec2& other) const
{
	return !operator==(other);
}
inline
Vec2 Vec2 ::operator+() const
{
	return *this;
}
inline
Vec2 Vec2 ::operator-() const
{
	return Vec2(-x, -y);
}
inline
float Vec2::Length() const
{
	return sqrtf(x * x + y * y);
}
inline
Vec2 Vec2::GetNormalized() const
{
	Vec2 v = *this;
	v.Normalize();
	return v;
}
inline
const Vec2& Vec2::operator +=(const Vec2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}
inline
const Vec2& Vec2::operator -=(const Vec2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}
inline
const Vec2& Vec2::operator *=(float s)
{
	x *= s;
	y *= s;
	return *this;
}
inline
const Vec2& Vec2::operator /=(float s)
{
	x /= s;
	y /= s;
	return *this;
}
inline 
Vec2 operator*(const Vec2& _v, const Mat4& m)
{
	Vec2 v = _v;
	Transform( v, m );
	return v;
}
inline
Vec2 operator*(const Mat4& m, const Vec2& _v)
{
	Vec2 v = _v;
	Transform( v, m );
	return v;
}
inline
Vec2 operator*(const Vec2& _v, const Mat3& m)
{
	Vec2 v = _v;
	Transform( v, m );
	return v;
}
inline
Vec2 operator*(const Mat3& m, const Vec2& _v)
{
	Vec2 v = _v;
	Transform( v, m );
	return v;
}

//================================================

//================================================
// Vec3 inline implement
//================================================
inline
Vec3::Vec3():x(0), y(0), z(0)
{
}
inline
Vec3::Vec3(float _x, float _y, float _z):x(_x), y(_y), z(_z)
{
}
inline
bool Vec3::operator==(const Vec3& other) const
{
	return x == other.x && y == other.y && z == other.z;
}
inline
bool Vec3::operator!=(const Vec3& other) const 
{
	return !operator==(other);
}
inline 
Vec3 Vec3::operator+() const
{
	return *this;
}
inline
Vec3 Vec3::operator-() const
{
	return Vec3(-x, -y, -z);
}
inline
float Vec3::Length() const
{
	return sqrtf(x * x + y * y + z * z);
}
inline
Vec3 Vec3::GetNormalized() const
{
	Vec3 v = *this;
	v.Normalize();
	return v;
}
inline
const Vec3& Vec3::operator +=(const Vec3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}
inline
const Vec3& Vec3::operator -=(const Vec3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}
inline
const Vec3& Vec3::operator *=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}
inline
const Vec3& Vec3::operator /=(float s)
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}
//================================================

//================================================
// Vec4 inline implement
//================================================
inline 
Vec4::Vec4():x(0), y(0), z(0), w(0)
{
}
inline
Vec4::Vec4(float _x, float _y, float _z, float _w):x(_x), y(_y), z(_z), w(_w)
{
}
inline
bool Vec4::operator==(const Vec4& other) const
{
	return x == other.x && y == other.y && z == other.z && w == other.w;
}
inline
bool Vec4::operator!=(const Vec4& other) const
{
	return !operator==(other);
}
inline
Vec4 Vec4::operator+() const
{
	return *this;
}
inline
Vec4 Vec4::operator-() const
{
	return Vec4(-x, -y, -z, -w);
}
inline
float Vec4::Length() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}
inline 
Vec4 Vec4 ::GetNormalized() const
{
	Vec4 v = *this;
	v.Normalize();
	return v;
}
inline
const Vec4& Vec4::operator +=(const Vec4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}
inline
const Vec4& Vec4::operator -=(const Vec4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}
inline
const Vec4& Vec4::operator *=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;
	return *this;
}
inline
const Vec4& Vec4::operator /=(float s)
{
	x /= s;
	y /= s;
	z /= s;
	w /= s;
	return *this;
}
//================================================


//================================================
// Quat inline implement
//================================================
inline
Quat::Quat():x(0), y(0), z(0), w(0)
{
}

inline
Quat::Quat(float _x, float _y, float _z, float _w)
		:x(_x), y(_y), z(_z), w(_w)
{
}

inline
bool Quat::operator == (const Quat& other) const
{
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

inline
bool Quat::operator != (const Quat& other) const
{
	return !operator==(other);
}

inline
Quat Quat::operator + () const
{
	return *this;
}

inline
Quat Quat::operator - () const
{
	return Quat(-x, -y, -z, -w);
}

inline
Quat& Quat::operator += (const Quat& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

inline
Quat& Quat::operator -= (const Quat& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

inline
Quat& Quat::operator *= (float f)
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;
	return *this;
}

inline
Quat& Quat::operator /= ( float f )
{
	float fInv = 1.0f / f;
	x *= fInv;
	y *= fInv;
	z *= fInv;
	w *= fInv;
	return *this;
}

inline
float Quat::Length() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

inline
bool Quat::IsIdentity() const
{
	return x == 0.0f && y == 0.0f && z == 0.0f && w == 1.0f;
}
inline
const Quat& Quat::SetIdentity()
{
	x = y = z = 0.0f;
	w = 1.0f;
	return *this;
}
inline
Quat Quat ::GetNormalize() const
{
	Quat q = *this;
	q.Normalize();
	return q;
}
//================================================


//================================================
// Mat3 inline implement
//================================================
inline
Mat3::Mat3()
{
	memset(this, 0, sizeof(Mat3));
}
inline
Mat3::Mat3(float _m[9])
{
	memcpy(m, _m, 9 * sizeof(float));
}

inline
Mat3::Mat3(	float _m11, float _m12, float _m13,
	float _m21, float _m22, float _m23,
	float _m31, float _m32, float _m33)
	
{
	m11 = _m11, m12 = _m12, m13 = _m13, 
	m21 = _m21, m22 = _m22, m23 = _m23, 
	m31 = _m31, m32 = _m32, m33 = _m33;
		
}

inline
float& Mat3::operator()(int row, int col)
{
	return m[3 * (row) + col ];
}

inline
const float& Mat3::operator()(int row, int col) const
{
	return m[3 * (row) + col];
}
inline
float& Mat3::operator[](int nIndex)
{
	return m[nIndex];
}
inline
const float& Mat3::operator[](int nIndex) const
{
	return m[nIndex];
}
inline
const Mat3& Mat3::operator+=(const Mat3& other)
{
	for(int i = 0; i < 9; ++i)
	{
		m[i] += other.m[i];
	}
	return *this;
}

inline
const Mat3& Mat3::operator-=(const Mat3& other)
{
	for(int i = 0; i < 9; ++i)
	{
		m[i] -= other.m[i];
	}
	return *this;
}

inline
bool Mat3::operator==(const Mat3& other) const
{
	for(int i = 0; i < 9; ++i)
	{
		if(m[i] != other.m[i])
			return false;
	}
	return true;
}

inline
bool Mat3::operator!=(const Mat3& other) const
{
	return !operator==(other);
}

inline
const Mat3& Mat3::SetIdentity()
{
	memset(this, 0, sizeof(Mat3));
	m11 = m22 = m33;
	return *this;
}

inline
bool Mat3::isIdentity() const
{
	return	m11 == 1.0f && m12 == 0.0f && m13 == 0.0f && 
			m21 == 0.0f && m22 == 1.0f && m23 == 0.0f && 
			m31 == 0.0f && m32 == 0.0f && m33 == 1.0f;
			
}
inline
float Mat3::Determinant() const
{
	return ((m11 * ((m22 * m33) - (m23 * m32))) -
            (m12 * ((m21 * m33) - (m23 * m31))) +
            (m13 * ((m21 * m32) - (m22 * m31))));
}
inline 
Mat3 Mat3::GetTranspose() const
{
	Mat3 ret = *this;
	ret.Transpose();
	return ret;
}
inline 
Mat3 Mat3::GetInverse() const
{
	Mat3 ret = *this;
	ret.Invert();
	return ret;
}
inline
Mat3::operator float*() const
{
	return (float*)m;
}
inline
Mat3::Mat3(const Quat& quat)
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
	
	m12 = xy + wz;
	m22 = 1.0f - (xx + zz);
	m32 = yz - wx;
	
	m13 = xz - wy;
	m23 = yz + wx;
	m33 = 1.0f - (xx + yy);
}
inline
Vec3 Mat3::GetRow(int row) const
{
	Vec3 v;
	v.x = (*this)(0, row);
	v.y = (*this)(1, row);
	v.z = (*this)(2, row);
	return v;
}
inline
Vec3 Mat3::GetLine(int line) const
{
	Vec3 v;
	v.x = (*this)(line, 0);
	v.y = (*this)(line, 1);
	v.z = (*this)(line, 2);
	return v;
}
inline
void Mat3::SetLine(int line, const Vec3& v)
{
	(*this)(line, 0) = v.x;
	(*this)(line, 1) = v.y;
	(*this)(line, 2) = v.z;
}
inline
void Mat3::SetRow(int row, const Vec3& v)
{
	(*this)(0, row) = v.x;
	(*this)(1, row) = v.y;
	(*this)(2, row) = v.z;
}
//================================================


//================================================
// Mat4 inline implement
//================================================
inline
Mat4::Mat4()
{
	memset(this, 0, sizeof(Mat4));
}
inline
Mat4::Mat4(float _m[16])
{
	memcpy(m, _m, 16* sizeof(float));
}
inline
Mat4::Mat4(const Mat3& other)
{
	m11 = other(0, 0);
	m12 = other(0, 1);
	m13 = other(0, 2);
	m14 = 0.0f;

	m21 = other(1, 0);
	m22 = other(1, 1);
	m23 = other(1, 2);
	m24 = 0.0f;

	m31 = other(2, 0);
	m32 = other(2, 1);
	m33 = other(2, 2);
	m34 = 0.0f;

	m41 = m42 = m43 = 0.0f;
	m44 = 1.0f;

}
inline
Mat4::Mat4(	float _m11, float _m12, float _m13, float _m14, 
	float _m21, float _m22, float _m23, float _m24,
	float _m31, float _m32, float _m33, float _m34,
	float _m41, float _m42, float _m43, float _m44)
{
	m11 = _m11, m12 = _m12, m13 = _m13, m14 = _m14, 
		m21 = _m21, m22 = _m22, m23 = _m23, m24 = _m24,
		m31 = _m31, m32 = _m32, m33 = _m33, m34 = _m34,
		m41 = _m41, m42 = _m42, m43 = _m43, m44 = _m44;
}

inline
float& Mat4::operator()(int row, int col)
{
	return m[4 * (row) + col ];
}

inline
const float& Mat4::operator()(int row, int col) const
{
	return m[4 * (row) + col];
}
inline
float& Mat4::operator[](int nIndex)
{
	return m[nIndex];
}
inline
const float& Mat4::operator[](int nIndex) const
{
	return m[nIndex];
}
inline
const Mat4& Mat4::operator+=(const Mat4& other)
{
	for(int i = 0; i < 16; ++i)
	{
		m[i] += other.m[i];
	}
	return *this;
}

inline
const Mat4& Mat4::operator-=(const Mat4& other)
{
	for(int i = 0; i < 16; ++i)
	{
		m[i] -= other.m[i];
	}
	return *this;
}

inline
bool Mat4::operator==(const Mat4& other) const
{
	for(int i = 0; i < 16; ++i)
	{
		if(m[i] != other.m[i])
			return false;
	}
	return true;
}

inline
bool Mat4::operator!=(const Mat4& other) const
{
	return !operator==(other);
}

inline
const Mat4& Mat4::SetIdentity()
{
	memset(this, 0, sizeof(Mat4));
	m11 = m22 = m33 = m44 = 1.0f;
	return *this;
}

inline
bool Mat4::isIdentity() const
{
	return	m11 == 1.0f && m12 == 0.0f && m13 == 0.0f && m14 == 0.0f &&
			m21 == 0.0f && m22 == 1.0f && m23 == 0.0f && m24 == 0.0f &&
			m31 == 0.0f && m32 == 0.0f && m33 == 1.0f && m34 == 0.0f &&
			m41 == 0.0f && m42 == 0.0f && m43 == 0.0f && m44 == 1.0f;
}
inline
float Mat4::Determinant() const
{
	return ((m11 * ((m22 * m33) - (m23 * m32))) -
            (m12 * ((m21 * m33) - (m23 * m31))) +
            (m13 * ((m21 * m32) - (m22 * m31))));
}
inline 
Mat4 Mat4::GetTranspose() const
{
	Mat4 ret = *this;
	ret.Transpose();
	return ret;
}
inline 
Mat4 Mat4::GetInverse() const
{
	Mat4 ret = *this;
	ret.Invert();
	return ret;
}
inline
Mat4::operator float*() const
{
	return (float*)m;
}
inline
Vec4 Mat4::GetRow(int row) const
{
	Vec4 v;
	v.x = (*this)(0, row);
	v.y = (*this)(1, row);
	v.z = (*this)(2, row);
	v.w = (*this)(3, row);
	return v;
}
inline
Vec4 Mat4::GetLine(int line) const
{
	Vec4 v;
	v.x = (*this)(line, 0);
	v.y = (*this)(line, 1);
	v.z = (*this)(line, 2);
	v.w = (*this)(line, 3);
	return v;
}
inline
void Mat4::SetLine(int line, const Vec4& v)
{
	(*this)(line, 0) = v.x;
	(*this)(line, 1) = v.y;
	(*this)(line, 2) = v.z;
	(*this)(line, 3) = v.w;
}
inline
void Mat4::SetRow(int row, const Vec4& v)
{
	(*this)(0, row) = v.x;
	(*this)(1, row) = v.y;
	(*this)(2, row) = v.z;
	(*this)(3, row) = v.w;
}
//================================================

//================================================
// Plane inline implement
//================================================
inline
Plane Plane::GetNormalized() const
{
	return Plane(*this).Normalize();
}
inline
Plane::Plane()
{
	a = b = c = d = 0;
}
inline
Plane::Plane(const Plane& other)
{
	a = other.a;
	b = other.b;
	c = other.c;
	d = other.d;
}
inline
Plane::Plane(float A, float B, float C, float D)
{
	a = A;
	b = B;
	c = C;
	d = D;
}
inline
Plane::Plane(const Vec3& n, const Vec3& p)
{
	 get_normal() = n;
	 d = -Dot(get_normal(), p);
}
inline
Plane::Plane(const Vec3& p1, const Vec3& p2, const Vec3& p3)
{
	get_normal() = Cross((p2 -p1).Normalize(), (p3 - p1).Normalize());
	d = -Dot(get_normal().Normalize(), p1);
}
inline
bool Plane::operator==(const Plane& other) const
{
	return (other.a == a && other.b == b && other.c== c && other.d == d);
}
inline
bool Plane::operator!=(const Plane& other) const
{
	return !operator==(other);
}
inline
Plane::operator float* ()
{
	return v;
}
inline
float Plane::PointDistance(const Vec3& point) const
{
	Vec3 vec( a, b, c );
	return d + Dot( vec, point);
}
//================================================


//================================================
// Helper functions inline implement
//================================================

inline 
Vec2 operator+(const Vec2& v1, const Vec2& v2)
{
	return Vec2(v1.x + v2.x, v1.y + v2.y);
}

inline 
Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline 
Vec4 operator+(const Vec4& v1, const Vec4& v2)
{
	return Vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

inline
Quat operator+(const Quat& v1, const Quat& v2)
{
	return Quat(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

inline 
Vec2 operator-(const Vec2& v1, const Vec2& v2)
{
	return Vec2(v1.x - v2.x, v1.y - v2.y);
}

inline 
Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline 
Vec4 operator-(const Vec4& v1, const Vec4& v2)
{
	return Vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

inline 
Quat operator-(const Quat& v1, const Quat& v2)
{
	return Quat(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

inline 
Vec2 operator*(const Vec2& v, float s)
{
	return Vec2(v.x * s, v.y * s);
}

inline 
Vec2 operator*(float s, const Vec2& v)
{
	return v * s;
}

inline 
Vec3 operator*(const Vec3& v, float s)
{
	return Vec3(v.x *s , v.y*s, v.z *s);
}

inline 
Vec3 operator*(float s, const Vec3& v)
{
	return v * s;
}

inline 
Vec4 operator*(const Vec4& v, float s)
{
	return Vec4(v.x *s , v.y*s, v.z *s, v.w * s);
}

inline 
Vec4 operator*(float s, const Vec4& v)
{
	return v * s;
}

inline 
Quat operator*(const Quat& v, float s)
{
	return Quat(v.x *s , v.y*s, v.z *s, v.w * s);
}

inline 
Quat operator*(float s, const Quat& v)
{
	return v * s;
}
inline
Mat4 operator*(const Mat4& mat, float s)
{
	Mat4 ret;
	for(int i = 0; i < 16; ++i)
		ret[i] = mat[i] * s;
	return ret;
}
inline
Mat3 operator*(const Mat3& mat, float s)
{
	Mat3 ret;
	for(int i = 0; i < 9; ++i)
		ret[i] = mat[i] * s;
	return ret;
}
inline
Mat4 operator*(float s, const Mat4& mat)
{
	return mat * s;
}

inline
Mat3 operator*(float s, const Mat3& mat)
{
	return mat * s;
}

inline 
float Dot(const Vec2& v1, const Vec2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

inline 
float Dot(const Vec3& v1, const Vec3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline 
float Dot(const Vec4& v1, const Vec4& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

inline 
float Dot(const Quat& q1, const Quat& q2)
{
	return q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
}

inline 
Vec3 Cross(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.y * v2.z - v1.z * v2.y, 
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x);
}

inline
Mat4 operator+(const Mat4& m1, const Mat4& m2)
{
	Mat4 ret;
	for(int i = 0; i < 16; ++i)
	{
		ret[i] = m1[i] + m2[i];
	}
	return ret;
}
inline
Mat3 operator+(const Mat3& m1, const Mat3& m2)
{
	Mat3 ret;
	for(int i = 0; i < 9; ++i)
	{
		ret[i] = m1[i] + m2[i];
	}
	return ret;
}

inline
Mat4 operator-(const Mat4& m1, const Mat4& m2)
{
	Mat4 ret;
	for(int i = 0; i < 16; ++i)
	{
		ret[i] = m1[i] - m2[i];
	}
	return ret;
}
inline
Mat3 operator-(const Mat3& m1, const Mat3& m2)
{
	Mat3 ret;
	for(int i = 0; i < 9; ++i)
	{
		ret[i] = m1[i] - m2[i];
	}
	return ret;
}

inline
std::ostream& operator<<(std::ostream& o, const Mat4& m)
{
	using namespace std;

	o.setf(ios_base::fixed, ios_base::floatfield);

	o << m[0]  <<"\t" << m[1]  << "\t" << m[2]  << "\t" << m[3]  << endl;
	o << m[4]  <<"\t" << m[5]  << "\t" << m[6]  << "\t" << m[7]  << endl;
	o << m[8]  <<"\t" << m[9]  << "\t" << m[10] << "\t" << m[11] << endl;
	o << m[12] <<"\t" << m[13] << "\t" << m[14] << "\t" << m[15];
	
	o.setf(ios_base::fmtflags(0), ios_base::floatfield);
	return o;
}
inline
std::ostream& operator<<(std::ostream& o, const Vec2& v)
{
	using namespace std;

	o.setf(ios_base::fixed, ios_base::floatfield);

	o << "[" << v.x << "," << v.y << "]";

	o.setf(ios_base::fmtflags(0), ios_base::floatfield);

	return o;
}
inline
std::ostream& operator<<(std::ostream& o, const Vec3& v)
{
	using namespace std;

	o.setf(ios_base::fixed, ios_base::floatfield);

	o << "[" << v.x << "," << v.y << "," << v.z << "]";

	o.setf(ios_base::fmtflags(0), ios_base::floatfield);

	return o;
}
inline
std::ostream& operator<<(std::ostream& o, const Vec4& v)
{
	using namespace std;

	o.setf(ios_base::fixed, ios_base::floatfield);

	o << "[" << v.x << "," << v.y << "," << v.z << "," << v.w << "]";

	o.setf(ios_base::fmtflags(0), ios_base::floatfield);

	return o;
}
inline
std::ostream& operator<<(std::ostream& o, const Quat& q)
{
	using namespace std;

	o.setf(ios_base::fixed, ios_base::floatfield);

	o << "[" << q.w << ",(" << q.x << "," << q.y << "," << q.z << ")]";

	o.setf(ios_base::fmtflags(0), ios_base::floatfield);
	
	return o;
}
inline
std::ostream& operator<<(std::ostream& o, const Plane& p)
{
	using namespace std;

	o.setf(ios_base::fixed, ios_base::floatfield);

	o << "[" << p.a << "," << p.b << "," << p.c << "," << p.d << "]";

	o.setf(ios_base::fmtflags(0), ios_base::floatfield);
	
	return o;
}
inline
std::ostream& operator<<(std::ostream& o, const Mat3& m)
{
	using namespace std;

	o.setf(ios_base::fixed, ios_base::floatfield);

	o << m[0]  <<"\t" << m[1]  << "\t" << m[2]  << endl;
	o << m[3]  <<"\t" << m[4]  << "\t" << m[5]  << endl;
	o << m[6]  <<"\t" << m[7]  << "\t" << m[8]  << endl;
		
	o.setf(ios_base::fmtflags(0), ios_base::floatfield);
	return o;
}
//================================================

#endif

