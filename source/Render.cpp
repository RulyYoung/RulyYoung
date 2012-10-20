/*
 *  Render.cpp
 *  OGL002
 *
 *  Created by Ruly on 09-11-3.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Render.h"
#include "RenderInterface.h"

#include "Engine.h"

Render::Render(void)
:	m_pFaceStart( 0 )
,	m_pFaceEnd( 0 )
{}

Render::~Render(void)
{}

void Render::_PushFace(const Face& src)
{
	FaceRN* const pNew = this->_AllocRN();
	(Face&)*pNew = src;
}

bool Render::_PopFace(void)
{
	if( m_pFaceStart )
	{
		this->OnDrawFace( *m_pFaceStart );
		this->_PopRN();
		return true;
	}
	return false;
}

void Render::OnDrawFace(const Face& face)
{
	::DrawFace( face );
}

FaceRN* Render::_AllocRN(void)
{
	FaceRN* const pNew = new FaceRN();
	if( m_pFaceEnd )
	{
		m_pFaceEnd->pNext = pNew;
	}
	else
	{
		m_pFaceStart = pNew;
	}
	m_pFaceEnd = pNew;
	return pNew;
}

void Render::_PopRN(void)
{
	if( m_pFaceStart )
	{
		if( 0 == m_pFaceStart->pNext )
		{
			m_pFaceEnd = 0;
		}
		FaceRN* const pDelete = m_pFaceStart;
		m_pFaceStart = m_pFaceStart->pNext;
		delete pDelete;
	}
}












