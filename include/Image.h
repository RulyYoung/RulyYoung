/*
 *  Image.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __IMAGE_H__
#define __IMAGE_H__
#include "DataUtil.h"
#include "TextureInterface.h"
//typedef ITexture* Image;

class ImageObject2D
{
public:
	ImageObject2D(void);	
	~ImageObject2D(void);
	ImageObject2D(const char* pFilename);
	ImageObject2D(const ImageObject2D& other);
	ImageObject2D& operator=(const ImageObject2D& other);
	bool Valid(void)	const;
	TEXTUREHANDLE GetHandle(void)	const;
	void GetInfo(TextureInfo* dest)	const;
private:
	ITexture* m_ptr;
};

typedef ImageObject2D Image2D;

#endif	//	__IMAGE_H__