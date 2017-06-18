#include "PhilipsWaveModel.h"
#include "Utils.h"
#include <random>
#include <complex>
#include <iostream>

    PhilipsWaveModel::PhilipsWaveModel(const Dvector windDir, const double waveAlign, const double intensity,
        const double waveLength, const double ajust, const PhilipsWave philips) :
            WaveModel(windDir, waveAlign, intensity, waveLength, ajust)
        {
            this->philips = philips;
            this->waveHeightT = Height(philips.getNx(), philips.getNy(), philips.getLx(), philips.getLy(), 0);
            this->tCour = 0;

            //Random coefficients generator
            std::default_random_engine generator;
            std::normal_distribution<double> distribution(0.0,1.0);
            epsilonR = distribution(generator);
            epsilonI = distribution(generator);
        }
    PhilipsWaveModel::~PhilipsWaveModel() {}

    void PhilipsWaveModel::HeightComputation(double t) {
        int N = philips.getNx();
        int M = philips.getNy();
        double L = pow(philips.getMaximumWindSpeed(), 2.0)/9.81;
        Height philipsSwellModel(N+1, M+1, philips.getLx(), philips.getLy());
        Height waveHeightFourierReal(N+1, M+1, philips.getLx(), philips.getLy());
        Height waveHeightFourierImaginary(N+1, M+1, philips.getLx(), philips.getLy());

        //Pk computing
        double kx, ky;
        for (int n = -N/2; n < N/2; n++) {
            for (int m = -M/2; m < M/2; m++) {
                kx = 2*M_PI*n/philips.getLx();
                ky = 2*M_PI*m/philips.getLy();
                double kNorm = sqrt(pow(kx, 2.0) + pow(ky, 2.0));
                philipsSwellModel(n+N/2, m+M/2) = philips.getModelAmplitude()*(exp(-1.0/pow(kNorm*L, 2.0))/pow(kNorm, 2.0))
                                                       * (pow(kx*this->getWindDir()(0), 2.0) + pow(ky*this->getWindDir()(1), 2.0));
            }
        }

        //h_tilde computing
        double omegaK;
        // On sépare les calculs entre partie réelle et imaginaire
        double tmpReal;
        double tmpIm;
        for (int n = -N/2; n < N/2; n++) {
            for (int m = -M/2; m < M/2; m++) {
                kx = 2*M_PI*n/philips.getLx();
                ky = 2*M_PI*n/philips.getLy();
                omegaK = sqrt(sqrt(pow(kx, 2.0) + pow(ky, 2.0))*9.81);
                tmpReal = 1/sqrt(2.0) * (epsilonR*cos(omegaK*t) - epsilonI*sin(omegaK*t)) * sqrt(philipsSwellModel(n+N/2, m+M/2))
                         + 1/sqrt(2.0) * (epsilonR*cos(omegaK*t) + epsilonI*sin(omegaK*t)) * sqrt(philipsSwellModel((-n)+N/2, (-m)+M/2));
                tmpIm = 1/sqrt(2.0) * (epsilonR*sin(omegaK*t) + epsilonI*cos(omegaK*t)) * sqrt(philipsSwellModel(n+N/2, m+M/2))
                        + 1/sqrt(2.0) * (- epsilonR*sin(omegaK*t) + epsilonI*cos(omegaK*t)) * sqrt(philipsSwellModel((-n)+N/2, (-m)+M/2));
                waveHeightFourierReal(n+N/2, m+M/2) = tmpReal;
                waveHeightFourierImaginary(n+N/2, m+M/2) = tmpIm;
            }
        }
        ifft2D(waveHeightFourierReal, waveHeightFourierImaginary);
        this->waveHeightT = waveHeightFourierReal;

    }


    //foncteur : Permet d'utiliser la classe comme une fonction
    double PhilipsWaveModel::operator ()(int x, int y, double t) {
        if (t != tCour) {
            // Si pas calculé pour le temps t on recalcule toute la matrice de hauteur
            HeightComputation(t);
            tCour = t;
        }
        // Sinon la matrice est déjà calculée pour ce t, on envoie juste l'élément
        // à la case (x, y)
        return waveHeightT(x, y);
    }
    //Recalculer la carte si t/= ancien t, sinon juste retourner Height(x, y)
