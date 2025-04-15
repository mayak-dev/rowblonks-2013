#include "pch.h"
#include "LuaHelpers.h"
#include "LuaDefs.h"
#include "VC90Defs.h"
#include "RBXDefs.h"

RBX::Instance* Lua::checkInstance(lua_State* L, int idx)
{
    // userdata is a boost::shared_ptr of the instance
    return *reinterpret_cast<RBX::Instance**>(luaL_checkudata(L, idx, "Object"));
}

RBX::DataModel* Lua::getDataModel(lua_State* L)
{
    auto scriptContext = RobloxExtraSpace::get(L)->shared->scriptContext;
    auto scParent = reinterpret_cast<RBX::Instance*>(scriptContext)->parent;
    return reinterpret_cast<RBX::DataModel*>(scParent);
}

void Lua::checkPermissions(lua_State* L, int role, const char* action)
{
    // based on sub_776B40 in studio

    if (role == 0)
        return;

    int identity = RobloxExtraSpace::get(L)->identity;

    switch (identity)
    {
    case 0:
    case 2:
        break;
    case 1:
    case 5:
    case 6:
        if (role == 1 || role == 2)
            return;
        break;
    case 3:
        if (role == 1)
            return;
        break;
    case 4:
        if (role == 1 || role == 2 || role == 4)
            return;
        break;
    case 7:
    case 8:
        return;
    case 9:
        if (role == 1 || role == 3 || role == 4)
            return;
        break;
    }

    luaL_error(L, "Insufficient permissions to %s. Identity %d is not within permission role %d.", action, identity, role);
}
