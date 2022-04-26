#include "Roslina.h"

Roslina::Roslina(int sila, int potomstwoCooldown, double potomstwoSzansa, int x, int y, SwiatRef& swiat) :
	Organizm(sila, 0, potomstwoCooldown, x, y, swiat),
	POTOMSTWO_SZANSA(potomstwoSzansa)
{}

void Roslina::akcja()
{
	if (gotowyNaPotomstwo())
		stworzPotomstwo();
	potomstwoCooldownWDol();
}

void Roslina::kolizja(Organizm& atakujacy)
{
	zabij();
}

bool Roslina::gotowyNaPotomstwo() const
{
	return potomstwoCooldown == 0 && POTOMSTWO_SZANSA > 0 && rand() % precyzjaLosowania <= (int)(POTOMSTWO_SZANSA * precyzjaLosowania);
}

string Roslina::toString()
{
	string reprezentacja = Organizm::toString();
	reprezentacja.append(" " + to_string(getPotomstwoCooldown()));
	return reprezentacja;
}

void Roslina::operator<<(ifstream& f)
{
	Organizm::operator<<(f);
	int pc = -1, s = -1;
	if (f >> pc && pc >= 0)
		potomstwoCooldown = pc;

}
