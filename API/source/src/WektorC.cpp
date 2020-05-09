include "SWektor.cpp"
#include "LZespolona.hh"
#include <iostream>
#include <iomanip>

template class Wektor<double, 5>;

template Wektor<double,5> operator *(double a, const Wektor<double,5> &Wektor2);
template std::ostream & operator <<(std::ostream &Strm, const Wektor<double, 5> &wektor);
template std::istream & operator >>(std::istream &Strm, Wektor<double, 5> &wektor);


template class Wektor<LZespolona, 5>;

template Wektor<LZespolona, 5> operator *(LZespolona a, const Wektor<LZespolona,5> &Wektor2);
template std::ostream & operator <<(std::ostream &Strm, const Wektor<LZespolona, 5> &wektor);
template std::istream & operator >>(std::istream &Strm, Wektor<LZespolona, 5> &wektor);
