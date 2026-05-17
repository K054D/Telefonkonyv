#include "menu.h"
#include "barat.h"
#include "ceg.h"
#include <iostream>
#include <cstring>
#include "memtrace.h"


void Menu::indit(){
    tk.fajlbolToltes("adatok.txt");

    int valasztas = -1;
    while(valasztas != 0){
        system("cls");
        menuKiir();
        std::cout << "Valasszon egy menupontot: ";
        std::cin >> valasztas;

        // A \n-t törölje ki az input bufferből
        std::cin.ignore(INT_MAX,'\n');

        switch(valasztas){
            case 1 :
                system("cls");
                adatFelvetel();
                break;
            case 2 :
                system("cls");
                listazas();
                break;
            case 3 :
                system("cls");
                keresesInditasa();
                break;
            case 4 :
                system("cls");
                adatTorol();
                break;
            case 5 :
                system("cls");
                adatModosit();
                break;
            case 0 :std::cout << "Adatok mentese es kilepes...\n"; break;
            default:std::cout << "Ervenytelen valasztas"; break;
        }
        if (valasztas != 0) {
            std::cout << "\nNyomjon ENTER-t a menube valo visszatereshez...";
            std::cin.get();
        }
    }


    tk.fajlbaMent("adatok.txt");
}

void Menu::menuKiir() const{
    std::cout << "*** TELEFONKONYV MENU *** \n";
    std::cout << "1. Uj adat felvetele \n";
    std::cout << "2. Adatok kilistazasa \n";
    std::cout << "3. Kereses inditasa \n";
    std::cout << "4. Adat torlese \n";
    std::cout << "5. Adat modositasa \n";
    std::cout << "0. Kilepes \n";
    std::cout << "***************************************\n";
}

void Menu::listazas() const{
    tk.listaz();
}

void Menu::adatFelvetel(){
    char tipus;
    std::cout << "Milyen tipusu kontaktot szeretne felvenni? (B- Barat // C- Ceg): ";
    std::cin >> tipus;

    std::cin.ignore(INT_MAX,'\n');

    if(tipus != 'B' && tipus != 'b' && tipus != 'C' && tipus != 'c'){
        std::cout << "Hibas tipus!";
        return;
    }

    int id;
    std::cout << "Adja meg a kontakt ID-jet: ";
    std::cin >> id;
    std::cin.ignore(INT_MAX,'\n');

    char nev[256], cim[256];
    std::cout << "Nev: ";
    std::cin.getline(nev, 256);
    std::cout << "Cim: ";
    std::cin.getline(cim, 256);

    if(tipus == 'B' || tipus == 'b'){
        char bnev[256], pszam[256];
        std::cout << "Becenev: ";
        std::cin.getline(bnev, 256);
        std::cout << "Privat szam: ";
        std::cin.getline(pszam, 256);
        tk.hozzaad(new Barat(bnev, pszam, id,nev,cim));
        std::cout << "Barat sikeresen felveve!\n";
    }else if(tipus == 'C' || tipus == 'c'){
        char mszam[256], fszam[256];
        std::cout << "Munkahelyi szam: ";
        std::cin.getline(mszam, 256);
        std::cout << "Fax szam: ";
        std::cin.getline(fszam, 256);
        tk.hozzaad(new Ceg(mszam, fszam, id,nev,cim));
        std::cout << "Ceg sikeresen felveve!\n";
    }
}

