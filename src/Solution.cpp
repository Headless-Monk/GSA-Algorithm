#include "../include/Solution.h"


Solution::Solution (const Problem& pbm)
{}

Solution::Solution (const Solution& sol)
{}
Solution::~Solution()
{}

//friend ostream& operator<< (ostream& os, const Solution& sol);
//friend istream& operator>> (istream& is, Solution& sol);

const Problem& Solution::pbm() const
{
}

/*
Solution& operator=  (const Solution& sol);
bool operator== (const Solution& sol) const;
bool operator!= (const Solution& sol) const;
*/

void Solution::initialize()
{
}

double Solution::fitness()
{
}

double Solution::get_fitness()
{
}

unsigned int Solution::size() const
{
}

vector<double>& Solution::solution()
{
}

double& Solution::position(const int index) //retournera une position du tableau _solution
{
}
void Solution::position(const int index, const double value)
{
}
