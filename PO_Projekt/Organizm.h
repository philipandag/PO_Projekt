#pragma once
#include "Swiat.h"
class Organizm
{
	int sila;
	int inicjatywa;
	int x;
	int y;
	Swiat swiat;

public:
	Organizm(int sila, int inicjatywa, int x, int y, Swiat& swiat);

	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;
};

