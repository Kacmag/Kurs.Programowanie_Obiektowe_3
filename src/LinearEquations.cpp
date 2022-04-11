#include "LinearEquations.hh"

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
        Strm>>UklRown.set_Matriks()>>UklRown.set_Wyraz_wolny();
        return Strm;
}

void UkladRownanLiniowych::fail()
{
        vecFail=Matriks*Wynik-Wyraz_wolny;
        std::cout<<Matriks*Wynik<<endl;
        std::cout<<Wyraz_wolny<<endl;
        std::cout<<Matriks*Wynik-Wyraz_wolny<<endl;
        failLength=pow(vecFail*vecFail, 0.5);

        std::cout<<"Wektor bledu: Ax-b =: ("<<scientific<<vecFail<<")"<<std::endl;

        std::cout<<"Dlugosc wektora bledu  ||Ax-b|| =: "<<scientific<<failLength<<std::endl;
}

std::ostream& operator << ( std::ostream &Strm,  const UkladRownanLiniowych    &UklRown)
{
        Strm<<"Podana macierz w postaci transponowanej: "<<std::endl;
        Strm<<UklRown.get_Matriks();

        Strm<<"Wektor Wyrazów wolnych: "<<std::endl;
        Strm<<UklRown.get_Wyraz_wolny();

        return Strm;
}

void UkladRownanLiniowych::cramerMethod()
{
    
    double Wyznaczniki[MATRIXSIZE];
    double Wyznacznik_Glowny;

    Matriks.gausMethod();
    Wyznacznik_Glowny=Matriks.get_Wyznacznik();

    Matrix XYZ;
    for(int i=0; i<MATRIXSIZE; i++)
    {
        XYZ=Matriks;
        XYZ.podmianaWiersza(Wyraz_wolny,i);
        XYZ.gausMethod();

        Wyznaczniki[i]=XYZ.get_Wyznacznik();
    }
    if(Wyznacznik_Glowny!=0)
    {
        for(int i=0; i<MATRIXSIZE; i++)
        {
            Wynik[i]=Wyznaczniki[i]/Wyznacznik_Glowny;
        }
   
    }
    else if(Wyznacznik_Glowny==0)
    {
        bool czy_nieoznaczony=true;
         for(int i=0; i<MATRIXSIZE; i++)
     {
         if(Wyznaczniki[i]!=0)
         {
             std::cout<<"Ten uklad jest sprzeczny"<<std::endl;
             czy_nieoznaczony=false;
             break;
         }
     }
     if(czy_nieoznaczony)
     {
                    std::cout<<"Ten uklad jest nieoznaczony"<<std::endl;
     }
        
    }
}