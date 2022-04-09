#include "Mlecz.h"

const double Mlecz::POTOMSTWO_SZANSA = 1;

Mlecz::Mlecz(int x, int y, ReferencjaSwiata& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}
Mlecz::Mlecz(ReferencjaSwiata& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, 0, 0, swiat)
{}

Mlecz::~Mlecz()
{
	cout << "Mlecz Papa" << endl;
}

void Mlecz::akcja()
{

}
void Mlecz::kolizja(Organizm& atakujacy)
{

}
void Mlecz::rysowanie()
{
	cout << ZNAK;
}
void Mlecz::stworzPotomstwo()
{

}
string Mlecz::getNazwa() const
{
	return "Mlecz";
}

void Mlecz::potomstwoCooldownWDol()
{
	if (POTOMSTWO_SZANSA * 1000 < rand() % 1000)
		potomstwoCooldown = 0;
}

