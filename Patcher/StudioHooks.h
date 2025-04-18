#pragma once

#include "RBXDefs.h"

// ===== ComputeProp null dereference fix =====
typedef float(__thiscall* computePropNullDerefFix_t)(float* _this);
extern computePropNullDerefFix_t computePropNullDerefFix_orig;

float __fastcall computePropNullDerefFix_hook(float* _this);

// ===== `RobloxView::RenderRequestJob` member function hooks =====

class RobloxView__RenderRequestJob
{
private:
	char padding1[560];
public:
	bool awake;
};

typedef void(__thiscall* RobloxView__RenderRequestJob__sleepTime_t)(RobloxView__RenderRequestJob* _this, double* a2, int a3);
extern RobloxView__RenderRequestJob__sleepTime_t RobloxView__RenderRequestJob__sleepTime_orig;

void __fastcall RobloxView__RenderRequestJob__sleepTime_hook(RobloxView__RenderRequestJob* _this, void*, double* a2, int a3);
