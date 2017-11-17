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
