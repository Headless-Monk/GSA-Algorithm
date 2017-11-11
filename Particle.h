#ifndef PARTICLE_H
#define PARTICLE_H

class Particle // index of a particle in the swarm and its fitness
{
public:
	Particle();
	~Particle();

private :
	int index;
	double fitness;
};

#endif

