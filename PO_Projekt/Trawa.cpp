#include "Trawa.h"

const double Trawa::POTOMSTWO_SZANSA = 0.1;

Trawa::Trawa(int x, int y, ReferencjaSwiata& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}
Trawa::Trawa(ReferencjaSwiata& swiat):
	Roslina(SILA, POTOMSTWO_COOLDOWN, 0, 0, swiat)
{}

Trawa::~Trawa()
{
	cout << "Trawa Papa" << endl;
}

void Trawa::akcja()
{
	if (gotowyNaPotomstwo())
	{
		oczekujacePotomstwo = true;
		resetPotomstwoCooldown();
	}
	potomstwoCooldownWDol();
}
void Trawa::kolizja(Organizm& atakujacy)
{
	this->zyje = false;
}
void Trawa::rysowanie()
{
	cout << ZNAK;
}
void Trawa::stworzPotomstwo()
{
	
}
string Trawa::getNazwa() const
{
	return "Trawa";
}

void Trawa::potomstwoCooldownWDol()
{
	if (POTOMSTWO_SZANSA * 1000 > rand() % 1000)
		potomstwoCooldown = potomstwoCooldown > 0 ? potomstwoCooldown - 1 : potomstwoCooldown;
}
