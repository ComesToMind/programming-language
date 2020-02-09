#include "Container.h"
#include <fstream>
using namespace std;
Language* In(ifstream &ifst);
void In(Container &c, ifstream &ifst)
{

	while (!ifst.eof())
	{

		Container *temp = new Container;
		if ((&c == c.Next) && (c.L == NULL))
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

			Container *p;
			p = c.Next->Next; //сохранение указателя на последующий элемент
			c.Next->Next = temp; // следующий элемент указывает на новый
			temp->L = In(ifst);
			temp->Next = p;
		}
	}


};