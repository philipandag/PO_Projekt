#include "Czlowiek.h"

Czlowiek::Czlowiek(int x, int y, int cooldown, int sila, SwiatRef& swiat) :
	Zwierze(sila == -1 ? SILA : sila, INICJATYWA, cooldown == -1 ? POTOMSTWO_COOLDOWN : cooldown, x, y, swiat),
	umiejetnoscCooldown(0),
	dodatkowaSila(0)
{}
Czlowiek::Czlowiek(int x, int y, SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat),
	umiejetnoscCooldown(0),
	dodatkowaSila(0)
{}
Czlowiek::Czlowiek(SwiatRef& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat),
	umiejetnoscCooldown(0),
	dodatkowaSila(0)
{}


string Czlowiek::getNazwa() const
{
	return "Czlowiek";
}

void Czlowiek::umiejetnoscCooldownWDol()
{
	if (umiejetnoscCooldown > 0)
		--umiejetnoscCooldown;
	if (dodatkowaSila > 0)
	{
		dodatkowaSila--;
		sila--;
	}
}

void Czlowiek::akcja()
{
	potomstwoCooldownWDol();
	umiejetnoscCooldownWDol();

	cout << "Czlowiek czeka na ruch (strzalki), sila: " << sila <<"\n";
	char ruch;
	Kierunek k;

	while (true)
	{
		ruch = _getch();
		switch (ruch)
		{
		case KEY_UP:
			k = Kierunek::N;
			break;
		case KEY_DOWN:
			k = Kierunek::S;
			break;
		case KEY_LEFT:
			k = Kierunek::W;
			break;
		case KEY_RIGHT:
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
	if (!potomstwo->sprobujDodacWOkolicy(x, y))
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
		dodatkowaSila = sila < UMIEJETNOSC_MAX_BONUS ? UMIEJETNOSC_MAX_BONUS - sila : 0;
		sila += dodatkowaSila;
		umiejetnoscCooldown = UMIEJETNOSC_COOLDOWN;
		swiat.dodajLog("Czlowiek uzywa umiejetnosci Magiczny Eliksir! Sila wzrasta o " + dodatkowaSila);
		cout << "Czlowiek uzywa umiejetnosci Magiczny Eliksir! Sila wzrasta o " << dodatkowaSila << endl;
		return true;
	}
	cout << "Czlowiek nie moze jeszcze uzyc Magiczny Eliksir przez " << umiejetnoscCooldown << " tur\n";
	return false;
}

string Czlowiek::toString()
{
	string reprezentacja = Zwierze::toString();
	reprezentacja.append(" " + to_string(umiejetnoscCooldown));
	reprezentacja.append(" " + to_string(dodatkowaSila));
	return reprezentacja;
}

void Czlowiek::operator<<(ifstream& f)
{
	Zwierze::operator<<(f);
	int uC = -1, dS = -1;
	if (f >> uC && uC >= 0)
		umiejetnoscCooldown = uC;
	if (f >> dS && dS >= 0)
	{
		dodatkowaSila = dS;
	}
}