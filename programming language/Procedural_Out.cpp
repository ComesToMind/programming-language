//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Procedural.h"
#include <ctime>

using namespace std;

void Out(Procedural *p, ofstream &ofst) {
	ofst << "It is Procedural:   abstrat data type = " << p->mAbstractDT
		<< ", data = " << p->mData << ", References:  " << p->mRef;
};

int YearsPassed(Procedural *p)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	return (timeinfo->tm_year + 1900) - p->mData;
};