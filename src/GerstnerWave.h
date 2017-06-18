#ifndef GERSTNERH
#define GERSTNERH
#include <ostream>
#include <string>
#include "Dvector.h"

class GerstnerWave
{
private:
  //Attributs
  double amplitude;
  double phase;
  Dvector direction= Dvector(2);
  double frequence;
  //la relation entre direction et fréquence est donnée par le modèle
  void setFrequence(double frequence);
  //Methodes declarees en public.
public:
  GerstnerWave( const double phase=0, const Dvector direction=Dvector(2), double amplitude=1.0);
  GerstnerWave(const GerstnerWave & gers);
  ~GerstnerWave();
  GerstnerWave & operator = (const GerstnerWave & gers);
  //Accesseurs definis en public
  double getAmplitude();
  double getPhase();
  Dvector getDirection();
  double getFrequence();
  //set en public aussi
  void setAmplitude(double amplitude);
  void setPhase(double phase);
  void setDirection(Dvector vect);
  //foncteur : Permet d'utiliser la classe comme une fonction
  //Affichage
  void display(std::ostream& str);
  double operator ()(int x, int y, double temps);
};
#endif
