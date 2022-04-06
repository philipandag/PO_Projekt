#include "Wilk.h"

Wilk::Wilk(int x, int y, Swiat& swiat) :
	Zwierze(9, 5, x, y, swiat)
{}

Wilk::Wilk(Swiat& swiat) :
	Zwierze(11, 4, swiat)
{}

Wilk::~Wilk()
{
	cout << "Wilk Papa" << endl;
}

void Wilk::akcja()
{
	cout << "Wilk Akcja" << endl;
}

void Wilk::kolizja(Organizm& atakujacy)
{

}

void Wilk::rysowanie()
{
	cout << "W";
}