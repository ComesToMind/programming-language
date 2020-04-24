#include <fstream>
#include "Functional.h"
#include <vector>
using namespace std;

Functional * InFunc(ifstream &ifst)
{
	Functional * f;
	f = new Functional;
	f->mKey = type::FUNCTIONAL;
	int inh;
	ifst >> inh;
	if (inh == 1 || inh == 0)
	{
		f->mLazyCalculations = inh;
	}
	else
	{
		char b;
		ifst >> b;
		while (!ifst.eof() && ifst.peek() != '\n')
		{
			ifst >> b;
			//b=?
		}
		return NULL;
	}
	ifst >> inh;
	if (inh == 0)
	{
		f->mType = Functional::STRICT;
	}
	else if (inh == 1)
	{
		f->mType = Functional::DYNAMIC;
	}
	else
	{
		char b;
		ifst >> b;
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
		f->mData = tail[0];
		f->mRef = tail[1];
		return f;

	}
	else
	{
		return NULL;
	}
	
}