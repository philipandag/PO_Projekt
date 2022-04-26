#pragma once
#include "Zwierze.h"
class Antylopa :
    public Zwierze
{
    static const int SILA = 4;
    static const int INICJATYWA = 4;
    static const int POTOMSTWO_COOLDOWN = 5;
    static const char ZNAK = 'A';

public:
    Antylopa(int x, int y, int cooldown, int sila, SwiatRef& swiat);
    Antylopa(int x, int y, SwiatRef& swiat);
    Antylopa(SwiatRef& swiat);
    void akcja() override;
    void kolizja(Organizm& atakujacy) override;
    void rysowanie() override;
    char getZnak() override;
    void stworzPotomstwo() override;
    void resetPotomstwoCooldown() override;
    string getNazwa() const override;
};

