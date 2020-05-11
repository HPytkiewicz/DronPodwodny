#include <iostream>
#include <iomanip>
#include "Macierz.cpp"

template class Macierz<double,3>;
template Macierz<double,3> operator *(double a, const Macierz<double,3> macierz);
template std::istream& operator >>(std::istream &strm, Macierz<double,3> &macierz);
template std::ostream& operator <<(std::ostream &strm, const Macierz<double,3> &macierz);

