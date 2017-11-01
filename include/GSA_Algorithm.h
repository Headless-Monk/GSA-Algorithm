#include <vector>
#include "Solution.h"
#include "SetUpParams.h"

#ifndef GSA_ALGORITHM_H
#define GSA_ALGORITHM_H

using std::vector;

class GSA_Algorithm
  {
	private:
		vector<Solution*> _solutions;     // individuals in population
		vector<struct particle> _fitness_values;
		const SetUpParams& _setup {};
		unsigned int _upper_cost,_lower_cost; // lower and upper fitness of individuals in population

	public:
		GSA_Algorithm(const Problem& pbm,const SetUpParams& setup);
		~GSA_Algorithm();

//		friend ostream& operator<< (ostream& os, const GSA_Algorithm& myAlgo);
//		friend istream& operator>> (istream& is, GSA_Algorithm& myAlgo);
//		GSA_Algorithm& operator= (const GSA_Algorithm& myAlgo);

		const SetUpParams& setup() const;
	  	void initialize();

		// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
        void evaluate();

	 	const vector<Solution*>& solutions() const;
		unsigned int upper_cost() const;
		unsigned int lower_cost() const;
		Solution& solution(const unsigned int index) const;
        vector<struct particle>&  fitness_values();
		double fitness(const unsigned int index) const;


		double best_cost() const;
		double worst_cost() const;
		Solution& best_solution() const;
		Solution& worst_solution() const;

		void evolution(int iter); /*makes an evolution step*/

  };

#endif // GSA_ALGORITHM_H
