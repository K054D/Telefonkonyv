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
    std::cout << "Milyen típusu kontaktot szeretne felvenni? (B- Barat // C- Ceg): ";
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

void Menu::keresesInditasa(){
    char keresett[256];
    std::cout << "Ird be a keresett nevet (pontos egyezes): ";
    std::cin.getline(keresett, 256);

    std::cout << "*** Eredmeny: ***\n";

    tk.keres([&keresett](const Kontakt& k) {
        return strcmp(k.getNev().c_str(), keresett) == 0;
    });
}

void Menu::adatTorol(){
    int id;
    std::cout << "Adja meg a torlendo kontakt ID-jet: ";
    std::cin >> id;
    std::cin.ignore(INT_MAX,'\n');

    if(tk.torol(id)){
        std::cout << "A(z)" << id << "ID-ju kontakt torolve lett";
    }else{
       std::cout << "Nem talalhato kontakt ezzel az ID-vel!";
    }
}

void Menu::adatModosit(){
    int id;
    std::cout << "Adja meg a modositando kontakt ID-jet: ";
    std::cin >> id;
    std::cin.ignore(INT_MAX,'\n');

    if(tk.torol(id)){
        std::cout << "Kontakt megtalalva, add meg az uj kontakt adatait!\n";
        adatFelvetel();
    }else{
       std::cout << "Nem talalhato kontakt ezzel az ID-vel!";
    }
}
