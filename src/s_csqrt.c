/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright (c) 2007 David Schultz <das@FreeBSD.ORG>
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
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "CRT.h"

#include "complex.h"
#include "float.h"
#include "math.h"

#include "math_private.h"

/* For avoiding overflow for components >= DBL_MAX / (1 + sqrt(2)). */
#define	THRESH	0x1.a827999fcef32p+1022

#pragma warning(push)
#pragma warning(disable: 4244)
double_complex
_C_DECL
__CRT_csqrt(double_complex z)
{
	//double_complex result;
	double a, b, rx, ry, scale, t;

	a = creal(z);
	b = cimag(z);

	/* Handle special cases. */
	if (z.a[0] == 0)
		return (CMPLX(0, b));
	if (isinf(b))
		return (CMPLX(INFINITY, b));
	if (isnan(a)) {
		t = (b - b) / (b - b);	/* raise invalid if b is not a NaN */
		return (CMPLX(a + 0.0L + t, a + 0.0L + t)); /* NaN + NaN i */
	}
	if (isinf(a)) {
		/*
		 * csqrt(inf + NaN i)  = inf +  NaN i
		 * csqrt(inf + y i)    = inf +  0 i
		 * csqrt(-inf + NaN i) = NaN +- inf i
		 * csqrt(-inf + y i)   = 0   +  inf i
		 */
		if (signbit(a))
			return (CMPLX(fabs(b - b), copysign(a, b)));
		else
			return (CMPLX(a, copysign(b - b, b)));
	}
	if (isnan(b)) {
		t = (a - a) / (a - a);	/* raise invalid */
		return (CMPLX(b + 0.0L + t, b + 0.0L + t)); /* NaN + NaN i */
	}

	/* Scale to avoid overflow. */
	if (fabs(a) >= THRESH || fabs(b) >= THRESH) {
		/*
		 * Don't scale a or b if this might give (spurious)
		 * underflow.  Then the unscaled value is an equivalent
		 * infinitesmal (or 0).
		 */
		if (fabs(a) >= 0x1p-1020)
			a *= 0.25;
		if (fabs(b) >= 0x1p-1020)
			b *= 0.25;
		scale = 2;
	} else {
		scale = 1;
	}

	/* Scale to reduce inaccuracies when both components are denormal. */
	if (fabs(a) < 0x1p-1022 && fabs(b) < 0x1p-1022) {
		a *= 0x1p54;
		b *= 0x1p54;
		scale = 0x1p-27;
	}

	/* Algorithm 312, CACM vol 10, Oct 1967. */
	if (a >= 0) {
		t = sqrt((a + hypot(a, b)) * 0.5);
		rx = scale * t;
		ry = scale * b / (2 * t);
	} else {
		t = sqrt((-a + hypot(a, b)) * 0.5);
		rx = scale * fabs(b) / (2 * t);
		ry = copysign(scale * t, b);
	}

	return (CMPLX(rx, ry));
}
#pragma warning(pop)

long_double_complex
_C_DECL
__CRT_csqrtl(long_double_complex z)
{
	double_complex _z;
	_z.a[0] = z.a[0];
	_z.a[1] = z.a[1];

	double_complex __z = __CRT_csqrt(_z);
	z.a[0] = __z.a[0];
	z.a[0] = __z.a[0];
	return z;
}
