#pragma once
#include "Zwierze.h"
class Owca :
    public Zwierze
{

public:
    Owca(int x, int y, Swiat& swiat);
	Owca(Swiat& swiat);
	~Owca();
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void rysowanie() override;
};

