#include "Zolw.h"

Zolw::Zolw(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Zwierze(sila == -1 ? SILA : sila, INICJATYWA, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, x, y, swiat)
{}
Zolw::Zolw(int x, int y, SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}
Zolw::Zolw(SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

void Zolw::akcja()
{
	potomstwoCooldownWDol();
	if (rand() % 4 == 0)
	{
		Kierunek k;
		k.losuj();

		int newX = x + k.getDx();
		int newY = y - k.getDy();

		przemieszczenie(newX, newY);
	}
}

void Zolw::kolizja(Organizm& atakujacy)
{
	if (atakujacy.getSila() >= 5)
	{
		if (atakujacy.getSila() >= this->sila)
			zabij();
		else
			atakujacy.zabij();
	}
	else
		swiat.dodajLog("Zolw odbija atak");
}

void Zolw::stworzPotomstwo()
{
	Zolw* potomstwo = new Zolw(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

void Zolw::rysowanie()
{
	cout << ZNAK;
}

char Zolw::getZnak()
{
	return ZNAK;
}

string Zolw::getNazwa() const
{
	return "Zolw";
}

void Zolw::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}