#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <ostream>
#include <cmath>
#include <cstdlib>


#include "Problem.h"

struct point
{
    double x, y;
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

	double fitness();
	void mass_calculation();



	void initialize(); //randomize agents positions
	void add_position(double sol);
	void delete_position();

	double get_current_fitness() const;
	double get_velocity() const;
	double get_acceleration() const;
	double get_mass() const;
	const Problem& get_pbm() const;
	unsigned int get_size() const;
	double get_position(const int index) const;


	void set_current_fitness(double fit);
	void set_velocity(double velocity);
	void set_acceleration(double acceleration);
	void set_mass(double acceleration);
	void set_position(const int index, const double val);


private:
	const Problem& _pbm;
  std::vector<double> _position;
	double _current_fitness;


  double _velocity;
  double _acceleration;
  double _mass;

};

#endif
