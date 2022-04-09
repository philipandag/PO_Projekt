#pragma once
#include "Roslina.h"
class Trawa :
    public Roslina
{
    static const int SILA = 0;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 1;
    static const char ZNAK = 'T';
public:
    Trawa(int x, int y, ReferencjaSwiata& swiat);
    Trawa(ReferencjaSwiata& swiat);
    ~Trawa();
    void akcja() override;
    void kolizja(Organizm& atakujacy) override;
    void potomstwoCooldownWDol() override;
    void stworzPotomstwo() override;
    void rysowanie() override;
    string getNazwa() const override;
};

