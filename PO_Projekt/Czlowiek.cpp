#include "Czlowiek.h"

Czlowiek::Czlowiek(int x, int y, Swiat& swiat) :
	Zwierze(5, 4, x, y, swiat)
{}

Czlowiek::Czlowiek(Swiat& swiat) :
	Zwierze(5, 4, swiat)
{}

Czlowiek::~Czlowiek()
{
	cout << "Czlowiek Papa" << endl;
}



void Czlowiek::akcja()
{
	char ruch;
	while (true)
	{
		ruch = _getch();
		switch (ruch)
		{
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		default:
			continue;
		}
		break;
	}
}

void Czlowiek::kolizja(Organizm& atakujacy)
{
	if (atakujacy.getSila() >= this->sila)
		toggleZyje();
	else
		atakujacy.toggleZyje();
}

void Czlowiek::rysowanie()
{
	cout << "C";
}
