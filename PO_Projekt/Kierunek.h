#pragma once
#include <stdlib.h>

class Kierunek {
public:
	enum K {					
		NONE = 0,			// NW N NE
		N = 1,				// W     E
		NE,					// SW S SE
		E,
		SE,
		S,
		SW,
		W,
		NW,
		ILOSC_KIERUNKOW
	};
private:
	K kierunek;
public:
	Kierunek();
	Kierunek(K kierunek);
	Kierunek& losuj();
	int getDx();
	int getDy();
	bool operator<(const Kierunek::K& kierunek) const;
	bool operator<(const Kierunek& kierunek) const;
	bool operator>(const Kierunek::K& kierunek) const;
	bool operator>(const Kierunek& kierunek) const;
	bool operator>=(const Kierunek::K& kierunek) const;
	bool operator>=(const Kierunek& kierunek) const;
	bool operator<=(const Kierunek::K& kierunek) const;
	bool operator<=(const Kierunek& kierunek) const;
	bool operator==(const Kierunek::K& kierunek) const;
	bool operator==(const Kierunek& kierunek) const;
	bool operator!=(const Kierunek::K& kierunek) const;
	bool operator!=(const Kierunek& kierunek) const;
	Kierunek& operator++();
	Kierunek operator++(int);
};

