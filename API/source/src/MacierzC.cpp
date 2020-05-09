#include <iostream>
#include <iomanip>
#include "LZespolona.hh"
#include "SMacierz.cpp"

template class Macierz<double,5>;
template Macierz<double,5> operator *(double a, const Macierz<double,5> macierz);
template std::istream& operator >>(std::istream &strm, Macierz<double,5> &macierz);
template std::ostream& operator <<(std::ostream &strm, const Macierz<double,5> &macierz);

template class Macierz<LZespolona,5>;
template Macierz<LZespolona,5> operator *(double a, const Macierz<LZespolona,5> macierz);
template std::istream& operator >>(std::istream &strm, Macierz<LZespolona,5> &macierz);
template std::ostream& operator <<(std::ostream &strm, const Macierz<LZespolona,5> &macierz);
