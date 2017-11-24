#include <iostream>
#include <ctime>

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
    Problem prob{1};
    Solution sol{prob};

    sol.initialize();
    //for(int i=0; i<sol.get_size(); i++)
      //sol.set_position(i, 1);
    cout << sol;
    cout << endl;


    sol.fitness();
    cout << "fitness : " << sol.get_current_fitness() << endl;
}

int main()
{
    srand(time(NULL));

    //testSetUpParam();
    //testProblem();
    testSolution();

  return 0;
}
