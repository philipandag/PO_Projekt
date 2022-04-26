#pragma once
#include <string>
#include <time.h>
#include <Windows.h>

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
#include "Zapisywacz.h"


class Gra
{
	Swiat* swiat;
	Zapisywacz* zapisywacz;
	string input;
	bool kontynuuj;

	void ustawDomyslnySwiat();
public:
	Gra();
	void start();
};

