#ifndef SETUPPARAM_H
#define SETUPPARAM_H

#include <iostream>

class SetUpParams
{
public:
	SetUpParams();
	~SetUpParams();

	void edit_params();
    void update_nb_independant_runs();

    /* GETTER */
	const unsigned int   get_nb_evolution_steps() const;
	const unsigned int   get_population_size() const;
	const unsigned int   get_nb_independant_runs() const;

    /* SETTER */
	void set_nb_evolution_steps(const unsigned int val);
	void set_population_size(const unsigned int val);

	/* SURCHARGES OPERATEURS DE FLUX */
    friend std::ostream& operator<< (std::ostream& os, const SetUpParams& setup);
	friend std::istream& operator>> (std::istream& is, SetUpParams& setup);

private:
	unsigned int _nb_evolution_steps;   // number of iterations per run
	unsigned int _population_size;		// number of solutions in the population
	unsigned int _nb_independant_runs;
};

#endif
