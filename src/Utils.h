#ifndef UTILS_HPP
#define UTILS_HPP

#include "Dvector.h"
#include "Height.h"

void myfft(Dvector & real, Dvector & im);

void myifft(Dvector & real, Dvector & im);

void fft2D(Height & hReal, Height & hIm);

void ifft2D(Height & hReal, Height & hIm);
#endif
