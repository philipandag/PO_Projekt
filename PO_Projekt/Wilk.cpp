#include "Wilk.h"

Wilk::Wilk(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Zwierze(sila == -1 ? SILA : sila, INICJATYWA, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, x, y, swiat)
{}
Wilk::Wilk(int x, int y, SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}
Wilk::Wilk(SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

void Wilk::kolizja(Organizm& atakujacy)
{
	if (instanceof<Wilk>(atakujacy))
	{
		if (gotowyNaPotomstwo() && atakujacy.gotowyNaPotomstwo())
			stworzPotomstwo();
	}
	else
		walka(atakujacy);
}

void Wilk::stworzPotomstwo()
{
	Wilk* potomstwo = new Wilk(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

void Wilk::rysowanie()
{
	cout << ZNAK;
}

char Wilk::getZnak()
{
	return ZNAK;
}

string Wilk::getNazwa() const
{
	return "Wilk";
}

void Wilk::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}