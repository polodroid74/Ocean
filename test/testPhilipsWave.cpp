#include <cstdlib>
#include "PhilipsWave.h"
#include <iostream>

using namespace std;

int main (){

    PhilipsWave philips1=PhilipsWave(10.0, 200, 10.3, 45.5, 10, 45);
    philips1.display(std::cout);

    PhilipsWave philips2=philips1;
    philips2.display(std::cout);

    PhilipsWave philips3=PhilipsWave(philips1);
    philips3.display(std::cout);

    PhilipsWave philips4=PhilipsWave();
    philips4.display(std::cout);
}
