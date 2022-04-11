#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "size.h"
#include <iostream>

using namespace std;

class Vector
{
    double Tablica[MATRIXSIZE];

    public:

    double get_Tablica(int i) const;
    double &set_Tablica(int i);
    double operator[](int i) const;
    double &operator[](int i);
    double operator*(Vector const Skl);

    Vector operator+(Vector const Skl);
    Vector operator-(Vector const Skl);
    Vector operator*(double const Skl);
    Vector operator/(double const Skl);
};

//Przeciazenia operatora >>
std::istream &operator>>(std::istream &Strm, Vector &vec);
//Przeciazenia operatora <<
std::ostream &operator<<(std::ostream &Strm, const Vector &vec);

#endif
