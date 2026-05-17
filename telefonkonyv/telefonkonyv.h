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

    Telefonkonyv(const Telefonkonyv& masik);
    Telefonkonyv& operator=(const Telefonkonyv& masik);

    bool hozzaad(Kontakt * uj);
    bool torol(int id);
    void listaz() const;
    bool fajlbolToltes(const char* fajlnev);
    bool fajlbaMent(const char* fajlnev) const;

    Kontakt* getKontakt(int id);
    int getMeret()const {return meret;}

    template <typename Predicate>
    void keres(Predicate feltetel)const{
        int talalatok = 0;
        for(int i = 0; i<meret; ++i){
            if(feltetel(*elemek[i])){
                elemek[i]->kiir();
                talalatok++;
            }
        }
        if(talalatok == 0){
            std::cout << "Nem talalhato a feltetelnek megfelelo elem!\n";
        }
    }


};


#endif // TELEFONKONYV_H_INCLUDED
