#include "Problem.h"

/**
  Constructeur de problème
	@param[in] num - Numero du problème
*/
Problem::Problem(int num): _num_pbm(num)
{
  _dimension = 30;
  switch(_num_pbm)
  {
    case 1 :
      _nom_pbm = "Rosenbrock";
      _LowerLimit = -5;
      _UpperLimit = 10;
      _direction = 1;
      break;

    case 2 :
      _nom_pbm = "Rastrigin";
      _LowerLimit = -5.12;
      _UpperLimit = 5.12;
      _direction = 1;
      break;

    case 3 :
      _nom_pbm = "Ackley";
      _LowerLimit = -32.768;
      _UpperLimit = 32.768;
      _direction = 1;
      break;

    case 4 :
      _nom_pbm = "Schwefel";
      _LowerLimit = -500;
      _UpperLimit = 500;
      _direction = 1;
      break;

    case 5 :
      _nom_pbm = "Schaffer";
      _LowerLimit = -100;
      _UpperLimit = 100;
      _dimension = 2;
      _direction = 1;
      break;

    case 6 :
      _nom_pbm = "Weierstrass";
      _LowerLimit = -2;
      _UpperLimit = 2;
      _dimension = 1;
      _direction = 1;
      break;
  }
}

/**
  Destructeur de problème
*/
Problem::~Problem()
{}

/*
SETTER
*/

/**
  Modifie le numero du probleme
	@param[in] num - Numero du problème
*/
void Problem::set_num_pbm(int num)
{
    _num_pbm = num;
}

/**
  Modifie la direction du problème Maximisation/Minimisation
	@param[in] direction - Direction du problème
*/
void Problem::set_direction(int direction)
{
    _direction = direction;
}

/**
  Modifie la limite basse du problème
	@param[in] lowerLimit - limite basse
*/
void Problem::set_LowerLimit(double lowerLimit)
{
    _LowerLimit = lowerLimit;
}

/**
  Modifie la limite haute du problème
	@param[in] upperLimit - limite haute
*/
void Problem::set_UpperLimit(double upperLimit)
{
    _UpperLimit = upperLimit;
}

/**
  Modifie la dimension du problème
	@param[in] dimension - dimension
*/
void Problem::set_dimension(int dimension)
{
    _dimension = dimension;
}

/**
  Modifie le nom du problème
	@param[in] nom - nom du probleme
*/
void Problem::set_nom(std::string nom)
{
    _nom_pbm = nom;
}


/*
GETTER
*/

/**
  Retourne le numero du probleme
	@param[out] num - int
*/
int Problem::get_num_pbm() const
{
    return _num_pbm;
}

/**
  Retourne la direction du problème
	@param[out] dir - int
*/
int Problem::get_direction() const
{
    return _direction;
}

/**
  Retourne la limite basse du problème
	@param[out] lowerlimit - double
*/
double Problem::get_LowerLimit() const
{
    return _LowerLimit;
}

/**
  Retourne la limite haute du problème
	@param[out] upperlimit - double
*/
double Problem::get_UpperLimit() const
{
    return _UpperLimit;
}

/**
  Retourne la dimension du problème
	@param[out] dimension - int
*/
unsigned int Problem::get_dimension() const
{
    return _dimension;
}

/**
  Retourne le nom du problème
	@param[out] nom_pbm - string
*/
std::string Problem::get_nom_pbm() const
{
    return _nom_pbm;
}

/*
SURCHARGES OPERATEURS DE FLUX
*/

/**
  Affiche toutes les donnees du problème sur le flux passe en parametre
	@param[in] os - ostream
	@param[in] pbm - Problem
	@param[out] os - ostream
*/
ostream& operator<<(ostream& os, const Problem& pbm)
{
    os << "Nom du probleme :    " << pbm.get_nom_pbm() << endl;
    if(pbm.get_direction() == 1)
        os << "Direction :          Minimisation" << endl;
    else
        os << "Direction :          Maximisation" << endl;
    os << "Limite basse :       " << pbm.get_LowerLimit() << endl;
    os << "Limite haute :       " << pbm.get_UpperLimit() << endl;
    os << "Dimension :          " << pbm.get_dimension();

    return os;
}

/**
  Lit les donnees du probleme sur le flux passe en parametre
	@param[in] is - istream
	@param[in] pbm - Problem
	@param[out] is - istream
*/
istream& operator>>(istream& is, Problem& pbm)
{
    cout << "Entrez les valeurs sous la forme (Numero probleme;Direction;Limite basse;Limite haute;Dimension)" << endl;

    char c;
    int tmp_1;
    double tmp_2;
    is >> c;

    is >> tmp_1;
        pbm.set_num_pbm(tmp_1);
    is >> c;

    is >> tmp_1;
        pbm.set_direction(tmp_1);
    is >> c;

    is >> tmp_2;
        pbm.set_LowerLimit(tmp_2);
    is >> c;

    is >> tmp_2;
        pbm.set_UpperLimit(tmp_2);
    is >> c;

    is >> tmp_1;
        pbm.set_dimension(tmp_1);
    is >> c;

    return is;
}

/*
SURCHARGES OPERATEURS LOGIQUES
*/

/**
  Recopie le probleme passee en parametre dans le probleme actuel
  	@param[in] pbm - Problem
	@param[out] pbm - Problem
*/
Problem& Problem::operator=(const Problem& pbm)
{
    set_nom(pbm.get_nom_pbm());
    set_num_pbm(pbm.get_num_pbm());
    set_direction(pbm.get_direction());
    set_LowerLimit(pbm.get_LowerLimit());
    set_UpperLimit(pbm.get_UpperLimit());
    set_dimension(pbm.get_dimension());

    return *this;
}
