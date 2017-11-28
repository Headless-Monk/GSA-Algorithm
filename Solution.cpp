#include "Solution.h"

#ifndef M_PI
    #define M_PI 3.1415926535897932384626
#endif

Solution::Solution(const Problem& pbm):
        _pbm{pbm}
{}

Solution::~Solution()
{}

void Solution::initialize()
{
    _position.resize(_pbm.get_dimension());
    for(int i=0; i<_position.size(); i++)
        _position[i] = ( (double)rand() / RAND_MAX ) * ( _pbm.get_UpperLimit() - _pbm.get_LowerLimit() ) + _pbm.get_LowerLimit();
    _mass = 0;
    _velocity = 0;
}

void Solution::inertia_mass_calculation(double mass_sum)
{
    _inertia_mass = _mass / mass_sum;
}


void Solution::mass_calculation(const Solution &minFit, const Solution &maxFit)
{
    if(minFit._current_fitness == maxFit._current_fitness)
        _mass = 1;
    else
    {
        double best, worst;
        if(_pbm.get_direction() == 1)
        {
            best = minFit._current_fitness;
            worst = maxFit._current_fitness;
        }
        else
        {
            best = maxFit._current_fitness;
            worst = minFit._current_fitness;
        }
        _mass = (_current_fitness - worst) / (best - worst);
    }
}

double Solution::force_calculation(Solution &Sol, double g)
{
    double sum = 0;
    for(unsigned int i = 0; i < _position.size(); i++)
    {
        sum += pow(Sol._position[i] - _position[i], 2);
    }
    sum = sqrt(sum);
}


/*
A FINIR RRRRRRRRRRRRRRRRR
questions :
- c'est quoi les rand ?
- c'est quoi les d ?
- lui demander pour le bordel de force calculat°
*/
void Solution::total_force_calculation(std::vector<Solution*> v, double g)
{
    _total_force = 0;
    for(unsigned int i = 0; i < v.size(); i++)
    {
        _total_force += (/*rand*/1 * force_calculation(*v[i],g));
    }
}

void Solution::acceleration_calculation()
{
    _acceleration = _total_force/_inertia_mass;
}

void Solution::update_solution()
{
    _velocity = /*rand*/1 * _velocity + _acceleration;
    for(unsigned int i = 0; i < _position.size(); i++)
        _position[i] = /*rand*/1 * _velocity + _acceleration;
}

double Solution::fitness()
{
    double sum = 0;

    double tmp1 = 0;
    double tmp2 = 0;

    switch(_pbm.get_num_pbm())
    {
      case 1 : //Rosenbrock
        for(int i=0; i<_position.size()-1; i++)
        {
            sum += pow(100 * (_position[i+1] - pow(_position[i], 2)), 2) + pow(_position[i]-1, 2);
            //std::cout << pow(_position[i]-1, 2) << " ; " << std::endl;
        }

        _current_fitness = sum;
        break;

      case 2 : //Rastrigin
        sum = 10 * _position.size();
        for(int i=0; i<_position.size(); i++)
        {
            sum += pow(_position[i], 2) - 10*cos(2*M_PI*_position[i]);
        }

        _current_fitness = sum;
        break;

      case 3 : //Ackley
        for(int i=0; i<_position.size(); i++)
        {
            tmp1 += pow(_position[i], 2);
        }

        for(int i=0; i<_position.size(); i++)
        {
            tmp2 += cos(2*M_PI*_position[i]);
        }

        sum += -20 * exp(-0.2 * sqrt((1./_position.size())*tmp1));
        sum -= exp((1./_position.size())*tmp2);
        sum += 20 + exp(1);

        _current_fitness = sum;
        break;

      case 4 : //Schwefel
        for(int i=0; i<_position.size(); i++)
        {
            tmp1 += _position[i] * sin(sqrt(abs(_position[i])));
        }
        sum += 418.9829 * _position.size() - tmp1 ;

        _current_fitness = sum;
        break;

      case 5 : //Schaffer
        sum += 0.5 +
        ( pow(sin(pow(_position[0],2)-pow(_position[1],2)),2)  - 0.5 ) / (pow(1+0.001 * (pow(_position[0],2)+pow(_position[1],2)),2));

        _current_fitness = sum;
        break;

      case 6 : //Weierstrass
        for(int i=0; i<500; i++) //0 à infini
        {
            sum += pow(0.7, i) * cos ( pow(3, i) * M_PI * _position[0]);
        }

        _current_fitness = sum;
        break;
    }
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

double Solution::get_velocity() const
{
    return _velocity;
}

double Solution::get_acceleration() const
{
    return _acceleration;
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

/* SETTER */

void Solution::set_current_fitness(double fit)
{
    _current_fitness = fit;
}

void Solution::set_velocity(double velocity)
{
    _velocity = velocity;
}

void Solution::set_acceleration(double acceleration)
{
    _acceleration = acceleration;
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
    os << "Velocite         : " << sol.get_velocity() << endl;
    os << "Acceleration     : " << sol.get_acceleration() << endl;
    os << "Masse            : " << sol.get_mass() << endl;
    os << "Fitness actuelle : " << sol.get_current_fitness() << endl;
    os << "Positions        : ";
    for(int i=0; i<sol.get_size(); i++)
        os << sol.get_position(i) << " ";
    os << endl;
 }

std::istream&  operator>>(std::istream& is, Solution& sol)
{
    cout << "Entrez les valeurs sous la forme (velocite;acceleration;masse;fitness)" << endl;

    char c;
    double tmp;
    is >> c;

    is >> tmp;
        sol.set_velocity(tmp);
    is >> c;

    is >> tmp;
        sol.set_acceleration(tmp);
    is >> c;

    is >> tmp;
        sol.set_mass(tmp);
    is >> c;

    is >> tmp;
        sol.set_current_fitness(tmp);
    is >> c;
}

void Solution::add_position(double sol)
{
    _position.push_back(sol);
}

void Solution::delete_position()
{
    _position.pop_back();
}
