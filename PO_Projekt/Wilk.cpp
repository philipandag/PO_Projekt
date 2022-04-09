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

}

void Wilk::kolizja(Organizm& atakujacy)
{
	walka(atakujacy);
}

void Wilk::stworzPotomstwo()
{

}

void Wilk::rysowanie()
{
	cout << ZNAK;
}

string Wilk::getNazwa() const
{
	return "Wilk";
}

void Wilk::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}