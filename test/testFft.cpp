#include <cstdlib>
#include "Utils.h"
#include "Dvector.h"
#include <iostream>
#include <cmath>

using namespace std;

int main (){
  Dvector real = Dvector(100, 0.0);
  // real(50) = 1.0;
  for (int x = 0; x < 100; x++) {
      real(x) = cos(x/10.0);
  }
  Dvector im = Dvector(100, 0.0);
  //real.fillRandomly();
  // im.fillRandomly();
  Dvector realc = Dvector(real);
  Dvector imc = Dvector(im);
  myfft(realc, imc);
  myifft(realc, imc);
  // Dvector error = realc - real;
  // error.display(std::cout);
  real.display(std::cout);
  //std::cout << std::endl;
  realc.display(std::cout);
}
