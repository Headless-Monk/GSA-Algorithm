#ifndef SETUPPARAM_H
#define SETUPPARAM_H

#include <iostream>

class SetUpParams
{
	//ici vous devez mettre quelques parametres tels que :

private:
	unsigned int _nb_evolution_steps;       // number of iterations per run
	unsigned int _population_size;		// number of solutions in the population
	unsigned int _nb_independant_runs;

public:
	SetUpParams();
	~SetUpParams();

	friend std::ostream& operator<< (std::ostream& os, const SetUpParams& setup);
	friend std::istream& operator>> (std::istream& is, SetUpParams& setup);
	void edit_params();

	const unsigned int   get_nb_evolution_steps() const;
	const unsigned int   get_population_size() const;
	const unsigned int   get_nb_independant_runs() const;
	void 				 update_nb_independant_runs();

	void set_nb_evolution_steps(const unsigned int val);
	void set_population_size(const unsigned int val);
};

#endif
