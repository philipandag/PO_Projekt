#include "Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, int x, int y, Swiat& swiat) :
	sila(sila),
	inicjatywa(inicjatywa),
	x(x),
	y(y),
	zyje(true),
	swiat(swiat)
{}

Organizm::Organizm(int sila, int inicjatywa, Swiat& swiat) :
	sila(sila),
	inicjatywa(inicjatywa),
	x(0),
	y(0),
	zyje(true),
	swiat(swiat)
{}

Organizm& Organizm::setPozycja(int x, int y)
{
	this->x = x;
	this->y = y;
	return *this;
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

void Organizm::toggleZyje() {
	this->zyje = false;
}

int Organizm::getSila() const
{
	return this->sila;
}

int Organizm::getInicjatywa() const
{
	return this->inicjatywa;
}

bool Organizm::operator<(Organizm& other) const
{
	return this->inicjatywa < other.inicjatywa;
}

bool Organizm::operator<(Organizm& other) const
{
	return this->inicjatywa > other.inicjatywa;
}