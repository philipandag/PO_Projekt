#include "Antylopa.h"

Antylopa::Antylopa(int x, int y, Swiat& swiat) :
	Zwierze(4, 4, x, y, swiat)
{}

Antylopa::Antylopa(Swiat& swiat) :
	Zwierze(4, 4, swiat)
{}

Antylopa::~Antylopa()
{
	cout << "Antylopa papa" << endl;
}

void Antylopa::akcja()
{
	cout << "Antylopa akcja" << endl;
}

void Antylopa::kolizja()
{

}

void Antylopa::rysowanie()
{
	cout << "A";
}