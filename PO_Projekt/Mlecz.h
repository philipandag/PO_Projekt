#pragma once
#include "Roslina.h"
class Mlecz :
    public Roslina
{
    static const int SILA = 0;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 3;
    static const char ZNAK = 'M';
public:
    Mlecz(int x, int y, ReferencjaSwiata& swiat);
    Mlecz(ReferencjaSwiata& swiat);
    ~Mlecz();
    void akcja() override;
    void kolizja(Organizm& atakujacy) override;
    void potomstwoCooldownWDol() override;
    void stworzPotomstwo() override;
    void rysowanie() override;
    string getNazwa() const override;
};

