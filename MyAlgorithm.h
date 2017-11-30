#ifndef MYALGORITHM_H
#define MYALGORITHM_H

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
	double _upper_cost, _lower_cost; // lower and upper fitness of individuals in population
	double _g;
	Solution _best_Solution_overall;

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

	//const std::vector<Solution*>& solutions() const;
	double upper_cost();
	double lower_cost();
	Solution& solution(const unsigned int index) const;
	//std::vector<struct particle>& fitness_values();
	//double fitness(const unsigned int index) const;

	void best_cost_overall() const; //best fitness
	double best_cost_overall() const; //best fitness
	double average_cost() const; //average fitness
	Solution& best_solution() const;
	//Solution& average_solution() const;
	//Solution& worst_solution() const;

	void spaceBound(); // check if solutions of iteration are still in boundaries ? else random pos or return to boundaries
	void evolution(int iter); //makes an evolution step ; recursive function from max_it to 0
};

#endif
