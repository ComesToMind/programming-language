#include "Container.h"
#include <fstream>
using namespace std;
void Out(Language *lg, ofstream &ofst);
void Out(Container &c, ofstream &ofst)
{
	if (&c != nullptr)
	{
		ofst << "Container contains that elements:" << endl;
		Container *temp;
		temp = &c;
		int i = 0;
		do
		{
			ofst << i << ": ";
			if (temp->L->mKey == type::PROCEDURAL)
			{
				Out(temp->L, ofst);
			}
			else
			{
				ofst << endl;
			}
			temp = temp->Next;
			i++;
		} while (temp != &c);
	}
	else
	{
		ofst << "Container is empty!" << endl;

	}



};