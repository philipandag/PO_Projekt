#include "Gra.h"

Gra::Gra():
	input(),
	kontynuuj(true)
{
	ustawDomyslnySwiat();
}

void Gra::ustawDomyslnySwiat()
{
	if (swiat != nullptr)
		delete swiat;

	swiat = new Swiat(20, 20);
	zapisywacz = new Zapisywacz(&swiat);

	swiat->dodajOrganizm(new Czlowiek(*swiat), 1, 1);
	swiat->dodajOrganizm(new Owca(*swiat), 2, 3);
	swiat->dodajOrganizm(new Owca(*swiat), 2, 2);
	swiat->dodajOrganizm(new Wilk(*swiat), 5, 6);
	swiat->dodajOrganizm(new Wilk(*swiat), 6, 6);
	swiat->dodajOrganizm(new Lis(*swiat), 2, 4);
	swiat->dodajOrganizm(new Lis(*swiat), 3, 4);
	swiat->dodajOrganizm(new Antylopa(*swiat), 14, 2);
	swiat->dodajOrganizm(new Antylopa(*swiat), 15, 3);
	swiat->dodajOrganizm(new CyberOwca(*swiat), 19, 19);
	swiat->dodajOrganizm(new CyberOwca(*swiat), 18, 19);
	swiat->dodajOrganizm(new Zolw(*swiat), 18, 4);
	swiat->dodajOrganizm(new Zolw(*swiat), 18, 5);

	swiat->dodajOrganizm(new Guarana(*swiat), 2, 1);
	swiat->dodajOrganizm(new Trawa(*swiat), 6, 7);
	swiat->dodajOrganizm(new BarszczSosnowskiego(*swiat), 9, 9);
	swiat->dodajOrganizm(new Mlecz(*swiat), 8, 17);
	swiat->dodajOrganizm(new WilczeJagody(*swiat), 15, 2);

	swiat->rysujSwiat();
	start();
}

void Gra::start()
{
	while (kontynuuj)
	{
		getline(cin, input);

		if (input == "l" || input == "L")
			zapisywacz->wczytaj(); 
		else if (input == "s" || input == "S")
			zapisywacz->zapisz(); 
		else if (input == "r" || input == "R")
			ustawDomyslnySwiat();
		else if (input.length() == 0 && swiat != nullptr)
		{
			kontynuuj = swiat->wykonajTure();
		}
	}
}
