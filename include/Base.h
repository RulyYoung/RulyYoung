//
//  Base.h
//  test
//
//  Created by Ruly on 2012-8-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef test_Base_h
#define test_Base_h

#include <assert.h>
#define ASSERT assert

#ifndef NULL
#define NULL 0
#endif
#define DELETE(P) {delete P;}
#define NEW new
#define SAFE_DELETE(P) if(P){DELETE(P);P=NULL;}
#define SAFE_RELEASE(P) if(P){P->Release();P=NULL;}


#define BIGFLOAT (99999999.0f)

#define PI 3.1415926f
#define ANGLE (PI / 180.0f)

#ifndef ARRAYLENGTH
#define ARRAYLENGTH(SRC) ( sizeof(SRC) / sizeof( SRC[ 0 ] ) )
#endif

typedef unsigned long UINT32;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef struct
	{
		int x,y;
	}SIZE;
typedef struct
	{
		int x,y;
	}POINT;
	
	
	

#endif
