#pragma once

#include <cstdio>

#define TSK_ASSERT(x)\
{\
	if (x == 0)\
		printf("%s:%d - error!", __FILE__, __LINE__);\
}