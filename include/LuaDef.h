//
//  LuaDef.h
//  D10
//
//  Created by Ruly on 2012-9-19.
//
//

#ifndef D10_LuaDef_h
#define D10_LuaDef_h

extern "C"
{
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}
class LuaDef
{
public:
	explicit LuaDef(lua_State* in_ls);
	~LuaDef(void);
private:
	lua_State* const m_ls;
	const int m_begin_stack_top;
};

#define DF(L) LuaDef _DF(L)

#define VALID_REF(REF)\
	( 0 <= REF )
#define SAFE_UNREF(L,REF)\
	if( -1 != (REF) )\
	{\
		lua_unref( L, (REF) );\
		REF = -1;\
	}
	
#endif
