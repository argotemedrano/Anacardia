#pragma once

#ifdef ANACARDIA_PLATFORM_WINDOWS
	#ifdef ACAR_BUILD_DLL
		#define ANACARDIA_API __declspec(dllexport)
	#else
		#define ANACARDIA_API __declspec(dllimport)
	#endif
#endif