#pragma once
#include "Zwierze.h"

class Wilk : 
	public Zwierze
{
	static const int SILA = 9;
	static const int INICJATYWA = 5;
	static const int POTOMSTWO_COOLDOWN = 5;
	static const char ZNAK = 'W';

public:
	Wilk(int x, int y, ReferencjaSwiata& swiat);
	Wilk(ReferencjaSwiata& swiat);
	~Wilk();
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void stworzPotomstwo() override;
	void rysowanie() override;
	char getZnak() override;
	void resetPotomstwoCooldown() override;
	string getNazwa() const override;
};

