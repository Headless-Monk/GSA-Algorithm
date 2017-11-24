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

	void initialize(); //randomize agents positions
	double fitness();
	void mass_calculation();
	unsigned int size() const;
	double& position(const int index); //retournera une position du tableau _solution
	void  position(const int index, const double value);



	void add_position(double sol);
	void delete_position();

	double get_current_fitness() const;
	double get_velocity() const;
	double get_acceleration() const;
	double get_mass() const;
	std::vector<double> get_position() const;
	const Problem& get_pbm() const;

	void set_current_fitness(double fit);
	void set_velocity(double velocity);
	void set_acceleration(double acceleration);
	void set_mass(double acceleration);
	void set_position(int pos, double val);


private:
	const Problem& _pbm;
  std::vector<double> _position;


  double _velocity;
  double _acceleration;
  double _mass;
	double _current_fitness;

};

#endif
