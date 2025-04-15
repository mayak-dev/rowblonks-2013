#include "pch.h"
#include "RBXHooks.h"
#include "Patches.h"
#include "VC90Defs.h"
#include "LuaApiExtensions.h"
#include "UrlHelper.h"

// ===== `RBX::ContentId` member function hooks =====

RBX::ContentId__convertToLegacyContent_t RBX::ContentId__convertToLegacyContent_orig = 
	reinterpret_cast<RBX::ContentId__convertToLegacyContent_t>(ADDRESS_CONVERTTOLEGACYCONTENT);

// rebuild asset URLs to use the assetdelivery API
void __fastcall RBX::ContentId__convertToLegacyContent_hook(RBX::ContentId* _this, void*, vc90::std::string* baseUrl)
{
	RBX::ContentId__convertToLegacyContent_orig(_this, baseUrl);

	UrlHelper urlHelper(_this->id);

	if (urlHelper.isAssetUrl())
	{
		urlHelper.protocol = "https";
		urlHelper.hostname = "assetdelivery.roblox.com";
		urlHelper.path = "v1/asset/";

		(*vc90::std::string__assign_from_cstr)(reinterpret_cast<vc90::std::string*>(&_this->id), urlHelper.buildUrl().c_str());
	}
}

// ===== `RBX::ContentProvider` member function hooks =====

RBX::ContentProvider__verifyScriptSignature_t RBX::ContentProvider__verifyScriptSignature_orig = 
	reinterpret_cast<RBX::ContentProvider__verifyScriptSignature_t>(ADDRESS_VERIFYSCRIPTSIGNATURE);

// SECURITY BYPASS
// never require script signatures (1)
const char* __cdecl RBX::ContentProvider__verifyScriptSignature_hook(const char* source, bool required)
{
	std::string copy = source;

	if (copy.size() == 0 || copy[0] != '%')
		return source;

	size_t endPos = copy.find('%', 1);
	if (endPos == std::string::npos)
		return source;

	return &source[endPos + 1];
}

RBX::ContentProvider__verifyRequestedScriptSignature_t RBX::ContentProvider__verifyRequestedScriptSignature_orig = 
	reinterpret_cast<RBX::ContentProvider__verifyRequestedScriptSignature_t>(ADDRESS_VERIFYREQUESTEDSCRIPTSIGNATURE);

// SECURITY BYPASS
// never require script signatures (2)
const char* __cdecl RBX::ContentProvider__verifyRequestedScriptSignature_hook(const char* source, const std::string& assetId, bool required)
{
	return RBX::ContentProvider__verifyRequestedScriptSignature_orig(source, assetId, false);
}

// ===== `RBX::DataModel` member function hooks =====

RBX::DataModel__startCoreScripts_t RBX::DataModel__startCoreScripts_orig =
	reinterpret_cast<RBX::DataModel__startCoreScripts_t>(ADDRESS_DATAMODEL_STARTCORESCRIPTS);

// execute a local Studio.ashx
void __fastcall RBX::DataModel__startCoreScripts_hook(DataModel* _this, void*, AdornRbxGfx* adorn, bool buildInGameGui)
{
	RBX::GuiBuilder__buildGui(&_this->guiBuilder, adorn, _this->workspace, buildInGameGui);

	char buf[RBX::ProtectedString::size];
	auto source = RBX::ProtectedString__fromTrustedSource(buf, "loadfile('rbxasset://../extra/studio.lua')()");

	auto sc = RBX::DataModel__create__ScriptContext(_this);
	RBX::ScriptContext__executeInNewThread(sc, 4, source, "magic");
}

// ===== `RBX::ScriptContext` member function hooks =====

RBX::ScriptContext__openState_t RBX::ScriptContext__openState_orig = 
	reinterpret_cast<RBX::ScriptContext__openState_t>(ADDRESS_SCRIPTCONTEXT_OPENSTATE);

// maybe move this later
static void __forceinline fixedOpenProtectedLibrary(lua_State* L, const char* name, lua_CFunction func)
{
	__asm
	{
		push func
		push name
		mov eax, L
		call RBX::ScriptContext__openProtectedLibrary
		add esp, 8
	}
}

// open Lua extensions
lua_State* __fastcall RBX::ScriptContext__openState_hook(ScriptContext* _this)
{
	auto L = RBX::ScriptContext__openState_orig(_this);

	fixedOpenProtectedLibrary(L, "maya", Lua::openApiExtensionsLibrary);

	return L;
}

// ===== `RBX::Http` member function hooks =====

RBX::Http__trustCheck_t RBX::Http__trustCheck_orig =
	reinterpret_cast<RBX::Http__trustCheck_t>(ADDRESS_HTTP_TRUSTCHECK);

// allow content from any url
bool __cdecl RBX::Http__trustCheck_hook(const char* url)
{
	return true;
}
