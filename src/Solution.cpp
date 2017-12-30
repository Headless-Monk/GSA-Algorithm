#include "Solution.h"

#ifndef M_PI
    #define M_PI 3.1415926535897932384626
#endif

/**
  Constructeur de solution
	@param[in] pbm - probleme
*/
Solution::Solution(const Problem& pbm):
        _pbm{pbm},
		_position{}, 
		_current_fitness{0}, 
		_mass{0}, 
		_inertia_mass{0}
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
  Initialise la position de toutes les solutions avec un nombre aleatoire compris entre les bornes du probleme
*/
void Solution::initialize()
{
    for(unsigned int i=0; i<_pbm.get_dimension(); i++)
        _position[i] = ( (double)rand() / RAND_MAX ) * ( _pbm.get_UpperLimit() - _pbm.get_LowerLimit() ) + _pbm.get_LowerLimit();
}

/**
  Calcule la masse gravitationnelle d'une planete en fonction de la fitness maximale et minimale
	@param[in] *minFit - Solution*
	@param[in] *maxFit - Solution*
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

void Solution::inertia_mass_calculation(double mass_sum)
{
    _inertia_mass = _mass / mass_sum;
}

/**
  Calcule l'acceleration d'une solution en fonction des autres solutions du probleme et d'une constante gravitationnelle g
	@param[in] v - vector<Solution*>
	@param[in] g - double
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
                _acceleration[k] += ( (r * g * v[j]->_inertia_mass * (v[j]->_position[k] - _position[k])) / (distance + e) );
            }
        }
    }
}

/**
  Met a jour la velocite et la position en fonction des valeurs precedentes et de l'acceleration
*/
void Solution::update_solution()
{
    for(unsigned int i = 0; i < _pbm.get_dimension(); i++)
    {
        _velocity[i] = ((double)rand() / RAND_MAX) * _velocity[i] + _acceleration[i];
        _position[i] = _position[i] + _velocity[i];
    }
}

/**
  Verifie que les positions de la solution se trouvent dans les limites de la fonction objective
	@param[out] Vrai/Faux - bool
*/
bool Solution::check_boundaries()
{
  for(unsigned int i=0; i<_pbm.get_dimension(); i++)
    if(_position[i]>_pbm.get_UpperLimit() || _position[i]<_pbm.get_LowerLimit())
      return false;
  return true;
}

/**
  Calcule et modifie la fitness courante de la solution
*/
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

/**
  Ajoute une dimension au vecteur position de valeur pos à la suite des autres
	@param[in] sol - double
*/
void Solution::add_position(double pos)
{
    _position.push_back(pos);
}

/**
  Supprime la derniere dimension du vecteur position
*/
void Solution::delete_position()
{
    _position.pop_back();
}

/* GETTER */

/**
  Retourne le probleme contenu dans une solution
  @param[out] pbm - Problem
*/
const Problem& Solution::get_pbm() const
{
    return _pbm;
}

/**
  Retourne la fitness actuelle d'une solution
  @param[out] fitness - double
*/
double Solution::get_current_fitness() const
{
    return _current_fitness;
}

/**
  Retourne la masse d'une solution
  @param[out] masse - double
*/
double Solution::get_mass() const
{
    return _mass;
}

double Solution::get_inertia_mass() const
{
    return _inertia_mass;
}

/**
  Retourne la taille du vecteur position d'une solution
  @param[out] taille - int
*/
unsigned int Solution::get_size() const
{
    return _position.size();
}

/**
  Retourne la valeur de la position d'une solution pour un index donnee
  @param[in] index - int
  @param[out] position - double
*/
double Solution::get_position(const int index) const
{
    return _position[index];
}

/**
  Retourne la valeur de la vitesse d'une solution pour un index donnee
  @param[in] index - int
  @param[out] vitesse - double
*/
double Solution::get_velocity(const int index) const
{
    return _velocity[index];
}

/**
  Retourne la valeur de l'acceleration d'une solution pour un index donnee
  @param[in] index - int
  @param[out] acceleration - double
*/
double Solution::get_acceleration(const int index) const
{
    return _acceleration[index];
}

/* SETTER */

/**
  Modifie la valeur de la fitness actuelle d'une solution
  @param[in] fit - double
*/
void Solution::set_current_fitness(double fit)
{
    _current_fitness = fit;
}

/**
  Modifie la valeur de la masse d'une solution
  @param[in] mass - double
*/
void Solution::set_mass(double mass)
{
    _mass = mass;
}

/**
  Modifie la valeur de la position d'une solution à une dimension donnee
  @param[in] pos - double
  @param[in] index - int
*/
void Solution::set_position(const int index, const double pos)
{
    _position[index] = pos;
}


/* OPERATEURS DE FLUX */

/**
  Affiche sur le flux passe en parametre toutes les informations de la solution
  @param[in] os - ostream
  @param[in] sol - Solution
  @param[out] os - ostream
*/
std::ostream& operator<<(std::ostream& os, const Solution& sol)
{
    os << "Fitness actuelle : " << sol.get_current_fitness() << endl;

    return os;
 }

/**
  Recopie la solution passee en parametre dans la solution actuelle
  @param[in] sol - Solution
  @param[out] sol - Solution
*/
Solution& Solution::operator=(const Solution &sol)
{
    _position = sol._position;
    _current_fitness = sol._current_fitness;
    _mass = sol._mass;
    _inertia_mass = sol._inertia_mass;
    _velocity = sol._velocity;
    _acceleration = sol._acceleration;

    return *this;
}
