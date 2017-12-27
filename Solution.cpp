#include "Solution.h"

#ifndef M_PI
    #define M_PI 3.1415926535897932384626
#endif

Solution::Solution(const Problem& pbm):
        _pbm(pbm),
        _position(), _velocity(), _acceleration(),
        _current_fitness(0), _mass(0)
{
    _position.reserve(_pbm.get_dimension());
    _position.resize(_pbm.get_dimension(), 0);

    _acceleration.reserve(_pbm.get_dimension());
    _acceleration.resize(_pbm.get_dimension(), 0);

    _velocity.reserve(_pbm.get_dimension());
    _velocity.resize(_pbm.get_dimension(), 0);
}

Solution::~Solution()
{}

/**
  Initialise la position de toutes les solutions avec un nombre aléatoire compris entre les bornes du problème
	@param[out] position - Vecteurs position
*/
void Solution::initialize()
{
    for(unsigned int i=0; i<_pbm.get_dimension(); i++)
        _position[i] = ( (double)rand() / RAND_MAX ) * ( _pbm.get_UpperLimit() - _pbm.get_LowerLimit() ) + _pbm.get_LowerLimit();
}

/**
  Calcule la masse gravitationnelle d'une planète en fonction de la fitness maximale et minimale
	@param[in] *minFit - Un pointeur sur la fitness minimale de la solution
	@param[in] *maxFit - Un pointeur sur la fitness maximale de la solution
	@param[out] mass - La masse gravitationnelle de la solution
*/
void Solution::mass_calculation(const Solution *minFit, const Solution *maxFit)
{
    if(minFit->_current_fitness == maxFit->_current_fitness)
        _mass = 1;
    else
    {
        double best, worst;

        if(_pbm.get_direction() == 1)
        {
            best = minFit->_current_fitness;
            worst = maxFit->_current_fitness;
        }
        else
        {
            best = maxFit->_current_fitness;
            worst = minFit->_current_fitness;
        }
        _mass = (_current_fitness - worst) / (best - worst);
    }
}

/**
  Calcule l'accéleration d'une solution
	@param[in] v - Vecteur de pointeur sur Solution
	@param[in] g - Constance gravitationnelle
*/
void Solution::acceleration_calculation(std::vector<Solution*> &v, double g)
{
    for(unsigned int i=0; i<_pbm.get_dimension(); i++)
        _acceleration[i] = 0;

    double e = 1.0;
	while (1.0 + e / 2.0 > 1.0)
	{
		e /= 2.0;
	}

    for(unsigned int j=0; j<v.size(); j++)
    {
        if(this != v[j])
        {
            double distance = 0;
            for(unsigned int i = 0; i < _pbm.get_dimension(); i++)
            {
                distance += pow(v[j]->_position[i] - _position[i], 2);
            }
            distance = sqrt(distance);

            for(unsigned int k=0; k<_pbm.get_dimension(); k++)
            {
                double r = ((double)rand() / RAND_MAX);
                _acceleration[k] += ( (r * g * v[j]->_mass * (v[j]->_position[k] - _position[k])) / (distance + e) );
            }
        }
    }
}

/**
  Met à jour la vélocité et la position en fonction des valeurs précédentes et de l'acc
	@param[in] v - Vecteur de pointeur sur Solution
	@param[in] g - Constance gravitationnelle
*/
void Solution::update_solution()
{
    for(unsigned int i = 0; i < _pbm.get_dimension(); i++)
    {
        _velocity[i] = ((double)rand() / RAND_MAX) * _velocity[i] + _acceleration[i];
        _position[i] = _position[i] + _velocity[i];
    }
}

bool Solution::check_boundaries()
{
  for(unsigned int i=0; i<_pbm.get_dimension(); i++)
    if(_position[i]>_pbm.get_UpperLimit() || _position[i]<_pbm.get_LowerLimit())
      return false;
  return true;
}

void Solution::fitness()
{
    double sum = 0;

    double tmp1 = 0;
    double tmp2 = 0;

    switch(_pbm.get_num_pbm())
    {
      case 1 : //Rosenbrock
        for(unsigned int i=0; i<_pbm.get_dimension()-1; i++)
        {
            sum += pow(100 * (_position[i+1] - pow(_position[i], 2)), 2) + pow(_position[i]-1, 2);
        }

        _current_fitness = sum;
        break;

      case 2 : //Rastrigin
        sum = 10 * _pbm.get_dimension();
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
        {
            sum += pow(_position[i], 2) - 10*cos(2*M_PI*_position[i]);
        }

        _current_fitness = sum;
        break;

      case 3 : //Ackley
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
        {
            tmp1 += pow(_position[i], 2);
        }

        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
        {
            tmp2 += cos(2*M_PI*_position[i]);
        }

        sum += -20 * exp(-0.2 * sqrt((1./_pbm.get_dimension())*tmp1));
        sum -= exp((1./_pbm.get_dimension())*tmp2);
        sum += 20 + exp(1);

        _current_fitness = sum;
        break;

      case 4 : //Schwefel
        for(unsigned int i=0; i<_pbm.get_dimension(); i++)
        {
            tmp1 += _position[i] * sin(sqrt(abs(_position[i])));
        }
        sum += 418.9829 * _pbm.get_dimension() - tmp1 ;

        _current_fitness = sum;
        break;

      case 5 : //Schaffer
        sum += 0.5 +
        ( pow(sin(pow(_position[0],2)-pow(_position[1],2)),2)  - 0.5 ) / (pow(1+0.001 * (pow(_position[0],2)+pow(_position[1],2)),2));

        _current_fitness = sum;
        break;

      case 6 : //Weierstrass
        for(unsigned int i=0; i<500; i++) //0 Ã  infini
        {
            sum += pow(0.7, i) * cos ( pow(3, i) * M_PI * _position[0]);
        }

        _current_fitness = sum;
        break;
    }
}

void Solution::add_position(double sol)
{
    _position.push_back(sol);
}

void Solution::delete_position()
{
    _position.pop_back();
}

/* GETTER */

const Problem& Solution::get_pbm() const
{
    return _pbm;
}

double Solution::get_current_fitness() const
{
    return _current_fitness;
}

double Solution::get_mass() const
{
    return _mass;
}

unsigned int Solution::get_size() const
{
    return _position.size();
}

double Solution::get_position(const int index) const
{
    return _position[index];
}

double Solution::get_velocity(const int index) const
{
    return _velocity[index];
}

double Solution::get_acceleration(const int index) const
{
    return _acceleration[index];
}

/* SETTER */

void Solution::set_current_fitness(double fit)
{
    _current_fitness = fit;
}

void Solution::set_mass(double mass)
{
    _mass = mass;
}

void Solution::set_position(const int index, const double val)
{
    _position[index] = val;
}


/* OPERATEURS DE FLUX */

std::ostream& operator<<(std::ostream& os, const Solution& sol)
{
    os << "Fitness actuelle : " << sol.get_current_fitness() << endl;

    return os;
 }

Solution& Solution::operator=(const Solution &sol)
{
    _position = sol._position;
    _current_fitness = sol._current_fitness;
    _mass = sol._mass;
    _velocity = sol._velocity;
    _acceleration = sol._acceleration;

    return *this;
}
