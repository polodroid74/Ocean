#ifndef HEIGHTH
#define HEIGHTH
#include <vector>
#include "Dvector.h"

class Height
{
    private :
    double lx, ly;
    int nx, ny;
    //std::vector<Dvector> heightMatrix;
    Dvector heightMatrix;

    public :
    Height(const int nx, const int ny, const double lx, const double ly, const double init=0);
    Height();
    Height(const Height & hgt);
    ~Height();
    void display(std::ostream& str);
    void displayFile(std::ostream& str);
    double operator()(const int x, const int y) const;
    double & operator()(const int x, const int y);
    uint sizeNx() const;
    uint sizeNy() const;
    double getLx() const;
    double getLy() const;
};

#endif
