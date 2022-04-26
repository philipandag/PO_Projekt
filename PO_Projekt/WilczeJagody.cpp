#include "WilczeJagody.h"

const double WilczeJagody::POTOMSTWO_SZANSA = 0.2;

WilczeJagody::WilczeJagody(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Roslina(sila == -1 ? SILA : sila, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, POTOMSTWO_SZANSA, x, y, swiat)
{}
WilczeJagody::WilczeJagody(int x, int y, SwiatRef& swiat):
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, x, y, swiat)
{}
WilczeJagody::WilczeJagody(SwiatRef& swiat) :
	Roslina(SILA, POTOMSTWO_COOLDOWN, POTOMSTWO_SZANSA, 0, 0, swiat)
{}

void WilczeJagody::kolizja(Organizm& atakujacy)
{
	zabij();
	atakujacy.zabij();
}

void WilczeJagody::rysowanie()
{
	cout << ZNAK;
}

char WilczeJagody::getZnak()
{
	return ZNAK;
}

void WilczeJagody::stworzPotomstwo()
{
	WilczeJagody* potomstwo = new WilczeJagody(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

string WilczeJagody::getNazwa() const
{
	return "WilczeJagody";
}

void WilczeJagody::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}