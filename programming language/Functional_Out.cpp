#include <fstream>
#include "Functional.h"
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
	ofst << ", data = " << p->mData << endl;
};