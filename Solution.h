#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <ostream>
#include <cmath>

#include "Problem.h"

struct point
{
    int x, y;
};

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

	void initialize();
	double fitness();
	void mass_calculation();
	unsigned int size() const;
	double& position(const int index); //retournera une position du tableau _solution
	void  position(const int index, const double value);



	void add_solution(double sol);
	void delete_solution();

	double get_current_fitness() const;
	double get_velocity() const;
	double get_acceleration() const;
	double get_mass() const;
	point get_position() const;
	const Problem& get_pbm() const;
	std::vector<double>& get_solution();

	void set_current_fitness(double fit);
	void set_velocity(double velocity);
	void set_acceleration(double acceleration);
	void set_mass(double acceleration);
	void set_position(point pos);
	void set_position_X(int x);
	void set_position_Y(int y);

private:
  double _velocity;
  double _acceleration;
  double _mass;
  point _position;
	std::vector<double> _solution;
	double _current_fitness;
	const Problem& _pbm;
};

#endif
