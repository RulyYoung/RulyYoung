//
//  LuaDef.cpp
//  D10
//
//  Created by Ruly on 2012-9-20.
//
//

#include "LuaDef.h"
#include "Base.h"

LuaDef::LuaDef(lua_State* in_ls)
	:	m_ls( in_ls )
	,	m_begin_stack_top( lua_gettop( in_ls ) )
{
}
LuaDef::~LuaDef(void)
{
	const int top_stack_now = lua_gettop( m_ls );
	ASSERT( top_stack_now == m_begin_stack_top );
	if( top_stack_now != m_begin_stack_top )
	{
		lua_settop( m_ls, m_begin_stack_top );
	}
}