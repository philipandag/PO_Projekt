#include "Lis.h"

Lis::Lis(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Zwierze(sila == -1 ? SILA : sila, INICJATYWA, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, x, y, swiat)
{}
Lis::Lis(int x, int y, SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}
Lis::Lis(SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}


void Lis::akcja()
{
	potomstwoCooldownWDol();

	Kierunek k;
	int newX, newY;
	int proby = 0;
	bool znaleziono = false;
	k.losuj();
	for(int i = 0; !znaleziono && i < Kierunek::ILOSC_KIERUNKOW; i++)
	{
		k++;
		proby++;
		newX = this->x + k.getDx();
		newY = this->y + k.getDy();
		if (plansza.naPlanszy(newX, newY))
			if (plansza[newX][newY] == nullptr || organizmy[plansza[newX][newY]].getSila() <= this->sila)
				znaleziono = true;
	}

	if(znaleziono)
		przemieszczenie(newX, newY);
}

void Lis::kolizja(Organizm& atakujacy)
{
	if (instanceof<Lis>(atakujacy))
	{
		if (gotowyNaPotomstwo() && atakujacy.gotowyNaPotomstwo())
			stworzPotomstwo();
	}
	else
		walka(atakujacy);
}

void Lis::stworzPotomstwo()
{
	Lis* potomstwo = new Lis(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

void Lis::rysowanie()
{
	cout << ZNAK;
}

char Lis::getZnak()
{
	return ZNAK;
}

string Lis::getNazwa() const
{
	return "Lis";
}

void Lis::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}