#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>

using namespace std;

class Problem // boundaries and dimension of search space
{
public:
	Problem(int num);
	~Problem();

	friend ostream& operator<< (ostream& os, const Problem& pbm);
	friend istream& operator>> (istream& is, Problem& pbm);

	void set_num_pbm(int num);
	void set_direction(int direction);
	void set_LowerLimit(double lowerLimit);
	void set_UpperLimit(double upperLimit);
	void set_dimension(int dimension);

	int get_num_pbm() const;
	int get_direction() const;
	double get_LowerLimit() const;
	double get_UpperLimit() const;
	unsigned int get_dimension() const;

	Problem& operator=  (const Problem& pbm);
	bool operator== (const Problem& pbm) const;
	bool operator!= (const Problem& pbm) const;

private:
	int _num_pbm;

	int _direction;	//Maximize=0 or Minimize=1
	double _LowerLimit, _UpperLimit;
	int _dimension;

};

#endif
