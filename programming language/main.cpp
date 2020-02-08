#include <iostream>
#include <fstream>

using namespace std;


enum type {
	PROCEDURAL,
	OBJORIENTED};

struct Procedural 
{
	type mKey;
	bool mAbstractDT;
	short int mData;
};
struct ObjectOriented 
{

	type mKey;

	enum inheritance {
		SINGLE,
		MULTIPLE,
		INTERFACE};
	inheritance mInher;
	short int mData;
};
struct Language 
{	
	
	type mKey;
	
};

void  * In(int key, ifstream &ifst)
{
	switch(key) 
	{
	case 1:
		Procedural * p;
		p = new Procedural;
		p->mKey = type::PROCEDURAL;
		ifst >> p->mAbstractDT >> p->mData;
		return p;
	case 2:

		ObjectOriented * o;
		o = new ObjectOriented;
		o->mKey = type::OBJORIENTED;
		int inh;
		ifst >> inh;
		if (inh == 0)
		{
			o->mInher = ObjectOriented::SINGLE;
		}
		else if (inh == 1)
		{
			o->mInher = ObjectOriented::MULTIPLE;
		}
		else if(inh == 2)
		{
			o->mInher = ObjectOriented::INTERFACE;
		}
		else return 0;
		ifst >> o->mData;
		return o;
	default:
		return 0;
	}
	
};

Language* In(ifstream &ifst) {
	Language *lg;
	int k;
	ifst >> k;
	lg = (Language *)(In(k, ifst));
	return lg;

};

//----------------------------------------------------

//----------------------------------------------------
// ¬ывод параметров текущей фигуры в поток
// ¬ывод параметров пр€моугольника в форматируемый поток
void Out(Procedural *p, ofstream &ofst) {
	ofst << "It is Procedural:   abstrat data type = " << p->mAbstractDT
		<< ", data = " << p->mData<< endl;
};
// ¬ывод параметров треугольника в поток
void Out(ObjectOriented *o, ofstream &ofst)
{
	ofst << "It is Object-Oriented: inheritance = "
		<< o->mKey << ", data = " << o->mData<< endl;
};

void Out(Language &lg, ofstream &ofst) 
{
	if (&lg == NULL)
	{
		ofst << "Incorrect figure!" << endl;
	}
	else
	{
		switch (lg.mKey) {
		case type::PROCEDURAL:
			Out((Procedural *)(&lg), ofst);
			break;
		case type::OBJORIENTED:
			Out((ObjectOriented *)&lg, ofst);
			break;
		}
	}
};

//----------------------------------------------------

////////////////////
//container
struct Container
{
	Container *Next;
	Language *L;
};


void In(Container &c, ifstream &ifst)
{

	while (!ifst.eof())
	{

	Container *temp = new Container;
	if ((&c == c.Next)&&(c.L==NULL))
	{
		c.L = In(ifst);
	}
	else
	{
		//Container *p;
		//p = c.Next; // сохранение указател€ на следующий элемент
		//c.Next = temp; // предыдущий узел указывает на создаваемый
		//temp->L = In(ifst); // сохранение пол€ данных добавл€емого узла
		//temp->Next = p;// созданный узел указывает на следующий элемент

		Container *p;
		p = c.Next->Next; //сохранение указател€ на последующий элемент
		c.Next->Next = temp; // следующий элемент указывает на новый
		temp->L = In(ifst);
		temp->Next = p;
	}
	}


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
			Out(*(temp->L), ofst);
			temp = temp->Next;
			i++;
		} while (temp != &c);
	}
	else
	{
		ofst << "Container is empty!" << endl;

	}

	
	
};

void Init(Container &c)
{
	c.Next = &c;
	c.L = NULL;
};

void Clear(Container *&c)
{
	Container *temp;
	temp = c->Next;
	while (temp!= c)
	{
		c->Next= temp->Next;
		delete temp;
		temp = c->Next;
	}
	delete c;
	c = nullptr;
	
};
/////////////////////////////////////////////////////

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
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(*c, ofst);
	cout << "Stop" << endl;
	system("pause");

	return 0; 
}