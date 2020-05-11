#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "Dr3D_gnuplot_api.hh"
#include "MacierzOb.hh"
#include "Wektor3D.hh"
#include "Dron.hh"

using std::vector;
using std::string;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void sayLoadError(){
  std::cout << "ERROR: Blad wczytywania. "  << std::endl;
}

void sayCountWektor3D(){
  std::cout << "Aktualna ilosc obiektow Wektor3D: " << Wektor3D::howMany_now() << std::endl;
  std::cout << "Laczna ilosc obiektow Wektor3D: " << Wektor3D::howMany() << std::endl;
}

void waitKey(){
  do{
    std::cout << "\n Press a key to continue..." << std::endl;
  }while(std::cin.get() != '\n');
}

int main(){
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-20,20,-20,20,-20,20));
  api->change_ref_time_ms(-1);

  Wektor3D A(2,3,2);

  waitKey();

  Dron D;
  D.AIDraw(api);

  api->redraw();
  char option = 'm';
  double value;
  std::cout << std::endl;
  do{
    switch(option){
    case 'm':
      std::cout << "r - zadaj ruch na wprost" << std::endl;
      std::cout << "o - zadaj zmiane orientacji" << std::endl;
      std::cout << "m - menu" << std::endl;
      std::cout << "p - wyswietl pozycje" << std::endl;
      std::cout << "k - zakoncz program" << std::endl;
      break;
    case 'o':
      std::cout << std::endl << "Podaj wartosc kata obrotu: " << std::endl;
      std::cin >> value;
      if(std::cin.good()){
	for(int i=0;i<100; ++i){
	  D.addAngle(value/100);
	  D.AIDraw(api);
	  api->redraw();
	  usleep(10000);
	}
      }else sayLoadError();
      break;
    case 'r':
      std::cout << std::endl << "Podaj wartosci kata wznoszenia/opadania: " << std::endl;
      std::cin >> value;
      if(std::cin.good()){
	D.setAngleUpDown(value);
	std::cout << std::endl << "Podaj wartosci odleglosci, na ktora ma sie przemiescic dron." << std::endl;
	std::cin >> value;
	if(std::cin.good()){
	D.setSpeed(value);
	D.Move();
      }else sayLoadError();
      }
    else sayLoadError();
    break;
    case 'p':
      std::cout << "Pozycja drona: " << std:: endl;
      std::cout << D.getPosition() << std::endl;

      break;
    }
  if(!std::cin.good()){
    std::cin.clear( );
    std::cin.ignore(10000,'\n');
  }
  D.AIDraw(api);
  std::cout << std::endl;
  sayCountWektor3D();
  std::cout << std::endl;
  std::cout << "Twoj wybor, m - menu";
  std::cin >> option;
  std::cout << std::endl;

  }while(option != 'k');
  waitKey();
}
