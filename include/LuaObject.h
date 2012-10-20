//
//  LuaObject.h
//  D10
//
//  Created by Ruly on 2012-10-1.
//
//

#ifndef __LUAOBJECT_H__
#define __LUAOBJECT_H__

#include "LuaDef.h"

class LuaObject
{
protected:
	LuaObject(lua_State* in_ls);
public:
	~LuaObject(void);
	void Get(void);
	template<typename T_FUNC>
	void ForEachNext(T_FUNC FUNC);
	static LuaObject* Create(lua_State* in_ls);
	static LuaObject* CreateFunction(lua_State* in_ls);
	static LuaObject* CreateNewTable(lua_State* in_ls);
private:
	lua_State* m_ls;
	int m_object_ref;
};

template<typename T_FUNC>
void LuaObject::ForEachNext(T_FUNC FUNC)
{
	DF( m_ls );
	Get();
	for
	(
		lua_pushnil( m_ls );
		lua_next( m_ls, -2 );
		lua_pop( m_ls, 1 ) )
	{
		FUNC( m_ls );
	}
	lua_pop( m_ls, 1 );
}

#endif