void Menu::keresesInditasa() const{
   std::cout << "*** Keresesi feltetelek ***\n";
   std::cout << "1. Kereses ID alapjan\n";
   std::cout << "2. Kereses nev alapjan (pontos egyezessel)\n";
   std::cout << "3. Kereses cim alapjan\n";
   std::cout << "Valasszon keresesi modot: ";

   int opcio;
   std::cin >> opcio;
   std::cin.ignore(INT_MAX,'\n');

   if(opcio == 1){
        int keresettID;
        std::cout << "Adja meg a keresett ID-t: ";
        std::cin >> keresettID;
        std::cin.ignore(INT_MAX,'\n');

        system("cls");
        std::cout << "Kereses eredmenye:\n";
        tk.keres([keresettID](const Kontakt& k){
            return k.getId() == keresettID;
        });
   }
   else if(opcio == 2){
        char keresettNev[256];
        std::cout << "Adja meg a keresett nevet (pontos egyezes): ";
        std::cin.getline(keresettNev, 256);

        system("cls");
        std::cout << "Kereses eredmenye:\n";
        tk.keres([&keresettNev](const Kontakt& k){
            return strcmp(k.getNev().c_str(), keresettNev) == 0;
        });
   }
    else if(opcio == 3){
        char keresettCim[256];
        std::cout << "Adja meg a keresett cimet: ";
        std::cin.getline(keresettCim, 256);

        system("cls");
        std::cout << "Kereses eredmenye:\n";
        tk.keres([&keresettCim](const Kontakt& k){
            return strstr(k.getCim().c_str(), keresettCim) != nullptr;
        });
   }else{
        std::cout << "Ervenytelen opcio!\n";
   }
}

void Menu::adatTorol(){
    int id;
    std::cout << "Adja meg a torlendo kontakt ID-jet: ";
    std::cin >> id;
    std::cin.ignore(INT_MAX,'\n');

    Kontakt* torlendo = tk.getKontakt(id);
    if (torlendo == nullptr) {
        std::cout << "Nem talalhato kontakt ezzel az ID-vel!\n";
        return;
    }

    std::cout << "\n*** Torlendo kontakt adatai ***\n";
    torlendo->kiir();


    char valasz;
    std::cout << "\nBiztosan torolni szeretne a kontaktot? (i/n): ";
    std::cin >> valasz;
    std::cin.ignore(INT_MAX, '\n');
    if (valasz == 'i' || valasz == 'I') {
        if (tk.torol(id)) {
            std::cout << "A(z) " << id << " ID-ju kontakt torolve lett.\n";
        } else {
            std::cout << "Hiba a torles soran!\n";
        }
    } else {
        std::cout << "Torles megszakitva. A kontakt megmaradt.\n";
    }


}

void Menu::adatModosit(){
    int id;
    std::cout << "Adja meg a modositando kontakt ID-jet: ";
    std::cin >> id;
    std::cin.ignore(INT_MAX,'\n');

    Kontakt* modositando = tk.getKontakt(id);

    if (modositando == nullptr) {
        std::cout << "Nem talalhato kontakt ezzel az ID-vel!\n";
        return;
    }

    std::cout << "\n*** Modositando kontakt jelenlegi adatai ***\n";
    modositando->kiir();

    std::cout << "\n*** Uj adatok megadasa ***\n";
    char ujNev[256], ujCim[256];

    std::cout << "Uj nev: ";
    std::cin.getline(ujNev, 256);
    std::cout << "Uj cim: ";
    std::cin.getline(ujCim, 256);

    modositando->setNev(ujNev);
    modositando->setCim(ujCim);

    if (Barat* b = dynamic_cast<Barat*>(modositando)) {
        char ujBnev[256], ujPszam[256];
        std::cout << "Uj becenev: ";
        std::cin.getline(ujBnev, 256);
        std::cout << "Uj privat szam: ";
        std::cin.getline(ujPszam, 256);

        b->setBecenev(ujBnev);
        b->setPrivatSzam(ujPszam);
    }else if (Ceg* c = dynamic_cast<Ceg*>(modositando)) {
        char ujMszam[256], ujFszam[256];
        std::cout << "Uj munkahelyi szam: ";
        std::cin.getline(ujMszam, 256);
        std::cout << "Uj fax szam: ";
        std::cin.getline(ujFszam, 256);

        c->setMunkahelyiSzam(ujMszam);
        c->setFax(ujFszam);
    }
    std::cout << "\nA(z) " << id << " ID-ju kontakt sikeresen modositva!\n";
}
