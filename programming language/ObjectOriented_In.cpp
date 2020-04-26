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
	bool flag = true;
	vector<int> tail;
	while (!ifst.eof() && ifst.peek() != '\n')
	{
		ifst >> inh;
		if (ifst.fail())
		{
			//Восстановили поток
			ifst.clear();
			ifst.ignore(numeric_limits<streamsize>::max(), '\n');
			flag = false;
			break;
		}
		if (inh >= 0)
		{
			tail.push_back(inh);
		}
	}

	if (tail.size() == 3 && flag)
	{
		
		if (tail[0] == 0 || tail[0] == 1 || tail[0] == 2)
		{
			o->mInher = static_cast<ObjectOriented::inheritance>(tail[0]);
			o->mData = tail[1];
			o->mRef = tail[2];
			return o;
		}
		else
		{
			return NULL;
		}

	}
	else
	{
		return NULL;
	}


	//int inh;
	//ifst >> inh;
	//if (inh == 0)
	//{
	//	o->mInher = ObjectOriented::SINGLE;
	//}
	//	else if (inh == 1)
	//	{
	//		o->mInher = ObjectOriented::MULTIPLE;
	//	}
	//		else if (inh == 2)
	//		{
	//			o->mInher = ObjectOriented::INTERFACE;
	//		}
	//else
	//{
	//	char b;
	//	while (!ifst.eof() && ifst.peek() != '\n')
	//	{
	//		ifst >> b;
	//		//b=?
	//	}
	//	return NULL;
	//}

	//vector<int> tail;
	//while (!ifst.eof() && ifst.peek() != '\n')
	//{
	//	ifst >> inh;
	//	tail.push_back(inh);
	//}
	//if (tail.size() == 2)
	//{
	//	o->mData = tail[0];
	//	o->mRef = tail[1];
	//	return o;

	//}
	//else
	//{
	//	return NULL;
	//}
}
