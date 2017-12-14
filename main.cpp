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

//unsigned benchmark = 1 ;
//SetUpParams setup;

void testAlgo(int pbm)
{
    // cout << " benchmark : "<< benchmark <<endl ;
    // cout << "boucle : "setup.get_independent_runs() <<endl ;

    Problem prob{pbm};
    SetUpParams setup{};
    MyAlgorithm algo{prob, setup};
    algo.initialize();

    cout << "premiere solution : " << endl;
    algo.afficher_best();

    cout << "0                                                                                               100%" << endl;

    algo.evolution();

    cout << endl << endl << "meilleure solution : " << endl;
    algo.afficher_best();

    cout << endl << endl << "all solutions : " << endl;
    algo.afficher_all();
}

bool fin(int a)
{
   /* cout << "(1) Nombre de planètes" << endl; // solution
    cout << "(2) Nombre d'évolutions " << endl; // evolution
    cout << "(3) Nombre de dimensions" << endl; // population
    cout << "(4) Nombre de boucles" << endl; // independant run
    cout << "(5) Choix du benchmark" << endl;
    cout << "(6) Paramètres par défaut" << endl;
    if(a==0)cout << "(7) Quitter" << endl;
    else cout << "(7) Lancer l'algorithme" << endl;

    int choix ;
    cin >>choix ;

    switch ( choix ) {
    case 1:
        cout << "Saisir le nombre de planètes : " ;
        cin >> choix ;
        setup.set_solution_size(5);
    break;
    case 2:
        cout << "Saisir le nombre d'évolutions : " ;
        cin >> choix ;
        setup.set_nb_evolution_steps(choix);
    break;
    case 3:
        cout << "Saisir le nombre de dimensions : " ;
        cin >> choix ;
        setup.set_population_size(choix);
    break;
    case 4:
        cout << "Saisir le nombre de boucles : " ;
        cin >> choix ;
        setup.set_independent_runs(choix);
    break;
    case 5:
        cout << " --> Rosenbrock (1) "<<endl;
        cout << " --> Rastrigin (2) "<<endl;
        cout << " --> Ackley (3) "<<endl;
        cout << " --> Schwefel (4) "<<endl;
        cout << " --> Schaffer (5) "<<endl;
        cout << " --> Weierstrass (6) "<<endl;

        cin >> choix;
        benchmark = choix;

    break;
    case 6:
        return false ;
    break;
    case 7:
        return true;
    break;
    }

    if (!fin(1))
    {
        return false;
    }*/
    return false;
}


int main()
{
    srand(time(NULL));
    //testSetUpParam();
    //testProblem();
    //testSolution();
    //testMass();

    //while (!fin(0))
   // {
    testAlgo(1);
    //}
  return 0;
}


