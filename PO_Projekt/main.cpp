#include <string>
#include <time.h>

#include "Swiat.h"
#include "Organizm.h"

#include "Antylopa.h"
#include "CyberOwca.h"
#include "Czlowiek.h"
#include "Lis.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"

#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "WilczeJagody.h"

int main()
{
	srand(time(0));
	Swiat swiat(3, 5);


	//swiat.dodajOrganizm(new Czlowiek(swiat), 1, 1);

	swiat.dodajOrganizm(new Lis(swiat), 1, 1);
	swiat.dodajOrganizm(new Wilk(swiat), 0, 0);
	swiat.dodajOrganizm(new Wilk(swiat), 1, 0);
	swiat.dodajOrganizm(new Wilk(swiat), 2, 0);
	swiat.dodajOrganizm(new Wilk(swiat), 0, 1);
	swiat.dodajOrganizm(new Wilk(swiat), 2, 1);
	swiat.dodajOrganizm(new Wilk(swiat), 0, 2);
	swiat.dodajOrganizm(new Wilk(swiat), 2, 2);
	swiat.dodajOrganizm(new Wilk(swiat), 0, 3);
	swiat.dodajOrganizm(new Wilk(swiat), 2, 3);
	swiat.dodajOrganizm(new Wilk(swiat), 0, 4);
	swiat.dodajOrganizm(new Wilk(swiat), 1, 4);
	swiat.dodajOrganizm(new Wilk(swiat), 2, 4);
	swiat.dodajOrganizm(new Lis(swiat), 1, 3);


	int licznikTury = 1;
	while (true)
	{
		swiat.wykonajTure();
	}
	
}