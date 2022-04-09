#pragma once
#include "Zwierze.h"
#include <conio.h>
using namespace std;

class Czlowiek :
	public Zwierze
{
	static const int SILA = 5;
	static const int INICJATYWA = 4;
	static const int POTOMSTWO_COOLDOWN = 3;
	static const char ZNAK = 'C';
	static const int UMIEJETNOSC_COOLDOWN = 5;

	int umiejetnoscCooldown;

public:
	Czlowiek(int x, int y, ReferencjaSwiata& swiat);
	Czlowiek(ReferencjaSwiata& swiat);
	~Czlowiek();
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void stworzPotomstwo() override;
	void rysowanie() override;
	void resetPotomstwoCooldown() override;
	string getNazwa() const override;
	void umiejetnoscCooldownWDol();

	bool specjalnaUmiejetnosc(); // ‧͙⁺˚*･༓☾　Magiczny Eliksir　☽༓･*˚⁺‧͙
};

