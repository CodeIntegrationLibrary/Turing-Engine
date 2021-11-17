#pragma once

#ifdef TR_PLATFORM_WINDOWS
	#ifdef TR_BUILD_DLL
		#define TURING_API _declspec(dllexport)
	#else
		#define TURING_API _declspec(dllimport)
	#endif
#else
	#error Turing only supports Windows!
#endif
