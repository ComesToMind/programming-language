#include <fstream>
#include "ObjectOriented.h"
using namespace std;


ObjectOriented * InOO(ifstream &ifst)
{
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
		ifst >> o->mData;
		//ifst.getline(error, 256);
		return NULL;
	}
	ifst >> o->mData;
	return o;

}
