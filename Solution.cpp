#include "Solution.h"

#ifndef M_PI
    #define M_PI 3.1415926535897932384626
#endif

Solution::Solution(const Problem& pbm):
        _pbm{pbm}
{}


Solution::~Solution()
{}


double Solution::fitness()
{
    double sum = 0;

    double tmp1 = 0;
    double tmp2 = 0;

    switch(_pbm.get_num_pbm())
    {
      case 1 : //Rosenbrock
        for(int i=1; i<_pbm.get_dimension(); i++)
        {
            sum += pow(100 * (i+1 - pow(i, 2)), 2) + pow(i-1, 2);
        }
        break;

      case 2 : //Rastrigin
        sum = 10 * _pbm.get_dimension();
        for(int i=1; i<=_pbm.get_dimension(); i++)
        {
            sum += pow(i, 2) - 10*cos(2*M_PI*i);
        }
        break;

      case 3 : //Ackley
        for(int i=1; i<=_pbm.get_dimension(); i++)
        {
            tmp1 += pow(i, 2);
        }

        for(int i=1; i<=_pbm.get_dimension(); i++)
        {
            tmp2 += cos(2*M_PI*i);
        }

        sum += -20 * exp(-0.2 * sqrt((1/_pbm.get_dimension())*tmp1));
        sum -= exp((1/_pbm.get_dimension())*tmp2);
        sum += 20 + exp(1);
        break;

      case 4 : //Schwefel
        for(int i=1; i<=_pbm.get_dimension(); i++)
        {
            tmp1 += i * sin(sqrt(i));
        }
        sum += 418.9829 * _pbm.get_dimension() - tmp1 ;
        break;

      case 5 : //Schaffer
        sum += 0.5 +
        ( pow(sin(pow(1,2)-pow(2,2)),2)  - 0.5 ) / (pow(1+0.001 * (pow(1,2)+pow(2,2)),2));
        break;

      case 6 : //Weierstrass
        for(int i=0; i<=_pbm.get_dimension(); i++)
        {
            sum += pow(0.7, i) * cos ( pow(0.025 * i , i) * M_PI * i)
        }
        break;
    }
}
