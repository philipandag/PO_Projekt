#include "CyberOwca.h"

CyberOwca::CyberOwca(int x, int y, ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, x, y, swiat)
{}

CyberOwca::CyberOwca(ReferencjaSwiata& swiat) :
	Zwierze(SILA, INICJATYWA, POTOMSTWO_COOLDOWN, swiat)
{}

CyberOwca::~CyberOwca()
{
	cout << "CyberOwca Papa" << endl;
}

void CyberOwca::akcja()
{

}

void CyberOwca::kolizja(Organizm& atakujacy)
{

}

void CyberOwca::stworzPotomstwo()
{

}

void CyberOwca::rysowanie()
{
	cout << ZNAK;
}

char CyberOwca::getZnak()
{
	return ZNAK;
}

string CyberOwca::getNazwa() const
{
	return "Cyber Owca";
}

void CyberOwca::resetPotomstwoCooldown()
{
	potomstwoCooldown = POTOMSTWO_COOLDOWN;
}