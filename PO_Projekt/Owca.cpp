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
	PlanszaRef& plansza = swiat.getPlansza();
	ListaOrganizmowRef& organizmy = swiat.getOrganizmy();
	Kierunek k;
	k.losuj();

	int newX = x + k.getDx();
	int newY = y = k.getDy();

	if (plansza.naPlanszy(x, y))
	{
		przemieszczenie(k.getDx(), k.getDy());
		if (!plansza.wolne(x, y))
			organizmy[plansza[x][y]].kolizja(*this);
	}

}

void Owca::kolizja(Organizm& atakujacy)
{
	if (instanceof<Owca>(atakujacy))
	{
		if (gotowyNaPotomstwo() && atakujacy.gotowyNaPotomstwo())
			atakujacy.toggleOczekujacePotomstwo();
	}
	else
		walka(atakujacy);
}

void Owca::stworzPotomstwo()
{

}

void Owca::rysowanie()
{
	cout << ZNAK;
}

string Owca::getNazwa() const
{
	return "Owca";
}

void Owca::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}