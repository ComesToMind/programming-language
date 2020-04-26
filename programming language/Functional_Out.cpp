#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Functional.h"
#include <ctime>
using namespace std;

void Out(Functional *p, ofstream &ofst) {
	ofst << "It is Functional : lazy calculations = " << p->mLazyCalculations
		<< ", typification = ";
	if (p->mType == 0)
	{
		ofst << " STRICT";
	}
	else if (p->mType == 1)
	{
		ofst << " DYNAMIC";
	}
	ofst << ", data = " << p->mData <<", references "<< p->mRef;
};
int passedYears(Functional *p)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	return (timeinfo->tm_year + 1900) - p->mData;
};