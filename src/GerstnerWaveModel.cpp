#include <iostream>
#include <string>
#include "Dvector.h"
#include "GerstnerWave.h"
#include "WaveModel.h"
#include "GerstnerWaveModel.h"
#include <cmath>
#include <list>
using namespace std;

GerstnerWaveModel::GerstnerWaveModel(const Dvector windDir,
  const double align, const double ajust, double intensity,
  const int nbOndes, const double phase) :
  WaveModel(windDir, align, intensity, 1, ajust)
  //La longeur d'onde vaut 1 par défaut (on en a pas besoin dans les calculs)
  {
    this->sizeList=nbOndes;
    double amplitude=intensity;
    for (int i=0;i<=nbOndes-1;i++){
      //Calcul d'une direction variant légèrement par rapport à l'angle de référence
      //(cette variation est aléatoire)
      double angle=(rand()+(double)RAND_MAX)/(2*(double)RAND_MAX)*align;
      Dvector waveDir=Dvector(2.0,0.0);
      //Application de la matrice de rotation
      waveDir(0)=cos(angle)*windDir(0)-sin(angle)*windDir(1);
      waveDir(1)=sin(angle)*windDir(0)+cos(angle)*windDir(1);
      this->waveList.push_back(GerstnerWave(phase,waveDir, amplitude));
    }
  }
  GerstnerWaveModel::GerstnerWaveModel(const GerstnerWaveModel & gers){}
  GerstnerWaveModel::~GerstnerWaveModel(){}
  double GerstnerWaveModel::operator()(int x, int y, double temps){
    double h=0;
    for (std::list<GerstnerWave>::iterator it=this->waveList.begin();
          it != this->waveList.end(); ++it)
    {
      //On somme les contributions des différentes ondes.
      h+=(*it)(x, y, temps);
    }
    //On ajuste la hauteur.
    return this->getAjust()*h/this->sizeList;
  }

  std::list<GerstnerWave> GerstnerWaveModel::getList(){
    return this->waveList;
  }
