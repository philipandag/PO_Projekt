#pragma once
#include "Roslina.h"
class Mlecz :
    public Roslina
{
    static const int SILA = 0;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 5;
    static const char ZNAK = 'M';
public:
    Mlecz(int x, int y, int cooldown, int sila, SwiatRef& swiat);
    Mlecz(int x, int y, SwiatRef& swiat);
    Mlecz(SwiatRef& swiat);
    void akcja() override;
    void stworzPotomstwo() override;
    void resetPotomstwoCooldown() override;
    void rysowanie() override;
    char getZnak() override;
    string getNazwa() const override;
};

