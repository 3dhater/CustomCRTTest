
/* @(#)e_lgamma.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 *
 */

#include "CRT.h"

/* __ieee754_lgamma(x)
 * Return the logarithm of the Gamma function of x.
 *
 * Method: call __ieee754_lgamma_r
 */

#include "float.h"

#include "math.h"
#include "math_private.h"

extern int signgam;

double __ieee754_lgamma_r(double x, int* signgamp);

double
_C_DECL
__CRT_ieee754_lgamma(double x)
{
	return __ieee754_lgamma_r(x,&signgam);
}

long double
_C_DECL
__CRT_ieee754_lgammal(long double x)
{
	return __CRT_ieee754_lgamma(x);
}
