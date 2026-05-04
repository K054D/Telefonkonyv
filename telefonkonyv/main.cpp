#include <iostream>
#include <stdexcept>
#include "telefonkonyv.h"
#include "menu.h"
#include "barat.h"
#include "ceg.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

class Hiba {
public:
    Hiba(const string& uzenet) {}
};

void test_1() {
    cout << "Program inditasa" << endl;
    Menu app;
    app.indit();
}

void test_2() {
    cout << "Heterogén kollekció mûködése" << endl;
    Telefonkonyv tk;
    tk.hozzaad(new Barat("Ferike", "06301234567", 1, "Nagy Ferenc", "Budapest"));
    tk.hozzaad(new Ceg("06302345678", "06303456789", 1, "Nagy Ferenc", "Budapest"));

    tk.listaz();
}

void test_3() {
    cout << "Generikus keresés" << endl;
    Telefonkonyv tk;
    tk.hozzaad(new Barat("Ferike", "06301234567", 1, "Nagy Ferenc", "Budapest"));


    tk.keres([](const Kontakt& k) {return true;});
}



int main() {
    try {
        int nr;
        if (cin >> nr) {
            switch (nr) {
                case 1:
                    test_1();
                    break;
                case 2:
                    test_2();   // Heterogén tároló teszt
                case 3:
                    test_3();
                    break;
                default:
                    cout << "Ismeretlen teszteset!" << endl;
                    break;
            }
        }
    } catch (std::exception& e) {
        cerr << e.what() << endl;
    } catch (Hiba&) {
        cerr << "Sajat kivetel!" << endl;
    } catch (...) {
        cerr << "*** Ismeretlen, nagy hiba! ***" << endl;
    }

    return 0;
}
