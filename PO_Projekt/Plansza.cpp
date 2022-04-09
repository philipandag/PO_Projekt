#include "Plansza.h"

Plansza::Plansza(int xSize, int ySize)
{
	this->xSize = xSize;
	this->ySize = ySize;

	plansza = new ListaOrganizmow::iterator**[xSize];
	for (int x = 0; x < xSize; x++)
	{
		plansza[x] = new ListaOrganizmow::iterator*[ySize];

		for (int y = 0; y < ySize; y++)
			plansza[x][y] = nullptr;
	}
}

Plansza::~Plansza()
{
	for (int x = 0; x < xSize; x++)
		for (int y = 0; y < ySize; y++)
			if(plansza[x][y] != nullptr)
				delete plansza[x][y];
}

int Plansza::getXSize() const
{
	return xSize;
}

int Plansza::getYSize() const
{
	return ySize;
}

ListaOrganizmow::iterator** Plansza::operator[](unsigned int pos)
{
	return plansza[pos];
}

bool Plansza::naPlanszy(int x, int y) const
{
	return x < xSize&& x >= 0 && y < ySize&& y >= 0;
}

bool Plansza::wolne(int x, int y) const
{
	return plansza[x][y] == nullptr;
}

void Plansza::unset(int x, int y)
{
	if (plansza[x][y] != nullptr)
	{
		plansza[x][y] = nullptr;
	}
}

void Plansza::set(int x, int y, ListaOrganizmow::iterator it)
{
	unset(x, y);
	plansza[x][y] = new ListaOrganizmow::iterator;
	*plansza[x][y] = it;
}

void Plansza::set(int x, int y, ListaOrganizmow::iterator* it)
{
	unset(x, y);
	plansza[x][y] = new ListaOrganizmow::iterator;
	*plansza[x][y] = *it;
}