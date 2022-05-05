#pragma once
#ifndef __WCHAR__
#define __WCHAR__

#ifndef MGF_USE_CRT
#include <wchar.h>
#else

#include "CRT.h"


/*ISO/IEC 9899:TC3, N1256*/

#ifdef __cplusplus
extern "C" {
#endif

#include "size_t.h"
#include "wchar_t.h"

	typedef struct {
		int i;
	} mbstate_t;

	typedef int wint_t;

	struct tm;

#include "NULL.h"
#include "WCHAR_MINMAX.h"

#define WEOF -1

	//7.24.2.1
	int _C_DECL fwprintf(FILE* stream, const wchar_t* format, ...);

	//7.24.2.2
	int _C_DECL fwscanf(FILE* stream, const wchar_t* format, ...);

	//7.24.2.3
	int _C_DECL swprintf(wchar_t* s, size_t n, const wchar_t* format, ...);

	//7.24.2.4
	int _C_DECL swscanf(const wchar_t* s, const wchar_t* format, ...);

	//7.24.2.5
	int _C_DECL vfwprintf(FILE* stream, const wchar_t* format, va_list arg);

	//7.24.2.6
	int _C_DECL vfwscanf(FILE* stream, const wchar_t* format, va_list arg);

	//7.24.2.7
	int _C_DECL vswprintf(wchar_t* s, size_t n, const wchar_t* format, va_list arg);

	//7.24.2.8
	int _C_DECL vswscanf(const wchar_t* s, const wchar_t* format, va_list arg);

	//7.24.2.9
	int _C_DECL vwprintf(const wchar_t* format, va_list arg);

	//7.24.2.10
	int _C_DECL vwscanf(const wchar_t* format, va_list arg);

	//7.24.2.11
	int _C_DECL wprintf(const wchar_t* format, ...);

	//7.24.2.12
	int _C_DECL wscanf(const wchar_t* format, ...);

	//7.24.3.1
	wint_t _C_DECL fgetwc(FILE* stream);

	//7.24.3.2
	wchar_t* _C_DECL fgetws(wchar_t* s, int n, FILE* stream);

	//7.24.3.3
	wint_t _C_DECL fputwc(wchar_t c, FILE* stream);

	//7.24.3.4
	int _C_DECL fputws(const wchar_t* s, FILE* stream);

	//7.24.3.5
	int _C_DECL fwide(FILE* stream, int mode);

	//7.24.3.6
	wint_t _C_DECL getwc(FILE* stream);

	//7.24.3.7
	wint_t _C_DECL getwchar();

	//7.24.3.8
	wint_t _C_DECL putwc(wchar_t c, FILE* stream);

	//7.24.3.9
	wint_t _C_DECL putwchar(wchar_t c);

	//7.24.3.10
	wint_t _C_DECL ungetwc(wint_t c, FILE* stream);

	//7.24.4.1.1
	double _C_DECL wcstod(const wchar_t* nptr, wchar_t** endptr);
	float _C_DECL wcstof(const wchar_t* nptr, wchar_t** endptr);
	long double _C_DECL wcstold(const wchar_t* nptr, wchar_t** endptr);

	//7.24.4.1.2
	long int _C_DECL wcstol( const wchar_t* nptr, wchar_t** endptr, int base);
	long long int _C_DECL wcstoll( const wchar_t* nptr, wchar_t** endptr, int base);
	unsigned long int _C_DECL wcstoul( const wchar_t* nptr, wchar_t** endptr, int base);
	unsigned long long int _C_DECL wcstoull( const wchar_t* nptr, wchar_t** endptr, int base);
	
	//7.24.4.2.1
	wchar_t* _C_DECL wcscpy(wchar_t* s1, const wchar_t* s2);
	
	//7.24.4.2.2
	wchar_t* _C_DECL wcsncpy(wchar_t* s1, const wchar_t* s2, size_t n);
	
	//7.24.4.2.3
	wchar_t* _C_DECL wmemcpy(wchar_t* s1, const wchar_t* s2, size_t n);
	
	//7.24.4.2.4
	wchar_t* _C_DECL wmemmove(wchar_t* s1, const wchar_t* s2, size_t n);
	
	//7.24.4.3.1
	wchar_t* _C_DECL wcscat(wchar_t* s1, const wchar_t* s2);

	//7.24.4.3.2
	wchar_t* _C_DECL wcsncat(wchar_t* s1, const wchar_t* s2, size_t n);

	//7.24.4.4.1
	int _C_DECL wcscmp(const wchar_t* s1, const wchar_t* s2);
	
	//7.24.4.4.2
	int _C_DECL wcscoll(const wchar_t* s1, const wchar_t* s2);

	//7.24.4.4.3
	int _C_DECL wcsncmp(const wchar_t* s1, const wchar_t* s2, size_t n);

	//7.24.4.4.4
	size_t _C_DECL wcsxfrm(wchar_t* s1, const wchar_t* s2, size_t n);

#ifdef __cplusplus
}
#endif


#endif //MGF_USE_CRT
#endif
