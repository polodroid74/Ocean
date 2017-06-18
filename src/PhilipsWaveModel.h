#ifndef PHILIPS_WAVEMODELH
#define PHILIPS_WAVEMODELH
#include "WaveModel.h"
#include "PhilipsWave.h"
#include "Height.h"
#include <ostream>
#include <string>

class PhilipsWaveModel :
    public WaveModel
{
private:
    PhilipsWave philips;
    Height waveHeightT;
    float tCour;
    double epsilonR, epsilonI;
public:
    PhilipsWaveModel(const Dvector windDir, const double waveAlign, const double intensity,
        const double waveLength, const double ajust, const PhilipsWave philips);
    ~PhilipsWaveModel();

    //foncteur : Permet d'utiliser la classe comme une fonction
    double operator ()(int x, int y, double t);

    void HeightComputation(double t);
};

    #endif
