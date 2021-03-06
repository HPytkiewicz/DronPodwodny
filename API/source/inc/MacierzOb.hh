#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include "rozmiar.h"
#include "Macierz.hh"
#include "Wektor3D.hh"
#include <cmath>
#include <iostream>

class MacierzOb : public Macierz<double, 3> {
public:
  MacierzOb() : Macierz<double,3>(){
    for(int i=0; i<3; ++i)
      tab[i][i]=1;
  }
  MacierzOb(Wektor3D angle){
    (*this) = MacierzOb(angle[0], WymiarX)*MacierzOb(angle[1], WymiarY)*MacierzOb(angle[2], WymiarZ);
  }
  MacierzOb(double alfa, Wymiar w){
    Obrot(alfa,w);
  }
  MacierzOb(const Macierz<double,3> Macierz) : Macierz<double,3>(Macierz){}

  MacierzOb Obrot(double alfa, Wymiar w){
    double tempAlfa = alfa / 180 * M_PI;
    switch(w){
    case WymiarX:
      // Wspolrzedne obrotu
      tab[1][1] = cos(tempAlfa);
      tab[1][2] = sin(tempAlfa);
      tab[2][1] = -sin(tempAlfa);
      tab[2][2] = cos(tempAlfa);
      // Wspolrzedne zera i jeden
      tab[0][2] = 0;
      tab[0][1] = 0;
      tab[2][0] = 0;
      tab[2][2] = 0;
      tab[0][0] = 1;

      break;
    case WymiarY:
      // Wspolrzedne obrotu
      tab[2][2]= cos(tempAlfa);
      tab[2][0]= sin(tempAlfa);
      tab[0][2]= -sin(tempAlfa);
      tab[0][0]= cos(tempAlfa);
      // Wspolrzedne zera i jeden
      tab[1][0]= 0;
      tab[2][1]= 0;
      tab[0][1]= 0;
      tab[1][2]= 0;
      tab[0][0]= 1;
      
      break;
    case WymiarZ:
      tab[0][0]= cos(tempAlfa);
      tab[0][1]= sin(tempAlfa);
      tab[1][0]= -sin(tempAlfa);
      tab[1][1]= cos(tempAlfa);

      tab[2][0]= 0;
      tab[2][1]= 0;
      tab[0][2]= 0;
      tab[1][2]= 0;
      tab[2][2]= 1;

      break;
    }
    return (*this);
  }
};

#endif
