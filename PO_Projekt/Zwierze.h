#pragma once
#include "Organizm.h"
class Zwierze : public Organizm
{
public:

	Zwierze(int sila, int inicjatywa, int potomstwoCooldown, int x, int y, SwiatRef& swiat);
	Zwierze(int sila, int inicjatywa, int potomstwoCooldown, SwiatRef& swiat);
	Zwierze(int sila, int inicjatywa, SwiatRef& swiat);

	Organizm& przemieszczenie(int x, int y);
	virtual void akcja() override;
	void walka(Organizm& atakujacy);

	string toString() override;
	void operator<<(ifstream& f) override;

};

