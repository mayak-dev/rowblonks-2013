#pragma once

#include "Patches.h"
#include "LuaHelpers.h"

struct lua_State;

typedef int (*lua_CFunction)(lua_State* L);

typedef struct luaL_Reg {
	const char* name;
	lua_CFunction func;
} luaL_Reg;

const auto luaL_register = reinterpret_cast<void(__cdecl*)(lua_State* L, const char* libname, const luaL_Reg* l)>(ADDRESS_LUAL_REGISTER);

const auto luaL_checklstring = reinterpret_cast<const char*(__cdecl*)(lua_State* L, int narg, size_t* len)>(ADDRESS_LUAL_CHECKLSTRING);
const auto luaL_checkinteger = reinterpret_cast<int(__cdecl*)(lua_State* L, int narg)>(ADDRESS_LUAL_CHECKINTEGER);
const auto luaL_checkudata = reinterpret_cast<void*(__cdecl*)(lua_State* L, int ud, const char* tname)>(ADDRESS_LUAL_CHECKUDATA);

const auto lua_pushinteger = reinterpret_cast<void(__cdecl*)(lua_State* L, int n)>(ADDRESS_LUA_PUSHINTEGER);

const auto luaL_error = reinterpret_cast<int(__cdecl*)(lua_State* L, const char* fmt, ...)>(ADDRESS_LUAL_ERROR);

#define luaL_checkstring(L,n)   (luaL_checklstring(L, (n), NULL))

namespace RBX
{
	class ScriptContext;
}

// gets allocated and constructed right before the lua_State in memory
class RobloxExtraSpace
{
public:
	static constexpr size_t size = 44;

	char padding1[12];

	class Shared
	{
	private:
		char padding1[4];
	public:
		RBX::ScriptContext* scriptContext;
	};
	
	Shared* shared;

private:
	char padding2[8];

public:
	int identity : 5;

	static inline RobloxExtraSpace* get(lua_State* L)
	{
		return reinterpret_cast<RobloxExtraSpace*>(reinterpret_cast<uint32_t>(L) - size);
	}
};
