/*
 *  Mat3.h
 *  cmdline_cpp
 *
 *  Created by Ruly on 2010-4-11.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
 
 #ifndef __MAT3_H__
 #define __MAT3_H__
 
 #include "quat.h"

namespace orb
{

	//! Orb 3x3 rotation Matrix
	/*!
		 This struct implemented a 3x3 matrix, with some member fucntions to
		 simplize matrix operation.
		 @warning This struct does not have a virtual destructor, so don't derive from this struct
		 unless you know exactly what you are doing.
		 @date 05/12/2003
		 @version 1.0
		 @author Dan Tong
		 @author mail: Lythm@citiz.net
	*/
	struct Mat3
	{
		//! Default Constructor
		/*!
			 This function set all the member value to default value 0.0f.
			 @return no return.
		*/
		Mat3();

		//! Constructor
		/*!
			 This function construct the matrix with a float[9] array.
			 @return no return.
		*/
		explicit Mat3(float _m[9]);
		
		//! Constructor
		/*!
			 This function construct the matrix with 9 float parameters
			 @return no return.
		*/
		Mat3(	float _m11, float _m12, float _m13,
			float _m21, float _m22, float _m23, 
			float _m31, float _m32, float _m33);

		//! Constructor
		/*!
			 This function construct the matrix with quaternion.
			 @param quat the unit quaternion to construct the matrix
			 @return no return.
			 @warning the quaternion must be a unit one
		*/
		explicit Mat3(const Quat& quat);

		//! float* extractor
		/*!
			 This function turn the matrix to a quaternion.
			 @return the quaternion value of this matrix.
		*/
		operator float*() const;
		//! Operator()
		/*!
			 This function return the reference to the sub value of the matrix, 
			 which locate at [row, col].
			 @param row the row
			 @param col the column
			 @return The reference to the sub value of the matrix.
		*/
		float& operator()(int row, int col);

		//! Operator()
		/*!
			 This is a const version of the operator().
			 @see float& operator()(int row, int col)
		*/
		const float& operator()(int row, int col) const;
	
		//! Operator+=
		/*!
			 This function add another matrix to itself.
			 @param other another matrix
			 @return the the const reference of *this
		*/
		const Mat3& operator+=(const Mat3& other);

		//! Operator[]
		/*!
			 This function return the reference to the sub value of the matrix, 
			 which locate at [nIndex].
			 @param nIndex the nIndex
			 @return The reference to the sub value of the matrix.
		*/
		float& operator[](int nIndex);

		//! Operator[]
		/*!
			 This is a const version of the operator().
			 @see float& operator[](int nIndex);
		*/
		const float& operator[](int nIndex) const;

		//! Operator-=
		/*!
			 This function subtract another matrix from itself.
			 @param other another matrix
			 @return the the const reference of *this
		*/
		const Mat3& operator-=(const Mat3& other);

		//! Operator*=
		/*!
			 This function multiply another matrix to itself.
			 @param other another matrix
			 @return the the const reference of *this
		*/
		const Mat3& operator*=(const Mat3& other);

		//! Operator==
		/*! @return if the vector is equal to parameter @b other, the function 
			 returns @b true, otherwise, it returns @b false.
		*/
		bool operator==(const Mat3& other) const;

		//! Operator!=
		/*! @return if the vector is not equal to parameter @b other, the function 
			 returns @b true, otherwise, it returns @b false.
		*/
		bool operator!=(const Mat3& other) const;

		//! SetIdentity
		/*!
			 This function initialize the matrix with identity value.
			 @return the const reference of the matrix.
		*/
		const Mat3& SetIdentity();

		//! IsIdentity
		/*!
			 @return If the matrix is a identity one, this function returns @b true.
			 Otherwise, it returns @b false.
		*/
		bool isIdentity() const;

		//! Transpose
		/*!
			 Transpose the matrix.
			 @return the const reference of the matrix.
		*/
		const Mat3& Transpose();

		//! GetTranspose
		/*!
			 Get the Transpose of the matrix.
			 @return the tranpose of the matrix.
		*/
		Mat3 GetTranspose() const;

		//! Invert
		/*!
			 Inverse the matrix.
			 @return the const reference of the matrix
		*/
		const Mat3& Invert();

		//! GetInverse
		/*!
			 Get the inverse of the matrix.
			 @return the inverse of the matrix
		*/
		Mat3 GetInverse() const;

		//! Determinant
		/*!
			 @return the Determinant of this matrix
		*/
		float Determinant() const;
		
		//! GetRow
		/*!
			 Get a row of the matrix
			 @return the specified row vector.
		*/
		Vec3 GetRow(int row) const;

		//! GetLine
		/*!
			 Get a Line of the matrix
			 @return the specified line vector.
		*/
		Vec3 GetLine(int line) const;

		//! SetLine
		/*!
			 Set a Line of the matrix
			 @return no return.
		*/
		void SetLine(int line, const Vec3& v);

		//! SetRow
		/*!
			 Set a row of the matrix
			 @return no return.
		*/
		void SetRow(int row, const Vec3& v);

	//! matBuildRotationAxis
	/*!
		 Build a 3x3 matrix from rotation against a specified axis(a vector3).
		 @param	axis a vector3 specified the axis that the rotation against. 
			The axis vector must be normalized before passed in.
		 @param radian the angle to rotate in radian
		 @return the rotation matrix
	*/
	static Mat3 RotationAxis(const Vec3& axis, float radian);
	

	//! matBuildRotationX
	/*!
		 Build a 3x3 matrix from rotation against X axis.
		 @param radian the angle to rotate in radian
		 @return the rotation matrix
	*/
	static Mat3 RotationX(float radian);

	//! matBuildRotationY
	/*!
		 Build a 3x3 matrix from rotation against Y axis.
		 @param radian the angle to rotate in radian
		 @return the rotation matrix
	*/
	static Mat3 RotationY(float radian);

	//! matBuildRotationZ
	/*!
		 Build a 3x3 matrix from rotation against Z axis.
		 @param radian the angle to rotate in radian
		 @return the rotation matrix
	*/
	static Mat3 RotationZ(float radian);

	public:
		union
		{
			float	m[9];							/*!< matrix member int float[16] format */
			
			struct	
			{
				float	m11,						/*!< matrix member [1,1]*/
						m12,						/*!< matrix member [1,2]*/
						m13,						/*!< matrix member [1,3]*/
						m21, 						/*!< matrix member [2,1]*/
						m22, 						/*!< matrix member [2,2]*/
						m23, 						/*!< matrix member [2,3]*/
						m31, 						/*!< matrix member [3,1]*/
						m32, 						/*!< matrix member [3,2]*/
						m33; 						/*!< matrix member [3,3]*/
			};										
		};
	};

	//! matrix operator*
	/*!
		 Multiply a matrix with a float.
		 @param mat a matrix to multiply
		 @param s a float to multiply
		 @return the result of the multiplication
	*/
	 Mat3 operator*(const Mat3& mat, float s);

	//! matrix operator*
	/*!
		 Multiply a float with a matrix.
		 @param s a float to multiply
		 @param mat a matrix to multiply
		 @return the result of the multiplication
	*/
	 Mat3 operator*(float s, const Mat3& mat);


	//! matrix operator+
	/*!
		 Add two matrix and return the result.
		 @param m1 the matrix to add
		 @param m2 the matrix to add
		 @return the result matrix of the addition
	*/
	 Mat3 operator+(const Mat3& m1, const Mat3& m2);

	//! matrix operator-
	/*!
		 Subtract two matrix and return the result.
		 @param m1 the matrix to subtract from
		 @param m2 the matrix to subtract
		 @return the result matrix of the subtraction
	*/
	 Mat3 operator-(const Mat3& m1, const Mat3& m2);
	

	//! matrix operator*
	/*!
		 Multiply two matrix and return the result.
		 @param m1 the matrix to multiply
		 @param m2 the matrix to multiply
		 @return the result matrix of the multiplication
	*/
	 Mat3 operator*(const Mat3& m1, const Mat3& m2);

}

#endif	//	#ifndef __MAT3_H__