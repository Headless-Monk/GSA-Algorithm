#include <iostream>

#include "SetUpParams.h"
#include "Problem.h"
#include "Solution.h"

using std::cout;
using std::endl;

void testSetUpParam()
{
  SetUpParams params{};
  cout << params << endl;
  params.edit_params();
  cout << endl << params << endl;
}

void testProblem()
{
    Problem prob_A{1};
    Problem prob_B{2};
    cout << prob_A << endl;
    cout << endl;
    cout << prob_B << endl;
    //cin >> prob;
    //cout << endl << prob;

    prob_A = prob_B;
    cout << prob_A << endl;
    cout << endl;
    cout << prob_B << endl;

    bool test;
    test = prob_A == prob_B;
    cout << test;
}

void testSolution()
{
  Problem prob_rosen{1};
  Solution sol_rosen{prob_rosen};
  sol_rosen.fitness();
}

int main()
{
    //testSetUpParam();
    //testProblem();
    testSolution();

  return 0;
}
