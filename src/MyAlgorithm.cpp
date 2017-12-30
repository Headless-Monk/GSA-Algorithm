#include "MyAlgorithm.h"
#include <fstream>
#include <iostream>

/**
  Constructeur de MyAlgorithm
  @param[in] pbm - Problem
  @param[in] setup - SetUpParams
*/
MyAlgorithm::MyAlgorithm(Problem& pbm, SetUpParams& setup):
    _solutions(), _upper_cost(NULL), _lower_cost(NULL),
    _best_Solution_overall(NULL), _pbm(pbm), _setup(setup), _g(0)
{
    for(unsigned int i = 0; i < _setup.get_population_size(); i++)
        _solutions.push_back(new Solution{_pbm});

    _best_Solution_overall = new Solution{_pbm};
}

/**
  Destructeur de MyAlgorithm
*/
MyAlgorithm::~MyAlgorithm()
{
    for(unsigned int i = 0; i < _setup.get_population_size(); i++)
        delete _solutions[i];

    delete _best_Solution_overall;
}

/**
  Realise une evolution complète sur l'ensemble des solutions (calcul de l'acceleration, calcul de fitness, mise a jour des positions des solutions, ...)
*/
void MyAlgorithm::evolution()
{
    double c = 0.0;
    for(unsigned int iter=0; iter<_setup.get_nb_independant_runs(); iter++)
    {
        /* chargement */
        if( ( (double)iter / (double)_setup.get_nb_independant_runs() ) >= c)
        {
            cout << "_";
            c += 0.01;
        }


        /* evaluation des individus */
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
            spaceBound(_solutions[i]);
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
        {
            _solutions[i]->fitness();
        }


        /* recherche des solutuions extremales */
        upper_cost();
        lower_cost();
        best_cost_overall();


        /* calcul des masses*/
        double mass_sum = 0;
        for(unsigned int i=0; i<_setup.get_population_size(); i++)
        {
            _solutions[i]->mass_calculation(_lower_cost, _upper_cost);
            mass_sum += _solutions[i]->get_mass();
    	}
    	
        /*calcul des masses inertielles*/
		for(unsigned int i=0; i<_setup.get_population_size(); i++)
        	_solutions[i]->inertia_mass_calculation(mass_sum);

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

/**
  Initialisation de toutes les solutions
*/
void MyAlgorithm::initialize()
{
    for(unsigned int i = 0; i < _setup.get_population_size(); i++)
        _solutions[i]->initialize();

    *_best_Solution_overall = *_solutions[0];
    _best_Solution_overall->fitness();
}

/**
  Affiche sur la console la meilleure solution de la population
*/
void MyAlgorithm::afficher_best()
{
    cout << *_best_Solution_overall << endl;
}

/**
  Affiche sur la console toutes les solutions de la population
*/
void MyAlgorithm::afficher_all()
{
    for(unsigned int i=0; i<_setup.get_population_size(); i++)
        cout << *_solutions[i] << endl;
}

/**
  Cree une nouvelle resolution avec les nouveaux paramètres modifies
  @param[in] setup - SetUpParams
  @param[in] pbm - Problem
*/
void MyAlgorithm::change_parameters(SetUpParams &setup, Problem &pbm)
{
    _setup = setup;
    _pbm = pbm;

    for(unsigned int i = 0; i < _solutions.size(); i++)
        delete _solutions[i];
    _solutions.resize(0);
    for(unsigned int i = 0; i < _setup.get_population_size(); i++)
        _solutions.push_back(new Solution(_pbm));

    _upper_cost = NULL;
    _lower_cost = NULL;
    _g = 0;
    delete _best_Solution_overall;
    _best_Solution_overall = new Solution(_pbm);
}

/**
  Met à jour la plus haute fitness de la population en fonction des fitness de l'evolution actuelle
*/
void MyAlgorithm::upper_cost()
{
    _upper_cost = _solutions[0];
    for(unsigned int i = 1; i < _setup.get_population_size(); i++)
        if(_solutions[i]->get_current_fitness() > _upper_cost->get_current_fitness())
            _upper_cost = _solutions[i];
}

/**
  Met à jour la plus basse fitness de la population en fonction des fitness de l'evolution actuelle
*/
void MyAlgorithm::lower_cost()
{
    _lower_cost = _solutions[0];
    for(unsigned int i = 1; i < _setup.get_population_size(); i++)
        if(_solutions[i]->get_current_fitness() < _lower_cost->get_current_fitness())
            _lower_cost = _solutions[i];
}

/**
  Met à jour la plus haute fitness de la population en fonction des fitness de l'evolution actuelle
*/
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

/**
  Verifie si une solution est dans les limites du problème courant, si non, la solution est replacee avec une postion tiree au hasard à l'interieur des limites
  @param[in] sol - Solution
*/
void MyAlgorithm::spaceBound(Solution *sol)
{
    if(sol->check_boundaries() == false)
        sol->initialize();
}

/**
  Fais evoluer la constante gravitationnelle g en fonction d'une constante g0 et d'une constante alpha
  @param[in] iter - int
  @param[in] g - double
*/
double MyAlgorithm::g_evolution(int iter)
{
    double g0 = 100;
    double alpha = 20;

    return g0*exp(-alpha*iter/_setup.get_nb_independant_runs());
}
