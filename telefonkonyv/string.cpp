#include <iostream>             // Kiíratáshoz
#include <cstring>              // Stringmûveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string.h"

using std::cin;
using std::ios_base;

// Konstruktor: egy char karakterbõl (createStrFromChar)
String::String(char ch) {
    len = 1;
    adat = new char[len+1];
    adat[0] = ch;
    adat[1] = '\0';
}


// Konstruktor: egy nullával lezárt char sorozatból (createStringFromCharStr)
String::String(const char *p) {
    len = strlen(p);
    adat = new char[len+1];
    strcpy(adat, p);
}

// Másoló konstruktor
String::String(const String& s1) {
    len = s1.len;
    adat = new char[len+1];
    strcpy(adat, s1.adat);
}

// operator=
String& String::operator=(const String& rhs_s) {
    if (this != &rhs_s) {
        delete[] adat;
        len = rhs_s.len;
        adat = new char[len+1];
        strcpy(adat, rhs_s.adat);
    }
    return *this;
}


// [] operátorok: egy megadott indexû elem REFERENCIÁJÁVAL térnek vissza.
// indexhiba esetén dobjon egy const char * típusú hibát!
char& String::operator[](unsigned int idx) {
    if (idx >= len) throw "String: indexelesi hiba";
    return adat[idx];
}

const char& String::operator[](unsigned int idx) const {
    if (idx >= len) throw "String: indexelesi hiba";
    return adat[idx];
}

// + operátor, ami két stringet ad össze (concatString)
String String::operator+(const String& rhs_s) const {
    String temp;
    temp.len = len + rhs_s.len;
    delete []temp.adat;
    temp.adat = new char[temp.len+1];
    strcpy(temp.adat, adat);
    strcat(temp.adat, rhs_s.adat);

    return temp;

}
// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s0) {
    os << s0.c_str();
    return os;
}

// << operátor, ami beolvas az istreamrõl egy szót
std::istream& operator>>(std::istream& is, String& s0) {
    unsigned char ch;
    s0 = String("");
	std::ios_base::fmtflags fl = is.flags();
	is.setf(ios_base::skipws);
    while (is >> ch) {
	    is.unsetf(ios_base::skipws);
        if (isspace(ch)) {
            is.putback(ch);
            break;
        } else {
            s0 = s0 + ch;
        }
    }
	is.setf(fl);
    return is;
}

bool String::operator==(const String& rhs_s) const{
    return strcmp(this->c_str(), rhs_s.c_str()) == 0;
}
