#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <vector>
#include <ostream>

#include "Solution.h"
#include "SetUpParams.h"

class Problem;

class MyAlgorithm
{
public:
	MyAlgorithm(Problem& pbm, SetUpParams& setup);
	~MyAlgorithm();

	void evolution(); //makes an evolution step ; recursive function from max_it to 0
	void initialize(); //random position for each solution + velocity=0
    void afficher_best();
	void afficher_all();
    void change_parameters(SetUpParams &setup, Problem &pbm);

	void upper_cost(); //trouve la meilleure solution de l'itération
	void lower_cost(); //trouve la pire solution de l'itération
	void best_cost_overall(); //best fitness
	void spaceBound(Solution *sol); // check if solutions of iteration are still in boundaries ? else random pos or return to boundaries
	double g_evolution(int iter); //calcule g pour une itération



private:
	std::vector<Solution*> _solutions;     // individuals in population
    Solution *_upper_cost, *_lower_cost; // lower and upper fitness of individuals in population
	Solution *_best_Solution_overall;

	Problem &_pbm;
	SetUpParams &_setup;

	double _g;
};

#endif
