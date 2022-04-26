#include "Guarana.h"

const double Guarana::POTOMSTWO_SZANSA = 0.5;

Guarana::Guarana(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Roslina(sila == -1 ? SILA : sila, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, POTOMSTWO_SZANSA, x, y, swiat)
{}
Guarana::Guarana(int x, int y, SwiatRef& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, x, y, swiat)
{}
Guarana::Guarana(SwiatRef& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, 0, 0, swiat)
{}

void Guarana::kolizja(Organizm& atakujacy)
{
	atakujacy.changeSila(3);
	zabij();
}

void Guarana::rysowanie()
{
	cout << ZNAK;
}

char Guarana::getZnak()
{
	return ZNAK;
}

void Guarana::stworzPotomstwo()
{
	Guarana* potomstwo = new Guarana(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

string Guarana::getNazwa() const
{
	return "Guarana";
}

void Guarana::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}
