//
//  IUnknown.cpp
//  test
//
//  Created by Ruly on 2012-7-18.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "IUnknown.h"

IUnknown::IUnknown(void)
	:	m_my_ref_count( 1 )
{}
IUnknown::~IUnknown(void)
{}
unsigned long IUnknown::Release(void)
{
	--m_my_ref_count;
	if( 0 >= m_my_ref_count )
	{
		delete this;
	}
	return m_my_ref_count;
}
unsigned long IUnknown::AddRef(void)
{
	++m_my_ref_count;
	return m_my_ref_count;
}






