#include "Zolw.h"

Zolw::Zolw(int x, int y, Swiat& swiat) :
	Zwierze(2, 1, x, y, swiat)
{}

Zolw::Zolw(Swiat& swiat) :
	Zwierze(11, 4, swiat)
{}

Zolw::~Zolw()
{
	cout << "Zolw Papa" << endl;
}

void Zolw::akcja()
{
	cout << "Zolw Akcja" << endl;
}

void Zolw::kolizja(Organizm& atakujacy)
{

}

void Zolw::rysowanie()
{
	cout << "Z";
}