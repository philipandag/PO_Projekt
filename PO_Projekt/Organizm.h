#pragma once
#include <iostream>
using namespace std;

class Swiat;

class Organizm
{
protected:
	int sila;
	int inicjatywa;
	int x;
	int y;
	bool zyje;
	Swiat& swiat;

public:
	Organizm(int sila, int inicjatywa, int x, int y, Swiat& swiat);
	Organizm(int sila, int inicjatywa, Swiat& swiat);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm& atakujacy) = 0;
	virtual void rysowanie() = 0;

	Organizm& setPozycja(int x, int y);

	int getX() const;
	int getY() const;
	bool getZyje() const;
	void toggleZyje();
	int getSila() const;
	int getInicjatywa() const;

	bool operator<(Organizm& other) const;
	bool operator>(Organizm& other) const;

};
