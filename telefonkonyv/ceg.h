#ifndef CEG_H_INCLUDED
#define CEG_H_INCLUDED

#include "kontakt.h"

class Ceg: public Kontakt{
    String munkahelyiszam;
    String faxszam;
public:
    Ceg(const char* mszam, const char* fszam, int id = 0, const char* n = "", const char* c = "") : Kontakt(id,n,c), munkahelyiszam(mszam), faxszam(fszam) {}


    void kiir() const override;
    void fajlbaIr(std::ostream &os) const override;

    Kontakt* clone() const override;

    ~Ceg(){}

};

#endif // CEG_H_INCLUDED
