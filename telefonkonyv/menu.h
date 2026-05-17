#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "telefonkonyv.h"

class Menu{
    Telefonkonyv tk;
    void menuKiir() const;
    void adatFelvetel();
    void adatModosit();
    void adatTorol();
    void listazas() const;
    void keresesInditasa() const;
public:
    void indit();
};

#endif // MENU_H_INCLUDED
