#include "Utils.h"
#include <math.h>
#include <iostream>

void myfft(Dvector & real, Dvector & im) {
    int n = real.size();
    if (n <= 1)
        return;
    Dvector evenReal = Dvector(n/2, 0);
    Dvector oddReal = Dvector(n/2, 0);
    Dvector evenIm = Dvector(n/2, 0);
    Dvector oddIm = Dvector(n/2, 0);
    for (int i = 0; i < n/2; i++) {
        evenReal(i) = real(2*i);
        oddReal(i) = real(2*i + 1);
        evenIm(i) = im(2*i);
        oddIm(i) = im(2*i + 1);
    }

    //Appel récursif sur chacun des deux tableaux
    myfft(evenReal, evenIm);
    myfft(oddReal, oddIm);

    //Fusion
    double r, i;
    for (int k = 0; k < n/2; k++) {
        r=oddReal(k)*cos(-2*M_PI*k/(float)n)-oddIm(k)*sin(-2*M_PI*k/(float)n);
        i=oddReal(k)*sin(-2*M_PI*k/(float)n)+oddIm(k)*cos(-2*M_PI*k/(float)n);

        real(k) = evenReal(k) + r;
        real(k + n/2) = evenReal(k) - r;

        im(k) = evenIm(k) + i;
        im(k + n/2) = evenIm(k) - i;
    }
}


void myifft(Dvector & real, Dvector & im) {
    int n = real.size();
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n; i++) {
        im(i) = -im(i);
    }
    myfft(real, im);
    for (int i = 0; i < n; i++) {
        im(i) = -im(i)/n;
        real(i) /= n;
    }
}

void fft2D(Height & hReal, Height & hIm) {
    int nx = hReal.sizeNx();
    int ny = hReal.sizeNy();
    Dvector hLineReal(ny);
    Dvector hLineIm(ny);
    // On lines
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            hLineReal(y) = hReal(x, y);
            hLineIm(y) = hIm(x, y);
        }
        myfft(hLineReal, hLineIm);
        for (int y = 0; y < ny; y++) {
            hReal(x, y) = hLineReal(y);
            hIm(x, y) = hLineIm(y);
        }
    }

    // On columns
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            hLineReal(x) = hReal(x, y);
            hLineIm(x) = hIm(x, y);
        }
        myfft(hLineReal, hLineIm);
        for (int x = 0; x < nx; x++) {
            hReal(x, y) = hLineReal(x);
            hIm(x, y) = hLineIm(x);
        }
    }
}

void ifft2D(Height & hReal, Height & hIm) {
    int nx = hIm.sizeNx();
    int ny = hIm.sizeNy();
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            hIm(x, y) = -hIm(x, y);
        }
    }
    fft2D(hReal, hIm);
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            hIm(x, y) = -hIm(x, y)/nx;
            hReal(x, y) /= nx;
        }
    }


}
