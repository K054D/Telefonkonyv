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

    Menu m;
    m.indit();
    return 0;
}
