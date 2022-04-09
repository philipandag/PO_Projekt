#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
    public Roslina
{
    static const int SILA = 10;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 3;
    static const char ZNAK = 'B';

public:
    BarszczSosnowskiego(int x, int y, ReferencjaSwiata& swiat);
    BarszczSosnowskiego(ReferencjaSwiata& swiat);
    ~BarszczSosnowskiego();
    void akcja() override;
    void kolizja(Organizm& atakujacy) override;
    void potomstwoCooldownWDol() override;
    void stworzPotomstwo() override;
    void rysowanie() override;
    string getNazwa() const override;
};

