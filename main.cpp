#include <iostream>
#include <ctime>

#include "SetUpParams.h"
#include "Problem.h"
#include "Solution.h"
#include "MyAlgorithm.h"

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

void testMass()
{
  /*Problem prob{1};

  Solution sol1{prob};
  Solution sol2{prob};
  Solution sol3{prob};

  sol1.initialize();
  for(unsigned int i=0; i<sol1.get_size(); i++)
    sol1.set_position(i, 1);
  sol2.initialize();
  for(unsigned int i=0; i<sol2.get_size()-10; i++)
    sol2.set_position(i, 1);
  sol3.initialize();

  sol1.fitness();
  cout << "fitness 1 : " << sol1.get_current_fitness() << endl;
  sol2.fitness();
  cout << "fitness 2 : " << sol2.get_current_fitness() << endl;
  sol3.fitness();
  cout << "fitness 3 : " << sol3.get_current_fitness() << endl << endl;

  sol1.mass_calculation(sol1, sol3);
  cout << "mass 1 : " << sol1.get_mass() << endl;
  sol2.mass_calculation(sol1, sol3);
  cout << "mass 2 : " << sol2.get_mass() << endl;
  sol3.mass_calculation(sol1, sol3);
  cout << "mass 3 : " << sol3.get_mass() << endl;*/
}

void testAlgo()
{
  Problem prob{1};
  SetUpParams setup{};

  MyAlgorithm algo{prob, setup};
  algo.initialize();

  cout << "première solution : " << endl;
  algo.afficher_best();
  cout << endl;

  algo.evolution();

  cout << "meilleure solution : " << endl;
  algo.afficher_best();
}


int main()
{
    srand(time(NULL));
    //testSetUpParam();
    //testProblem();
    //testSolution();
    //testMass();
    testAlgo();

  return 0;
}
