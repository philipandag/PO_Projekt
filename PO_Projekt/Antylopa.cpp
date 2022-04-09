#include "Antylopa.h"

Antylopa::Antylopa(int x, int y, ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}

Antylopa::Antylopa(ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

Antylopa::~Antylopa()
{
	cout << "Antylopa papa" << endl;
}

void Antylopa::akcja()
{

}

void Antylopa::kolizja(Organizm& atakujacy)
{

}

void Antylopa::stworzPotomstwo()
{

}

void Antylopa::rysowanie()
{
	cout << ZNAK;
}

string Antylopa::getNazwa() const
{
	return "Antylopa";
}

void Antylopa::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}