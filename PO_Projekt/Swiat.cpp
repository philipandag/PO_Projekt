#include "Swiat.h"
#include <iostream>

using std::cout;
using std::endl;

Swiat::Swiat(int xSize, int ySize):
	organizmy(),
	planszaX(xSize),
	planszaY(xSize)
{
	plansza = new Organizm**[xSize];
	for (int x = 0; x < xSize; x++)
	{
		plansza[x] = new Organizm*[ySize];

		for (int y = 0; y < ySize; y++)
			plansza[x][y] = nullptr;
	}
}

Swiat::~Swiat()
{
	for (int x = 0; x < planszaX; x++)
	{
		delete plansza[x];
	}
	delete plansza;
}

void Swiat::wykonajTure()
{
	priority_queue<Organizm*> buffer = organizmy;

	for (int i = 0; i < buffer.size(); i++)
	{
		Organizm* o = buffer.top();
		buffer.pop();
		o->akcja();
	}
}

void Swiat::rysujSwiat()
{
	cout << "\nSWIAT" << endl;
	for (int y = 0; y < planszaY; y++)
	{
		cout << "|";
		for (int x = 0; x < planszaY; x++)
		{
			if (plansza[x][y] != nullptr)
			{
				plansza[x][y]->rysowanie();
				cout << " ";
			}
			else
				cout << "  ";
		}
		cout << "|" << endl;
	}
}

void Swiat::dodajOrganizm(Organizm&& organizm, int x, int y)
{
	if (plansza[x][y] == nullptr)
	{
		organizmy.push( &(organizm.setPozycja(x, y)) );
		plansza[x][y] = &organizm;
	}
	else
	{
		cout << "Pole zajête!" << endl;
	}
}
