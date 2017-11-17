#ifndef PROBLEM_H
#define PROBLEM_H

class Direction;
class Problem // boundaries and dimension of search space
{
public:
	Problem(int num);
	~Problem();

	//friend ostream& operator<< (ostream& os, const Problem& pbm);
	//friend istream& operator>> (istream& is, Problem& pbm);

	//Problem& operator=  (const Problem& pbm);
	//bool operator== (const Problem& pbm) const;
	//bool operator!= (const Problem& pbm) const;



	//Direction _direction() const; //Maximize=0 or Minimize=1
	//int r_dimension() const;


private:
	int _num_pbm;

	int _direction;	//Maximize=0 or Minimize=1
	double _LowerLimit, _UpperLimit;
	int _dimension;

};

#endif
