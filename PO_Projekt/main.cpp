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
	Swiat swiat(10, 10);


	swiat.dodajOrganizm(new Czlowiek(swiat), 1, 1);
	swiat.dodajOrganizm(new Czlowiek(swiat), 1, 2);


	int licznikTury = 1;
	while (true)
	{
		swiat.wykonajTure();
	}
	
}