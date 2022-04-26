#pragma once
#include "Roslina.h"
class Trawa :
    public Roslina
{
    static const int SILA = 0;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 5;
    static const char ZNAK = 'T';
public:
    Trawa(int x, int y, int cooldown, int sila, SwiatRef& swiat);
    Trawa(int x, int y, SwiatRef& swiat);
    Trawa(SwiatRef& swiat);
    void stworzPotomstwo() override;
    void resetPotomstwoCooldown() override;
    void rysowanie() override;
    char getZnak() override;
    string getNazwa() const override;
};

