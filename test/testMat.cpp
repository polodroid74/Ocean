#include "../srcMat/prodmat_ijk.C"
#include "../srcMat/prodmat_ikj.C"
#include <iostream>
#include <sstream>
#include <cassert>
#include <chrono>
#include <cstdlib>

using namespace std;

int main (int argc, char *argv[]){

    srand(time(NULL));
    int n = 100;
    if (argc > 0)
        n = atoi(argv[1]);
    double *A = new double[n*n];
    double *C = new double[n*n];
    double *B = new double[n*n];
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            A[i*n + j] = rand()/(double)RAND_MAX;
            B[i*n + j] = rand()/(double)RAND_MAX;
            C[i*n + j] = rand()/(double)RAND_MAX;
        }
    }

    //-----------------Calcul du temps d'execution----------------
    auto start = std::chrono::high_resolution_clock::now();
    DGEMM_ijk(n, A, B, C);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << "Temps pour une matrice de taille " << n << "x" << n << " avec ijk: " << diff.count() << "s" << endl;


    auto start1 = std::chrono::high_resolution_clock::now();
    DGEMM_ikj(n, A, B, C);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1-start1;
    cout << "Temps pour une matrice de taille " << n << "x" << n << " avec ikj: " << diff1.count() << "s" << endl;

    //----------------Nombre de défauts de cache---------------------
    //DGEMM_ikj(n, A, B, C);
    //DGEMM_ijk(n, A, B, C);
}
