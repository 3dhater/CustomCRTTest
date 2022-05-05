#pragma once
#ifndef __CASSERT_H__
#define __CASSERT_H__

#ifndef MGF_USE_CRT
#include <cassert>
#else
namespace std
{
#include "CRT/assert.h"
}
#endif


#endif