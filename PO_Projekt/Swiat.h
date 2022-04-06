#pragma once
#include <queue>
#include <queue>
#include "Organizm.h"

using std::priority_queue;

class Swiat
{
	priority_queue<Organizm&> organizmy;
	
public:
	Swiat();
	void wykonajTure();
	void rysujSwiat();
};

