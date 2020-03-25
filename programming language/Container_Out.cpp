#include "Container.h"
#include <fstream>
using namespace std;
void Out(Language *lg, ofstream &ofst);
int YearsPassed(Language *lg);
bool Compare(Language *first, Language *second);

void Sort(Container *&c)
{
	//if container contains 1 element, do nothing
	if (c == c->Next)
	{
		return;
	}
	Container *current = c;
	

	bool flag = false;
	Language *temp;
	//buble sort
	do
	{
		current = c;
		//if we didnt swap elements container is sorted
		flag = false;

		
		do
		{
			if (Compare(current->L,current->Next->L))
			{
				temp = current->L;
				current->L = current->Next->L;
				current->Next->L = temp;
				flag = true;
			}
			current = current->Next;

		} while (current->Next != c);
	} while (flag);
};
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
				ofst << YearsPassed(temp->L) << " years have been passed!!!" << endl
			}
			else
			{
				ofst << endl;
			}
			;
			temp = temp->Next;
			i++;
		} while (temp != &c);
	}
	else
	{
		ofst << "Container is empty!" << endl;

	}
};
