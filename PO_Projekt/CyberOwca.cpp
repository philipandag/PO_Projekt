#include "CyberOwca.h"

CyberOwca::CyberOwca(int x, int y, Swiat& swiat) :
	Zwierze(11, 4, x, y, swiat)
{}

CyberOwca::CyberOwca(Swiat& swiat) :
	Zwierze(11, 4, swiat)
{}

CyberOwca::~CyberOwca()
{
	cout << "CyberOwca Papa" << endl;
}

void CyberOwca::akcja()
{
	cout << "CyberOwca Akcja" << endl;
}

void CyberOwca::kolizja(Organizm& atakujacy)
{

}

void CyberOwca::rysowanie()
{
	cout << "#";
}