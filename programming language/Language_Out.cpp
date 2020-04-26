#include <fstream>
#include "Language.h"
using namespace std;

void Out(Procedural *p, ofstream &ofst);
void Out(ObjectOriented *o, ofstream &ofst);
int passedYears(ObjectOriented *o);
int passedYears(Procedural *o);
int passedYears(Functional *o);

void Out(Functional *p, ofstream &ofst);
void Out(Language *lg, ofstream &ofst)
{
	if (lg == NULL)
	{
		ofst << "!!! INCORRECT type of language !!!";
	}
	else
	{
		switch (lg->mKey) {
		case type::PROCEDURAL:
			Out((Procedural *)(lg), ofst);
			break;
		case type::OBJORIENTED:
			Out((ObjectOriented *)lg, ofst);
			break;
		case type::FUNCTIONAL:
			Out((Functional *)lg, ofst);
			break;
		}
	}
};
int passedYears(Language *lg)
{
	if (lg != NULL)
	{
		switch (lg->mKey) {
		case type::PROCEDURAL:
			return passedYears((Procedural *)(lg));
			break;
		case type::OBJORIENTED:
			return passedYears((ObjectOriented *)lg);
			break;
		case type::FUNCTIONAL:
			return passedYears((Functional *)lg);
			break;
		}
	}
	else
	{
		return NULL;
	}
	
};
