#pragma once
#include "Roslina.h"
class Guarana :
    public Roslina
{
    static const int SILA = 0;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 5;
    static const char ZNAK = 'G';
public:
    Guarana(int x, int y, int cooldown, int sila, SwiatRef& swiat);
    Guarana(int x, int y, SwiatRef& swiat);
    Guarana(SwiatRef& swiat);
    void kolizja(Organizm& atakujacy) override;
    void resetPotomstwoCooldown() override;
    void stworzPotomstwo() override;
    void rysowanie() override;
    char getZnak() override;
    string getNazwa() const override;
};

