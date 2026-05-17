#include <iostream>
#include <stdexcept>
#include <windows.h>
#include "menu.h"
#include "memtrace.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    try {
        Menu m;
        m.indit();
    }
    catch (const std::exception& e) {
        cerr << "\nVegzetes hiba tortent a program futasa soran: " << e.what() << endl;
    }
    return 0;
}
