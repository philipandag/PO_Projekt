#include "Swiat.h"
#include <iostream>
#include <windows.h>

using std::cout;
using std::endl;

Swiat::Swiat(int xSize, int ySize) :
	organizmy(),
	plansza(xSize, ySize),
	numerTury(1)
{}

bool Swiat::grabarz(ListaOrganizmow::iterator& i)
{
	if (organizmy[i].getZyje() == false)
	{
		organizmy -= i;
		return true;
	}
	return false;
}

void Swiat::wykonajTure()
{
	log.push_back(getNapisTury());

	for (ListaOrganizmow::iterator i = organizmy.begin(); i != organizmy.end(); i++)
	{
		rysujSwiat();
		//Sleep(100);

		Organizm& o = organizmy[i];

		if (grabarz(i))
			continue;

		o.akcja();
	}
	numerTury++;
	rysujSwiat();
}

void Swiat::rysujSwiat()
{
	system("cls");
	cout << "Tura " << getNapisTury() << "\n\tSwiat:\n";
	for (int y = 0; y < plansza.getYSize(); y++)
	{
		cout << "|";
		for (int x = 0; x < plansza.getXSize(); x++)
		{
			if (plansza[x][y] != nullptr)
			{
				organizmy[plansza[x][y]].rysowanie();
			}		
			else
				cout << " ";
		}
		cout << "|\n";
	}
	wypiszLog();
	cout.flush();
}

void Swiat::dodajOrganizm(Organizm* organizm, int x, int y)
{
	if (plansza.naPlanszy(x, y) && plansza.wolne(x,y))
	{
		organizm->setPozycja(x, y);
		organizmy += organizm;
		plansza[x][y] = organizm->iterator;
	}
	else
	{
		dodajLog("Nie mozna postawic tutaj organizmu!(" + to_string(x) + ", " + to_string(y) + ")");
	}
}

string Swiat::getNapisTury() const
{
	return "Tura " + to_string(numerTury) + ". ";
}

void Swiat::dodajLog(string komunikat)
{
	log.push_back(komunikat);
}

string Swiat::logToString()
{
	string buffer;
	for (list<string>::iterator it = log.begin(); log.size() > MAX_LOG_SIZE;)
		log.erase(it++);

	for (list<string>::iterator it = log.begin(); it != log.end(); it++)
		buffer += *it + "\n";
	return buffer;
}

void Swiat::wypiszLog()
{
	for (list<string>::iterator it = log.begin(); log.size() > MAX_LOG_SIZE;)
		log.erase(it++);

	for (list<string>::iterator it = log.begin(); it != log.end(); it++)
		cout << *it << "\n";
}

Plansza& Swiat::getPlansza()
{
	return plansza;
}
ListaOrganizmow& Swiat::getOrganizmy()
{
	return organizmy;
}

void Swiat::wyczyscEkran()
{
	cout << string(100, '\n');
}