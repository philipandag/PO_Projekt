#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#ifdef _DEBUG
#define DEBUG_NEW new(NORMAL_BLOCK, __FILE_, _LINE_)
#define new DEBUG_NEW
#endif

#include "Swiat.h"
#include "Organizm.h"

#include "Antylopa.h"
#include "CyberOwca.h"
#include "Czlowiek.h"
#include "Lis.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Swiat swiat(10, 10);

	swiat.dodajOrganizm(new Czlowiek(swiat), 0, 0);
	swiat.dodajOrganizm(new Owca(swiat), 1, 0);
	swiat.dodajOrganizm(new CyberOwca(swiat), 2, 0);
	swiat.dodajOrganizm(new Wilk(swiat), 1, 1);
	swiat.dodajOrganizm(new Lis(swiat), 2, 2);
	swiat.dodajOrganizm(new Antylopa(swiat), 3, 3);
	cout << endl;
	swiat.rysujSwiat();
	while (true)
	{
		system("cls");
		swiat.wykonajTure();
		swiat.rysujSwiat();
	}
	
}