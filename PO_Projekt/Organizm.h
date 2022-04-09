#pragma once
#include "miscellaneous.cpp"
#include "Kierunek.h"
#include <list>
#include <iostream>
#include <random>
#include <string>
#include "ReferencjaSwiataDlaOrganizmu.h"
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
	ReferencjaSwiata& swiat;
	PlanszaRef& plansza;
	ListaOrganizmowRef& organizmy;



public:
	ListaOrganizmowRef::iterator* iterator;

	Organizm(int sila, int inicjatywa, int potomstwoCooldown, int x, int y, ReferencjaSwiata& swiat);
	Organizm(int sila, int inicjatywa, int potomstwoCooldown, ReferencjaSwiata& swiat);
	Organizm(int sila, int inicjatywa, ReferencjaSwiata& swiat);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm& atakujacy) = 0;
	virtual void stworzPotomstwo() = 0;
	virtual void rysowanie() = 0;
	virtual string getNazwa() const = 0;
	virtual void potomstwoCooldownWDol() = 0;
	virtual void resetPotomstwoCooldown() = 0;

	Organizm& setPozycja(int x, int y);
	void changeSila(int dSila);
	void toggleOczekujacePotomstwo();

	int getX() const;
	int getY() const;
	bool getZyje() const;
	void zabij();
	int getSila() const;
	int getInicjatywa() const;
	bool gotowyNaPotomstwo() const;
	bool maOczekujacePotomstwo() const;
	bool sprobujPostawicWOkolicy(int x, int y);
	bool operator<(const Organizm& other) const;
	bool operator>(const Organizm& other) const;

	string raportZSmierci() const;
	string raportZKolizji(const Organizm& ofiara) const;
	string raportZRuchu() const;
	string raportZNarodzin() const;
};
