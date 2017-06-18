=================Utilisation de la simulation===============

La simulation se paramètre au niveau du fichier main.cpp :

-Les paramètres lx et ly permettent de regler la taille de l'ocean.
-Les paramètes nbPointsx et nbPointsy permettent de choisir le nombre de points de discrétisation.

-Le prototype de GerstnerWaveModel() est le suivant:

    GerstnerWaveModel(const Dvector windDir,const double align,
        const double ajust, double intensity,
        const int nbOndes, const double phase);

   Le paramètre align représente l'angle des vagues par rapport au vent.
   Les paramètres ajust et intensity permettent de régler la hauteur des vagues
   Le paramètre nbOndes permet de choisir le nombre d'ondes impliquées

-Le prototype de la fonction PhilipsWaveModel() est le suivant:
  PhilipsWaveModel(const double windDir, const double waveAlign, const double intensity,
          const double waveLength, const double ajust, const PhilipsWave philips);

      -Le paramètre  philips est l'onde de Philips à considérer.



Pour lancer la simulation, créer un dossier build, se placer dedans. exécuter la commande "cmake.."
puis la commande "make". Enfin lancer l'executable "./exe"
