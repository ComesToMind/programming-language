//#pragma once
#include <fstream>
#include "Procedural.h"
using namespace std;

void Out(Procedural *p, ofstream &ofst) {
	ofst << "It is Procedural:   abstrat data type = " << p->mAbstractDT
		<< ", data = " << p->mData << ", References:  " << p->mRef << endl;
};