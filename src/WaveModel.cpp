#include <cstdlib>
#include <iostream>
#include "WaveModel.h"
using namespace ::std;

WaveModel::WaveModel(const Dvector windDir, const double waveAlign, const double intensity,
  const double waveLength, const double ajust){

    this->windDir=windDir;
    this->waveAlign=waveAlign;
    this->intensity=intensity;
    this->waveLength=waveLength;
    this->ajust=ajust;
  }
  //constructeur par défaut: mise à zero de tout les paramètres
  WaveModel::WaveModel(){
    // WaveModel(0, 0, 0, 0, 0);
  }
  WaveModel::WaveModel(const WaveModel & wave){
    this->windDir=wave.windDir;
    this->waveAlign=wave.waveAlign;
    this->intensity=wave.intensity;
    this->waveLength=wave.waveLength;
    this->ajust=wave.ajust;
  }
  WaveModel::~WaveModel(){}

  void WaveModel::display(ostream& str){
    str<<"MODELE: \n";
    str << "Direction du vent: ";
    this->getWindDir().display(str);
    str<<"\n";
    str << "Alignement des vagues: " << this->waveAlign << "\n";
    str << "Intensite des vagues: " << this->intensity << "\n";
    str << "Longeur d'onde: " << this->waveLength << "\n";
    str << "Ajustement: " << this->ajust << "\n";
    str<<"\n";
  }
  WaveModel & WaveModel::operator = (const WaveModel & wave){
    this->windDir=wave.windDir;
    this->waveAlign=wave.waveAlign;
    this->intensity=wave.intensity;
    this->waveLength=wave.waveLength;
    this->ajust=wave.ajust;
    return *this;
    }

  Dvector WaveModel::getWindDir(){
    return this->windDir;
  }
  double WaveModel::getwaveAlign(){
    return this->waveAlign;
  }
  double WaveModel::getIntensity(){
    return this->intensity;
  }
  double WaveModel::getAveLength(){
    return this->waveLength;
  }
  double WaveModel::getAjust(){
    return this->ajust;
  }
  //pas besoin du mot clé virtuel dans l'mplémentation
  double WaveModel::operator ()(int x, int y, double temps){
    return 0;
  }
