#include <cstdlib>
#include "GerstnerWave.h"
#include "Dvector.h"
#include <iostream>

using namespace std;

int main (){
  Dvector direction=Dvector(2,1.0);
  GerstnerWave gers=GerstnerWave(20,direction);
  gers.display(std::cout);
  Dvector direction1= Dvector(2,1.454545545);
  GerstnerWave gers1=GerstnerWave(2.44,direction1);
  gers1.display(std::cout);
  GerstnerWave gers2=gers;
  gers2.display(std::cout);
  GerstnerWave gers3=GerstnerWave(gers1);
  gers3.display(std::cout);
  double h=gers3(direction1(0), direction1(1), 1.0);
  std::cout << "hauteur= " << h << std::endl;
}
