#include "Lis.h"

Lis::Lis(int x, int y, ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}

Lis::Lis(ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

Lis::~Lis()
{
	cout << "Lis Papa" << endl;
}

void Lis::akcja()
{
	Kierunek ruch;
	int x, y;
	int proby = 0;
	bool znaleziono = false;
	ruch.losuj();
	do 
	{
		ruch++;
		proby++;
		x = this->x + ruch.getDx();
		y = this->y + ruch.getDy();
		PlanszaRef& plansza = swiat.getPlansza();
		ListaOrganizmowRef& organizmy = swiat.getOrganizmy();
		if (plansza.naPlanszy(x, y))
			if (plansza[x][y] == nullptr || organizmy[plansza[x][y]].getSila() <= this->sila)
				znaleziono = true;
	} while (!znaleziono && proby < 10);

	if(znaleziono)
		przemieszczenie(ruch.getDx(), ruch.getDy());

	potomstwoCooldownWDol();
}

void Lis::kolizja(Organizm& atakujacy)
{
	if (instanceof<Lis>(atakujacy))
	{
		if (gotowyNaPotomstwo() && atakujacy.gotowyNaPotomstwo())
			atakujacy.toggleOczekujacePotomstwo();
	}
	else
		walka(atakujacy);
}

void Lis::stworzPotomstwo()
{

}

void Lis::rysowanie()
{
	cout << ZNAK;
}

string Lis::getNazwa() const
{
	return "Lis";
}

void Lis::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}