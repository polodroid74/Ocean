#include "Dvector.h"
#include <iostream>
#include <cassert>


using namespace std;

int main (){
  Dvector vectTest = Dvector(4, 36.5);
  vectTest=vectTest.resize(3);
  cout << vectTest <<"\n";
  vectTest=vectTest.resize(10,1);
  cout << vectTest<<"\n";
}
