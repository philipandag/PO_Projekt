#pragma once
#include "Roslina.h"
class WilczeJagody :
    public Roslina
{
    static const int SILA = 99;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 2;
    static const char ZNAK = 'J';
public:
    WilczeJagody(int x, int y, ReferencjaSwiata& swiat);
    WilczeJagody(ReferencjaSwiata& swiat);
    ~WilczeJagody();
    void akcja() override;
    void kolizja(Organizm& atakujacy) override;
    void potomstwoCooldownWDol() override;
    void stworzPotomstwo() override;
    void rysowanie() override;
    string getNazwa() const override;
};

