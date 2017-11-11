#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include "Particle.h"

#include <vector>
#include <ostream>

class Solution;
class SetUpParams;
class Problem;

class MyAlgorithm
{
private:
	std::vector<Solution*> _solutions;     // individuals in population
	//std::vector<struct Particle> _fitness_values;
	const SetUpParams &_setup;
	const Problem &_pbm;
	unsigned int _upper_cost, _lower_cost; // lower and upper fitness of individuals in population

public:
	MyAlgorithm(const Problem& pbm, const SetUpParams& setup);
	~MyAlgorithm();

	//friend std::ostream& operator<< (std::ostream& os, const MyAlgorithm& myAlgo);
	//friend std::istream& operator>> (std::istream& is, MyAlgorithm& myAlgo);
	//MyAlgorithm& operator= (const MyAlgorithm& myAlgo);
	const SetUpParams& setup() const;
	void initialize(); //random position for each solution + velocity=0
	void initProblem(); //switch init upper/lower limit and dimension

	// creates an array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
	void evaluate();

	const std::vector<Solution*>& solutions() const;
	unsigned int upper_cost() const;
	unsigned int lower_cost() const;
	Solution& solution(const unsigned int index) const;
	std::vector<struct particle>&  fitness_values();
	double fitness(const unsigned int index) const;


	double best_cost() const; //best fitness
	double average_cost() const; //average fitness
	Solution& best_solution() const;
	//Solution& average_solution() const;
	//Solution& worst_solution() const;

	void spaceBound(); // check if solutions of iteration are still in boundaries ? else random pos or return to boundaries
	void evolution(int iter); //makes an evolution step ; recursive function from max_it to 0

};

#endif
