#include "Language.h"
int passedYears(Language *lg);
bool Compare(Language *first, Language *second)
{
	 return passedYears(first) < passedYears(second);
};