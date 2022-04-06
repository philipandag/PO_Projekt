#include "Owca.h"

Owca::Owca(int x, int y, Swiat& swiat) :
	Zwierze(4, 4, x, y, swiat)
{}

Owca::Owca(Swiat& swiat) :
	Zwierze(11, 4, swiat)
{}

Owca::~Owca()
{
	cout << "Owca Papa" << endl;
}

void Owca::akcja()
{
	cout << "Owca Akcja" << endl;
}

void Owca::kolizja(Organizm& atakujacy)
{

}

void Owca::rysowanie()
{
	cout << "O";
}