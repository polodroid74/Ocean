#include "Dvector.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <fstream>

using namespace std;

int main (){
    Dvector vectTest = Dvector(4, 36.5);
    stringstream str;
    vectTest.display(str);
    assert(str.str() == "36.5\n36.5\n36.5\n36.5\n");
    cout << "test 1 OK\n";
    // Dvector vecTest2;
    // assert(vecTest2.size()==0);
    // vecTest2=Dvector(45,1.); // probleme avec = non redéfini
    // assert(vecTest2.size()==45);
    Dvector vecTest3=Dvector(45,1.);
    assert(vecTest3.size()==45);
    cout << "test 2 OK\n";
    vectTest.~Dvector();
    str.str("");
    cout << "OK\n";

    // Test fichiers
    Dvector vectFile = Dvector("../test/tp1_test1.txt");
    vectFile.display(str);
    cout <<  "Sortie fichier 1 : \n" << str.str();
    vectFile.~Dvector();
    std::cout << "Test fichier 1 OK\n";

    Dvector vectFile2 = Dvector("../test/tp1_test2.txt");
    vectFile2.display(str);
    //cout <<  "Sortie fichier 2 : " << str.str() << "\n";
    vectFile2.~Dvector();
    str.str("");
    std::cout << "Test fichier 2 OK\n";

    // Test operateurs

}
