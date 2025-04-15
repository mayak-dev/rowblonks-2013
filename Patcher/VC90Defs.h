#pragma once

#include "Patches.h"

// this is necessary for compatibility, as we are using a newer version of MSVC as well as possibly different build configs

namespace vc90
{
	const auto operator_new = reinterpret_cast<void* (__cdecl**)(size_t)>(ADDRESS_OPERATOR_NEW);

	const auto _RTDynamicCast = 
		reinterpret_cast<PVOID(__cdecl**)(PVOID inptr, LONG VfDelta, PVOID SrcType, PVOID TargetType, BOOL isReference)>(ADDRESS_RTDYNAMICCAST);

	namespace std
	{
		// ===== `string` class =====
		// in other words, a `std::basic_string<char, std::char_traits<char>, std::allocator<char>>`
		// this DLL is built with _ITERATOR_DEBUG_LEVEL=1 on Release, making std::string and vc90::std::string *mostly* compatible

		const auto string__constructor = reinterpret_cast<class string*(__thiscall**)(void* buf, const char* str)>(ADDRESS_STRING_CONSTRUCTOR);
		const auto string__destructor = reinterpret_cast<void(__thiscall**)(class string* _this)>(ADDRESS_STRING_DESTRUCTOR);

		class string
		{
		public:
			static constexpr size_t size = 28;
		};

		const auto string__assign_from_cstr = reinterpret_cast<void(__thiscall**)(string* _this, const char* str)>(ADDRESS_STRING_ASSIGN_FROM_CSTR);
	}
}
