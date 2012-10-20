//
//  LoadFileChunk.cpp
//  D10
//
//  Created by Ruly on 2012-10-4.
//
//

#include "LuaFileChunk.h"
#include "Base.h"
#include "LuaObject.h"

LuaFileChunk::LuaFileChunk(lua_State* in_ls, const std::string& in_filename)
	:	m_ls( in_ls )
	,	m_filename( in_filename )
	,	m_chunk( NULL )
{
	m_env_table = LuaObject::CreateNewTable( in_ls );
}
LuaFileChunk::~LuaFileChunk(void)
{
	SAFE_DELETE( m_env_table );
	SAFE_DELETE( m_chunk );
}
bool LuaFileChunk::LoadFile(void)
{
	DF( m_ls );
	if( 0 != luaL_loadfile( m_ls, m_filename.c_str() ) )
	{
		printf( "\n[ERROR]%s.", lua_tostring( m_ls, -1 ) );
		lua_pop( m_ls, 1 );
		return false;
	}
	m_chunk = LuaObject::CreateFunction( m_ls );
	BindEnvTableToChunk();

	ExecuteChunk();
	return true;
}
LuaObject* LuaFileChunk::GetEnvTable(void)	const
{
	return m_env_table;
}
void LuaFileChunk::ExecuteChunk(void)
{
	m_chunk->Get();
	if( 0 != lua_pcall( m_ls, 0, 0, 0 ) )
	{
		printf( "\n[ERROR]%s.", lua_tostring( m_ls, -1 ) );
		lua_pop( m_ls, 1 );
	}
}
void LuaFileChunk::BindEnvTableToChunk(void)
{
	m_chunk->Get();
	m_env_table->Get();
	lua_setfenv( m_ls, -2 );
	lua_pop( m_ls, 1 );
}
