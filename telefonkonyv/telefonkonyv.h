#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED

#include "kontakt.h"

class Telefonkonyv{
    Kontakt** elemek;
    int meret;
    int kapacitas;
public:
    Telefonkonyv() : elemek(nullptr), meret(0), kapacitas(0) {}
    ~Telefonkonyv();


};


#endif // TELEFONKONYV_H_INCLUDED
