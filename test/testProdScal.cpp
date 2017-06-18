#include "Dvector.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <fstream>

using namespace std;

int main (){
    Dvector vectTest1 = Dvector(2, 5.0);
    Dvector vectTest2 = Dvector(2, 1.5);
    assert(vectTest1.prodscal(vectTest2) == 15);
    cout << "test 1 OK\n";
    vectTest1(0)=1.6;
    vectTest2(1)=-3.0;
    assert(vectTest1.prodscal(vectTest2) == -12.6);
    cout << "test 2 OK\n";
}
