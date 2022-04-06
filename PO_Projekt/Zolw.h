#pragma once
#include "Zwierze.h"
class Zolw : 
	public Zwierze
{

public:
	Zolw(int x, int y, Swiat& swiat);
	Zolw(Swiat& swiat);
	~Zolw();
	void akcja() override;
	void kolizja() override;
	void rysowanie() override;
};

