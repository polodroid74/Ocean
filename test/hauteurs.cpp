#include "Height.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>


using namespace std;

int main (){
    Height hauteurs = Height(3, 6, 20.5, 18.8, 5);
    std::stringstream str;
    hauteurs.display(str);
    assert(str.str() == "5 5 5 5 5 5 \n5 5 5 5 5 5 \n5 5 5 5 5 5 \n");
    assert(hauteurs.sizeNx() == 3);
    assert(hauteurs.sizeNy() == 6);
    assert(hauteurs.getLx() == 20.5);
    assert(hauteurs.getLy() == 18.8);
    //cout<<str.str()<<"\n";
    cout << "Test initialisation OK\n";

    Height hauteurs2 = Height();
    str.str("");
    //std::cout << hauteurs2.sizeNx() << std::endl;
    assert(hauteurs2.sizeNx() == 0);
    assert(hauteurs2.sizeNy() == 0);
    assert(hauteurs2.getLx() == 0);
    assert(hauteurs2.getLy() == 0);
    hauteurs2.display(str);
    assert(str.str() == "");
    cout << "Test constructeur par défaut OK\n";

    Height hauteurs3 = Height(hauteurs);
    str.str("");
    hauteurs3.display(str);
    assert(str.str() == "5 5 5 5 5 5 \n5 5 5 5 5 5 \n5 5 5 5 5 5 \n");
    assert(hauteurs3.sizeNx() == 3);
    assert(hauteurs3.sizeNy() == 6);
    assert(hauteurs3.getLx() == 20.5);
    assert(hauteurs3.getLy() == 18.8);
    cout << "Test constructeur par copie OK\n";

    ofstream file("height.txt", ios::out);
    if (file) {
        hauteurs3.displayFile(file);
    }
    file.close();
}
