#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, int potomstwoCooldown, int x, int y, ReferencjaSwiata& swiat) :
	sila(sila),
	inicjatywa(inicjatywa),
	x(x),
	y(y),
	zyje(true),
	potomstwoCooldown(potomstwoCooldown),
	oczekujacePotomstwo(false),
	swiat(swiat),
	plansza(swiat.getPlansza()),
	organizmy(swiat.getOrganizmy()),
	iterator(nullptr)
{}

Organizm::Organizm(int sila, int inicjatywa, int potomstwoCooldown, ReferencjaSwiata& swiat) :
	Organizm(sila, inicjatywa, potomstwoCooldown, x, y, swiat)
{}

Organizm::Organizm(int sila, int inicjatywa, ReferencjaSwiata& swiat):
	Organizm(sila, inicjatywa, -1, x, y, swiat)
{}

Organizm& Organizm::setPozycja(int x, int y)
{
	this->x = x;
	this->y = y;
	return *this;
}

void Organizm::changeSila(int dSila)
{
	this->sila += dSila;
}

int Organizm::getX() const
{
	return this->x;
}

int Organizm::getY() const
{
	return this->y;
}

bool Organizm::getZyje() const {
	return this->zyje;
}

bool Organizm::maOczekujacePotomstwo() const
{
	return oczekujacePotomstwo;
}

bool Organizm::sprobujPostawicWOkolicy(int x, int y)
{
	Kierunek k;
	k.losuj();
	int newX, newY;
	for (int i = 0; i < Kierunek::ILOSC_KIERUNKOW; i++)
	{
		k++;
		newX = x + k.getDx();
		newY = y + k.getDy();
		if (plansza.naPlanszy(newX, newY) && plansza.wolne(newX, newY))
		{
			swiat.dodajOrganizm(this, newX, newY);
			return true;
		}
	}
	return false;
}

void Organizm::zabij() 
{
	swiat.dodajLog(raportZSmierci());
	this->zyje = false;
	plansza.unset(x, y);
}

int Organizm::getSila() const
{
	return this->sila;
}

int Organizm::getInicjatywa() const
{
	return this->inicjatywa;
}

bool Organizm::operator<(const Organizm& other) const
{
	return this->inicjatywa < other.inicjatywa;
}

bool Organizm::operator>(const Organizm& other) const
{
	return this->inicjatywa > other.inicjatywa;
}

bool Organizm::gotowyNaPotomstwo() const
{
	return potomstwoCooldown == 0;
}

void Organizm::toggleOczekujacePotomstwo()
{
	oczekujacePotomstwo = true;
}

string Organizm::raportZSmierci() const
{
	return " - " + getNazwa() + " umiera";
}

string Organizm::raportZKolizji(const Organizm& atakujacy) const
{
	return " - " + getNazwa() + " natrafia na " + atakujacy.getNazwa();
}

string Organizm::raportZRuchu() const
{
	return " - " + getNazwa() + " ruszyl sie na pole (" + to_string(getX()) + ", " + to_string(getY()) + ")";
}

string Organizm::raportZNarodzin() const
{
	return " - Na swiat przychodzi " + getNazwa() + " na (" + to_string(getX()) + ", " + to_string(getY()) + ")!";
}