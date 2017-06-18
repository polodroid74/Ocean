#ifndef WAVEMODELH
#define WAVEMODELH
#include <ostream>
#include <string>
#include "Dvector.h"

class WaveModel
{
private:
  //Attributs
  Dvector windDir;
  double waveAlign;
  double intensity;
  double waveLength;
  double ajust;

  //Methodes declarees en prive.
public:
  WaveModel(const Dvector windDir, const double waveAlign=0, const double intensity=0,
    const double waveLength=0, const double ajust=0);
  WaveModel();
  WaveModel(const WaveModel & vect);
  ~WaveModel();
  //operateur egal
  WaveModel & operator = (const WaveModel & wm);
  //Accesseurs definis en public
  Dvector getWindDir();
  double getwaveAlign();
  double getIntensity();
  double getAveLength();
  double getAjust();
  //foncteur : Permet d'utiliser la classe comme une focntion
  virtual double operator ()(int x, int y, double temps) = 0;
  //Affichage
  void display(ostream& str);
};

#endif
