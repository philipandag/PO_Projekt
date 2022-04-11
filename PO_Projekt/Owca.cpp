#include "Owca.h"

Owca::Owca(int x, int y, ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}

Owca::Owca(ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

Owca::~Owca()
{
	cout << "Owca Papa" << endl;
}

void Owca::akcja()
{
	potomstwoCooldownWDol();
	Kierunek k;
	k.losuj();

	int newX = x + k.getDx();
	int newY = y - k.getDy();

	przemieszczenie(newX, newY);
}

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
	if (!potomstwo->sprobujPostawicWOkolicy(x, y))
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