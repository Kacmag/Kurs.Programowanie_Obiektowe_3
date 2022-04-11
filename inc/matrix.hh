#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "size.h"
#include "vector.hh"
#include <algorithm>
#include <iostream>

class Matrix 
{

        Vector Tablica[MATRIXSIZE]; 

        double Wyznacznik;



        public:

        Vector operator[](int i) const;
        Vector &operator[](int i);
        Vector operator*(Vector Skl);

        double get_Wyznacznik()const{return Wyznacznik;};
        void gausMethod();
        void podmianaWiersza(Vector wek, int i);
        
};

//Przeciazenia operatora >>
std::istream& operator >> (std::istream &Strm, Matrix &Matriks);
//Przeciazenia operatora <<
std::ostream& operator << (std::ostream &Strm, const Matrix &Matriks);


#endif
