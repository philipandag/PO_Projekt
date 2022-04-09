#pragma once
#include <list>
#include <string>
#include "Organizm.h"
#include "Czlowiek.h"
#include "ListaOrganizmow.h"
#include "Plansza.h"
#include "Kierunek.h"
#include "ReferencjaSwiataDlaOrganizmu.h"

using namespace std;

struct OrganizmPointerCompare
{
	bool operator()(Organizm* o1, Organizm* o2)
	{
		return (*o1) < (*o2);
	}
};

class Swiat:
	public ReferencjaSwiata
{
	static const int MAX_LOG_SIZE = 10;

	ListaOrganizmow organizmy;

	unsigned int numerTury;
	list<string> log;

	string getNapisTury() const;
	void wypiszLog();
	bool grabarz(ListaOrganizmow::iterator i); // usuwa organizm jesli jest martwy, zwraca 1 gdy to sie stalo, 0 gdy nie byl martwy
	void narodziny(Organizm& rodzic);
	void skutkiKolizji(Organizm& atakujacy, Organizm& atakowany, int oldX, int oldY, int x, int y, ListaOrganizmow::iterator& i);

public:
	Plansza plansza;
	Swiat(int xSize, int ySize);
	void wykonajTure();
	void rysujSwiat();

	void dodajOrganizm(Organizm* organizm, int x, int y);
	void dodajLog(string komunikat) override;
	Plansza& getPlansza() override;
	ListaOrganizmow& getOrganizmy() override;
};
