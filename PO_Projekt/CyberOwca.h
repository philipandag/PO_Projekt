#pragma once
#include "Zwierze.h"

class CyberOwca :
    public Zwierze
{
    static const int SILA = 11;
    static const int INICJATYWA = 4;
    static const int POTOMSTWO_COOLDOWN = -1;
    static const char ZNAK = '#';

public:
    CyberOwca(int x, int y, ReferencjaSwiata& swiat);
    CyberOwca(ReferencjaSwiata& swiat);
    ~CyberOwca();
    void akcja() override;
    void kolizja(Organizm& atakujacy) override;
    void rysowanie() override;
    void stworzPotomstwo() override;
    void resetPotomstwoCooldown() override;
    string getNazwa() const override;
};

