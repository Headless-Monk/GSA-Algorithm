#include "MyAlgorithm.h"
#include <fstream>
#include <iostream>

MyAlgorithm::MyAlgorithm(Problem& pbm, SetUpParams& setup):
    _solutions{}, _upper_cost{NULL}, _lower_cost{NULL},
    _best_Solution_overall{NULL}, _pbm{pbm}, _setup{setup}, _g{0}
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
    for(unsigned int iter=0; iter<_setup.get_nb_independant_runs(); iter++)
    {
        /* chargement */
        if( ( (double)iter / (double)_setup.get_nb_independant_runs() ) >= c)
        {
            cout << (char)219u;
            c += 0.01;
        }


        /* évaluation des individus */
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
            spaceBound(_solutions[i]);
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
        {
            _solutions[i]->fitness();
        }


        /* recherche des solutuions extrémales */
        upper_cost();
        lower_cost();
        best_cost_overall();


        /* calcul des masses*/
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
            _solutions[i]->mass_calculation(_lower_cost, _upper_cost);


        /* calcul de g */
        _g = g_evolution(iter);


        /* calcul de l'acceleration */
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
            _solutions[i]->acceleration_calculation(_solutions, _g);


        /* mouvement des planetes */
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
            _solutions[i]->update_solution();
    }
}

void MyAlgorithm::initialize()
{
    for(unsigned int i = 0; i < _setup.get_population_size(); i++)
        _solutions[i]->initialize();

    *_best_Solution_overall = *_solutions[0];
    _best_Solution_overall->fitness();
}

void MyAlgorithm::afficher_best()
{
    cout << *_best_Solution_overall << endl;
}

void MyAlgorithm::afficher_all()
{
    for(unsigned int i=0; i<_setup.get_population_size(); i++)
        cout << *_solutions[i] << endl;
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

    _upper_cost = NULL;
    _lower_cost = NULL;
    _g = 0;
    delete _best_Solution_overall;
    _best_Solution_overall = new Solution{_pbm};
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
