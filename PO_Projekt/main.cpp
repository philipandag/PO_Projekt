#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#ifdef _DEBUG
#define DEBUG_NEW new(NORMAL_BLOCK, __FILE_, _LINE_)
#define new DEBUG_NEW
#endif

#include "Organizm.h"
#include "Swiat.h"

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

	swiat.dodajOrganizm(Czlowiek(swiat), 0, 0);
	swiat.dodajOrganizm(Owca(swiat), 1, 0);
	swiat.dodajOrganizm(CyberOwca(swiat), 2, 0);
	swiat.dodajOrganizm(Wilk(swiat), 1, 1);
	swiat.dodajOrganizm(Lis(swiat), 2, 2);
	swiat.dodajOrganizm(Antylopa(swiat), 3, 3);
	cout << endl;
	char input = NULL;
	swiat.rysujSwiat();
	while (input != EOF)
	{
		input = _getch();
		system("cls");
		cout << "input: " << input << endl;
		swiat.wykonajTure();
		swiat.rysujSwiat();
	}
	
}