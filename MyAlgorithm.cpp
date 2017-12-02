#include "MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup):
    _solutions{}, _pbm{pbm}, _setup{setup}, _best_Solution_overall{nullptr}
{
    for(unsigned int i = 0; i < _pbm.get_dimension(); i++)
        _solutions.push_back(new Solution{_pbm});

    _best_Solution_overall = new Solution{_pbm};
}

MyAlgorithm::~MyAlgorithm()
{
    for(unsigned int i = 0; i < _pbm.get_dimension(); i++)
        delete _solutions[i];

    delete _best_Solution_overall;
}

void MyAlgorithm::evolution()
{
    double c = 0.0;
    for(unsigned int iter=0; iter<_setup.get_nb_evolution_steps(); iter++)
    {
        /* chargement */
        if( ( (double)iter / (double)_setup.get_nb_evolution_steps() ) >= c)
        {
            cout << "-";
            c += 0.1;
        }

        /* évaluation des individus */
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
            spaceBound(_solutions[i]);
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
            _solutions[i]->fitness();

        /* recherche des solutuions extrémales */
        upper_cost();
        lower_cost();
        best_cost_overall();

        /* calcul des masses*/
        double mass_sum = 0;
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
        {
            _solutions[i]->mass_calculation(_lower_cost, _upper_cost);
            mass_sum += _solutions[i]->get_mass();
        }
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
            _solutions[i]->inertia_mass_calculation(mass_sum);

        /* calcul de g */
        _g = g_evolution(iter);

        /* calcul des forces */
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
            _solutions[i]->total_force_calculation(_solutions, _g);


        /* calcul de l'acceleration */
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
            _solutions[i]->acceleration_calculation();

        /* mouvement des planetes */
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
            _solutions[i]->update_solution();
    }
}

void MyAlgorithm::afficher_all()
{
    for(unsigned int i=0; i<_pbm.get_dimension(); i++)
        std::cout << *_solutions[i] << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void MyAlgorithm::afficher_best()
{
    std::cout << *_best_Solution_overall << std::endl;
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

    return g0*exp(-alpha*iter/_setup.get_nb_evolution_steps());
}

void MyAlgorithm::initialize()
{
    for(unsigned int i = 0; i < _pbm.get_dimension(); i++)
        _solutions[i]->initialize();

    *_best_Solution_overall = *_solutions[0];
    _best_Solution_overall->fitness();
}

void MyAlgorithm::upper_cost()
{
    _upper_cost = _solutions[0];
    for(unsigned int i = 1; i < _solutions.size(); i++)
        if(_solutions[i]->get_current_fitness() > _upper_cost->get_current_fitness())
            _upper_cost = _solutions[i];
}

void MyAlgorithm::lower_cost()
{
    _lower_cost = _solutions[0];
    for(unsigned int i = 1; i < _solutions.size(); i++)
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
