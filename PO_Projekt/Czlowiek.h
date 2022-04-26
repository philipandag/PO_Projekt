#pragma once
#include "Zwierze.h"
#include <conio.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Czlowiek :
	public Zwierze
{
	static const int SILA = 5;
	static const int INICJATYWA = 4;
	static const int POTOMSTWO_COOLDOWN = 3;
	static const char ZNAK = 'C';
	static const int UMIEJETNOSC_COOLDOWN = 5;
	static const int UMIEJETNOSC_MAX_BONUS = 10;

	int umiejetnoscCooldown;
	int dodatkowaSila;

public:
	Czlowiek(int x, int y, int cooldown, int sila, SwiatRef& swiat);
	Czlowiek(int x, int y, SwiatRef& swiat);
	Czlowiek(SwiatRef& swiat);
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void stworzPotomstwo() override;
	void rysowanie() override;
	char getZnak() override;
	void resetPotomstwoCooldown() override;
	string getNazwa() const override;
	void operator<<(ifstream& f) override;
	string toString() override;
	void umiejetnoscCooldownWDol();

	bool specjalnaUmiejetnosc(); // ‧͙⁺˚*･༓☾　Magiczny Eliksir　☽༓･*˚⁺‧͙
};

