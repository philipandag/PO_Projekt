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
	potomstwoCooldownWDol();
	Kierunek k;
	k.losuj();

	int newX = x + k.getDx();
	int newY = y - k.getDy();

	przemieszczenie(newX, newY);
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

char Antylopa::getZnak()
{
	return ZNAK;
}

string Antylopa::getNazwa() const
{
	return "Antylopa";
}

void Antylopa::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}