#pragma once

struct lua_State;

namespace RBX
{
	class Instance;
	class DataModel;
}

namespace Lua
{
	RBX::Instance* checkInstance(lua_State* L, int idx);

	RBX::DataModel* getDataModel(lua_State* L);

	void checkPermissions(lua_State* L, int role, const char* action);
}
