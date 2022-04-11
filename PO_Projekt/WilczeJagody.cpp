#include "WilczeJagody.h"

const double WilczeJagody::POTOMSTWO_SZANSA = 0.3;

WilczeJagody::WilczeJagody(int x, int y, ReferencjaSwiata& swiat):
	Roslina(SILA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}
WilczeJagody::WilczeJagody(ReferencjaSwiata& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, 0, 0, swiat)
{}

WilczeJagody::~WilczeJagody()
{
	cout << "WilczeJagody Papa" << endl;
}

void WilczeJagody::akcja()
{

}

void WilczeJagody::kolizja(Organizm& atakujacy)
{
	atakujacy.zabij();
	this->zyje = false;
}

void WilczeJagody::rysowanie()
{
	cout << ZNAK;
}

char WilczeJagody::getZnak()
{
	return ZNAK;
}

void WilczeJagody::stworzPotomstwo()
{

}

string WilczeJagody::getNazwa() const
{
	return "WilczeJagody";
}

void WilczeJagody::potomstwoCooldownWDol()
{
	if (POTOMSTWO_SZANSA * 1000 < rand() % 1000)
		potomstwoCooldown = 0;
}
