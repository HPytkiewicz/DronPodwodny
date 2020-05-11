#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <cmath>
#include <iostream>

class Wektor3D : public Wektor<double, 3>{
  static int countAll;
  static int countDestroyed;

public:
  static int howMany(){return countAll;}
  static int howMany_now(){return countAll - countDestroyed;}

  Wektor3D() : Wektor<double,3>() {++countAll;}
  Wektor3D(double x, double y, double z) {tab[0] = x; tab[1]=y; tab[2]=z; ++countAll;}
  Wektor3D(const Wektor<double, 3> M) : Wektor<double,3>(M) {++countAll;}
  /*!
   * \brief Destructor, adds 1 to countDestroyed
   */
  ~Wektor3D(){++countDestroyed;}

  Wektor3D Reverse(Wymiar Wymiar)const;
};

#endif
