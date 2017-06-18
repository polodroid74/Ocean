#include <cstdlib>
#include "PhilipsWave.h"
#include "Dvector.h"
#include "PhilipsWaveModel.h"
#include "../src/Height.cpp"
#include <iostream>

using namespace std;

int main (){
  //creation du modele
  Dvector direction=Dvector(2.0,1.0);
  PhilipsWave philips = PhilipsWave(10, 100, 100, 100, 90, 90);
  PhilipsWaveModel wModel = PhilipsWaveModel(direction, 0.5, 2, 10, 0.2, philips);

  //creation de la map
  Dvector coor;
  int nbpoints=90;
  Height hauteurs = Height(nbpoints, nbpoints, 100, 100, 0);
  for (int i=0;i<nbpoints;i++){
    for(int j=0;j<nbpoints;j++){
      hauteurs(i,j)=wModel(i, j, 100.0);
    }
  }
  hauteurs.displayFile(std::cout);
}
