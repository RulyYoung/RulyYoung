//
//  LuaObject.cpp
//  D10
//
//  Created by Ruly on 2012-10-1.
//
//
#include "LuaObject.h"
#include "Base.h"

LuaObject::LuaObject(lua_State* in_ls)
{
	m_ls = in_ls;
	m_object_ref = lua_ref( in_ls, true );
}
LuaObject* LuaObject::Create(lua_State* in_ls)
{
	return NEW LuaObject( in_ls );
}
LuaObject* LuaObject::CreateFunction(lua_State* in_ls)
{
	ASSERT( lua_isfunction( in_ls, -1 ) );
	return NEW LuaObject( in_ls );
}
LuaObject* LuaObject::CreateNewTable(lua_State* in_ls)
{
	lua_newtable( in_ls );
	return Create( in_ls );
}
LuaObject::~LuaObject(void)
{
	lua_unref( m_ls, m_object_ref );
}
void LuaObject::Get(void)
{
	lua_rawgeti( m_ls, LUA_REGISTRYINDEX, m_object_ref );
}

