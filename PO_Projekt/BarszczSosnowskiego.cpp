#include "BarszczSosnowskiego.h"

const double BarszczSosnowskiego::POTOMSTWO_SZANSA = 0.1;

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, ReferencjaSwiata& swiat):
	Roslina(SILA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}

BarszczSosnowskiego::BarszczSosnowskiego(ReferencjaSwiata& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, 0, 0, swiat)
{}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
	cout << "BarszczSosnowskiego Papa" << endl;
}

void BarszczSosnowskiego::akcja()
{

}
void BarszczSosnowskiego::kolizja(Organizm& atakujacy)
{

}
void BarszczSosnowskiego::rysowanie()
{
	cout << ZNAK;
}

char BarszczSosnowskiego::getZnak()
{
	return ZNAK;
}

void BarszczSosnowskiego::stworzPotomstwo()
{

}
string BarszczSosnowskiego::getNazwa() const
{
	return "BarszczSosnowskiego";
}

void BarszczSosnowskiego::potomstwoCooldownWDol()
{
	if (POTOMSTWO_SZANSA * 1000 < rand() % 1000)
		potomstwoCooldown = 0;
}

