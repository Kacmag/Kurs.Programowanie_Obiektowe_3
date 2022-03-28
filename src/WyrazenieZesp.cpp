#include "WyrazenieZesp.hh"
#include <iostream>

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

bool WczytajWyrazenieZesp(WyrazenieZesp &rWyrZ, std::istream &rStrmWe) {
  rStrmWe >> rWyrZ.Arg1 >> rWyrZ.Op >> rWyrZ.Arg2;

  return rStrmWe.fail() == false;
}
