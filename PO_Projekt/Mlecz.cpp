#include "Mlecz.h"

const double Mlecz::POTOMSTWO_SZANSA = 0.2;

Mlecz::Mlecz(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Roslina(sila == -1 ? SILA : sila, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, POTOMSTWO_SZANSA, x, y, swiat)
{}
Mlecz::Mlecz(int x, int y, SwiatRef& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, x, y, swiat)
{}
Mlecz::Mlecz(SwiatRef& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, 0, 0, swiat)
{}

void Mlecz::akcja()
{
	bool udaloSie = false;
	for (int i = 0; i < 3; i++)
	{
		if (gotowyNaPotomstwo())
		{
			stworzPotomstwo();
			udaloSie = true;
		}
	}
	if (udaloSie)
		resetPotomstwoCooldown();
	else
		potomstwoCooldownWDol();
}

void Mlecz::rysowanie()
{
	cout << ZNAK;
}

char Mlecz::getZnak()
{
	return ZNAK;
}

void Mlecz::stworzPotomstwo()
{
	Mlecz* potomstwo = new Mlecz(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

string Mlecz::getNazwa() const
{
	return "Mlecz";
}

void Mlecz::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}