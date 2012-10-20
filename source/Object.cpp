//
//  Object.cpp
//  D10
//
//  Created by Ruly on 2012-10-13.
//
//

#include "Object.h"
#include "Base.h"

Object::Object(void)
	:	m_ref_counter( 1 )
{}
Object::~Object(void)
{}
unsigned int Object::AddRef(void)
{
	return ++m_ref_counter;
}
unsigned int Object::Release(void)
{
	--m_ref_counter;
	unsigned int last_ref_counter = m_ref_counter;
	if( 0 >= m_ref_counter )
	{
		DELETE( this );
	}
	return last_ref_counter;
}