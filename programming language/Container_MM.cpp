#include "Container.h"
#include <fstream>
using namespace std;
void Out(Language *lg, ofstream &ofst);

void MultiMethod(Container &c, ofstream &ofst)
{
	if (&c != nullptr)
	{
		ofst << endl << "Multimethod." << endl;
		Container *first;
		Container *second;
		first = &c;
		//second = c.Next;
		while (first->Next != &c) //from 0 to n-1
		{
			second = first->Next;
			while (second !=&c) //from first to n
			{
				switch (first->L->mKey)
				{
				case type::PROCEDURAL:
					switch (second->L->mKey)
					{
					case type::PROCEDURAL:
						ofst << "Procedural and Procedural." << endl;
						break;
					case type::OBJORIENTED:
						ofst << "Procedural and OOP." << endl;
						break;
					default:
						ofst << "Unknown type." << endl;
						break;
					}
					break;
				case type::OBJORIENTED:
					switch (second->L->mKey)
					{
					case type::PROCEDURAL:
						ofst << "OOP and Procedural." << endl;
						break;
					case type::OBJORIENTED:
						ofst << "OOP and OOP." << endl;
						break;
					default:
						ofst << "Unknown type." << endl;
						break;
					}
					break;
				default:
					ofst << "Unknown type." << endl;
					break;
				}
				Out(first->L,ofst);
				Out(second->L,ofst);
				second = second->Next;
			}
			
			first = first->Next;
		} 
	}
	else
	{
		ofst << "Container is empty!" << endl;

	}


	}