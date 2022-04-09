#include "Kierunek.h"

Kierunek::Kierunek()
{
	this->kierunek = ILOSC_KIERUNKOW;
}
Kierunek::Kierunek(K kierunek)
{
	this->kierunek = kierunek;
}

Kierunek& Kierunek::losuj()
{
	this->kierunek = static_cast<K>(rand() % K::ILOSC_KIERUNKOW);
	return *this;
}

int Kierunek::getDx()
{
	return kierunek > N && kierunek < S ? 1 : (kierunek > S && kierunek < ILOSC_KIERUNKOW ? -1 : 0);
}

int Kierunek::getDy()
{
	return kierunek < E || kierunek > W ? -1 : (kierunek > E && kierunek < W ? 1 : 0); // dla kierunku N dY == -1 poniewa¿ y planszy jest liczony od góry
}

bool Kierunek::operator<(const Kierunek::K& kierunek) const
{
	return this->kierunek < kierunek;
}
bool Kierunek::operator<(const Kierunek& kierunek) const
{
	return this->kierunek < kierunek.kierunek;
}
bool Kierunek::operator>(const Kierunek::K& kierunek) const
{
	return this->kierunek > kierunek;
}
bool Kierunek::operator>(const Kierunek& kierunek) const
{
	return this->kierunek > kierunek.kierunek;
}
Kierunek& Kierunek::operator++()
{
	kierunek = static_cast<K>( (kierunek + 1) % K::ILOSC_KIERUNKOW );
	return *this;
}

Kierunek Kierunek::operator++(int)
{
	kierunek = static_cast<K>((kierunek + 1) % K::ILOSC_KIERUNKOW);
	return *this;
}

bool Kierunek::operator>=(const Kierunek& kierunek) const
{
	return this->kierunek >= kierunek.kierunek;
}

bool Kierunek::operator>=(const Kierunek::K& kierunek) const
{
	return this->kierunek >= kierunek;
}

bool Kierunek::operator<=(const Kierunek& kierunek) const
{
	return this->kierunek <= kierunek.kierunek;
}

bool Kierunek::operator<=(const Kierunek::K& kierunek) const
{
	return this->kierunek <= kierunek;
}

bool Kierunek::operator==(const Kierunek& kierunek) const
{
	return this->kierunek == kierunek.kierunek;
}

bool Kierunek::operator==(const Kierunek::K& kierunek) const
{
	return this->kierunek == kierunek;
}

bool Kierunek::operator!=(const Kierunek& kierunek) const
{
	return this->kierunek != kierunek.kierunek;
}

bool Kierunek::operator!=(const Kierunek::K& kierunek) const
{
	return this->kierunek != kierunek;
}