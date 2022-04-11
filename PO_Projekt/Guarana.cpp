#include "Guarana.h"

const double Guarana::POTOMSTWO_SZANSA = 0.5;

Guarana::Guarana(int x, int y, ReferencjaSwiata& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}
Guarana::Guarana(ReferencjaSwiata& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, 0, 0, swiat)
{}

Guarana::~Guarana()
{
	cout << "Guarana Papa" << endl;
}

void Guarana::akcja()
{

}
void Guarana::kolizja(Organizm& atakujacy)
{
	atakujacy.changeSila(3);
	this->zabij();
}
void Guarana::rysowanie()
{
	cout << ZNAK;
}

char Guarana::getZnak()
{
	return ZNAK;
}

void Guarana::stworzPotomstwo()
{

}
string Guarana::getNazwa() const
{
	return "Guarana";
}

void Guarana::potomstwoCooldownWDol()
{
	if (POTOMSTWO_SZANSA * 1000 < rand() % 1000)
		potomstwoCooldown = 0;
}
