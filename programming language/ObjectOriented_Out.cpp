//#pragma once
#include <fstream>
#include "ObjectOriented.h"
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

	ofst << ", data = " << o->mData << endl;
};