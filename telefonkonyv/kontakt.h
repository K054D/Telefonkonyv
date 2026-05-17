#ifndef KONTAKT_H_INCLUDED
#define KONTAKT_H_INCLUDED

#include <iostream>
#include "string.h"


class Kontakt{
protected:
    int id;
    String nev;
    String cim;
public:
    Kontakt(int id = 0, const char* n = "", const char* c = "") : id(id), nev(n), cim(c) {}
    virtual void kiir() const = 0;
    virtual void fajlbaIr(std::ostream &os) const = 0;

    virtual Kontakt* clone() const = 0;

    const String& getNev() const { return nev; }
    const String& getCim() const { return cim; }
    int getId() const { return id; }

    void setNev(const char* ujNev) { nev = ujNev; }
    void setCim(const char* ujCim) { cim = ujCim; }

    virtual ~Kontakt(){};

};

#endif // KONTAKT_H_INCLUDED
