#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
using namespace std;
void Init(Container &c);
void Clear(Container *&c);
void In(Container &c, ifstream &ifst);
void Out(Container &c, ofstream &ofst);
void Sort(Container *&c);
int main(int argc, char* argv[]) 
{
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	Container *c = new Container;
	Init(*c);
	In(*c, ifst);
	ofst << "Filled container. " << endl;
	Out(*c, ofst);

	ofst << endl << endl << "Sorted Container!!!" << endl;
	Sort(c);
	Out(*c, ofst);

	Clear(c);
	//ofst << "Empty container. " << endl;
	Out(*c, ofst);
	cout << "Stop" << endl;
	system("pause");

	return 0; 
}