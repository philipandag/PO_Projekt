#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, int potomstwoCooldown, int x, int y, SwiatRef& swiat) :
	Organizm(sila, inicjatywa, potomstwoCooldown, x, y, swiat)
{}
Zwierze::Zwierze(int sila, int inicjatywa, int potomstwoCooldown, SwiatRef& swiat) :
	Organizm(sila, inicjatywa, potomstwoCooldown, swiat)
{}
Zwierze::Zwierze(int sila, int inicjatywa, SwiatRef& swiat) :
	Organizm(sila, inicjatywa, -1, swiat)
{}

void Zwierze::akcja()
{
	potomstwoCooldownWDol();
	Kierunek k;
	k.losuj();

	int newX = x + k.getDx();
	int newY = y - k.getDy();

	przemieszczenie(newX, newY);
}

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

		if(getZyje() && plansza.wolne(x, y))
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

string Zwierze::toString()
{
	string reprezentacja = Organizm::toString();
	reprezentacja.append(" " + to_string(getPotomstwoCooldown()));
	reprezentacja.append(" " + to_string(getSila()));
	return reprezentacja;
}

void Zwierze::operator<<(ifstream& f)
{
	Organizm::operator<<(f);
	int pc = -1, s = -1;
	if(f >> pc && pc >= 0)
		potomstwoCooldown = pc;
	if (f >> s && s >= 0)
		sila = s;
}