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
			//p = c.Next; // ���������� ��������� �� ��������� �������
			//c.Next = temp; // ���������� ���� ��������� �� �����������
			//temp->L = In(ifst); // ���������� ���� ������ ������������ ����
			//temp->Next = p;// ��������� ���� ��������� �� ��������� �������

			Container *p;
			p = c.Next->Next; //���������� ��������� �� ����������� �������
			c.Next->Next = temp; // ��������� ������� ��������� �� �����
			temp->L = In(ifst);
			temp->Next = p;
		}
	}


};