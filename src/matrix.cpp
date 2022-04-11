#include "matrix.hh"



Vector Matrix::operator[](int i) const
{
    return Tablica[i];
}

Vector &Matrix::operator[](int i)
{
    return Tablica[i];
}

void Matrix::gausMethod()
{
    Matrix pomoc=*this;
    int a = 1;
    double suma=1;
    for (int i = 0; i < MATRIXSIZE; i++)
    {
            for (int j = i + 1; j < MATRIXSIZE; j++)
            {
                
                if (pomoc[i][i] == 0)
                {
                        for (int k = i + 1; k < MATRIXSIZE; k++)
                        {
                            if (pomoc[k][i] != 0)
                            {
                            std::swap(pomoc[i], pomoc[k]);
                            a*=-1;
                            }
                            else
                            {
                            break;
                            }
                        }             
                }
                else
                {
                    
                    double  dzielnik;
                    Vector vec;
                    for(int t = i + 1; t < MATRIXSIZE; t++)
                    {
                            dzielnik=pomoc[t][i]/pomoc[i][i];
                            vec=pomoc[i]*dzielnik;
                            pomoc[t]=pomoc[t]-vec;

                    }
                
                } 
            }
    }
    for (int i = 0; i < MATRIXSIZE; i++)
    {
        suma=suma*pomoc[i][i];
    }
    
    suma*=a;
    Wyznacznik=suma;
    
}
  Vector Matrix::operator*(Vector Skl)
  {
        Vector wynik;
        Vector suma;
            for(int i=0; i<MATRIXSIZE; i++)
            {
                suma=suma+Tablica[i]*Skl[i];
            } 
        wynik=suma;
        return wynik;
  }


std::ostream &operator<<(std::ostream &Strm, const Matrix &Matriks)
{
    for (int i = 0; i < MATRIXSIZE; i++)
        Strm << Matriks[i] << endl;
    return Strm;
}

  void Matrix::podmianaWiersza(Vector wek, int i)
  {
    Tablica[i]=wek;
  }





std::istream &operator>>(std::istream &Strm, Matrix &Matriks)
{
    for (int i = 0; i < MATRIXSIZE; i++)
        Strm >> Matriks[i];
    return Strm;
}




