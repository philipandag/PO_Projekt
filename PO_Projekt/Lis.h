#pragma once
#include "Zwierze.h"

class Lis :
    public Zwierze
{
	static const int SILA = 3;
	static const int INICJATYWA = 7;
	static const int POTOMSTWO_COOLDOWN = 5;
	static const char ZNAK = 'L';

public:
    Lis(int x, int y, int cooldown, int sila, SwiatRef& swiat);
    Lis(int x, int y, SwiatRef& swiat);
	Lis(SwiatRef& swiat);
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void stworzPotomstwo() override;
	void rysowanie() override;
	char getZnak() override;
	void resetPotomstwoCooldown() override;
	string getNazwa() const override;
};

