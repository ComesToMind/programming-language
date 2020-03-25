//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "ObjectOriented.h"
#include <ctime>
using namespace std;

void Out(ObjectOriented *o, ofstream &ofst)
{
	ofst << "It is Object-Oriented: inheritance = ";
	if (o->mInher == 0)
	{
		ofst << "SINGLE";
	}
	else if (o->mInher == 1)
	{
		ofst << "MULTIPLE";
	}
	else
		ofst << "INTERFACE";

	ofst << ", data = " << o->mData << ", References:  " << o->mRef << endl;
}; endl;
};
int YearsPassed(ObjectOriented *o)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	return (timeinfo->tm_year + 1900) - o->mData;
};