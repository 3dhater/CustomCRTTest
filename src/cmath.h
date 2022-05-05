#pragma once
#ifndef __CMATH_H__
#define __CMATH_H__

#ifndef MGF_USE_CRT
#include <cmath>
#else

namespace std
{
	#include "CRT/math.h"
}

#endif

#endif