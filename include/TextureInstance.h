/*
 *  TextureInstance.h
 *  OGL002
 *
 *  Created by Ruly on 09-11-7.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef __TEXTUREINSTANCE_H__
#define __TEXTUREINSTANCE_H__
#include "TextureInterface.h"

class TextureInstance
:	public ITexture
{
	TextureInstance(void);
	virtual ~TextureInstance(void);
public:

	TextureInstance(TEXTUREHANDLE, const TextureInfo&, const char*);
	TEXTUREHANDLE GetHandle(void);
	void GetInfo(TextureInfo*);
	void GetFilename(std::string& out)	const;
	
private:
	
	TextureInfo m_tiInfo;
	TEXTUREHANDLE m_nHandle;

	std::string m_filename;
};


#endif	//	__TEXTUREINSTANCE_H__