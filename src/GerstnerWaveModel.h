#ifndef GERSTNERWAVEMODELH
#define GERSTNERWAVEMODELH
#include <ostream>
#include <string>
#include "Dvector.h"
#include "GerstnerWave.h"
#include "WaveModel.h"
#include <list>

class GerstnerWaveModel: public WaveModel
{
public:
  std::list<GerstnerWave> getList();
  GerstnerWaveModel(const Dvector windDir,const double align=1.0,
    const double ajust=1.0, double intensity=1.0,
     const int nbOndes=1.0, const double phase=0.0);
     
  GerstnerWaveModel(const GerstnerWaveModel & gers);
  ~GerstnerWaveModel();
  double operator()(int x, int y, double temps);
  void display(std::ostream& str);

private:
  double sizeList;
  std::list<GerstnerWave> waveList;

};
#endif
