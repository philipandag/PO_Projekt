#include "CyberOwca.h"

CyberOwca::CyberOwca(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Zwierze(sila == -1 ? SILA : sila, INICJATYWA, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, x, y, swiat)
{}
CyberOwca::CyberOwca(int x, int y, SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}

CyberOwca::CyberOwca(SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

void CyberOwca::kolizja(Organizm& atakujacy)
{
	if (instanceof<CyberOwca>(atakujacy))
	{
		if (gotowyNaPotomstwo() && atakujacy.gotowyNaPotomstwo())
			stworzPotomstwo();
	}
	else
		walka(atakujacy);
}

void CyberOwca::stworzPotomstwo()
{
	CyberOwca* potomstwo = new CyberOwca(swiat);
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

void CyberOwca::rysowanie()
{
	cout << ZNAK;
}

char CyberOwca::getZnak()
{
	return ZNAK;
}

string CyberOwca::getNazwa() const
{
	return "Cyber Owca";
}

void CyberOwca::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}