#include <cstdlib>
#include "GerstnerWave.h"
#include "Dvector.h"
#include "GerstnerWaveModel.h"
#include "../src/Height.cpp"
#include <iostream>

using namespace std;

int main (){
  //creation du modele
  Dvector direction=Dvector(2.0,1.0);
  direction(1)=0.0;
  GerstnerWaveModel gwm=GerstnerWaveModel(direction,30,1.0,3.0,1.0,1.0);

  //creation de la map
  Dvector coor;
  int nbpoints=90;
  Height hauteurs = Height(nbpoints, nbpoints, 100, 100, 0);
  for (int i=0;i<nbpoints;i++){
    for(int j=0;j<nbpoints;j++){
      hauteurs(i,j)=gwm(i, j, 1.0);
    }
  }
  hauteurs.displayFile(std::cout);
}
