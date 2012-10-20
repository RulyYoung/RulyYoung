//
//  LuaLoaderBase.h
//  D10
//
//  Created by Ruly on 2012-10-4.
//
//

#ifndef D10_LuaLoaderBase_h
#define D10_LuaLoaderBase_h

#include <string>
#include "LuaDef.h"

class LuaFileChunk;
class LuaLoaderBase
{
public:
	LuaLoaderBase(void);
	~LuaLoaderBase(void);
	bool LoadFile(const std::string& filename);
	void OnLoadFile(void);
private:
	void LoadDefaultLibrary(void);
private:
	lua_State* m_ls;
	LuaFileChunk* m_file_chunk;
};

#endif
