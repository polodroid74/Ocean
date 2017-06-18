#include "ocean.h"
#include "GerstnerWaveModel.h"
#include <math.h>
#include <iostream>

Ocean::Ocean(WaveModel* wm, float lx, float ly, int nx, int ny){
  this->lx=lx;
  this->ly=ly;
  this->nx=nx;
  this->ny=ny;
  this->wm=wm;
  this->t=0.0;
  this->vertices = new float[nx*ny];
  this->hauteur= Height(nx, ny, lx, ly, 0);
}

Ocean::~Ocean(){
}

int Ocean::getNx(){
  return this->nx;
}

int Ocean::getNy(){
  return this->ny;
}

float Ocean::get_lx(){
  return this->lx;
}

float Ocean::get_ly(){
  return this->ly;
}

void Ocean::main_computation()
{
  //Mise
  for (int x=0;x<nx;x++){
    for(int y=0;y<ny;y++){
      hauteur(x,y)=(*wm)(x, y, t);
    }
  }
}

void Ocean::setT(float t){
    this->t = t;
}

/** Initialise la grille dans la direction x
 *  param[in]   y        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x]   = (lx/nx)*x;
    vertices[3*x+2] = (ly/ny)*y;
  }
  vertices[3*nx]   = lx;
  vertices[3*nx+2] = (ly/ny)*y;
}

/** Initialise la grille dans la direction y
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y]   = (lx/nx)*x;
    vertices[3*y+2] = (ly/ny)*y;
  }
  vertices[3*ny]   = (lx/nx)*x;
  vertices[3*ny+2] = ly;
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un y donné
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x+1] = pow(-1, x+y)*hauteur(y, x);
  }
  vertices[3*nx+1] = pow(-1, nx+y)*hauteur(y, 0);
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un x donné
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y+1] = hauteur(y,x);
  }
  vertices[3*ny+1]  = hauteur(0,x);
}
