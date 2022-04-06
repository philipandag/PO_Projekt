#include "Swiat.h"

Swiat::Swiat():
	organizmy()
{
}
void Swiat::wykonajTure()
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		Organizm& o = organizmy.top();
		organizmy.pop();
		o.akcja();
		organizmy.push(o);
	}
}
void Swiat::rysujSwiat();
