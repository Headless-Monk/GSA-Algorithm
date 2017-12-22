#include "MyAlgorithm.h"
#include <fstream>
#include <iostream>

MyAlgorithm::MyAlgorithm(Problem& pbm, SetUpParams& setup):
    _solutions{}, _pbm{pbm}, _setup{setup}, _best_Solution_overall{nullptr}
{
    for(unsigned int i = 0; i < _setup.get_population_size(); i++)
        _solutions.push_back(new Solution{_pbm});

    _best_Solution_overall = new Solution{_pbm};
}

MyAlgorithm::~MyAlgorithm()
{
    for(unsigned int i = 0; i < _setup.get_population_size(); i++)
        delete _solutions[i];

    delete _best_Solution_overall;
}

void MyAlgorithm::evolution()
{
    double c = 0.0;
    std::ofstream fichier("sortie.csv", ios::out);  // on ouvre le fichier en lecture
    for(unsigned int iter=0; iter<_setup.get_nb_independant_runs(); iter++)
    {	
        /* chargement */
        if(iter%1000 == 0)fichier << _best_Solution_overall->get_current_fitness() << "," << iter <<"\n";
        
        if( ( (double)iter / (double)_setup.get_nb_independant_runs() ) >= c)
        {
        	
            cout << (char)219u;
            c += 0.01;
        }


//cout << "-------- liste des individus ------------------------------------" << endl << endl;
//afficher_all();
//cout << endl;


        /* évaluation des individus */
//cout << "-------- evalution des individus --------------------------------" << endl << endl;
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
            spaceBound(_solutions[i]);
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
        {
            _solutions[i]->fitness();
        }
//afficher_all();
//cout << endl;


        /* recherche des solutuions extrémales */
//cout << "-------- recherche des solutuions extremales --------------------" << endl << endl;
        upper_cost();
        lower_cost();
        best_cost_overall();
//cout << "upper : " << endl << *_upper_cost << endl;
//cout << "lower : " << endl << *_lower_cost << endl;
//cout << "best : " << endl << *_best_Solution_overall << endl;


        /* calcul des masses*/
//cout << "-------- calcul des masses --------------------------------------" << endl << endl;
        double mass_sum = 0;
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
        {
            _solutions[i]->mass_calculation(_lower_cost, _upper_cost);
            mass_sum += _solutions[i]->get_mass();
        }

        for(unsigned int i=0; i<_setup.get_population_size(); i++)
            _solutions[i]->inertia_mass_calculation(mass_sum);
//afficher_all();
//cout << endl;


        /* calcul de g */
//cout << "-------- calcul de g --------------------------------------------" << endl << endl;
        _g = g_evolution(iter);


        /* calcul de l'acceleration */
//cout << "-------- calcul de l'acceleration -------------------------------" << endl << endl;
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
            _solutions[i]->acceleration_calculation(_solutions, _g);
//cout << endl;


        /* mouvement des planetes */
//cout << "-------- mouvement des planetes ---------------------------------" << endl << endl;
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
            _solutions[i]->update_solution(); /* =_solutions[i]->initialize(); la solution finale est pas meilleure qu'un random à chaque itération */
//afficher_all();
//cout << endl;


//cout << "-------- fin iteration ------------------------------------------" << endl;
//cout << "-----------------------------------------------------------------" << endl << endl;
    }
}

void MyAlgorithm::afficher_all()
{
    for(unsigned int i=0; i<_setup.get_population_size(); i++)
        cout << *_solutions[i] << endl;
}

void MyAlgorithm::afficher_best()
{
    cout << *_best_Solution_overall << endl;
}

void MyAlgorithm::spaceBound(Solution *sol)
{
    if(sol->check_boundaries() == false)
        sol->initialize();
}

double MyAlgorithm::g_evolution(int iter)
{
    double g0 = 100;
    double alpha = 20;

    return g0*exp(-alpha*iter/_setup.get_nb_independant_runs());
}

void MyAlgorithm::initialize()
{
    for(unsigned int i = 0; i < _setup.get_population_size(); i++)
        _solutions[i]->initialize();

    *_best_Solution_overall = *_solutions[0];
    _best_Solution_overall->fitness();
}

void MyAlgorithm::upper_cost()
{
    _upper_cost = _solutions[0];
    for(unsigned int i = 1; i < _setup.get_population_size(); i++)
        if(_solutions[i]->get_current_fitness() > _upper_cost->get_current_fitness())
            _upper_cost = _solutions[i];
}

void MyAlgorithm::lower_cost()
{
    _lower_cost = _solutions[0];
    for(unsigned int i = 1; i < _setup.get_population_size(); i++)
        if(_solutions[i]->get_current_fitness() < _lower_cost->get_current_fitness())
            _lower_cost = _solutions[i];
}

void MyAlgorithm::best_cost_overall()
{

    if(_pbm.get_direction() == 0) //maximisation
    {
        if(_upper_cost->get_current_fitness() > _best_Solution_overall->get_current_fitness())
            *_best_Solution_overall = *_upper_cost;
    }
    else //minimisation
    {
        if(_lower_cost->get_current_fitness() < _best_Solution_overall->get_current_fitness())
            *_best_Solution_overall = *_lower_cost;
    }
}

void MyAlgorithm::change_parameters(SetUpParams &setup, Problem &pbm)
{
    _setup = setup;
    _pbm = pbm;

    for(unsigned int i = 0; i < _solutions.size(); i++)
        delete _solutions[i];
    _solutions.resize(0);
    for(unsigned int i = 0; i < _setup.get_population_size(); i++)
        _solutions.push_back(new Solution{_pbm});

    _upper_cost = nullptr;
    _lower_cost = nullptr;
    _g = 0;
    delete _best_Solution_overall;
    _best_Solution_overall = new Solution{_pbm};
}
