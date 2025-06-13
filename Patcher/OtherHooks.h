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

// ===== physics fps unlocking =====

typedef int(__cdecl* getPhysicsStepsPerSec_t)();
extern getPhysicsStepsPerSec_t getPhysicsStepsPerSec_orig;

int __cdecl getPhysicsStepsPerSec_hook();

typedef double(__cdecl* getSecsPerPhysicsStep_t)();
extern getSecsPerPhysicsStep_t getSecsPerPhysicsStep_orig;

double __cdecl getSecsPerPhysicsStep_hook();

// ===== motor and motor6d fps fix =====

extern void* motor6dJointFpsFix_ptr;
void motor6dJointFpsFix_hook();

extern void* motorJointFpsFix_ptr;
void motorJointFpsFix_hook();

// ===== roblosecurity cookie =====

typedef LPVOID HINTERNET;

typedef HINTERNET(__stdcall* InternetOpenA_t)(LPCSTR lpszAgent, DWORD dwAccessType, LPCSTR lpszProxy, LPCSTR lpszProxyBypass, DWORD dwFlags);
extern InternetOpenA_t InternetOpenA_orig;

HINTERNET __stdcall InternetOpenA_hook(LPCSTR lpszAgent, DWORD dwAccessType, LPCSTR lpszProxy, LPCSTR lpszProxyBypass, DWORD dwFlags);
