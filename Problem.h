#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <string>

using namespace std;

class Problem
{
public:
	Problem(int num);
	~Problem();

	/* SETTER */
	void set_num_pbm(int num);
	void set_direction(int direction);
	void set_LowerLimit(double lowerLimit);
	void set_UpperLimit(double upperLimit);
	void set_dimension(int dimension);
	void set_nom(std::string nom);

    /* GETTER */
	int get_num_pbm() const;
	int get_direction() const;
	double get_LowerLimit() const;
	double get_UpperLimit() const;
	unsigned int get_dimension() const;
	std::string get_nom_pbm() const;

    /* SURCHARGES OPERATEURS DE FLUX */
	friend ostream& operator<< (ostream& os, const Problem& pbm);
	friend istream& operator>> (istream& is, Problem& pbm);

    /* SURCHARGES OPERATEURS LOGIQUES */
	Problem& operator=  (const Problem& pbm);
	bool operator== (const Problem& pbm) const;
	bool operator!= (const Problem& pbm) const;

private:
	int _num_pbm;
	std::string _nom_pbm;

	int _direction;	//Maximize=0 or Minimize=1
	double _LowerLimit, _UpperLimit;
	int _dimension;

};

#endif
