#include "Container.h"
#include <fstream>
using namespace std;
Language* In(ifstream &ifst);
void In(Container &c, ifstream &ifst)
{

	while (!ifst.eof())
	{

		Container *temp = new Container;
		if ((&c == c.Next)&&(!ifst.tellg()))
		{
			c.L = In(ifst);
		}
		else
		{
			//Container *p;
			//p = c.Next; // сохранение указателя на следующий элемент
			//c.Next = temp; // предыдущий узел указывает на создаваемый
			//temp->L = In(ifst); // сохранение поля данных добавляемого узла
			//temp->Next = p;// созданный узел указывает на следующий элемент
		
			//идем на последний элемент
			Container *counter = c.Next;
			while(counter->Next != &c)
			{
				counter = counter->Next;

			}

			counter->Next = temp;
			temp->L = In(ifst);
			temp->Next = &c;

			//Container *p;
			//p = c.Next->Next; //сохранение указателя на последующий элемент
			//c.Next->Next = temp; // следующий элемент указывает на новый
			//temp->L = In(ifst);
			//temp->Next = p;
		}
	}


};