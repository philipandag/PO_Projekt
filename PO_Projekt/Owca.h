#pragma once
#include "Zwierze.h"

class Owca :
    public Zwierze
{
	static const int SILA = 4;
	static const int INICJATYWA = 4;
	static const int POTOMSTWO_COOLDOWN = 3;
	static const char ZNAK = 'O';

public:
    Owca(int x, int y, ReferencjaSwiata& swiat);
	Owca(ReferencjaSwiata& swiat);
	~Owca();
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void stworzPotomstwo() override;
	void rysowanie() override;
	char getZnak() override;
	void resetPotomstwoCooldown() override;
	string getNazwa() const override;
};

