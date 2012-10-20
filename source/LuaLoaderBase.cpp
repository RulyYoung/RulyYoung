//
//  LuaLoaderBase.cpp
//  D10
//
//  Created by Ruly on 2012-10-4.
//
//

#include "Base.h"
#include "LuaLoaderBase.h"
#include "LuaFileChunk.h"
#include "LuaObject.h"

LuaLoaderBase::LuaLoaderBase(void)
	:	m_file_chunk( NULL )
{
	m_ls = lua_open();
	LoadDefaultLibrary();
}
LuaLoaderBase::~LuaLoaderBase(void)
{
	SAFE_DELETE( m_file_chunk );
	lua_close( m_ls );
}
bool LuaLoaderBase::LoadFile(const std::string& filename)
{
	SAFE_DELETE( m_file_chunk );
	m_file_chunk = NEW LuaFileChunk( m_ls, filename );
	
	if( !m_file_chunk->LoadFile() )
	{
		SAFE_DELETE( m_file_chunk );
		return false;
	}
	printf("\n[Load]\"%s.\"", filename.c_str());

	DF( m_ls );
	OnLoadFile();
	return true;
}
void LuaLoaderBase::OnLoadFile(void)
{
	printf( "\nLoad file success!" );
	m_file_chunk->GetEnvTable()->ForEachNext(
		[](lua_State* ls){
			printf( "\n\"%s\" = \"%s\";",
				lua_tostring( ls, -2 ), lua_tostring( ls, -1 ) );
		}
	);
}
void LuaLoaderBase::LoadDefaultLibrary(void)
{
	DF( m_ls );
	lua_pop( m_ls, luaopen_base( m_ls ) );
}
