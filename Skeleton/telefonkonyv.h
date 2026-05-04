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

    Telefonkonyv(const Telefonkonyv& masik): elemek(nullptr), meret(0), kapacitas(0){};
    Telefonkonyv& operator=(const Telefonkonyv& masik){return *this;}

    bool hozzaad(Kontakt * uj);
    bool torol(int id);
    void listaz() const;
    bool fajlbolToltes(const char* fajlnev);
    bool fajlbaMent(const char* fajlnev);

    template <typename Predicate>
    void keres(Predicate feltetel){
        for(int i = 0; i<meret; ++i){
            if(feltetel(*elemek[i])){
                elemek[i]->kiir();
            }
        }
    }


};


#endif // TELEFONKONYV_H_INCLUDED
