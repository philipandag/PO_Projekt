#pragma once
#include "ListaOrganizmow.h"
#include "ReferencjaSwiataDlaOrganizmu.h"
class Plansza:
	public PlanszaRef
{
	ListaOrganizmow::iterator*** plansza;
	int xSize;
	int ySize;
public:
	Plansza(int xSize, int ySize);
	~Plansza();
	int getXSize() const;
	int getYSize() const;
	bool naPlanszy(int x, int y) const override;
	bool wolne(int x, int y) const override;
	void unset(int x, int y) override;
	void set(int x, int y, ListaOrganizmow::iterator it) override;
	void set(int x, int y, ListaOrganizmow::iterator* it) override;
	ListaOrganizmow::iterator** operator[](unsigned int pos) override;
};

