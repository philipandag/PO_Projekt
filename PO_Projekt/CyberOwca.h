#pragma once
#include "Zwierze.h"
class CyberOwca :
    public Zwierze
{

public:
    CyberOwca(int x, int y, Swiat& swiat);
    CyberOwca(Swiat& swiat);
    ~CyberOwca();
    void akcja() override;
    void kolizja() override;
    void rysowanie() override;
};

