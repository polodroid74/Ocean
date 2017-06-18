#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */

#include "window.h"
#include "ocean.h"
#include "PhilipsWaveModel.h"
#include "GerstnerWaveModel.h"

Ocean* ocean;
int mainwindow;
int main(int argc, char** argv) {
  /** @todo Initialiser des paramètres de simulation */
  float lx = 700;
  float ly = 700;
  int nbPointsX = 100;
  int nbPointsY = 100;

  /** @todo Initialiser du modèle*/
  // -- Gerstner --
  Dvector direction=Dvector(2.0,1.0);
  direction(1)=0.0;
  GerstnerWaveModel wModel = GerstnerWaveModel(direction,30.0,1.0,5.0,10.0,1.0);

  // -- Philips --
//  Dvector direction=Dvector(2.0,1.0);
//  PhilipsWave philips = PhilipsWave(10, 100, lx, ly, nbPointsX, nbPointsY);
//  PhilipsWaveModel wModel = PhilipsWaveModel(direction, 0.5, 2, 10, 0.2, philips);
  /** @todo Initialiser du champ de hauteur */
  /** @todo Initialiser de l'océan */
  ocean = new Ocean(&wModel, lx, ly, nbPointsX, nbPointsY);

  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;

}
