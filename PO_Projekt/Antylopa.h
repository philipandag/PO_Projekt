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
    void kolizja() override;
    void rysowanie() override;
};

