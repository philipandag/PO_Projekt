#pragma once
#include "Roslina.h"
class WilczeJagody :
    public Roslina
{
    static const int SILA = 99;
    static const double POTOMSTWO_SZANSA;
    static const int POTOMSTWO_COOLDOWN = 5;
    static const char ZNAK = 'J';
public:
    WilczeJagody(int x, int y, int cooldown, int sila, SwiatRef& swiat);
    WilczeJagody(int x, int y, SwiatRef& swiat);
    WilczeJagody(SwiatRef& swiat);
    void kolizja(Organizm& atakujacy) override;
    void stworzPotomstwo() override;
    void resetPotomstwoCooldown() override;
    void rysowanie() override;
    char getZnak() override;
    string getNazwa() const override;
};

