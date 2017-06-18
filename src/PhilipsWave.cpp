
#include <cstdlib>
#include "PhilipsWave.h"

using namespace std;

PhilipsWave::PhilipsWave(const double modelAmplitude, const double maximumWindSpeed, const double lx, const double ly, const int nx, const int ny) {
    this->modelAmplitude = modelAmplitude;
    this->maximumWindSpeed = maximumWindSpeed;
    this->lx = lx;
    this->ly = ly;
    this->nx = nx;
    this->ny = ny;
}

PhilipsWave::PhilipsWave(const PhilipsWave & philips) {
    this->modelAmplitude = philips.modelAmplitude;
    this->maximumWindSpeed = philips.maximumWindSpeed;
    this->lx = philips.lx;
    this->ly = philips.ly;
    this->nx = philips.nx;
    this->ny = philips.ny;
}

PhilipsWave::PhilipsWave() :
    PhilipsWave(0, 0, 0, 0, 0, 0)
{
}

PhilipsWave::~PhilipsWave() {}

PhilipsWave & PhilipsWave::operator = (const PhilipsWave & philips) {
    this->modelAmplitude = philips.modelAmplitude;
    this->maximumWindSpeed = philips.maximumWindSpeed;
    this->lx = philips.lx;
    this->ly = philips.ly;
    this->nx = philips.nx;
    this->ny = philips.ny;
    return *this;
}


//Accesseurs
double PhilipsWave::getModelAmplitude() const {
    return this->modelAmplitude;
}
double PhilipsWave::getMaximumWindSpeed() const {
    return this->maximumWindSpeed;
}
double PhilipsWave::getLx() const {
    return this->lx;
}
double PhilipsWave::getLy() const {
    return this->ly;
}
int PhilipsWave::getNx() const {
    return this->nx;
}
int PhilipsWave::getNy() const {
    return this->ny;
}

//Mutateurs
void PhilipsWave::setModelAmplitude(double modelAmplitude) {
    this->modelAmplitude = modelAmplitude;
}
void PhilipsWave::setMaximumWindSpeed(double maximumWindSpeed) {
    this->maximumWindSpeed = maximumWindSpeed;
}
void PhilipsWave::setLx(double lx) {
    this->lx = lx;
}
void PhilipsWave::setLy(double ly) {
    this->ly = ly;
}
void PhilipsWave::setNx(int nx) {
    this->nx = nx;
}
void PhilipsWave::setNy(int ny) {
    this->ny = ny;
}

void PhilipsWave::display(ostream& str){
    str<<"Modele de Philips: \n";
    str << "Amplitude: " << this->modelAmplitude << std::endl;
    str << "Vitesse maximale du vent: " << this->maximumWindSpeed << std::endl;
    str << "Taille du problème: (" << this->lx << " ," << this->ly << ")" << std::endl;
    str << "Taille discrétisée: (" << this->nx << " ," << this->ny << ")" << std::endl;
    str<<"\n";
  }
