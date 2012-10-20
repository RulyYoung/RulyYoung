//
//  LoadFileChunk.h
//  D10
//
//  Created by Ruly on 2012-10-4.
//
//

#ifndef __D10__LoadFileChunk__
#define __D10__LoadFileChunk__

#include <string>
#include "LuaDef.h"

class LuaObject;
class LuaFileChunk
{
public:
	LuaFileChunk(lua_State* in_ls, const std::string& in_filename);
	~LuaFileChunk(void);
	bool LoadFile(void);
	LuaObject* GetEnvTable(void)	const;
private:
	void ExecuteChunk(void);
	void BindEnvTableToChunk(void);
private:
	LuaObject* m_env_table; 
	LuaObject* m_chunk;
	lua_State* m_ls;
	std::string m_filename;
};

#endif /* defined(__D10__LoadFileChunk__) */
