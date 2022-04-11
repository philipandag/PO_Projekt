#include "Czlowiek.h"

Czlowiek::Czlowiek(int x, int y, ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat),
	umiejetnoscCooldown(UMIEJETNOSC_COOLDOWN)
{}

Czlowiek::Czlowiek(ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat),
	umiejetnoscCooldown(UMIEJETNOSC_COOLDOWN)
{}

Czlowiek::~Czlowiek()
{
	cout << "Czlowiek Papa" << endl;
}

string Czlowiek::getNazwa() const
{
	return "Czlowiek";
}

void Czlowiek::umiejetnoscCooldownWDol()
{
	umiejetnoscCooldown > 0 ? --umiejetnoscCooldown : NULL;
	if (sila > SILA)
		sila--;
}

void Czlowiek::akcja()
{
	potomstwoCooldownWDol();
	umiejetnoscCooldownWDol();

	cout << "Czlowiek czeka na ruch\n";
	char ruch;
	Kierunek k;

	while (true)
	{
		ruch = _getch();
		switch (ruch)
		{
		case 'w':
		case 'W':
			k = Kierunek::N;
			break;
		case 's':
		case 'S':
			k = Kierunek::S;
			break;
		case 'a':
		case 'A':
			k = Kierunek::W;
			break;
		case 'd':
		case 'D':
			k = Kierunek::E;
			break;
		case ' ':
			specjalnaUmiejetnosc();

		default:
			continue;
		}
		break;
	}

	przemieszczenie(x + k.getDx(), y + k.getDy());
}

void Czlowiek::kolizja(Organizm& atakujacy)
{
	if (instanceof<Czlowiek>(atakujacy))
	{
		if (gotowyNaPotomstwo() && atakujacy.gotowyNaPotomstwo())
			stworzPotomstwo();
	}
	else
		walka(atakujacy);
}

void Czlowiek::stworzPotomstwo()
{
	Czlowiek* potomstwo = new Czlowiek(swiat);
	if (!potomstwo->sprobujPostawicWOkolicy(x, y))
		delete potomstwo;
	else
	{
		resetPotomstwoCooldown();
		swiat.dodajLog(potomstwo->raportZNarodzin());
	}
}

void Czlowiek::rysowanie()
{
	cout << ZNAK;
}

char Czlowiek::getZnak()
{
	return ZNAK;
}

void Czlowiek::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}

bool Czlowiek::specjalnaUmiejetnosc()
{
	if (umiejetnoscCooldown == 0)
	{
		sila = 10;
		umiejetnoscCooldown = UMIEJETNOSC_COOLDOWN;
		swiat.dodajLog("Czlowiek uzywa umiejetnosci Magiczny Eliksir!");
		cout << "Czlowiek uzywa umiejetnosci Magiczny Eliksir!\n";
		return true;
	}
	cout << "Czlowiek nie moze jeszcze uzyc Magiczny Eliksir przez " << umiejetnoscCooldown << " tur\n";
	return false;
}