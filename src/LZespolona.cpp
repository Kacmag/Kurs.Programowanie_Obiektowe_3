#include "LZespolona.hh"

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator+(LZespolona Skl1, LZespolona Skl2) {
  LZespolona Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje podzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator/(LZespolona Skl1, LZespolona Skl2) {
  LZespolona Wynik, Sprze, Licznik;
  double Modul;

  Sprze = Skl2.Sprzezenie();
  Licznik = *this * Sprze;
  Modul = Skl2.Modul2();

  if (Modul == 0) {
    cerr << "ERR: Nie wolno dzielić przez 0." << endl;
    exit(2);
  }
  Wynik.re = Licznik.re / Modul;
  Wynik.im = Licznik.im / Modul;
  return Wynik;
}
