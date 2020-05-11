#include "Prostopadloscian.hh"
#include <iostream>

Prostopadloscian::Prostopadloscian(const Wektor3D & W1){
  point0=W1;
}

Prostopadloscian::Prostopadloscian(const MacierzOb & Macierz, const Wektor3D &Srod, const Wektor3D &Punkt){
  center=Srod;
  point0=Punkt;
  orientation=Macierz;
}

Prostopadloscian::Prostopadloscian(const Wektor3D & Alfa, const Wektor3D & Srod, const Wektor3D & Punkt){
  center=Srod;
  point0=Punkt;
  orientation=MacierzOb(Alfa[0], WymiarX)*MacierzOb(Alfa[1], WymiarY)*MacierzOb(Alfa[2], WymiarZ);
}

void Prostopadloscian::Refresh(){
  punkty[0]=center + orientation * point0;
  punkty[1]=center + orientation * point0.Reverse(WymiarX);
  punkty[2]=center + orientation * point0.Reverse(WymiarX).Reverse(WymiarY);
  punkty[3]=center + orientation * point0.Reverse(WymiarY);
  punkty[4]=center + orientation * point0.Reverse(WymiarZ);
  punkty[5]=center + orientation * point0.Reverse(WymiarZ).Reverse(WymiarX);
  punkty[6]=center + orientation * point0.Reverse(WymiarZ).Reverse(WymiarX).Reverse(WymiarY);
  punkty[7]=center + orientation * point0.Reverse(WymiarZ).Reverse(WymiarY);
}

int Prostopadloscian::Draw(std::shared_ptr<drawNS::Draw3DAPI> api){
  Refresh();
  id=api->draw_polyhedron(vector<vector<Point3D> >{
      {drawNS::Point3D(punkty[0]), drawNS::Point3D(punkty[1]), drawNS::Point3D(punkty[2]), drawNS::Point3D(punkty[3])},
      {drawNS::Point3D(punkty[4]), drawNS::Point3D(punkty[5]), drawNS::Point3D(punkty[6]), drawNS::Point3D(punkty[7])}
    },"red");

  return id;
}
