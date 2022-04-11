#pragma once
#include <vector>
#include <list>
#include "Organizm.h"
#include "ReferencjaSwiataDlaOrganizmu.h"
using namespace std;

class ListaOrganizmow:
	public ListaOrganizmowRef
{
	static bool organizmMniejszy(const Organizm& o1, const Organizm& o2);
public:

	void wstaw(Organizm& o1) override; // wstawia organizm do tablicy zachowujac porzadek wg Inicjatyw i wieku
	int getInicjatywa(int pos) override;
	int getInicjatywa(iterator pos) override;
	iterator last() override;
	void operator+=(Organizm& organizm) override; // dodaje organizm uzywajac wstaw()
	void operator+=(Organizm* organizm) override;
	Organizm& operator[](const ListaOrganizmow::iterator& i) override; // zwraca organizm pod iteratorem
	Organizm& operator[](const ListaOrganizmow::iterator* i) override;
	ListaOrganizmow& operator-=(ListaOrganizmow::iterator& i) override; // usuwa organizm pod iteratorem
	ListaOrganizmow& operator-=(ListaOrganizmow::iterator* i) override;

};

