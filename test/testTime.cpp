#include "Dvector.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <ctime>

using namespace std;

int main (){
    Dvector vectTest = Dvector(100000000, 36.5);
    Dvector vectTest2 = Dvector(200000000, 36.5);
    Dvector vectTestRes;
    Dvector vectTestRes2;
    clock_t timeBeg;
    clock_t timeEnd;

    timeBeg = clock();
    vectTestRes = vectTest;
    timeEnd = clock();
    cout << "Temps pour un vecteur à 100 000 000 de composantes : " << double(timeEnd - timeBeg)/CLOCKS_PER_SEC << endl;



    timeBeg = clock();
    vectTestRes2 = vectTest2;
    timeEnd = clock();
    cout << "Temps pour un vecteur à 200 000 000 de composantes : " << double(timeEnd - timeBeg)/CLOCKS_PER_SEC << endl;
    //vectTestRes2.display(cout);
}
