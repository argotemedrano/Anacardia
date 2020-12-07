#pragma once

#ifdef ANACARDIA_PLATFORM_WINDOWS
	#ifdef ACAR_BUILD_DLL
		#define ANACARDIA_API __declspec(dllexport)
	#else
		#define ANACARDIA_API __declspec(dllimport)
	#endif
#endif

// TODO: Debug break only works for windows
#ifdef ANACARDIA_ENABLE_ASSERTS
#define ANACARDIA_ASSERT(x, ...) { if (!(x)) { ANACARDIA_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}}
#define ANACARDIA_CORE_ASSERT(x, ...) { if (!(x)) { ANACARDIA_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define ANACARDIA_ASSERT(x, ...)
#define ANACARDIA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)