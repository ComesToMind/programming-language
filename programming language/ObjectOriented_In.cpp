#include <fstream>
#include "ObjectOriented.h"
#include <vector>
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
		char b;
		while (!ifst.eof() && ifst.peek() != '\n')
		{
			ifst >> b;
			//b=?
		}
		return NULL;
	}

	vector<int> tail;
	while (!ifst.eof() && ifst.peek() != '\n')
	{
		ifst >> inh;
		tail.push_back(inh);
	}
	if (tail.size() == 2)
	{
		o->mData = tail[0];
		o->mRef = tail[1];
		return o;

	}
	else
	{
		return NULL;
	}
}
