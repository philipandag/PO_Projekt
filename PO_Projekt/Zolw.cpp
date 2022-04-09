#include "Zolw.h"

Zolw::Zolw(int x, int y, ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}

Zolw::Zolw(ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

Zolw::~Zolw()
{
	cout << "Zolw Papa" << endl;
}

void Zolw::akcja()
{

}

void Zolw::kolizja(Organizm& atakujacy)
{
	if (atakujacy.getSila() >= this->sila)
		zabij();
	else
		atakujacy.zabij();
}

void Zolw::stworzPotomstwo()
{

}

void Zolw::rysowanie()
{
	cout << ZNAK;
}

string Zolw::getNazwa() const
{
	return "Zolw";
}

void Zolw::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}