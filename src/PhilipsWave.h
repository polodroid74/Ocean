#ifndef PHILIPS_WAVEH
#define PHILIPS_WAVEH
#include <ostream>
#include <string>

using namespace ::std;

class PhilipsWave
{
private:
    double modelAmplitude;
    double maximumWindSpeed;
    double lx, ly; //Real dimensions
    int nx, ny; //Discretized dimensions
public:
    PhilipsWave(const double modelAmplitude, const double maximumWindSpeed, const double lx, const double ly, const int nx, const int ny);
    PhilipsWave();
    PhilipsWave(const PhilipsWave & philips);
    ~PhilipsWave();
    PhilipsWave & operator = (const PhilipsWave & philips);
    //foncteur : Permet d'utiliser la classe comme une fonction
    //double operator ()();

    //Accesseurs
    double getModelAmplitude() const;
    double getMaximumWindSpeed() const;
    double getLx() const;
    double getLy() const;
    int getNx() const;
    int getNy() const;

    //Mutateurs
    void setModelAmplitude(double modelAmplitude);
    void setMaximumWindSpeed(double maximumWindSpeed);
    void setLx(double lx);
    void setLy(double ly);
    void setNx(int nx);
    void setNy(int ny);
    void display(ostream& str);
};

#endif
