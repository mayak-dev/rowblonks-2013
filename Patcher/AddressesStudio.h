#pragma once

// STUDIO ADDRESSES

// MSVC 9.0

constexpr auto ADDRESS_OPERATOR_NEW = 0x00AB7618;
constexpr auto ADDRESS_RTDYNAMICCAST = 0x00AB76E4;
constexpr auto ADDRESS_STRING_ASSIGN_FROM_CSTR = 0x00AB72E8;
constexpr auto ADDRESS_STRING_CONSTRUCTOR = 0x00AB72A4;
constexpr auto ADDRESS_STRING_DESTRUCTOR = 0x00AB72A8;

// studio only

constexpr auto ADDRESS_SERVERPLACEID_1 = 0x0052E10D;
constexpr auto ADDRESS_SERVERPLACEID_2 = 0x0052E7FF;

constexpr auto ADDRESS_COMPUTEPROP_NULL_DEREF = 0x005A3A40;

constexpr auto ADDRESS_ROBLOXVIEW_RENDERREQUESTJOB_SLEEPTIME = 0x004CDD60;

// Roblox

constexpr auto ADDRESS_CONTENTID_CONVERTTOLEGACYCONTENT = 0x0068FC40;
constexpr auto ADDRESS_INVALID_REQUEST_CHECK = 0x00897E70;
constexpr auto ADDRESS_CERT_PIN_JUMP = 0x007EB5F1;

constexpr auto ADDRESS_VERIFYSCRIPTSIGNATURE = 0x006A0250;
constexpr auto ADDRESS_VERIFYREQUESTEDSCRIPTSIGNATURE = 0x006A0900;

constexpr auto ADDRESS_DATAMODEL_STARTCORESCRIPTS = 0x0066ACA0;
constexpr auto ADDRESS_GUIBUILDER_BUILDGUI = 0x00882B90;

constexpr auto ADDRESS_SCRIPTCONTEXT_EXECUTEINNEWTHREAD = 0x006FD030;
constexpr auto ADDRESS_SCRIPTCONTEXT_OPENSTATE = 0x006FD730;
constexpr auto ADDRESS_SCRIPTCONTEXT_OPENPROTECTEDLIBRARY = 0x006E74F0;
constexpr auto ADDRESS_SCRIPTCONTEXT_ADDSCRIPT = 0x006FD5C0;

constexpr auto ADDRESS_DM_CREATE_SCRIPTCONTEXT = 0x0047DE10;
constexpr auto ADDRESS_DM_FIND_PLAYERS = 0x00412060;

constexpr auto ADDRESS_PLAYERS_GAMECHAT = 0x004F2A50;

constexpr auto ADDRESS_PROTECTEDSTRING_FROMTRUSTEDSOURCE = 0x00695DD0;
constexpr auto ADDRESS_PROTECTEDSTRING_DESTRUCTOR = 0x00432580;

constexpr auto ADDRESS_CORESCRIPT_CONSTRUCTOR = 0x0085C420;
constexpr auto ADDRESS_MAKE_CORESCRIPT_SHAREDPTR = 0x006ECF50;

constexpr auto ADDRESS_SCRIPT_CONSTRUCTOR = 0x00695540;
constexpr auto ADDRESS_MAKE_SCRIPT_SHAREDPTR = 0x00477800;

constexpr auto ADDRESS_SCRIPT_SETDISABLED = 0x00695280;
constexpr auto ADDRESS_SCRIPT_SETSOURCE = 0x00695150;

constexpr auto ADDRESS_REGISTER_SCRIPT_LIBRARY = 0x00658180;

constexpr auto ADDRESS_INSTANCE_SETROBLOXLOCKED = 0x005FD3B0;
constexpr auto ADDRESS_INSTANCE_SETNAME = 0x005FD300;
constexpr auto ADDRESS_INSTANCE_SETPARENT = 0x006004F0;

constexpr auto ADDRESS_HTTP_TRUSTCHECK = 0x005E8A10;

constexpr auto ADDRESS_SCRIPT_HASH_CHECK = 0x00774480;

constexpr auto ADDRESS_PHYSICS_STEPS_PER_SEC = 0x0089D7B0;
constexpr auto ADDRESS_SECS_PER_PHYSICS_STEP = 0x0089D820;

constexpr auto ADDRESS_HEARTBEATTASK_CONSTRUCTOR = 0x006AE160;

constexpr auto ADDRESS_RUNSERVICE_STEP = 0x006AEC00;
constexpr auto ADDRESS_FIRE_HEARTBEAT_SIGNAL = 0x006AE600;
constexpr auto ADDRESS_FIRE_STEPPED_SIGNAL = 0x006AE9F0;

constexpr auto ADDRESS_DATAMODELJOB_SLEEPTIME = 0x0095AA20;

constexpr auto ADDRESS_MOTOR6DJOINT_FPS_FIX = 0x008A2AA9;
constexpr auto ADDRESS_MOTOR6DJOINT_FPS_FIX_JUMPOUT = 0x008A2AAF;

constexpr auto ADDRESS_MOTORJOINT_FPS_FIX = 0x008A2273;
constexpr auto ADDRESS_MOTORJOINT_FPS_FIX_JUMPOUT = 0x008A2279;

// Lua

constexpr auto ADDRESS_LUAL_REGISTER = 0x008B9240;
constexpr auto ADDRESS_LUAL_CHECKLSTRING = 0x008B8E90;
constexpr auto ADDRESS_LUAL_CHECKINTEGER = 0x008B8FD0;
constexpr auto ADDRESS_LUAL_CHECKUDATA = 0x008B8D80;
constexpr auto ADDRESS_LUAL_ERROR = 0x008B82A0;

constexpr auto ADDRESS_LUA_PUSHINTEGER = 0x008B7210;
