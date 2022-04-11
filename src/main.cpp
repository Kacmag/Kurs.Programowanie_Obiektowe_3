#include <iostream>
#include "vector.hh"
#include "matrix.hh"
#include "LinearEquations.hh"



using namespace std;

int main()
{

    UkladRownanLiniowych   UklRown; 
    cout << endl << "Podaj macierz w postaci transponowanej:" << endl << endl;

    cin>>UklRown;
    cout<<UklRown<< endl;;

    cout<<"Rozwiazanie x = (x1, x2, x3)"<<endl;
    UklRown.cramerMethod();

    cout<<UklRown.get_Wynik()<<endl;
    UklRown.fail();
    
}
