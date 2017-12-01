#include "SetUpParams.h"


SetUpParams::SetUpParams():
    _independent_runs{30}, _nb_evolution_steps{75000},
    _population_size{30}, _solution_size{30}
{}


SetUpParams::~SetUpParams()
{}

std::ostream& operator<<(std::ostream& os, const SetUpParams& setup)
{
    os << "independant runs :   " << setup._independent_runs << std::endl;
    os << "nb evolution steps : " << setup._nb_evolution_steps << std::endl;
    os << "population size :    " << setup._population_size << std::endl;
    os << "solution size :      " << setup._solution_size << std::endl;
}

std::istream& operator>> (std::istream& is, SetUpParams& setup)
{
    char c;
    unsigned int val;

    is >> c >> val;
    setup.set_independent_runs(val);

    is >> c >> val;
    setup.set_nb_evolution_steps(val);

    is >> c >> val;
    setup.set_population_size(val);

    is >> c >> val;
    setup.set_solution_size(val);
}

void SetUpParams::edit_params()
{
    std::cout << "(independent_runs;nb_evolution_steps;population_size;solution_size)" << std::endl;
    std::cin >> *this;
}

const unsigned int SetUpParams::get_independent_runs() const
{ return _independent_runs; }

const unsigned int SetUpParams::get_nb_evolution_steps() const
{ return _nb_evolution_steps; }

const unsigned int SetUpParams::get_population_size() const
{ return _population_size; }

const unsigned int SetUpParams::get_solution_size() const
{ return _solution_size; }

void SetUpParams::set_independent_runs(const unsigned int val)
{
    if(val >= 0)
        _independent_runs = val;
}

void SetUpParams::set_nb_evolution_steps(const unsigned int val)
{
    if(val >= 0)
        _nb_evolution_steps = val;
}

void SetUpParams::set_population_size(const unsigned int val)
{
    if(val >= 0)
        _population_size = val;
}

void SetUpParams::set_solution_size(const unsigned int val)
{
    if(val >= 0)
        _solution_size = val;
}
