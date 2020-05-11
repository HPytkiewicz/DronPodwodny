#ifndef BRYLA_HH
#define BRYLA_HH

#include "rozmiar.h"
#include "MacierzOb.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>
#include <string>

class Bryla{
protected:
  MacierzOb orientation;
  Wektor3D center;
  Wektor3D point0;
  int id;

public:
  Bryla() : id(-1){}
  Bryla(MacierzOb M, Wektor3D S, Wektor3D P) : orientation(M), center(S), point0(P), id(-1) {}

  void setCenter(const Wektor3D & Wektor){center = Wektor;}
  Wektor3D getCenter() const {return center;}

  void setPoint0(const Wektor3D & Wektor){point0 = Wektor;}
  Wektor3D getPoint0() const {return point0;}

  void setOrientation(const MacierzOb & Macierz){orientation = Macierz;}
  MacierzOb getOrientation() const {return orientation;}

  int getID() const {return id;}

  virtual int Draw(std::shared_ptr<drawNS::Draw3DAPI> api) = 0;
  virtual void UnDraw(std::shared_ptr<drawNS::Draw3DAPI> api) {if(id!=-1){api->erase_shape(id); id =-1;}}
};

#endif
