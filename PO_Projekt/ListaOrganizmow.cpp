#include "ListaOrganizmow.h"


static bool organizmMniejszy(const Organizm* const o1, const Organizm* const o2)
{
	return (*o1) < (*o2);
}

int ListaOrganizmow::getInicjatywa(int pos)
{
	ListaOrganizmow::iterator i = begin();
	advance(i, pos);
	return (*i)->getInicjatywa();
}


int ListaOrganizmow::getInicjatywa(iterator pos)
{
	return (*pos)->getInicjatywa();
}

ListaOrganizmow::iterator ListaOrganizmow::last()
{
	ListaOrganizmow::iterator i = end();
	advance(i, 1);
	return i;
}

void ListaOrganizmow::wstaw(Organizm& organizm)
{
	int szukanaInicjatywa = organizm.getInicjatywa();
	bool found = false;

	ListaOrganizmow::iterator i = begin();

	while (i != end() && getInicjatywa(i) >= szukanaInicjatywa)
	{
		i++;
	}

	insert(i, &organizm);
	ListaOrganizmow::iterator* it = new ListaOrganizmow::iterator;
	*it = --i;
	organizm.iterator = it;

}

void ListaOrganizmow::operator+=(Organizm& organizm)
{
	wstaw(organizm);
}
void ListaOrganizmow::operator+=(Organizm* organizm)
{
	wstaw(*organizm);
}

Organizm& ListaOrganizmow::operator[](const ListaOrganizmow::iterator* i)
{
	return ***i;
}

Organizm& ListaOrganizmow::operator[](const ListaOrganizmow::iterator& i)
{
	return **i;
}

ListaOrganizmow& ListaOrganizmow::operator-=(ListaOrganizmow::iterator& i)
{
	ListaOrganizmow::iterator copy = i;
	ListaOrganizmow::iterator it = i;
	if (++copy == end())
		i--;
	else
		i++;
	delete (*it);
	erase(it);
	return *this;
}

ListaOrganizmow& ListaOrganizmow::operator-=(ListaOrganizmow::iterator* i)
{
	return this->operator-=(*i);
}