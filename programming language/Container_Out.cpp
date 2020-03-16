#include "Container.h"
#include <fstream>
using namespace std;
void Out(Language *lg, ofstream &ofst);
int YearsPassed(Language *lg);
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
			Out(temp->L, ofst);
			ofst << YearsPassed(temp->L) << " years have been passed!!!"<< endl;
			temp = temp->Next;
			i++;
		} while (temp != &c);
	}
	else
	{
		ofst << "Container is empty!" << endl;

	}



};