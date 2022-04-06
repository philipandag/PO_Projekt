#pragma once
#include <queue>
#include "Organizm.h"
#include "Czlowiek.h"

using std::priority_queue;


class Swiat
{

	priority_queue<Organizm*> organizmy;
	Organizm*** plansza;
	int planszaX;
	int planszaY;
	
public:
	Swiat(int xSize, int ySize);
	~Swiat();
	void wykonajTure();
	void rysujSwiat();
	void dodajOrganizm(Organizm* organizm, int x, int y);
};
