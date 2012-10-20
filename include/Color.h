//
//  Color.h
//  D10
//
//  Created by Ruly on 2012-9-20.
//
//

#ifndef D10_Color_h
#define D10_Color_h

struct Color
{
public:
	Color(void)
		:	a( 1 )
		,	r( 1 )
		,	g( 1 )
		,	b( 1 )
	{}
	Color(unsigned int nColor)
		:	a( ( 0xff & ( nColor >> 24 ) ) / 255.0f )
		,	r( ( 0xff & ( nColor >> 16 ) ) / 255.0f )
		,	g( ( 0xff & ( nColor >> 8 ) ) / 255.0f )
		,	b( ( 0xff & ( nColor >> 0 ) ) / 255.0f )
	{}
	float GetAlpha(void)	const
	{
		return a;
	}
	float GetRed(void)	const
	{
		return r;
	}
	float GetGreen(void)	const
	{
		return g;
	}
	float GetBlue(void)	const
	{
		return b;
	}
	unsigned int ToValue(void)	const
	{
		return	GetNormalizeValue( 0x100 * a ) << 24
			|	GetNormalizeValue( 0x100 * r ) << 16
			|	GetNormalizeValue( 0x100 * g ) << 8
			|	GetNormalizeValue( 0x100 * b )
			;
	}
private:
	static unsigned int GetNormalizeValue(int value)
	{
		if( 0xff < value )
		{
			return 0xff;
		}
		else if( 0 > value )
		{
			return 0;
		}
		else
		{
			return value;
		}
	}
	float a, r, g, b;
};


#endif
