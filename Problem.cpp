#include "Problem.h"

Problem::Problem(int num): _num_pbm{num}
{
  _dimension = 30;
  switch(_num_pbm)
  {
    case 1 : //Rosenbrock
      _LowerLimit = -5;
      _UpperLimit = 10;
      _direction = 1;
      break;

    case 2 : //Rastrigin
      _LowerLimit = -5.12;
      _UpperLimit = 5.12;
      _direction = 1;
      break;

    case 3 : //Ackley
      _LowerLimit = -32.768;
      _UpperLimit = 32.768;
      _direction = 1;
      break;

    case 4 : //Schwefel
      _LowerLimit = -500;
      _UpperLimit = 500;
      _direction = 1;
      break;

    case 5 : //Schaffer
      _LowerLimit = -100;
      _UpperLimit = 100;
      _dimension = 2;
      _direction = 1;
      break;

    case 6 : //Weierstrass
      _LowerLimit = -2;
      _UpperLimit = 2;
      _dimension = 1;
      _direction = 1; //à vérifier
      break;
  }
}

Problem::~Problem()
{
}

/*
SETTER
*/

void Problem::_set_num_pbm(int num)
{
    _num_pbm = num;
}

void Problem::_set_direction(int direction)
{
    _direction = direction;
}

void Problem::_set_LowerLimit(double lowerLimit)
{
    _LowerLimit = lowerLimit;
}

void Problem::_set_UpperLimit(double upperLimit)
{
    _UpperLimit = upperLimit;
}

void Problem::_set_dimension(int dimension)
{
    _dimension = dimension;
}

/*
GETTER
*/

int Problem::_get_num_pbm() const
{
    return _num_pbm;
}

int Problem::_get_direction() const
{
    return _direction;
}

double Problem::_get_LowerLimit() const
{
    return _LowerLimit;
}

double Problem::_get_UpperLimit() const
{
    return _UpperLimit;
}

int Problem::_get_dimension() const
{
    return _dimension;
}

/*
SURCHARGES OPERATEURS DE FLUX
*/

ostream& operator<<(ostream& os, const Problem& pbm)
{
    os << "Numero du probleme : " << pbm._get_num_pbm() << endl;
    os << "Direction : " << pbm._get_direction() << endl;
    os << "Limite basse : " << pbm._get_LowerLimit() << endl;
    os << "Limite haute : " << pbm._get_UpperLimit() << endl;
    os << "Dimension : " << pbm._get_dimension();
}

istream& operator>>(istream& is, Problem& pbm)
{
    cout << "Entrez les valeurs sous la forme (x,x,x,x,x) avec un 'n' si la valeur ne change pas" << endl;

    char c;
    int tmp_1;
    double tmp_2;
    is >> c;

    is >> tmp_1;
    if(tmp_1 != 'n')
        pbm._set_num_pbm(tmp_1);
    is >> c;

    is >> tmp_1;
    if(tmp_1 != 'n')
        pbm._set_direction(tmp_1);
    is >> c;

    is >> tmp_2;
    if(tmp_2 != 'n')
        pbm._set_LowerLimit(tmp_2);
    is >> c;

    is >> tmp_2;
    if(tmp_2 != 'n')
        pbm._set_UpperLimit(tmp_2);
    is >> c;

    is >> tmp_1;
    if(tmp_1 != 'n')
        pbm._set_dimension(tmp_1);
    is >> c;
}

/*
SURCHARGES OPERATEURS LOGIQUES
*/

Problem& Problem::operator=(const Problem& pbm)
{
    _set_num_pbm(pbm._get_num_pbm());
    _set_direction(pbm._get_direction());
    _set_LowerLimit(pbm._get_LowerLimit());
    _set_UpperLimit(pbm._get_UpperLimit());
    _set_dimension(pbm._get_dimension());
}

bool Problem::operator==(const Problem& pbm) const
{
    return (_get_num_pbm() == pbm._get_num_pbm() && _get_direction() == pbm._get_direction() && _get_LowerLimit() == pbm._get_LowerLimit() && _get_UpperLimit() == pbm._get_UpperLimit() && _get_dimension() == pbm._get_dimension());
}

bool Problem::operator!= (const Problem& pbm) const
{
    return !(*this==pbm);
}





