#pragma once
#include "Roslina.h"
#include "CyberOwca.h"
class BarszczSosnowskiego :
    public Roslina
{
    static const int SILA = 10;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 5;
    static const char ZNAK = 'B';

public:
    BarszczSosnowskiego(int x, int y, int cooldown, int sila, SwiatRef& swiat);
    BarszczSosnowskiego(int x, int y, SwiatRef& swiat);
    BarszczSosnowskiego(SwiatRef& swiat);
    void akcja() override;
    void kolizja(Organizm& atakujacy) override;
    void resetPotomstwoCooldown() override;
    void stworzPotomstwo() override;
    void rysowanie() override;
    char getZnak() override;
    string getNazwa() const override;
};

