// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#endif

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "exampleConfig.h"
#include "matrix.hh"
#include "vector.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 *
 * EDIT: dodane kreowanie wektorow i macierzy 
 */

int main() {
  std::cout
      << "Project System of Linear Equations" 
      /* << "\n Based on C++ Boiler Plate ver."
      << PROJECT_VERSION_MAJOR // duże zmiany, najczęściej brak kompatybilności wstecz
      << "." << PROJECT_VERSION_MINOR // istotne zmiany
      << "." << PROJECT_VERSION_PATCH // naprawianie bugów
      << "." << PROJECT_VERSION_TWEAK // zmiany estetyczne itd. */
      << std::endl;
  // std::system("cat ../LICENSE");
  std::cout << "Vector:" << std::endl;
  Vector tmpV1 = Vector();
  std::cout << "Vector - konstruktor bezparametryczny:\n" << tmpV1 << std::endl;
  double argumentsV[] = {1.0, 2.0};
  Vector tmpV2 = Vector(argumentsV);
  std::cout << "Vector - konstruktor parametryczny:\n" << tmpV2 << std::endl;

  std::cout << "Matrix:" << std::endl;
  Matrix tmpM1 = Matrix();
  std::cout << "Matrix - konstruktor bezparametryczny:\n" << tmpM1 << std::endl;
  double argumentsM[][SIZE] = {{1.0, 2.0}, {3.0, 4.0}};
  Matrix tmpM2 = Matrix(argumentsM);
  std::cout << "Matrix - konstruktor parametryczny:\n" << tmpM2 << std::endl;
}
