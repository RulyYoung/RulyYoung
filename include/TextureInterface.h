/*
 *  TextureInterface.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-7.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __TEXTUREINTERFACE_H__
#define __TEXTUREINTERFACE_H__
#include "DataUtil.h"
#include "IUnknown.h"
#include "Base.h"
/*
@property(readonly) Texture2DPixelFormat pixelFormat;
@property(readonly) NSUInteger pixelsWide;
@property(readonly) NSUInteger pixelsHigh;

@property(readonly) GLuint name;

@property(readonly, nonatomic) CGSize contentSize;
@property(readonly) GLfloat maxS;
@property(readonly) GLfloat maxT;
*/

typedef enum {
	TFMT_AUTOMATIC = 0,
	TFMT_RGBA8888,
	TFMT_RGBA4444,
	TFMT_RGBA5551,
	TFMT_RGB565,
	TFMT_RGB888,
	TFMT_L8,
	TFMT_A8,
	TFMT_LA88,
	TFMT_RGB_PVRTC2,
	TFMT_RGB_PVRTC4,
	TFMT_RGBA_PVRTC2,
	TFMT_RGBA_PVRTC4
}TEXTUREFORMAT;// Texture2DPixelFormat;

struct TextureInfo
{
public:
	TEXTUREFORMAT nFormat;
	SIZE szPixelSize;
	SIZE szContentSize;
	float fMaxS;
	float fMaxT;
};

typedef UINT32 TEXTUREHANDLE;

class ITexture
:	public IUnknown
{
protected:

	ITexture(void)	{}
	virtual ~ITexture(void)	{}

public:
	virtual TEXTUREHANDLE GetHandle(void) = 0;
	virtual void GetInfo(TextureInfo*) = 0;
	virtual void GetFilename(std::string& out)	const = 0;
};

ITexture* CreateTextureFormFile(const char* lpcFilename);

#endif // __TEXTUREINTERFACE_H__



















