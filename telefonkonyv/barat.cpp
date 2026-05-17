#include "barat.h"
#include "memtrace.h"

using namespace std;

void Barat::kiir() const{
    cout<< "[" <<id << "]"<< nev.c_str()<< "(Barat)" <<endl;
    cout << " - Cim: " << cim.c_str() << endl;
    cout << " - Becenev: " << becenev.c_str() << endl;
    cout << " - Privat szam: " << privatszam.c_str() << endl;
    cout << "******************************************" << endl;
}
void Barat::fajlbaIr(ostream &os) const{
    os << "B;"<<id<<";"<< nev.c_str() << ";" << cim.c_str()<<";"<<becenev.c_str()<<";"<<privatszam.c_str()<<";"<<"\n";
}

Kontakt* Barat::clone() const{
    return new Barat(*this);
}
