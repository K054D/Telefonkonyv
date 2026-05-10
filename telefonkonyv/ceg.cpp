#include "ceg.h"

using namespace std;

void Ceg::kiir() const{
    cout<< "[" <<id << "]"<< nev.c_str()<< "(Ceg)" <<endl;
    cout << " - Cim: " << cim.c_str() << endl;
    cout << " - Munkahelyi szam: " << munkahelyiszam.c_str() << endl;
    cout << " - Fax szam: " << faxszam.c_str() << endl;
    cout << "******************************************" << endl;
}
void Ceg::fajlbaIr(ostream &os) const{
    os << "C;"<<id<<";"<< nev.c_str() << ";" << cim.c_str()<<";"<<munkahelyiszam.c_str()<<";"<<faxszam.c_str()<<";"<<"\n";
}

Kontakt* Ceg::clone() const{
    return new Ceg(*this);
}
