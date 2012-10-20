/*
 *  vec3.h
 *  cmdline_cpp
 *
 *  Created by Ruly on 2010-4-11.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __VEC3_H__
#define __VEC3_H__

namespace orb
{


	//! Orb vector3
	/*!
		 This struct implemented a 3 dimension vector, with some member fucntions to
		 simplize vector operation.
		 @warning This struct does not have a virtual destructor, so don't derive from this struct
		 unless you know exactly what you are doing.
		 @date 05/12/2003
		 @version 1.0
		 @author Dan Tong
		 @author mail: Lythm@citiz.net
	*/
	struct Vec3
	{
		//! Default Constructor
		/*!
			 This function set all the member value to default value 0.0f.
			 @return no return
		*/
		Vec3();

		//! Constructor
		/*!
			 This function assign x, y and z value to the vector
			 @param _x x value of the vector
			 @param _y y value of the vector
			 @param _z z value of the vector
			 @return no return
		*/
		Vec3(float _x, float _y, float _z);

		//! Operator ==
		/*! @return if the vector is equal to parameter @b other, the function 
			 returns @b true, otherwise, it returns @b false.
		*/
		bool operator==(const Vec3& other) const;

		//! Operator !=
		/*! @return if the vector is not equal to parameter @b other, the function 
			 returns @b true, otherwise, it returns @b false.
		*/
		bool operator!=(const Vec3& other) const;

		//! operator +
		/*!
			 Unary operator
			 Sign operation, return the positive vector value
			 @return the positive vector value
		*/
		Vec3 operator+() const;
		
		//! operator -
		/*!
			 Unary operator
			 Sign operation, return the negative vector value
			 @return the negative vector value
		*/
		Vec3 operator-() const;
		
		//! Vector length
		/*!
			 @return the module of the vector
		*/
		float Length() const;

		//! Normalize operation
		/*!
			 This funtction normalize the vector
			 @return the const refernce of the vector.
		*/
		const Vec3& Normalize();

		//! GetNormalized operation
		/*!
			 @return the normalized vector
		*/
		Vec3 GetNormalized() const;

		const Vec3& operator +=(const Vec3& other);
		const Vec3& operator -=(const Vec3& other);
		const Vec3& operator *=(float s);
		const Vec3& operator /=(float s);

		// data member

		float x;			/*!< x member of the vector */
		float y;			/*!< y member of the vector */
		float z;			/*!< z member of the vector */
	};


	//! vector3 operator+
	/*!
		 Add two vector3 and return the result.
		 @param v1 a vector
		 @param v2 a vector
		 @return the result of the addition
	*/
	 Vec3 operator+(const Vec3& v1, const Vec3& v2);
	//! vector3 operator-
	/*!
		 Subtract two vector3 and return the result.
		 @param v1 a vector
		 @param v2 a vector
		 @return the result of the subtraction
	*/
	 Vec3 operator-(const Vec3& v1, const Vec3& v2);

	//! vector3 operator*
	/*!
		 Multiply a vector3 with a float
		 @param v a vector
		 @param s a float
		 @return the result of the multiplication
	*/
	 Vec3 operator*(const Vec3& v, float s);

	//! vector3 operator*
	/*!
		 Multiply a float with a vector3.
		 @param s a float
		 @param v a vector
		 @return the result of the multiplication
	*/
	 Vec3 operator*(float s, const Vec3& v);


	//! vector3 cross production
	/*!
		 @param v1 a vector
		 @param v2 a vector
		 @return the result of cross production
	*/
	 Vec3 Cross(const Vec3& v1, const Vec3& v2);

	//! vector3 dot production
	/*!
		 @param v1 a vector
		 @param v2 a vector
		 @return the result of dot production
	*/
	 float Dot(const Vec3& v1, const Vec3& v2);

	//! Transform
	/*!
		 Transform a vector 3 by a matrix
		 @return the const reference of the vector
	*/
	 const Vec3& Transform(Vec3& v, const Mat4& m);

	//! Transform
	/*!
		 Transform a vector 3 by a matrix
		 @return the const reference of the vector
	*/
	 const Vec3& Transform(Vec3& v, const Mat3& m);

	//! vector2 dot production
	/*!
		 @param v1 a vector
		 @param v2 a vector
		 @return the result of dot production
	*/
	 float Dot(const Vec2& v1, const Vec2& v2);

}


#endif	//	#ifndef __VEC3_H__
