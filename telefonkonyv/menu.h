#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "telefonkonyv.h"

class Menu(){
    Telefonkonyv tk;

    void menuKiir();
    void adatFelvetel();
    void adatModosit();
    void adatTorol();
    void listazas();
    void keresesInditasa();
public:
    void indit();
};

#endif // MENU_H_INCLUDED
