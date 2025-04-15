#include "pch.h"
#include "PlayerHooks.h"
#include "Patches.h"

RBX::Network::initWithPlayerSecurity_t RBX::Network::initWithPlayerSecurity_orig = 
	reinterpret_cast<RBX::Network::initWithPlayerSecurity_t>(ADDRESS_PLAYER_NETWORK_INIT);

// SECURITY BYPASS
void __cdecl RBX::Network::initWithPlayerSecurity_hook()
{
	initWithoutSecurity();
}

// ===== `RBX::Network::ClientReplicator` member function hooks =====

RBX::Network::ClientReplicator__canUseProtocolVersion_t RBX::Network::ClientReplicator__canUseProtocolVersion_orig =
	reinterpret_cast<RBX::Network::ClientReplicator__canUseProtocolVersion_t>(ADDRESS_CLIENTREPLICATOR_PROTOCOLVERSION);

bool __fastcall RBX::Network::ClientReplicator__canUseProtocolVersion_hook(RBX::Network::ClientReplicator* _this, void*, int version)
{
	// to match the studio protocol version (originally uses version 13)
	return version <= 12;
}

// ===== `RBX::Network::Replicator::RockyItem` member function hooks =====

RBX::Network::Replicator__RockyItem__write_t RBX::Network::Replicator__RockyItem__write_orig =
	reinterpret_cast<RBX::Network::Replicator__RockyItem__write_t>(ADDRESS_ROCKYITEM_WRITE);

// SECURITY BYPASS
// never send rocky items
bool __fastcall RBX::Network::Replicator__RockyItem__write_hook(RBX::Network::Replicator__RockyItem* _this, void*, void* bitstream)
{
	return true;
}
