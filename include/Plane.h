/*
 *  Plane.h
 *  cmdline_cpp
 *
 *  Created by Ruly on 2010-4-11.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
 
 #ifndef __PLANE_H__
 #define __PLANE_H__

namespace orb
{

	//! Orb Plane
	/*!
		 This struct implemented a Plane.
		 
		 @warning This struct does not have a virtual destructor, so don't derive from this struct
		 unless you know exactly what you are doing.
		 @date 05/28/2003
		 @version 1.0
		 @author Dan Tong
		 @author mail: Lythm@citiz.net
	*/
	
	
	struct Plane
	{
		//! Default Constructor
		/*!
			 This function set all the member value to default value 0.0f.
			 @return no return.
		*/
		Plane();

		//! Copy Constructor
		Plane(const Plane& other);

		//! Constructor
		/*!
			 Construct the plane with four coefficient.
			 AX + BY + CZ + D = 0
			 @return no return.
		*/
		Plane(float A, float B, float C, float D);

		//! Constructor
		/*!
			 Construct the plane from three points
			 @return no return.
		*/
		Plane(const Vec3& p1, const Vec3& p2, const Vec3& p3);

		//! Constructor
		/*!
			 Construct the plane from a normal and a point
			 @return no return.
		*/
		Plane(const Vec3& n, const Vec3& p);

		//! Normalize
		/*!
			 Normalize the plane.
			 @return const refernce of *this
		*/
		const Plane& Normalize();

		//! GetNormalized
		/*!
			 @return the normalized plane of this plane
		*/
		Plane GetNormalized() const;

		//! PointDistance
		/*!
			 Calculate the distance between the given point and this plane
			 @return distance
		*/
		float PointDistance(const Vec3& point) const;

		//! Operator ==
		/*! @return if the plane is equal to parameter @b other, the function 
			 returns @b true, otherwise, it returns @b false.
		*/
		bool operator==(const Plane& other) const;

		//! Operator !=
		/*! @return if the plane is not equal to parameter @b other, the function 
			 returns @b true, otherwise, it returns @b false.
		*/
		bool operator!=(const Plane& other) const;

		//! Operator float*
		operator float* ();

		//! planeDotNormal
		/*!
			 Calculate a vector3 and a plane's dot production, which assume the w of 
			 the vector is 0
			 @return the dot production
		*/
		static float DotNormal(const Plane& plane, const Vec3& v);
		
		//! planeLineIntersection
		/*!
			 Calculate the intersection of a plane and a line
			 @return the intersection
		*/
		static Vec3 LineIntersection(const Plane& plane, const Vec3& start, const Vec3& end);

		union
		{
			struct 
			{
				float a, b, c, d;				/*!< plane formular coefficient---- AX + BY +CZ +D = 0*/
			};
			struct 
			{
			//	Vec3	normal;					/*!< plane face normal*/
			//	float	d;						/*!< value of any a point in the plane dot normal*/
			};
			float v[4];
		};
		Vec3& get_normal(void)
		{
			return *(Vec3*)v;
		}
	};
	
	//! planeDotVec
	/*!
		 Calculate a vector4 and a plane's dot production
		 @return the dot production
	*/
	float Dot(const Plane& plane, const Vec4& v);

	//! planeDotVec
	/*!
		 Calculate a vector3 and a plane's dot production, which assume the w of 
		 the vector is 1
		 @return the dot production
	*/
	float Dot(const Plane& plane, const Vec3& v);

	//! planeTransform
	/*!
		 Transform the plane by a matrix
		 @return the const reference of the parameter 1
	*/
	const Plane& Transform(Plane& plane, const Mat4& m);
	
	

}

#endif	//	#ifndef __PLANE_H__