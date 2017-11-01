#include <iostream>
#include "../include/GSA_Algorithm.h"


using namespace std;

struct particle // index of a particle in the swarm and its fitness
{
    int index;
    double fitness;
};


GSA_Algorithm::GSA_Algorithm(const Problem& pbm,const SetUpParams& setup)
{}
GSA_Algorithm::~GSA_Algorithm()
{}

// friend ostream& operator<< (ostream& os, const GSA_Algorithm& myAlgo);
// friend istream& operator>> (istream& is, GSA_Algorithm& myAlgo);
// GSA_Algorithm& operator= (const GSA_Algorithm& myAlgo);

const SetUpParams& GSA_Algorithm::setup() const
{}
void GSA_Algorithm::initialize()
{
}

// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
void GSA_Algorithm::evaluate()
{
}

const vector<Solution*>& GSA_Algorithm::solutions() const
{
}

unsigned int GSA_Algorithm::upper_cost() const
{
}

unsigned int GSA_Algorithm::lower_cost() const
{
}

Solution& GSA_Algorithm::solution(const unsigned int index) const
{
}

vector<struct particle>&  GSA_Algorithm::fitness_values()
{
}

double GSA_Algorithm::fitness(const unsigned int index) const
{
}


double GSA_Algorithm::best_cost() const
{
}

double GSA_Algorithm::worst_cost() const
{
}

Solution& GSA_Algorithm::best_solution() const
{
}

Solution& GSA_Algorithm::worst_solution() const
{
}

void GSA_Algorithm::evolution(int iter) /*makes an evolution step*/
{
}


int main()
{
	cout << "test" << endl;
    return 0;
}

