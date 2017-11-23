#include "Solution.h"


Solution::Solution(const Problem& pbm):
        _pbm{pbm}
{}


Solution::~Solution()
{}


double Solution::fitness()
{

    switch(_pbm.get_num_pbm())
    {
      case 1 : //Rosenbrock

        break;

      case 2 : //Rastrigin

        break;

      case 3 : //Ackley

        break;

      case 4 : //Schwefel

        break;

      case 5 : //Schaffer

        break;

      case 6 : //Weierstrass

        break;
    }
}
