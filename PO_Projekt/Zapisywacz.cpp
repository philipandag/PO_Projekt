#include "Zapisywacz.h"

Zapisywacz::Zapisywacz(Swiat** swiat):
	swiat(swiat)
{}

Zapisywacz::Zapisywacz() :
	swiat(nullptr)
{}

void Zapisywacz::wczytaj()
{
	ifstream plik;
	plik.open(plikZapisu, std::fstream::in);
	if (*swiat != nullptr)
		delete *swiat;

	int swiatX, swiatY;
	plik >> swiatX >> swiatY;
	if (swiatX < 0 || swiatY < 0)
	{
		std::cout << "Bledne wymiary swiata, uszkodzony plik zapisu w linijce 0";
		exit(-1);
	}
	*swiat = new Swiat(swiatX, swiatY);
	Swiat* swiat = *this->swiat;

	string nazwa;
	Organizm* o;
	int linia = 1;
	while (plik >> nazwa)
	{
		linia++;
		if (nazwa == "BarszczSosnowskiego") o = new BarszczSosnowskiego(*swiat); else
		if (nazwa == "Guarana") o = new Guarana(*swiat); else
		if (nazwa == "Mlecz") o = new Mlecz(*swiat); else
		if (nazwa == "Trawa") o = new Trawa(*swiat); else
		if (nazwa == "WilczeJagody") o = new WilczeJagody(*swiat); else
		if (nazwa == "Antylopa") o = new Antylopa(*swiat); else
		if (nazwa == "CyberOwca") o = new CyberOwca(*swiat); else
		if (nazwa == "Czlowiek") o = new Czlowiek(*swiat); else
		if (nazwa == "Lis") o = new Lis(*swiat); else
		if (nazwa == "Owca") o = new Owca(*swiat); else
		if (nazwa == "Wilk") o = new Wilk(*swiat); else
		if (nazwa == "Zolw") o = new Zolw(*swiat); 
		else
		{
			cout << "Bledna nazwa zwierzecia, uszkodzony plik zapisu w linijce " << linia << endl;
			exit(-1);
		}
		*o << plik;
	}
	plik.close();
	swiat->rysujSwiat();
	cout << "Gra wczytana, wcisnij enter aby rozpoczac gre\n";
}
void Zapisywacz::zapisz()
{
	ListaOrganizmow organizmy = (*swiat)->getOrganizmy();

	ofstream plik;
	plik.open(plikZapisu, std::ofstream::out || std::ofstream::trunc);
	plik << (*swiat)->getPlansza().getXSize() << " " << (*swiat)->getPlansza().getYSize() << endl;

	for (ListaOrganizmow::iterator i = organizmy.begin(); i != organizmy.end(); i++)
	{
		if(!(*swiat)->grabarz(i))
			plik << (*i)->toString() << endl;
	}

	cout << "Zapisano pomyslnie, wcisnij enter aby kontynuowac gre\n";
	plik.close();
}

Swiat* Zapisywacz::getSwiat()
{
	return *this->swiat;
}

Zapisywacz::~Zapisywacz()
{
}