#pragma once
#include "Zwierze.h"
#include <conio.h>

class Czlowiek : public Zwierze
{

public:
	Czlowiek(int x, int y, Swiat& swiat);
	Czlowiek(Swiat& swiat);
	~Czlowiek();
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void rysowanie() override;
};

