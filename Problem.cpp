#include "Problem.h"

Problem::Problem(int num): _num_pbm{num}
{
  switch(_num_pbm)
  {
    case 1 :
      _LowerLimit = 0;
      _UpperLimit = 1;
      _dimension = 30;
      break;

    case 2 :
      _LowerLimit = 0;
      _UpperLimit = 1;
      _dimension = 30;
      break;

    //case...
  }
}
