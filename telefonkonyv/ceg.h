#ifndef CEG_H_INCLUDED
#define CEG_H_INCLUDED

#include "kontakt.h"

class Ceg: public Kontakt{
    String munkahelyiszam;
    String faxszam;
public:
    Barat(int id = 0, const char* n = "", const char* c = "", const char* mszam, const char* fszam) : Kontakt(id,n,c), mszam(munkahelyiszam), fszam(faxszam) {}


    void kiir() const override;
    void fajlbaIr(ostream &os) const override;

    Kontakt* clone() const ovrride{return nullptr};

    ~Ceg(){}

};

#endif // CEG_H_INCLUDED
