//
//  Material.h
//  D10
//
//  Created by Ruly on 2012-9-17.
//
//

#ifndef D10_Material_h
#define D10_Material_h
#include "LuaLoader.h"

class Material
{
public:
	bool LoadPair(lua_State*);
private:
	
};

class MaterialMngr
	:	public LuaLoader<Material>
{
public:
private:
};


#endif
