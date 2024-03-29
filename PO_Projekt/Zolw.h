#pragma once
#include "Zwierze.h"

class Zolw :
	public Zwierze
{
	static const int SILA = 2;
	static const int INICJATYWA = 1;
	static const int POTOMSTWO_COOLDOWN = 8;
	static const char ZNAK = 'Z';

public:
	Zolw(int x, int y, int cooldown, int sila, SwiatRef& swiat);
	Zolw(int x, int y, SwiatRef& swiat);
	Zolw(SwiatRef& swiat);
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void rysowanie() override;
	char getZnak() override;
	void stworzPotomstwo() override;
	void resetPotomstwoCooldown() override;
	string getNazwa() const override;
};

