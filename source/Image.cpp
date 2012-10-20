/*
 *  Image.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Image.h"
#include <stdlib.h>
#include <stdio.h>

typedef std::map<std::string, ITexture*> tex_map_t;
static tex_map_t& GetMap(void)
{
	static tex_map_t g;
	return g;
}
ImageObject2D::ImageObject2D(void)
	:	m_ptr( 0 )
{}
ImageObject2D::~ImageObject2D(void)
{
	if( m_ptr )
	{
		std::string filename;
		m_ptr->GetFilename( filename );
		if( 0 == m_ptr->Release() )
		{
			tex_map_t::iterator iFind = GetMap().find( filename );
			if( iFind != GetMap().end() )
			{
				GetMap().erase( iFind );
			}
		}
	}
}
ImageObject2D::ImageObject2D(const char* filename_ptr)
	:	m_ptr( 0 )
{
	struct local
	{
		static char* strlwr(char* s)
		{
			enum
			{
				ADDVALUE = 'a' - 'A',
			};
			for(char* p = s; *p; ++p)
			{
				if( 'A' <= *p && 'Z' >= *p )
				{
					*p += ADDVALUE;
				}
			}
			return s;
		}
	};
	//	统一小写
	char buffer[ 0x400 ];
	strcpy( buffer, filename_ptr );
	local::strlwr( buffer );
	
	std::string filename( buffer );
	tex_map_t::iterator iFind = GetMap().find( filename );
	if( iFind != GetMap().end() )
	{
		m_ptr = iFind->second;
		m_ptr->AddRef();
	}
	else
	{
		m_ptr = CreateTextureFormFile( filename.c_str() );
		if( m_ptr )
		{
			GetMap().insert( std::make_pair( filename, m_ptr ) );
		}
	}
}

ImageObject2D::ImageObject2D(const ImageObject2D& other)
:	m_ptr( 0 )
{
	*this = other;
}

ImageObject2D& ImageObject2D::operator=(const ImageObject2D& other)
{
	SAFE_RELEASE( m_ptr );
	m_ptr = other.m_ptr;
	if( m_ptr )
	{
		m_ptr->AddRef();
	}
	return *this;
}
bool ImageObject2D::Valid(void)	const
{
	return 0 != m_ptr;
}
TEXTUREHANDLE ImageObject2D::GetHandle(void)	const
{
	if( this->Valid() )
	{
		return m_ptr->GetHandle();
	}
	return 0;
}
void ImageObject2D::GetInfo(TextureInfo* dest)	const
{
	if( this->Valid() )
	{
		m_ptr->GetInfo( dest );
	}
}

