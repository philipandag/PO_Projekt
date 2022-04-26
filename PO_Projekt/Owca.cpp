#include "Owca.h"

Owca::Owca(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Zwierze(sila == -1 ? SILA : sila, INICJATYWA, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, x, y, swiat)
{}
Owca::Owca(int x, int y, SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}
Owca::Owca(SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

void Owca::kolizja(Organizm& atakujacy)
{
	if (instanceof<Owca>(atakujacy))
	{
		if (gotowyNaPotomstwo() && atakujacy.gotowyNaPotomstwo())
			stworzPotomstwo();
	}
	else
		walka(atakujacy);
}

void Owca::stworzPotomstwo()
{
	Owca* potomstwo = new Owca(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

void Owca::rysowanie()
{
	cout << ZNAK;
}

char Owca::getZnak()
{
	return ZNAK;
}

string Owca::getNazwa() const
{
	return "Owca";
}

void Owca::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}