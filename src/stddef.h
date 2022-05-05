#pragma once
#ifndef __STDDEF__
#define __STDDEF__

#ifndef MGF_USE_CRT
#include <stddef.h>
#else

#include "CRT.h"

// ISO/IEC 9899:TC3, N1256

#ifdef __cplusplus
extern "C" {
#endif

	// 7.17:2
#include "size_t.h"

		// 7.17:2
#ifndef _PTRDIFF_T_DEFINED
		typedef size_t ptrdiff_t;
#define _PTRDIFF_T_DEFINED
#endif

		// 7.17:2
#ifndef __cplusplus
#ifndef __CRT_WCHAR_T_DEFINED
#define __CRT_WCHAR_T_DEFINED
		typedef unsigned short wchar_t;
#endif
#endif

		// 7.17:3
#include "NULL.h"

		// 7.17:3
#ifndef offsetof
#define offsetof(type,member) ((size_t)&(((type*)0)->member))
#endif

#ifdef __cplusplus
}
#endif

#endif //MGF_USE_CRT
#endif