#include "Height.h"
#include "Dvector.h"
#include <cstdlib>
#include <iostream>


Height::Height(const int nx, const int ny, const double lx, const double ly, const double init) {
    //this->heightMatrix = std::vector<Dvector>(nx, Dvector(ny, init));
    this->heightMatrix = Dvector(nx*ny, init);
    this->lx = lx;
    this->ly = ly;
    this->nx = nx;
    this->ny = ny;
}
Height::Height() {
    //this->heightMatrix = std::vector<Dvector>();
    this->heightMatrix = Dvector();
    this->lx = 0;
    this->ly = 0;
    this->nx = 0;
    this->ny = 0;

}
Height::Height(const Height & hgt) {
    //this->heightMatrix = std::vector<Dvector>(hgt.heightMatrix);
    this->heightMatrix = Dvector(hgt.heightMatrix);
    this->lx = hgt.getLx();
    this->ly = hgt.getLy();
    this->nx = hgt.sizeNx();
    this->ny = hgt.sizeNy();

}
Height::~Height() {
}

// void Height::display(std::ostream& str) {
//     for (uint i = 0; i < this->heightMatrix.size(); i++) {
//         this->heightMatrix.at(i).display(str);
//         str << "\n";
//     }
// }

void Height::display(std::ostream& str) {
    for (uint x = 0; x < this->sizeNx(); x++) {
        for (uint y = 0; y < this->sizeNy(); y++) {
            str << (*this)(x, y) << " ";
        }
        str << endl;
    }
}

void Height::displayFile(std::ostream& str) {
    str << "# X   Y   Z\n";
    for (uint x = 0; x < this->sizeNx(); x++) {
        for (uint y = 0; y < this->sizeNy(); y++) {
            str << x*(this->lx/this->sizeNx()) << " " << y*(this->ly/this->sizeNy()) << " " << (*this)(x, y) << endl;
        }
    str << endl;
    }
}

double Height::operator()(const int x, const int y) const{
    //return this->heightMatrix.at(x)(y);
    return this->heightMatrix(x*nx + y);
}

double & Height::operator()(const int x, const int y){
    return this->heightMatrix(x*nx + y);
}
// uint Height::sizeNx() const {
//     return this->heightMatrix.size();
// }
// uint Height::sizeNy() const {
//     if (this->sizeNx() == 0) {
//         return 0;
//     }
//     return this->heightMatrix.at(0).size();
// }

uint Height::sizeNx() const {
    return this->nx;
}
uint Height::sizeNy() const {
    return this->ny;
}

double Height::getLx() const {
    return this->lx;
}
double Height::getLy() const {
    return this->ly;
}
