#include "Trawa.h"

const double Trawa::POTOMSTWO_SZANSA = 0.3;

Trawa::Trawa(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Roslina(sila == -1 ? SILA : sila, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, POTOMSTWO_SZANSA, x, y, swiat)
{}
Trawa::Trawa(int x, int y, SwiatRef& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, x, y, swiat)
{}
Trawa::Trawa(SwiatRef& swiat):
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, 0, 0, swiat)
{}

void Trawa::rysowanie()
{
	cout << ZNAK;
}

char Trawa::getZnak()
{
	return ZNAK;
}

void Trawa::stworzPotomstwo()
{
	Trawa* potomstwo = new Trawa(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}
string Trawa::getNazwa() const
{
	return "Trawa";
}

void Trawa::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}