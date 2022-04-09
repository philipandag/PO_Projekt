#pragma once
#include <list>
#include <string>

using namespace std;

class Organizm;

class ListaOrganizmowRef :
	public list<Organizm*> {
public:
	virtual void wstaw(Organizm& o1) = 0; // wstawia organizm do tablicy zachowujac porzadek wg Inicjatyw i wieku
	virtual int getInicjatywa(int pos) = 0;
	virtual int getInicjatywa(iterator pos) = 0;
	virtual iterator last() = 0;
	virtual void operator+=(Organizm& organizm) = 0; // dodaje organizm uzywajac wstaw()
	virtual void operator+=(Organizm* organizm) = 0;
	virtual Organizm& operator[](const list<Organizm*>::iterator& i) = 0; // zwraca organizm pod iteratorem
	virtual Organizm& operator[](const list<Organizm*>::iterator* i) = 0;
	virtual ListaOrganizmowRef& operator-=(const list<Organizm*>::iterator& i) = 0; // usuwa organizm pod iteratorem
	virtual ListaOrganizmowRef& operator-=(const list<Organizm*>::iterator* i) = 0;
};

class PlanszaRef
{
public:
	virtual ListaOrganizmowRef::iterator** operator[](unsigned int pos) = 0;
	virtual bool wolne(int x, int y) const = 0;
	virtual bool naPlanszy(int x, int y) const = 0;
	virtual void unset(int x, int y) = 0;
	virtual void set(int x, int y, ListaOrganizmowRef::iterator it) = 0;
	virtual void set(int x, int y, ListaOrganizmowRef::iterator* it) = 0;
};

class ReferencjaSwiata
{
public:
	virtual void dodajOrganizm(Organizm* organizm, int x, int y) = 0;
	virtual PlanszaRef& getPlansza() = 0;
	virtual ListaOrganizmowRef& getOrganizmy() = 0;
	virtual void dodajLog(string komunikat) = 0;
};

