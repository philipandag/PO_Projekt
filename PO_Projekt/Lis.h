#pragma once
#include "Zwierze.h"
class Lis :
    public Zwierze
{

public:
    Lis(int x, int y, Swiat& swiat);
	Lis(Swiat& swiat);
	~Lis();
	void akcja() override;
	void kolizja() override;
	void rysowanie() override;
};

