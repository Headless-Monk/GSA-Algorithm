#ifndef PROBLEM_H
#define PROBLEM_H

class Problem //benchmark
{
public:
	Problem(int num, int lower, int upper, int direction, int dimension);
	~Problem();

	//friend ostream& operator<< (ostream& os, const Problem& pbm);
	//friend istream& operator>> (istream& is, Problem& pbm);

	//Problem& operator=  (const Problem& pbm);
	//bool operator== (const Problem& pbm) const;
	//bool operator!= (const Problem& pbm) const;



	Direction _direction() const; //Maximize=0 or Minimize=1
	int _dimension() const;
	double _LowerLimit, _UpperLimit;

private:

	int _dimension;
	int _num_pbm;
};

#endif
