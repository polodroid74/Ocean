#include "Dvector.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <fstream>

using namespace std;

int main (){
    Dvector vectTest = Dvector(4, 36.5);
    std::stringstream str;
    vectTest.display(str);
    assert(str.str() == "36.5\n36.5\n36.5\n36.5\n");
    str.str("");
    vectTest.display(str);
    //cout<<str.str()<<"\n";
    cout << "Test initialisation OK\n";
    Dvector vectTest1 = Dvector(4, 36.5);
    Dvector vectTest2 = Dvector(4, 30);

    Dvector vectTest3 = vectTest1-vectTest2;
    str.str("");
    vectTest3.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "6.5\n6.5\n6.5\n6.5\n");
    cout << "Test vect-vect OK\n";

    Dvector vectTest4 = vectTest1+vectTest2;
    str.str("");
    vectTest4.display(str);
    //gcout<<str.str()<<"\n";
    assert(str.str() == "66.5\n66.5\n66.5\n66.5\n");
    cout << "Test vect+vect OK\n";


    Dvector vectTest8 = 10 + vectTest1;
    str.str("");
    vectTest8.display(str);
    assert(str.str() == "46.5\n46.5\n46.5\n46.5\n");
    //cout<<str.str()<<"\n";
    cout << "Test int+vect OK\n";

    Dvector vectTest12 = vectTest1 + 10;
    str.str("");
    vectTest12.display(str);
    assert(str.str() == "46.5\n46.5\n46.5\n46.5\n");
    //cout<<str.str()<<"\n";
    cout << "Test vect+int OK\n";

    Dvector vectTest13 = vectTest1 - 100;
    str.str("");
    vectTest13.display(str);
    assert(str.str() == "-63.5\n-63.5\n-63.5\n-63.5\n");
    //cout<<str.str()<<"\n";
    cout << "Test vect-int OK\n";

    Dvector vectTest6 = 10 * vectTest1;
    str.str("");
    vectTest6.display(str);
    assert(str.str() == "365\n365\n365\n365\n");
    //cout<<str.str()<<"\n";
    cout << "Test int*vect OK\n";

    Dvector vectTest14 = vectTest1*10;
    str.str("");
    vectTest14.display(str);
    assert(str.str() == "365\n365\n365\n365\n");
    //cout<<str.str()<<"\n";
    cout << "Test vect*int OK\n";

    Dvector vectTest7 = vectTest2/30;
    str.str("");
    vectTest7.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "1\n1\n1\n1\n");
    cout << "Test vect/int OK\n";

    Dvector vectTest9 = -vectTest1;
    str.str("");
    vectTest9.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "-36.5\n-36.5\n-36.5\n-36.5\n");
    cout << "Test -vect OK\n";

    Dvector vectTest10 = vectTest1;
    vectTest10 += vectTest2;
    str.str("");
    vectTest10.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "66.5\n66.5\n66.5\n66.5\n");
    cout << "Test vect+=vect OK\n";

    Dvector vectTest11 = vectTest1;
    vectTest11 -= vectTest2;
    str.str("");
    vectTest11.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "6.5\n6.5\n6.5\n6.5\n");
    cout << "Test vect-=vect OK\n";


    vectTest12 = vectTest1;
    std::stringstream str1;
    std::stringstream str2;
    str1 << vectTest12;
    str2 <<"36.5 36.5 36.5 36.5 ";
    str1 << (vectTest12-vectTest1);
    str2<<"0 0 0 0 ";
    assert(str1.str() == str2.str());
    cout << "Test stream << vect OK\n";

    vectTest13=Dvector(5,0);
    std::stringstream str3;
    std::stringstream str4;
    std::stringstream str5;
    str3 << "1 2 3 4 5 ";
    str3 >> vectTest13;
    //cout << vectTest13 << "\n";
    str4 << vectTest13;
    str5 << "1 2 3 4 5 ";
    assert(str4.str() == str5.str());
    cout << "Test stream >> vect OK\n";

    vectTest11 *= vectTest2;
    str.str("");
    vectTest11.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "195\n195\n195\n195\n");
    cout << "Test vect*=vect OK\n";

    vectTest11 += 5;
    str.str("");
    vectTest11.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "200\n200\n200\n200\n");
    cout << "Test vect+=int OK\n";

    vectTest11 -= 150;
    str.str("");
    vectTest11.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "50\n50\n50\n50\n");
    cout << "Test vect-=int OK\n";

    vectTest11 *= 3;
    str.str("");
    vectTest11.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "150\n150\n150\n150\n");
    cout << "Test vect*=int OK\n";

    vectTest11 /= 50;
    str.str("");
    vectTest11.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "3\n3\n3\n3\n");
    cout << "Test vect/=int OK\n";

    Dvector vectTest16;
    vectTest16 = vectTest1;
    str.str("");
    vectTest16.display(str);
    assert(str.str() == "36.5\n36.5\n36.5\n36.5\n");

    vectTest11 = vectTest2;
    str.str("");
    vectTest11.display(str);
    assert(str.str() == "30\n30\n30\n30\n");

    Dvector vectTestDim2 = Dvector(3, 36.5);
    vectTestDim2 = vectTest2;
    str.str("");
    vectTest11.display(str);
    //cout<<str.str()<<"\n";
    assert(str.str() == "30\n30\n30\n30\n");
    cout << "Test \"=\" OK\n";

    Dvector vectTestDim = Dvector(3, 36.5);

    if ((vectTest2 == vectTest2)
    && (vectTest11 == vectTest2)
    && (vectTest11 + 6.5 == vectTest16)
    && !(vectTest11 == vectTest16)
    && !(vectTestDim == vectTest1)) {
        cout << "Test \"==\" OK\n";
    }
}
