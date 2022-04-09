#pragma once
#include "Roslina.h"
class Guarana :
    public Roslina
{
    static const int SILA = 0;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 2;
    static const char ZNAK = 'G';
public:
    Guarana(int x, int y, ReferencjaSwiata& swiat);
    Guarana(ReferencjaSwiata& swiat);
    ~Guarana();
    void akcja() override;
    void kolizja(Organizm& atakujacy) override;
    void potomstwoCooldownWDol() override;
    void stworzPotomstwo() override;
    void rysowanie() override;
    string getNazwa() const override;
};

