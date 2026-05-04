#ifndef BARAT_H_INCLUDED
#define BARAT_H_INCLUDED

#include "kontakt.h"

class Barat: public Kontakt{
    String becenev;
    String privatszam;
public:
    Barat(const char* bnev, const char* pszam, int id = 0, const char* n = "", const char* c = "") : Kontakt(id,n,c), becenev(bnev), privatszam(pszam) {}


    void kiir() const override;
    void fajlbaIr(ostream &os) const override;

    Kontakt* clone() const override{return nullptr;}

    ~Barat(){}

};

#endif // BARAT_H_INCLUDED
