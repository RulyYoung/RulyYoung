/*
 *  RenderInterface.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-4.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "RenderInterface.h"
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

#define _A(V) ( 0xff & ( V >> 24 ) )
#define _R(V) ( 0xff & ( V >> 16 ) )
#define _G(V) ( 0xff & ( V >> 8 ) )
#define _B(V) ( 0xff & ( V >> 0 ) )

class Test
{
public:
	Test(void)
	{}
private:
	int aaa;
};

#define TRANS_COLOR(C) ( 0xff00ff00 & C ) |\
 ( ( 0xff & ( C >> 16 ) ) |\
  ( 0x00ff0000 & ( C << 16 ) ) )

void DrawFace(const Face& face)
{
	float sh,sw;
	sw = face.w / 2;
	sh = face.h / 2;

    const GLfloat squareVertices[] = {
	/*
		0,0,
		face.w, 0,
		0, face.h,
		face.w, face.h,
		*/
		-sw, -sh,
		sw, -sh,
        -sw, sh,
		sw, sh,
    };
	
	UINT32 cc = TRANS_COLOR( face.c );
	const UINT32 cb[ 4 ] =
	{
		cc,cc,cc,cc,
	};

	if( face.img.Valid() )
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, face.img.GetHandle() );
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); 
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		TextureInfo info;
		face.img.GetInfo( &info );
		const RectF uv( face.uv.l * info.fMaxS, face.uv.t * info.fMaxT, face.uv.r * info.fMaxS, face.uv.b * info.fMaxT );
		GLfloat	coordinates[] = 
		{
			uv.l,			uv.t,
			uv.r,			uv.t,
			uv.l,			uv.b,
			uv.r,			uv.b,
		};
		glTexCoordPointer( 2, GL_FLOAT, 0, coordinates );
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}

    glVertexPointer(2, GL_FLOAT, 0, squareVertices);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, cb );//ca );
    glEnableClientState(GL_COLOR_ARRAY);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
}




void BeginFace(const Face& face)
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glTranslatef( face.x, face.y, 0 );
	glRotatef( face.angle, 0, 0, 1.0f );
}

void EndFace(void)
{
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



















