#pragma once
#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#if _MSC_VER > 1900
#ifndef MGF_USE_CRT
#include <filesystem>
#else
#include "CRT/filesystem_internal.h"
#endif

#else 

#include "CRT/filesystem_internal.h"
#endif


#endif