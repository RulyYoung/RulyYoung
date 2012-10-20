//
//  LuaLoader.h
//  test
//
//  Created by Ruly on 2012-7-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef test_LuaLoader_h
#define test_LuaLoader_h

#include <map>
#include "LuaDef.h"
#include "LuaObject.h"
#include "LuaLoaderBase.h"

template<typename T_RES>
class LuaLoader
	:	public LuaLoaderBase
{
public:
	LuaLoader(void);
	~LuaLoader(void);
	typedef LuaLoader<T_RES> SELF_TYPE;
	const T_RES* Find(const std::string& name)	const;
	void Add(const std::string& name, const T_RES& res);
	template<typename T_FUNC>
	void ForEach(T_FUNC func)
	{
		for( auto i = m_table.begin(); i != m_table.end(); ++i )
		{
			func( i->second );
		}
	}
private:
	void Clear(void);
	T_RES* Find(const std::string& name);
	void Remove(const std::string& name);
	std::map<std::string,T_RES*> m_table;
};
////////////////////////////////////////////////////////////////////////////////
template<typename T_RES>
LuaLoader<T_RES>::LuaLoader(void)
{}
template<typename T_RES>
LuaLoader<T_RES>::~LuaLoader(void)
{
	Clear();
}
template<typename T_RES>
const T_RES* LuaLoader<T_RES>::Find(const std::string& name)	const
{
	return const_cast<SELF_TYPE>( this )->Find( name );
}
template<typename T_RES>
void LuaLoader<T_RES>::Add(const std::string& name, const T_RES& res)
{
	m_table.erase( name );
	m_table.insert( std::make_pair( name, NEW T_RES( res ) ) );
}
template<typename T_RES>
void LuaLoader<T_RES>::Clear(void)
{
	ForEach(
		[](T_RES* ptr)
		{
			DELETE( ptr );
		}
	);
	m_table.clear();
}
template<typename T_RES>
T_RES* LuaLoader<T_RES>::Find(const std::string& name)
{
	auto i_find = m_table.find( name );
	if( i_find != m_table.end() )
	{
		return &i_find->second;
	}
	return NULL;
}
template<typename T_RES>
void LuaLoader<T_RES>::Remove(const std::string& name)
{
	T_RES* res = Find( name );
	SAFE_DELETE( res );
	m_table.erase( name );
}
#endif
