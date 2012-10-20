/*
 *  quat.h
 *  cmdline_cpp
 *
 *  Created by Ruly on 2010-4-11.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __QUAT_H__
#define __QUAT_H__
namespace orb
{
	struct Mat4;
	struct Mat3;

	//! Orb quaternion
	/*!
		 This struct implemented a quaternion, with some member fucntions to
		 simplize quaternion operation.
		 @warning This struct does not have a virtual destructor, so don't derive from this struct
		 unless you know exactly what you are doing.
		 @date 05/12/2003
		 @version 1.0
		 @author Dan Tong
		 @author mail: Lythm@citiz.net
	*/
	struct Quat
	{
		//! Default Constructor
		/*!
			 This function set all the member value to default value 0.0f.
			 @return no return.
		*/
		Quat();

		//! Constructor
		/*!
			 This function assign x, y, z and w value to the quaternion
			 @param _x x value of the quaternion
			 @param _y y value of the quaternion
			 @param _z z value of the quaternion
			 @param _w w value of the quaternion
			 @return no return.
		*/
		Quat(float _x, float _y, float _z, float _w);
		
		//! Constructor
		/*!
			 This function construct a quaternion from a Mat3
			 @param mat matrix to construct quaternion
			 @return no return.
		*/
		explicit Quat(const Mat3& mat);

		//! Constructor
		/*!
			 This function construct a quaternion from a Mat4
			 @param mat matrix to construct quaternion
			 @return no return.
		*/
		explicit Quat(const Mat4& mat);
		
		//! Operator ==
		/*! @return if the vector is equal to parameter @b other, the function 
			 returns @b true, otherwise, it returns @b false.
		*/
		bool operator == (const Quat& other) const;

		//! Operator !=
		/*! @return if the vector is not equal to parameter @b other, the function 
			 returns @b true, otherwise, it returns @b false.
		*/
		bool operator != (const Quat& other) const;

		//! operator +
		/*!
			 Unary operator
			 Sign operation, return the negative quaternion value
			 @return the negative quaternion value
		*/
		Quat operator + () const;

		//! operator -
		/*!
			 Unary operator
			 Sign operation, return the negative quaternion value
			 @return the negative quaternion value
		*/
		Quat operator - () const;
		
		//! operator +=
		/*!
			 This operator add another quaternion to itself.
			 @return the reference of *this.
		*/
		Quat& operator += (const Quat& other);

		//! operator +=
		/*!
			 This operator subtract another quaternion from itself.
			 @return the reference of *this.
		*/
		Quat& operator -= (const Quat& other);

		//! operator *=
		/*!
			 This operator multiply another quaternion to itself.
			 @return the reference of *this.
		*/
		Quat& operator *= (const Quat& other);

		//! operator *=
		/*!
			 This operator multiply a float to itself.
			 @return the reference of *this.
		*/
		Quat& operator *= (float f);

		//! operator /=
		/*!
			 This operator divide a float from itself.
			 @return the reference of *this.
		*/
		Quat& operator /= ( float f );

		//! Quat length
		/*!
			 @return the module of the quaternion
		*/
		float Length() const;
	
		//! IsIdentity
		/*!
			 @return If the quaternion is a identity one, this function returns @b true.
			 Otherwise, it returns @b false.
		*/
		bool IsIdentity() const;

		//! SetIdentity
		/*!
			 This function initialize the quaternion with identity value
			 @return the const reference of the quaternion.
		*/
		const Quat& SetIdentity();

		//! Normalize operation
		/*!
			 This funtction normalize the quaternion
			 @return the const reference of the quaternion.
		*/
		const Quat& Normalize();

		//! Normalize operation
		/*!
			 @return the normalized quaternion
		*/
		Quat GetNormalize() const;

	//! quatSlerp
	/*!
		 Calculate the slerp between the two quaternion, and return the result.
		 @param qs start quaternion
		 @param qf end quaternion
		 @param s Slerp scale
		 @return the slerp result quaternion between the two quaternion
	*/
	static Quat Slerp(const Quat& qs , const Quat& qf, float s);

	//! quatBuildRotationAxis
	/*!
		 Build a quaternion from rotation against a specified axis(a vector3).
		 @param	axis a vector3 specified the axis that the rotation against.
		 @param radian the angle to rotate in radian
		 @return the rotation quaternion
	*/
	static Quat RotationAxis(const Vec3& axis, float radian);
	 
		// data member

		float x;			/*!< x member of the quaternion */
		float y;			/*!< y member of the quaternion */
		float z;			/*!< z member of the quaternion */
		float w;			/*!< w member of the quaternion */
	};

	//! quaternion operator+
	/*!
		 Add two quaternion and return the result.
		 @param q1 a quaternion
		 @param q2 a quaternion
		 @return the result of the addition
	*/
	 Quat operator+(const Quat& q1, const Quat& q2);
	//! quaternion operator-
	/*!
		 Subtract two quaternion and return the result.
		 @param q1 a quaternion
		 @param q2 a quaternion
		 @return the result of the subtraction
	*/
	 Quat operator-(const Quat& q1, const Quat& q2);

	//! quaternion operator*
	/*!
		 Multiply a quaternion with a float
		 @param q a quaternion to multiply
		 @param s a float to multiply
		 @return the result of the multiplication
	*/
	 Quat operator*(const Quat& q, float s);

	//! quaternion operator*
	/*!
		 Multiply a float with a quaternion.
		 @param s a float to multiply
		 @param q a quaternion to multiply
		 @return the result of the multiplication
	*/
	 Quat operator*(float s, const Quat& q);


	//! quaternion operator*
	/*!
		 Multiply two quaternion and return the result.
		 @param q1 the quaternion to multiply
		 @param q2 the quaternion to multiply
		 @return the result of the multiplication
	*/
	 Quat operator * ( const Quat& q1 , const Quat& q2);





};

#endif	//	#ifndef __QUAT_H__
