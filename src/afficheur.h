#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "SetUpParams.h"
#include "Problem.h"
#include "Solution.h"
#include "MyAlgorithm.h"

class afficheur
{
    public:
        afficheur();
        virtual ~afficheur();

        void init();

        void afficher_pbm();
        void afficher_menu_principal();
        void start_resolution();
        void afficher_menu_eddit();

    private:
        Problem _pbm;
        SetUpParams _setup;
        MyAlgorithm _algo;
};

#endif // AFFICHEUR_H

