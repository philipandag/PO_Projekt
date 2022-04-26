#include "Antylopa.h"

Antylopa::Antylopa(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Zwierze(sila == -1 ? SILA : sila, INICJATYWA, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, x, y, swiat)
{}
Antylopa::Antylopa(int x, int y, SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}
Antylopa::Antylopa(SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}


void Antylopa::akcja()
{
	potomstwoCooldownWDol();
	Kierunek k;
	k.losuj();

	int newX = x + 2 * k.getDx();
	int newY = y + 2 * k.getDy();

	przemieszczenie(newX, newY);
}

void Antylopa::kolizja(Organizm& atakujacy)
{
	if (instanceof<Antylopa>(atakujacy))
	{
		if (gotowyNaPotomstwo() && atakujacy.gotowyNaPotomstwo())
			stworzPotomstwo();
	}
	else if(rand() % 2 == 0)
	{
		walka(atakujacy);
	}
	else
	{
		sprobujPrzemiescicWOkolicy(x, y);
	}
}

void Antylopa::stworzPotomstwo()
{
	Antylopa* potomstwo = new Antylopa(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

void Antylopa::rysowanie()
{
	cout << ZNAK;
}

char Antylopa::getZnak()
{
	return ZNAK;
}

string Antylopa::getNazwa() const
{
	return "Antylopa";
}

void Antylopa::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}