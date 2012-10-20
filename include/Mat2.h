/*
 *  Mat2.h
 *  cmdline_cpp
 *
 *  Created by Ruly on 2010-4-12.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __MAT2_H__
#define __MAT2_H__

namespace orb
{
	struct Mat2
	{
	public:
		float& operator[](int idx)
		{
			return m[ idx ];
		}
		struct
		{
			float m[ 4 ];
		};
		inline void Rot(float rad)
		{
			*this = RotationAxis( rad );
		}
		static Mat2 RotationAxis(float radian)
		{
			Mat2 ret;
			float c = (float)cos(radian);
			float s = (float)sin(radian);
									
			ret[0] = c;
			ret[1] = s;
					
			ret[2] = -s;
			ret[3] = c;
			return ret;
		}
	};

	Mat2 operator*(const Mat2& m1, const Mat2& m2)
	{
		Mat2 r;
		r[ 0 ] = m1[ 0 ] * m2[ 0 ] + m1[ 1 ] * m2[ 2 ];
		r[ 1 ] = m1[ 0 ] * m2[ 1 ] + m1[ 1 ] * m2[ 3 ];
		r[ 2 ] = m1[ 2 ] * m2[ 0 ] + m1[ 1 ] * m2[ 2 ];
		r[ 3 ] = m1[ 2 ] * m2[ 1 ] + m1[ 1 ] * m2[ 3 ];
		return res;
	}

};

#endif	//	#ifndef __MAT2_H__ 