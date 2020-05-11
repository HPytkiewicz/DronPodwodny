#include "Dron.hh"
#include <iostream>

void Dron::AIDraw(std::shared_ptr<drawNS::Draw3DAPI> api){
  UnDraw(api);
  DrawPropeller0(api);
  DrawPropeller1(api);
  DrawBody(api);
}

void Dron::Move(){
  // osie X i Y
  position = position + speed * (1- abs(sin(angle[0] /180 * M_PI))) * Wektor3D(sin(angle[2] / 180 * M_PI), cos(angle[2] / 180 * M_PI), 0) * (cos(angle[0] / 180 * M_PI) > 0 ? 1 : -1);
  // os Z
  position = position + (speed) * Wektor3D(0, 0, sin(angle[0] / 180 * M_PI));

  speed = 0;
  angle[0] = 0;
}

void Dron::UnDraw(std::shared_ptr<drawNS::Draw3DAPI> api){
  body.UnDraw(api);
  propeller[0].UnDraw(api);
  propeller[1].UnDraw(api);
}

int Dron::DrawPropeller0(std::shared_ptr<drawNS::Draw3DAPI> api){
  Wektor3D tempPoint = MacierzOb(angle) * point0Body;

  propeller[0].setCenter(position - tempPoint);
  propeller[0].setPoint0(point0Propeller);
  MacierzOb tempMacierz(angle);
  propeller[0].setOrientation(tempMacierz);
  int id = propeller[0].Draw(api);
  return id;
}

int Dron::DrawPropeller1(std::shared_ptr<drawNS::Draw3DAPI> api){
  Wektor3D tempPoint = MacierzOb(angle) * point0Body.Reverse(WymiarX);

  propeller[1].setCenter(position - tempPoint);
  propeller[1].setPoint0(point0Propeller);
  MacierzOb tempMacierz(angle);
  propeller[1].setOrientation(tempMacierz);
  int id = propeller[1].Draw(api);
  return id;
}

int Dron::DrawBody(std::shared_ptr<drawNS::Draw3DAPI> api){
  body.setCenter(position);
  body.setPoint0(point0Body);
  MacierzOb tempMacierz(angle);
  body.setOrientation(tempMacierz);
  int id = body.Draw(api);

  return id;
}
