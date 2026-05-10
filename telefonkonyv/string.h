#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>


class String {
    char *adat;    ///< pointer az adatra
    size_t len;     ///< hossz lezáró nulla nélkül
public:

    /// Konstruktor egy char karakterből
    /// @param ch - karakter
    String(char ch);

    /// Konstruktor egy nullával lezárt char sorozatból
    /// Ez a deafault is!
    /// @param p - pointer egy C sztringre
    String(const char* p = "");

    /// Másoló konstruktor
    /// @param s1 - String, amiből létrehozzuk az új String-et
    String(const String& rhs);

    /// Destruktor
    ~String() { delete[] adat;}

    /// Értékadó operátor.
    /// @param rhs_s - jobboldali String
    /// @return baoldali (módosított) string (referenciája)
    String& operator=(const String& rhs);

    /// C-sztringet ad vissza
    /// @return pinter egy '\0'-val lezárt (C) sztringre
    const char* c_str() const { return adat; }

     /// A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// @param idx - charakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob.
    char& operator[](unsigned int idx);

     /// A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// @param idx - karakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob (assert helyett).
    const char& operator[](unsigned int idx) const;

    /// Két Stringet összefűz
    /// @param rhs_s - jobboldali String
    /// @return új String, ami tartalmazza a két stringet egmás után
    String operator+(const String& rhs_s) const;

     /// Összehasonlít 2 Stringet.
    /// @param rhs_s - jobboldali String
    /// @return bool (a két String egyenlő-e)
    bool operator==(const String& rhs_s) const;
};
/// Globális függvények:
/// kiír az ostream-re
/// @param os - ostream típusú objektum
/// @param s0 - String, amit kiírunk
/// @return os
std::ostream& operator<<(std::ostream& os, const String& s0);

/// Beolvas az istream-ről egy szót egy string-be.
/// @param is - istream típusú objektum
/// @param s0 - String, amibe beolvas
/// @return is
std::istream& operator>>(std::istream& is, String& s0);


#endif // STRING_H_INCLUDED
