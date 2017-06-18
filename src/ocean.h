#ifndef OCEANHXX
#define OCEANHXX

#include "Height.h"
#include "WaveModel.h"
class Ocean
{
private:
  Height hauteur;
  float lx;
  float ly;
  int nx;
  int ny;
  float t;
  WaveModel* wm;
  float *vertices;
public:
  ~Ocean();
  Ocean(WaveModel* wm, float lx, float ly, int nx, int ny);
  void main_computation();
  int getNx();
  int getNy();
  float get_lx();
  float get_ly();
  void setT(float t);

/** Initialise la grille dans la direction x
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void init_gl_VertexArrayX(const int y, double* const vertices) const;

/** Initialise la grille dans la direction y
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void init_gl_VertexArrayY(const int x, double* const vertices) const;

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un y donné
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void gl_VertexArrayX(const int y, double* const vertices) const;

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un x donné
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void gl_VertexArrayY(const int x, double* const vertices) const;
};
#endif
