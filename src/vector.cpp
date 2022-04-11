#include "vector.hh"

double Vector::get_Tablica(int i) const
{
    return Tablica[i];
}



double &Vector::set_Tablica(int i)
{
    return Tablica[i];
}



double Vector::operator[](int i) const
{
    if (i >= 0 && i < MATRIXSIZE)
        return Tablica[i];
    else
        cerr << "Blad indexu" << endl;
    return Tablica[i];
}



double &Vector::operator[](int i)
{
    if (i >= 0 && i < MATRIXSIZE)
        return Tablica[i];
    else
        cerr << "Blad indexu" << endl;
    return  Tablica[i];
}



Vector Vector::operator+(Vector const Skl)
{
    Vector Wynik;
    for (int i = 0; i < MATRIXSIZE; i++)
        Wynik[i] = Tablica[i] + Skl[i];

    return Wynik;
}



Vector Vector::operator-(Vector const Skl)
{
    Vector Wynik;
    for (int i = 0; i < MATRIXSIZE; i++)
        Wynik[i] = Tablica[i] - Skl[i];

    return Wynik;
}



double Vector::operator*(Vector const Skl)
{
    double Wynik = 0;
    for (int i = 0; i < MATRIXSIZE; i++)
        Wynik += Tablica[i] * Skl[i];

    return Wynik;
}



Vector Vector::operator*(double const Skl)
{
    Vector Wynik;
    for (int i = 0; i < MATRIXSIZE; i++)
        Wynik[i] = Tablica[i] * Skl;

    return Wynik;
}



Vector Vector::operator/(double const Skl)
{
    Vector Wynik;
    for (int i = 0; i < MATRIXSIZE; i++)
        Wynik[i] = Tablica[i] / Skl;

    return Wynik;
}



std::istream &operator>>(std::istream &Strm, Vector &vec)
{
    for(int i=0; i<MATRIXSIZE; i++)
      Strm>>vec[i];

return Strm;
}



std::ostream &operator<<(std::ostream &Strm, const Vector &vec)
{
    for(int i=0; i<MATRIXSIZE; i++)
      Strm<<vec[i]<<" ";

return Strm;
}
