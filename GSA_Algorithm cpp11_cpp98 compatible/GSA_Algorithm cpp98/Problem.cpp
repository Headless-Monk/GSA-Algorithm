#include "Problem.h"

Problem::Problem(int num): _num_pbm{num}
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

Problem::~Problem()
{}

/*
SETTER
*/

void Problem::set_num_pbm(int num)
{
    _num_pbm = num;
}

void Problem::set_direction(int direction)
{
    _direction = direction;
}

void Problem::set_LowerLimit(double lowerLimit)
{
    _LowerLimit = lowerLimit;
}

void Problem::set_UpperLimit(double upperLimit)
{
    _UpperLimit = upperLimit;
}

void Problem::set_dimension(int dimension)
{
    _dimension = dimension;
}

void Problem::set_nom(std::string nom)
{
    _nom_pbm = nom;
}


/*
GETTER
*/

int Problem::get_num_pbm() const
{
    return _num_pbm;
}

int Problem::get_direction() const
{
    return _direction;
}

double Problem::get_LowerLimit() const
{
    return _LowerLimit;
}

double Problem::get_UpperLimit() const
{
    return _UpperLimit;
}

unsigned int Problem::get_dimension() const
{
    return _dimension;
}

std::string Problem::get_nom_pbm() const
{
    return _nom_pbm;
}

/*
SURCHARGES OPERATEURS DE FLUX
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

bool Problem::operator==(const Problem& pbm) const
{
    return (get_num_pbm() == pbm.get_num_pbm() && get_direction() == pbm.get_direction() && get_LowerLimit() == pbm.get_LowerLimit() && get_UpperLimit() == pbm.get_UpperLimit() && get_dimension() == pbm.get_dimension());
}

bool Problem::operator!= (const Problem& pbm) const
{
    return !(*this==pbm);
}
