#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <ostream>
#include <cmath>
#include <cstdlib>


#include "Problem.h"

class Solution
{
	//contient la declaration d'une solution
public:
	Solution(const Problem& pbm);
	Solution(const Solution& sol);
	~Solution();

	friend std::ostream& operator<< (std::ostream& os, const Solution& sol);
	friend std::istream& operator>> (std::istream& is, Solution& sol);

	//Solution& operator=  (const Solution& sol);
	//bool operator== (const Solution& sol) const;
	//bool operator!= (const Solution& sol) const;

	void update_solution();
	vector<double> force_calculation(Solution *Sol, double g);
	void total_force_calculation(std::vector<Solution*> v, double g);
	void acceleration_calculation();
	void inertia_mass_calculation(double mass_sum); //somme de toutes les masses de la population
	void mass_calculation(const Solution &minFit, const Solution &maxFit); //solutions ayant la fitness min et max dans la population de MyAlgorithm
	double fitness();
	void initialize(); //randomize agents positions
	void add_position(double sol);
	void delete_position();

	double get_current_fitness() const;
	double get_mass() const;
	const Problem& get_pbm() const;
	unsigned int get_size() const;
	double get_position(const int index) const;

	void set_current_fitness(double fit);
	void set_mass(double acceleration);
	void set_position(const int index, const double val);

private:
	const Problem& _pbm;
    std::vector<double> _position;
	double _current_fitness;
    double _mass; // best=1 ; worst=0
	double _inertia_mass;
	vector<double> _total_force;

    vector<double> _velocity;
    vector<double> _acceleration;

};

#endif
