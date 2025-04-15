#include "pch.h"
#include "OtherHooks.h"
#include "Patches.h"
#include "VC90Defs.h"

// ===== bypass "invalid request" for some urls =====

invalidRequestCheck_t invalidRequestCheck_orig = reinterpret_cast<invalidRequestCheck_t>(ADDRESS_INVALID_REQUEST_CHECK);

// really only takes 1 std::string by value, and is responsible for calling its destructor
void __cdecl invalidRequestCheck_hook(char a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	auto url = reinterpret_cast<vc90::std::string*>(&a1);
	(*vc90::std::string__destructor)(url);
}

// ===== bypass GetScriptState.ashx check =====

scriptHashCheck_t scriptHashCheck_orig = reinterpret_cast<scriptHashCheck_t>(ADDRESS_SCRIPT_HASH_CHECK);

bool __fastcall scriptHashCheck_hook(void* _this, void*, int a2, int a3)
{
	return true;
}

// ===== ComputeProp null dereference fix =====

computePropNullDerefFix_t computePropNullDerefFix_orig = reinterpret_cast<computePropNullDerefFix_t>(ADDRESS_COMPUTEPROP_NULL_DEREF);

float __fastcall computePropNullDerefFix_hook(float* _this)
{
	if (_this)
		return *(_this + 30);

	return 0.0f;
}
