#include "telefonkonyv.h"
#include "barat.h"
#include "ceg.h"
#include <fstream>
#include <cstring>

Telefonkonyv::~Telefonkonyv(){
    for(int i = 0; i < meret; ++i){
        delete elemek[i];
    }
    delete[] elemek;
}

Telefonkonyv::Telefonkonyv(const Telefonkonyv& masik): meret(masik.meret), kapacitas(masik.kapacitas){
    if(kapacitas>0){
       elemek = new Kontakt*[kapacitas];
       for(int i = 0; i<meret; ++i){
            elemek[i] = masik.elemek[i]->clone();
        }
    }else{
        elemek = nullptr;
    }
};
Telefonkonyv& Telefonkonyv::operator=(const Telefonkonyv& masik){
    if(this == &masik) return *this;

    for(int i = 0; i < meret; ++i){
        delete elemek[i];
    }
    delete[] elemek;

    meret = masik.meret;
    kapacitas = masik.kapacitas;
    if(kapacitas>0){
       elemek = new Kontakt*[kapacitas];
       for(int i = 0; i<meret; ++i){
            elemek[i] = masik.elemek[i]->clone();
        }
    }else{
        elemek = nullptr;
    }

    return *this;
}

bool Telefonkonyv::hozzaad(Kontakt * uj){
    if(meret == kapacitas){
        int ujkapacitas = (kapacitas==0)? 2 : kapacitas*2;
        Kontakt** ujelemek = new Kontakt*[ujkapacitas];

        for(int i = 0; i < meret; ++i){
            delete elemek[i];
        }
        delete[] elemek;

        kapacitas = ujkapacitas;
        elemek = ujelemek;
    }

    elemek[meret++] = uj;
    return true;
}
bool Telefonkonyv::torol(int id){
    for(int i = 0; i < meret; ++i){
        if(elemek[i]->getId() == id){
            delete elemek[i];

            for(int j = i; j< meret-1; ++j){
                elemek[j] = elemek[j+1];
            }
            //Mivel az utolsó elem duplikált lett
            elemek[meret-1] = nullptr;

            meret--;

            return true;
        }
    }
    return false;
}
void Telefonkonyv::listaz() const{
    if(meret == 0){
        std::cout << "A telefonkonyv ures!" << std::endl;
        return;
    }

    std::cout << "*** TELEFONKONYY ("<<meret<<" db rekord) ***"<<std::endl;
    for(int i = 0; i < meret; ++i){
        elemek[i]->kiir();
        std::cout << "*************************************" << std::endl;
    }
}

bool Telefonkonyv::fajlbolToltes(const char* fajlnev){
    std::ifstream fajl(fajlnev);
    if(!fajl.is_open()) return false;

    char sorbuffer[512];

    while(fajl.getline(sorbuffer, 512)){
        char tipus = sorbuffer[0];

        strtok(sorbuffer, ";");

        int id = std::stoi(strtok(nullptr, ";"));
        char* nev = strtok(nullptr, ";");
        char* cim = strtok(nullptr, ";");

        if(tipus == 'B'){
            char* bnev = strtok(nullptr, ";");
            char* pszam = strtok(nullptr, ";");

            hozzaad(new Barat(bnev,pszam,id,nev,cim));
        }

        if(tipus == 'C'){
            char* mszam = strtok(nullptr, ";");
            char* fszam = strtok(nullptr, ";");

            hozzaad(new Ceg(mszam,fszam,id,nev,cim));
        }
    }
    fajl.close();
    return true;
}


bool Telefonkonyv::fajlbaMent(const char* fajlnev){
    std::ofstream fajl(fajlnev);
    if(!fajl.is_open()) return false;

    for(int i = 0; i < meret; ++i){
        elemek[i]->fajlbaIr(fajl);
    }

    fajl.close();
    return true;
}



