#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <cmath>
#include "matrix.hh"
#include "vector.hh"

class UkladRownanLiniowych 
{

    Matrix Matriks;
    Vector Wyraz_wolny;
    Vector Wynik;
    Vector vecFail;

    double failLength;


    public:

    Matrix get_Matriks()const{return Matriks;};
    Vector get_Wyraz_wolny()const{return Wyraz_wolny;};
    Vector get_Wynik()const{return Wynik;};
    Matrix &set_Matriks(){return Matriks;};
    Vector &set_Wyraz_wolny(){return Wyraz_wolny;};

    void cramerMethod();
    void fail();

};


//Przeciazenia operatora >>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);
//Przeciazenia operatora <<
std::ostream& operator << ( std::ostream &Strm,  const UkladRownanLiniowych    &UklRown);


#endif
