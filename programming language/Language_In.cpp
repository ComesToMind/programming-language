//#pragma once
#include <fstream>
#include "Language.h"
using namespace std;
Language * In(int key, ifstream &ifst)
{
	//char error[256];
	int inh;
	switch (key)
	{

	case 1:
		Procedural * p;
		p = new Procedural;
		p->mKey = type::PROCEDURAL;
		ifst >> inh;
		if (inh == 1 || inh == 0)
		{
			p->mAbstractDT = inh;
			ifst >> p->mData;
			return (Language *)p;
		}
		else
		{
			ifst >> p->mData;
			return NULL;
		}
		
		
	case 2:

		ObjectOriented * o;
		o = new ObjectOriented;
		o->mKey = type::OBJORIENTED;
		
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
			ifst >> o->mData;
			//ifst.getline(error, 256);
			return NULL;
		}
		ifst >> o->mData;
		return (Language *)o;
	default:
		//дочитываем до конца, если не тот ключ
		//ifst.getline(error, 256);
		ifst >> inh >> inh;
		return NULL;
	}

};
Language* In(ifstream &ifst) {
	Language *lg;
	int k;
	ifst >> k;
	lg = In(k, ifst);
	return lg;

};
