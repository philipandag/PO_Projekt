#include "Wilk.h"

Wilk::Wilk(int x, int y, ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}

Wilk::Wilk(ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

Wilk::~Wilk()
{
	cout << "Wilk Papa" << endl;
}

void Wilk::akcja()
{
	potomstwoCooldownWDol();
	Kierunek k;
	k.losuj();

	int newX = x + k.getDx();
	int newY = y - k.getDy();

	przemieszczenie(newX, newY);
}

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