/*
 *  TextureInterface.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-7.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "TextureInterface.h"
#include "TextureInstance.h"
#include "Texture2D.h"

TextureInstance::TextureInstance(TEXTUREHANDLE handle, const TextureInfo& info, const char* lpcFilename)
	:	m_nHandle( handle )
	,	m_tiInfo( info )
	,	m_filename( lpcFilename )
{}

TextureInstance::~TextureInstance(void)
{
	//	这里没有释放纹理句柄
	//const GLuint h = m_nHandle;
	//::glDeleteTextures( 1, &h );
}

void TextureInstance::GetFilename(std::string& out)	const
{
	out = m_filename;
}

TEXTUREHANDLE TextureInstance::GetHandle(void)
{
	return m_nHandle;
}

void TextureInstance::GetInfo(TextureInfo* dest)
{
	if( dest )
	{
		*dest = m_tiInfo;
	}
}


ITexture* CreateTextureFormFile(const char* lpcFilename)
{
	NSString* name = [ [NSString alloc] initWithUTF8String: lpcFilename ];
	Texture2D* tex = [[Texture2D alloc] initWithImagePath:name sizeToFit:NO pixelFormat:kTexture2DPixelFormat_Automatic];

	TEXTUREHANDLE handle = [tex name];
	if( 0 == handle )
	{
		return 0;
	}

	TextureInfo info;
	info.nFormat = (TEXTUREFORMAT)tex.pixelFormat;
	info.szContentSize.x = tex.contentSize.width;
	info.szContentSize.y = tex.contentSize.height;
	info.szPixelSize.x = tex.pixelsWide;
	info.szPixelSize.y = tex.pixelsHigh;
	info.fMaxS = (float)info.szContentSize.x / (float)info.szPixelSize.x;
	info.fMaxT = (float)info.szContentSize.y / (float)info.szPixelSize.y;

	[tex release];
	
	return new TextureInstance( handle, info, lpcFilename );	
}


















