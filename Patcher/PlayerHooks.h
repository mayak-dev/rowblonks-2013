#pragma once

#include "RBXDefs.h"

namespace RBX
{
	namespace Network
	{
		// SECURITY BYPASS
		void __cdecl initWithPlayerSecurity_hook();

		// ===== `RBX::Network::ClientReplicator` member function hooks =====

		bool __fastcall ClientReplicator__canUseProtocolVersion_hook(RBX::Network::ClientReplicator* _this, void*, int version);

		// ===== `RBX::Network::Replicator::RockyItem` member function hooks =====

		// SECURITY BYPASS
		bool __fastcall Replicator__RockyItem__write_hook(RBX::Network::Replicator__RockyItem* _this, void*, void* bitstream);
	}
}

// ===== `CRobloxWnd::RenderRequestJob` member function hooks =====

class CRobloxWnd__RenderRequestJob
{
private:
	char padding1[536];
public:
	bool awake;
};

typedef void(__thiscall* CRobloxWnd__RenderRequestJob__sleepTime_t)(CRobloxWnd__RenderRequestJob* _this, double* a2, int a3);
extern CRobloxWnd__RenderRequestJob__sleepTime_t CRobloxWnd__RenderRequestJob__sleepTime_orig;

void __fastcall CRobloxWnd__RenderRequestJob__sleepTime_hook(CRobloxWnd__RenderRequestJob* _this, void*, double* a2, int a3);

// ===== `CRobloxWnd::UserInputJob` member function hooks =====

class CRobloxWnd__UserInputJob;

typedef void(__thiscall* CRobloxWnd__UserInputJob__sleepTime_t)(CRobloxWnd__UserInputJob* _this, double* a2, int a3);
extern CRobloxWnd__UserInputJob__sleepTime_t CRobloxWnd__UserInputJob__sleepTime_orig;

void __fastcall CRobloxWnd__UserInputJob__sleepTime_hook(CRobloxWnd__UserInputJob* _this, void*, double* a2, int a3);
