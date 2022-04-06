#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, int x, int y, Swiat& swiat) :
	sila(sila),
	inicjatywa(inicjatywa),
	x(x),
	y(y),
	swiat(swiat)
{}

Organizm::Organizm(int sila, int inicjatywa, Swiat& swiat) :
	sila(sila),
	inicjatywa(inicjatywa),
	x(0),
	y(0),
	swiat(swiat)
{}



Organizm& Organizm::setPozycja(int x, int y)
{
	this->x = x;
	this->y = y;
	return *this;
}
