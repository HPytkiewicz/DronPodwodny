#ifndef DRON_HH
#define DRON_HH


#include "rozmiar.h"
#include "Prostopadloscian.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>

class Dron{
protected:
  Wektor3D position;
  
  double speed;

  Wektor3D angle;
  Wektor3D point0Body;
  Wektor3D point0Propeller;
  Prostopadloscian body;
  Prostopadloscian propeller[2];

public:
  Dron(){
    speed=0;
    point0Body = {2,3,2};
    point0Propeller = {0.5,0.5,0.5};
  }

  void setSpeed(double S){speed = S;}
  double getSpeed() const {return speed;}

  void setAngle(double A){angle[2]=A;}
  double getAngle() const {return angle[2];}
  void addAngle(double A){angle[2]+=A;}

  void setAngleUpDown(double A){angle[0] = A;}
  double setAngleUpDown() const {return angle[0];}

  void setPosition(Wektor3D Wektor){position = Wektor;}
  Wektor3D getPosition() const {return position;}

  void AIDraw(std::shared_ptr<drawNS::Draw3DAPI> api);
  void Move();

  void UnDraw(std::shared_ptr<drawNS::Draw3DAPI> api);
  int DrawPropeller0(std::shared_ptr<drawNS::Draw3DAPI> api);
  int DrawPropeller1(std::shared_ptr<drawNS::Draw3DAPI> api);
  int DrawBody(std::shared_ptr<drawNS::Draw3DAPI> api);
};

#endif
