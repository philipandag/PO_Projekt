#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, int potomstwoCooldown, int x, int y, ReferencjaSwiata& swiat) :
	Organizm(sila, inicjatywa, potomstwoCooldown, x, y, swiat)
{}
Zwierze::Zwierze(int sila, int inicjatywa, int potomstwoCooldown, ReferencjaSwiata& swiat) :
	Organizm(sila, inicjatywa, potomstwoCooldown, swiat)
{}
Zwierze::Zwierze(int sila, int inicjatywa, ReferencjaSwiata& swiat) :
	Organizm(sila, inicjatywa, -1, swiat)
{}


void Zwierze::walka(Organizm& atakujacy)
{
	if (atakujacy.getSila() >= this->sila)
	{
		zabij();
	}
	else
	{
		atakujacy.zabij();
	}
}

Organizm& Zwierze::przemieszczenie(int x, int y)
{
	if (plansza.naPlanszy(x, y))
	{
		if (!plansza.wolne(x, y))
		{
			swiat.dodajLog(raportZKolizji(organizmy[plansza[x][y]]));
			organizmy[plansza[x][y]].kolizja(*this);
		}

		if(plansza.wolne(x, y))
		{
			plansza.unset(this->x, this->y);
			plansza.set(x, y, *this->iterator);
			this->x = x;
			this->y = y;
			swiat.dodajLog(raportZRuchu());
		}
	}

	return *this;
}

void Zwierze::potomstwoCooldownWDol()
{
	potomstwoCooldown = potomstwoCooldown > 0 ? potomstwoCooldown - 1 : potomstwoCooldown;
}
