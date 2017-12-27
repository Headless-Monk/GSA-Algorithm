#include "SetUpParams.h"

/**
  Constructeur de SetUpParams
*/
SetUpParams::SetUpParams():
    _nb_evolution_steps(2000000), _population_size(30),
    _nb_independant_runs(_nb_evolution_steps/_population_size)
{}

/**
  Destructeur de SetUpParams
*/
SetUpParams::~SetUpParams()
{}

/**
  Modifie la valeur de la masse d'une solution
*/
void SetUpParams::edit_params()
{
    std::cout << "(nb_evolution_steps;population_size)" << std::endl;
    std::cin >> *this;
}

/**
  Modifie la valeur du nombre de runs independants en fonctions du nombre d'evolutions et de la taille de la population
*/
void SetUpParams::update_nb_independant_runs()
{
	_nb_independant_runs = _nb_evolution_steps/_population_size;
}

/*
GETTER
*/

/**
  Retourne le nombre de boucles d'evolution de la resolution
  @param[out] nb_evolution_steps - int
*/
const unsigned int SetUpParams::get_nb_evolution_steps() const
{ return _nb_evolution_steps; }

/**
  Retourne le nombre d'individus de la resolution
  @param[out] population_size - int
*/
const unsigned int SetUpParams::get_population_size() const
{ return _population_size; }

/**
  Retourne le nombre de runs independants de la resolution
  @param[out] nb_independant_runs - int
*/
const unsigned int SetUpParams::get_nb_independant_runs() const
{ return _nb_independant_runs; }

/*
SETTER
*/

/**
  Modifie le nombre de boucles d'evolution de la resolution
  @param[in] val - int
*/
void SetUpParams::set_nb_evolution_steps(const unsigned int val)
{
    if(val >= 0)
        _nb_evolution_steps = val;
}

/**
  Modifie le nombre d'individus de la resolution
  @param[in] val - int
*/
void SetUpParams::set_population_size(const unsigned int val)
{
    if(val >= 0)
        _population_size = val;
}

/*
SURCHARGES OPERATEURS DE FLUX
*/

/**
  Affiche les donnees d'une resolution sur le flux passe en parametre
  @param[in] os - ostream
  @param[in] setup - SetUpParams
*/
std::ostream& operator<<(std::ostream& os, const SetUpParams& setup)
{
    os << "nb evolution steps : " << setup._nb_evolution_steps << std::endl;
    os << "nb independant runs : " << setup._nb_independant_runs << std::endl;
    os << "population size :    " << setup._population_size << std::endl;

    return os;
}

/**
  Lit les donnees d'une resolution sur le flux passe en parametre
  @param[in] is - istream
  @param[in] setup - SetUpParams
*/
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
