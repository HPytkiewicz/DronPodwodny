#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "rozmiar.h"
#include "Bryla.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>

using std::vector;
using drawNS::Point3D;

class Prostopadloscian : public Bryla{
protected:
  Wektor3D punkty[8];
public:
  Prostopadloscian() : Bryla() {}
  Prostopadloscian(const Wektor3D &W1);
  Prostopadloscian(const MacierzOb & Macierz, const Wektor3D & Srod, const Wektor3D & Punkt);
  Prostopadloscian(const Wektor3D &Alfa, const Wektor3D & Srod, const Wektor3D & Punkt);

  void Refresh();
  /*!
   * \brief Draws cuboid
   * \param api -
   * \return id of shape
   */
  int Draw(std::shared_ptr<drawNS::Draw3DAPI> api) override;
};

#endif
