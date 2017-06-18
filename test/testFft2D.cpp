#include <cstdlib>
#include "Utils.h"
#include "Dvector.h"
#include "Height.h"
#include <iostream>
#include <cmath>

using namespace std;

int main (){
    Height real = Height(100, 100, 200, 200, 0.0);
    for (int x = 0; x < 100; x++) {
        for(int y = 0; y < 100; y++) {
            real(x, y) = cos(y / 10.0);
        }
    }
    Height im = Height(100, 100, 200, 200, 0.0);
    Height realc = Height(real);
    Height imc = Height(im);
    fft2D(realc, imc);
    //ifft2D(realc, imc);
    real.display(std::cout);
    //std::cout << std::endl;
    realc.display(std::cout);
}
