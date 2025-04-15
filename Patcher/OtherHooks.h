#pragma once

// ===== bypass "invalid request" for some urls =====
// really only takes 1 std::string by value, and is responsible for calling its destructor
typedef void(__cdecl* invalidRequestCheck_t)(char a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern invalidRequestCheck_t invalidRequestCheck_orig;

void __cdecl invalidRequestCheck_hook(char a1, int a2, int a3, int a4, int a5, int a6, int a7);

// ===== bypass GetScriptState.ashx check =====
typedef bool(__thiscall* scriptHashCheck_t)(void* _this, int a2, int a3);
extern scriptHashCheck_t scriptHashCheck_orig;

bool __fastcall scriptHashCheck_hook(void* _this, void*, int a2, int a3);

// ===== ComputeProp null dereference fix =====
typedef float(__thiscall* computePropNullDerefFix_t)(float* _this);
extern computePropNullDerefFix_t computePropNullDerefFix_orig;

float __fastcall computePropNullDerefFix_hook(float* _this);
