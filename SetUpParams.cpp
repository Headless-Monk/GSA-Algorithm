#include "SetUpParams.h"


SetUpParams::SetUpParams():
    _nb_evolution_steps{2000000}, _population_size{30},
    _nb_independant_runs{_nb_evolution_steps/_population_size}
{}

SetUpParams::~SetUpParams()
{}

void SetUpParams::edit_params()
{
    std::cout << "(nb_evolution_steps;population_size)" << std::endl;
    std::cin >> *this;
}

void SetUpParams::update_nb_independant_runs()
{
	_nb_independant_runs = _nb_evolution_steps/_population_size;
}

/*
GETTER
*/

const unsigned int SetUpParams::get_nb_evolution_steps() const
{ return _nb_evolution_steps; }

const unsigned int SetUpParams::get_population_size() const
{ return _population_size; }

const unsigned int SetUpParams::get_nb_independant_runs() const
{ return _nb_independant_runs; }

/*
SETTER
*/

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

/*
SURCHARGES OPERATEURS DE FLUX
*/

std::ostream& operator<<(std::ostream& os, const SetUpParams& setup)
{
    os << "nb evolution steps : " << setup._nb_evolution_steps << std::endl;
    os << "nb independant runs : " << setup._nb_independant_runs << std::endl;
    os << "population size :    " << setup._population_size << std::endl;

    return os;
}

std::istream& operator>> (std::istream& is, SetUpParams& setup)
{
    char c;
    unsigned int val;

    is >> c >> val;
    setup.set_nb_evolution_steps(val);

    is >> c >> val;
    setup.set_population_size(val);

    return is;
}
