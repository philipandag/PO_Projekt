#pragma once
#include <fstream>
#include <string>
#include "Organizm.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Antylopa.h"
#include "CyberOwca.h"
#include "Czlowiek.h"
#include "Lis.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Swiat.h"

const string plikZapisu = "zapis.zwierzaki";

class Zapisywacz
{
	Swiat** swiat;
public:
	Zapisywacz(Swiat** swiat);
	Zapisywacz();
	~Zapisywacz();
	void wczytaj();
	void zapisz();
	Swiat* getSwiat();
};

