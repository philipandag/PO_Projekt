#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, int x, int y, Swiat& swiat) :
	Organizm(sila, inicjatywa, x, y, swiat)
{}
Zwierze::Zwierze(int sila, int inicjatywa, Swiat& swiat) :
	Organizm(sila, inicjatywa, swiat)
{}