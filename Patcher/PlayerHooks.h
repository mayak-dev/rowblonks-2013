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
