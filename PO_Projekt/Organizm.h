#pragma once
#include "miscellaneous.cpp"
#include "Kierunek.h"
#include <list>
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include "WirtualneReferencje.h"
using namespace std;


class Organizm
{
protected:

	int sila;
	int inicjatywa;
	int x;
	int y;
	bool zyje;
	int potomstwoCooldown;
	bool oczekujacePotomstwo;
	SwiatRef& swiat;
	PlanszaRef& plansza;
	ListaOrganizmowRef& organizmy;



public:
	ListaOrganizmowRef::iterator* iterator;

	Organizm(int sila, int inicjatywa, int potomstwoCooldown, int x, int y, SwiatRef& swiat);
	Organizm(int sila, int inicjatywa, int potomstwoCooldown, SwiatRef& swiat);
	Organizm(int sila, int inicjatywa, SwiatRef& swiat);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm& atakujacy) = 0;
	virtual void stworzPotomstwo() = 0;
	virtual void rysowanie() = 0;
	virtual char getZnak() = 0;
	virtual string getNazwa() const = 0;
	virtual void potomstwoCooldownWDol();
	virtual void resetPotomstwoCooldown() = 0;
	virtual void operator<<(ifstream& f);

	Organizm& setPozycja(int x, int y);
	void changeSila(int dSila);
	void toggleOczekujacePotomstwo();

	int getX() const;
	int getY() const;
	bool getZyje() const;
	void zabij();
	int getSila() const;
	int getInicjatywa() const;
	int getPotomstwoCooldown() const;
	virtual bool gotowyNaPotomstwo() const;
	bool maOczekujacePotomstwo() const;
	bool sprobujPostawicWOkolicy(int x, int y);
	bool sprobujDodacWOkolicy(int x, int y);
	bool sprobujPrzemiescicWOkolicy(int x, int y);
	bool operator<(const Organizm& other) const;
	bool operator>(const Organizm& other) const;
	virtual string toString();

	string raportZSmierci() const;
	string raportZKolizji(const Organizm& ofiara) const;
	string raportZRuchu() const;
	string raportZNarodzin() const;
};
