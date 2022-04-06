#pragma once
#include "Zwierze.h"
class Antylopa :
    public Zwierze
{

public:
    Antylopa(int x, int y, Swiat& swiat);
    Antylopa(Swiat& swiat);
    ~Antylopa();
    void akcja() override;
    void kolizja(Organizm& atakujacy) override;
    void rysowanie() override;
};

