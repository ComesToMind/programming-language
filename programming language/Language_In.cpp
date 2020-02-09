//#pragma once
#include <fstream>
#include "Language.h"
using namespace std;
void * In(int key, ifstream &ifst)
{
	char error[256];
	switch (key)
	{

	case 1:
		Procedural * p;
		p = new Procedural;
		p->mKey = type::PROCEDURAL;
		ifst >> p->mAbstractDT >> p->mData;
		return p;
	case 2:

		ObjectOriented * o;
		o = new ObjectOriented;
		o->mKey = type::OBJORIENTED;
		int inh;
		ifst >> inh;
		if (inh == 0)
		{
			o->mInher = ObjectOriented::SINGLE;
		}
		else if (inh == 1)
		{
			o->mInher = ObjectOriented::MULTIPLE;
		}
		else if (inh == 2)
		{
			o->mInher = ObjectOriented::INTERFACE;
		}
		else
		{
			ifst.getline(error, 256);
			return 0;
		}
		ifst >> o->mData;
		return o;
	default:
		ifst.getline(error, 256);
		return 0;
	}

};
Language* In(ifstream &ifst) {
	Language *lg;
	int k;
	ifst >> k;
	lg = (Language *)(In(k, ifst));
	return lg;

};
