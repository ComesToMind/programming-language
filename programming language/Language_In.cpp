//#pragma once
#include <fstream>
#include "Language.h"
using namespace std;

ObjectOriented* inOO(ifstream &ifst);
Procedural * inProc(ifstream &ifst);
Functional * inFunc(ifstream &ifst);
Language * In(int key, ifstream &ifst)
{
	int inh;
	switch (key)
	{
	case 1:
		return (Language *)inProc(ifst);
	case 2:
		return (Language *)inOO(ifst);
	case 3: 
		return (Language *)inFunc(ifst);
	default:
		char b;
		do 
		{
			ifst >> b;
		}while(!ifst.eof() && ifst.peek() != '\n');
		return NULL;
	}

};
Language* In(ifstream &ifst) {
	Language *lg;
	int k;
	ifst >> k;
	
	if (ifst.fail())
	{
		//Восстановили поток
		ifst.clear();
		ifst.ignore(numeric_limits<streamsize>::max(), '\n');
		return NULL;
	}

	lg = In(k, ifst);
	return lg;

};
