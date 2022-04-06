#include "Lis.h"

Lis::Lis(int x, int y, Swiat& swiat) :
	Zwierze(3, 7, x, y, swiat)
{}

Lis::Lis(Swiat& swiat) :
	Zwierze(11, 4, swiat)
{}

Lis::~Lis()
{
	cout << "Lis Papa" << endl;
}

void Lis::akcja()
{
	cout << "Lis Akcja" << endl;
}

void Lis::kolizja()
{

}

void Lis::rysowanie()
{
	cout << "L";
}