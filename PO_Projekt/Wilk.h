#pragma once
#include "Zwierze.h"
class Wilk : 
	public Zwierze
{

public:
	Wilk(int x, int y, Swiat& swiat);
	Wilk(Swiat& swiat);
	~Wilk();
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void rysowanie() override;
};

