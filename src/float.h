/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 1989 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	from: @(#)float.h	7.1 (Berkeley) 5/8/90
 * $FreeBSD$
 */
#pragma once
#ifndef __FLOAT__
#define __FLOAT__

#ifndef MGF_USE_CRT
#include <float.h>
#else

// Modified for migui 
#include "CRT.h"

// 5.2.4.2.2:7
#define FLT_ROUNDS	__CRT_flt_rounds()

// 5.2.4.2.2:8
#define	FLT_EVAL_METHOD	0 // just 0

// 5.2.4.2.2:9
#define FLT_RADIX	2

#define FLT_MANT_DIG	24		/* p */
#define DBL_MANT_DIG	53
#define LDBL_MANT_DIG	DBL_MANT_DIG // VS2019: DBL_MANT_DIG
#define	DECIMAL_DIG	17     // VS2019: 17

#define FLT_DIG		6		/* floor((p-1)*log10(b))+(b == 10) */
#define DBL_DIG		15
#define LDBL_DIG	DBL_DIG   // VS2019: DBL_DIG

#define FLT_MIN_EXP	(-125)		/* emin */
#define DBL_MIN_EXP	(-1021)
#define LDBL_MIN_EXP	DBL_MIN_EXP    // VS2019: DBL_MIN_EXP

#define FLT_MIN_10_EXP	(-37)		/* ceil(log10(b**(emin-1))) */
#define DBL_MIN_10_EXP	(-307)
#define LDBL_MIN_10_EXP	DBL_MIN_10_EXP  // VS2019: DBL_MIN_10_EXP

#define FLT_MAX_EXP	128		/* emax */
#define DBL_MAX_EXP	1024
#define LDBL_MAX_EXP	DBL_MAX_EXP   // VS2019: DBL_MAX_EXP

#define FLT_MAX_10_EXP	38		/* floor(log10((1-b**(-p))*b**emax)) */
#define DBL_MAX_10_EXP	308
#define LDBL_MAX_10_EXP	DBL_MAX_10_EXP   // VS2019: DBL_MAX_10_EXP

#define FLT_MAX		3.40282347E+38F	/* (1-b**(-p))*b**emax */
#define DBL_MAX		1.7976931348623157E+308
#define LDBL_MAX	DBL_MAX   // VS2019: DBL_MAX

#define FLT_EPSILON	1.19209290E-07F	/* b**(1-p) */
#define DBL_EPSILON	2.2204460492503131E-16
#define LDBL_EPSILON	DBL_EPSILON   // VS2019: DBL_EPSILON

#define FLT_MIN		1.17549435E-38F	/* b**(emin-1) */
#define DBL_MIN		2.2250738585072014E-308
#define LDBL_MIN	DBL_MIN  // VS2019: DBL_MIN

#ifdef __cplusplus
extern "C" {
#endif

	// current in __crt
#define FLT_ROUNDS_INDETERMINABLE -1
#define FLT_ROUNDS_TOWARDZERO 0
#define FLT_ROUNDS_TONEAREST 1
#define FLT_ROUNDS_TOWPOSINF 2
#define FLT_ROUNDS_TOWNEGINF 3

	int _C_DECL __CRT_flt_rounds();
	
#ifdef __cplusplus
}
#endif

#endif //MGF_USE_CRT

#endif