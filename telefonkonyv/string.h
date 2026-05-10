#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>


class String {
    char *adat;    ///< pointer az adatra
    size_t hossz;     ///< hossz lezáró nulla nélkül
public:

    String() : adat(nullptr), hossz(0) {}
    String(const char* txt) : adat(nullptr), hossz(0) {}
    String(const String& rhs) : adat(nullptr), hossz(0) {}
    ~String() { delete[] adat;}

    String& operator=(const String& rhs);

    const char* c_str() const { return adat; }
};

#endif // STRING_H_INCLUDED
