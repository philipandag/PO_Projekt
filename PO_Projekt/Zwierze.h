#pragma once
#include "Organizm.h"
class Zwierze : public Organizm
{
protected:

	void potomstwoCooldownWDol() override;
public:

	Zwierze(int sila, int inicjatywa, int potomstwoCooldown, int x, int y, ReferencjaSwiata& swiat);
	Zwierze(int sila, int inicjatywa, int potomstwoCooldown, ReferencjaSwiata& swiat);
	Zwierze(int sila, int inicjatywa, ReferencjaSwiata& swiat);

	Organizm& przemieszczenie(int x, int y);
	void walka(Organizm& atakujacy);
};

