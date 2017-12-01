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
	MyAlgorithm(const Problem& pbm, const SetUpParams& setup);
	~MyAlgorithm();

	/*
	* FAIT
	*/
	void initialize(); //random position for each solution + velocity=0
	void upper_cost(); //trouve la meilleure solution de l'itération
	void lower_cost(); //trouve la pire solution de l'itération
	void best_cost_overall(); //best fitness
	double g_evolution(int iter); //calcule g pour une itération
	void spaceBound(Solution *sol); // check if solutions of iteration are still in boundaries ? else random pos or return to boundaries
	void evolution(int iter); //makes an evolution step ; recursive function from max_it to 0
	void afficher_best();
	void afficher_all();

	/*
	* A FAIE
	*/


	//friend std::ostream& operator<< (std::ostream& os, const MyAlgorithm& myAlgo);
	//friend std::istream& operator>> (std::istream& is, MyAlgorithm& myAlgo);
	//MyAlgorithm& operator= (const MyAlgorithm& myAlgo);
	const SetUpParams& setup() const;
	void initProblem(); //switch init upper/lower limit and dimension

	// creates an array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
	void evaluate();

	//const std::vector<Solution*>& solutions() const;
	Solution& solution(const unsigned int index) const;
	//std::vector<struct particle>& fitness_values();
	//double fitness(const unsigned int index) const;

	double average_cost() const; //average fitness
	Solution& best_solution() const;
	//Solution& average_solution() const;
	//Solution& worst_solution() const;


private:
	std::vector<Solution*> _solutions;     // individuals in population
	const Problem &_pbm;
	const SetUpParams &_setup;
	Solution *_upper_cost, *_lower_cost; // lower and upper fitness of individuals in population
	double _g;
	Solution *_best_Solution_overall;
	int _iterations;

	//std::vector<struct Particle> _fitness_values;
};

#endif
