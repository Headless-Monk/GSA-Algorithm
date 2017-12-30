#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <ostream>
#include <cmath>
#include <cstdlib>


#include "Problem.h"

class Solution
{
public:
	Solution(const Problem& pbm);
	~Solution();

	void initialize(); //randomize agents positions
	void mass_calculation(const Solution *minFit, const Solution *maxFit); //solutions ayant la fitness min et max dans la population de MyAlgorithm
	void inertia_mass_calculation(double mass_sum);
	void acceleration_calculation(std::vector<Solution*> &v, double g);
	void update_solution();
    bool check_boundaries();
	void fitness();
	void add_position(double pos);
	void delete_position();

    /* GETTER */
	const Problem& get_pbm() const;
	double get_current_fitness() const;
	double get_mass() const;
	double get_inertia_mass() const;
	unsigned int get_size() const;
	double get_position(const int index) const;
	double get_velocity(const int index) const;
	double get_acceleration(const int index) const;

    /* SETTER */
	void set_current_fitness(double fit);
	void set_mass(double acceleration);
	void set_position(const int index, const double pos);

	/* OPERATEURS DE FLUX */
	Solution& operator=(const Solution &sol);
	friend std::ostream& operator<< (std::ostream& os, const Solution& sol);

private:
    const Problem& _pbm;

    std::vector<double> _position;
    vector<double> _velocity;
    vector<double> _acceleration;

    double _current_fitness;
    double _mass; // best=1 ; worst=0
    double _inertia_mass;
};

#endif
