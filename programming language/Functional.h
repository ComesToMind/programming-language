#pragma once
#include "Type.h"
struct Functional
{
	type mKey;
	short int mData;
	int mRef;
	unsigned short int mLazyCalculations;
	enum typification
	{
		STRICT,
		DYNAMIC
	} mType;
};

