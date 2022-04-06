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

		}
	}
}

void Czlowiek::kolizja()
{
	cout << "Czlowiek kolizja" << endl;
}

void Czlowiek::rysowanie()
{
	cout << "C";
}
