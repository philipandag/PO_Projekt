#pragma once
#include "Organizm.h"



class Roslina :
    public Organizm
{
	const int precyzjaLosowania = 1000;
	const double POTOMSTWO_SZANSA;
public:
	Roslina(int sila, int potomstwoCooldown, double potomstwoSzansa, int x, int y, SwiatRef& swiat);

	virtual void akcja();
	virtual void kolizja(Organizm& atakujacy) override;
	bool gotowyNaPotomstwo() const override;
	string toString() override;
	void operator<<(ifstream& f) override;
};

