#ifndef RATE_h
#define RATE_h
#define x 4
#define y 10
#define x2 18
#define y2 40
#include <iostream>
#include "Role.h"
#include <map>
using namespace std;
typedef multimap<int, char*> Rate;
void rating(Role** dptr, int nmb) {
	Rate myRate;
	for (int i=0; i<nmb;i++)
		myRate.insert(Rate::value_type(dptr[i]->level, dptr[i]->name));
	int i=0;
	mvprintw(x, y, "%s ", "<----Here is the Rating.---->");
	for (Rate::reverse_iterator it=myRate.rbegin(); it != myRate.rend(); it++)
	{
		mvprintw(x+1+i, y, "Lv. %d : %s ", it->first, it->second);
		i++;
	}
}

#endif
