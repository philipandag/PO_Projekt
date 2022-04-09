#pragma once
#include "Organizm.h"
class Roslina :
    public Organizm
{
	static const int POTOMSTWO_COOLDOWN = 1;
public:
	Roslina(int sila, int potomstwoCooldown, int x, int y, ReferencjaSwiata& swiat);

	void akcja()
	{

	}

	void kolizja(Organizm& atakujacy) override
	{
		atakujacy.zabij();
	}

	void resetPotomstwoCooldown() override
	{
		potomstwoCooldown = POTOMSTWO_COOLDOWN;
	}
};

