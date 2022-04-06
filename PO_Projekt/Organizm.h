#pragma once
#include <iostream>
using namespace std;

class Swiat;

class Organizm
{
	int sila;
	int inicjatywa;
	int x;
	int y;
	Swiat& swiat;

public:
	Organizm(int sila, int inicjatywa, int x, int y, Swiat& swiat);
	Organizm(int sila, int inicjatywa, Swiat& swiat);

	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;

	Organizm& setPozycja(int x, int y);
};
