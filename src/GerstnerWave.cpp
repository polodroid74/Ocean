#include <cstdlib>
#include "GerstnerWave.h"
#include "Dvector.h"
#include <cmath>
#include<iostream>

using namespace ::std;

GerstnerWave::GerstnerWave(const double phase,
  const Dvector direction, double amplitude){
    this->phase=phase;
    this->direction=Dvector(direction);
    //Fréquence calculée conformément au modèle
    this->frequence=sqrt((this->direction).norme()*9.81);
    this->amplitude=amplitude;
  }
GerstnerWave::GerstnerWave(const GerstnerWave & gers){
    this->amplitude=gers.amplitude;
    this->phase=gers.phase;
    this->direction=gers.direction;
    this->frequence=gers.frequence;
}

GerstnerWave::~GerstnerWave(){}

GerstnerWave & GerstnerWave::operator = (const GerstnerWave & gers){
  this->direction=gers.direction;
  this->amplitude=gers.amplitude;
  this->phase=gers.phase;
  this->frequence=gers.frequence;
  return *this;
}
//Accesseurs definis en public
double GerstnerWave::getAmplitude(){
  return this->amplitude;
}
double GerstnerWave::getPhase(){
  return this->phase;
}
Dvector GerstnerWave::getDirection(){
  return this->direction;
}
double GerstnerWave::getFrequence(){
  return this->frequence;
}
void GerstnerWave::setAmplitude(double amplitude){
  this->amplitude=amplitude;
}
void GerstnerWave::setPhase(double phase){
this->phase=phase;
  }
void GerstnerWave::setDirection(Dvector vect){
  this->direction=direction;
}
void GerstnerWave::setFrequence(double frequence){
  this->frequence=frequence;
}
//Affichage
void GerstnerWave::display(ostream& str){
    str<<"MODELE: \n";
    str << "amplitude: " << this->amplitude << "\n";
    str << "Phase: " << this->phase << "\n";
    str << "Frequence: " << this->frequence << "\n";
    str << "direction: \n";
    this->direction.display(str);
    str<<"\n";
  }
 double GerstnerWave::operator()(int x, int y, double temps){
        Dvector coor = Dvector(2);
        coor(0) = x;
        coor(1) = y;
        //Calcul selon le modèle
        return (this->amplitude*cos(this->direction.prodscal(coor)
        -this->frequence*temps+this->getPhase()));
  }
