#include "BarszczSosnowskiego.h"

const double BarszczSosnowskiego::POTOMSTWO_SZANSA = 0.1;

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Roslina(sila == -1 ? SILA : sila, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, POTOMSTWO_SZANSA, 0, 0, swiat)
{}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, SwiatRef& swiat):
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, x, y, swiat)
{}

BarszczSosnowskiego::BarszczSosnowskiego(SwiatRef& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, 0, 0, swiat)
{}

void BarszczSosnowskiego::akcja()
{
	Kierunek k;
	int x, y;

	for (int i = 0; i < Kierunek::ILOSC_KIERUNKOW; i++)
	{
		x = this->x + k.getDx();
		y = this->y + k.getDy();
		if ( plansza.naPlanszy(x, y) && !(plansza.wolne(x, y) || instanceof<CyberOwca>(organizmy[plansza[x][y]]) || instanceof<BarszczSosnowskiego>(organizmy[plansza[x][y]])))
			organizmy[plansza[x][y]].zabij();
		k++;
	}

	if (gotowyNaPotomstwo())
		stworzPotomstwo();
	potomstwoCooldownWDol();
}

void BarszczSosnowskiego::kolizja(Organizm& atakujacy)
{
	zabij();
	if (!instanceof<CyberOwca>(atakujacy))
		atakujacy.zabij();
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
	BarszczSosnowskiego* potomstwo = new BarszczSosnowskiego(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}
string BarszczSosnowskiego::getNazwa() const
{
	return "BarszczSosnowskiego";
}

void BarszczSosnowskiego::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}