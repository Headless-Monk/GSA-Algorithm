#include "Solution.h"

#ifndef M_PI
    #define M_PI 3.1415926535897932384626
#endif

Solution::Solution(const Problem& pbm):
        _pbm{pbm}
{}

Solution::~Solution()
{}

double Solution::fitness()
{
    double sum = 0;

    double tmp1 = 0;
    double tmp2 = 0;

    switch(_pbm.get_num_pbm())
    {
      case 1 : //Rosenbrock
        for(int i=1; i<_pbm.get_dimension(); i++)
        {
            sum += pow(100 * (i+1 - pow(i, 2)), 2) + pow(i-1, 2);
        }
        break;

      case 2 : //Rastrigin
        sum = 10 * _pbm.get_dimension();
        for(int i=1; i<=_pbm.get_dimension(); i++)
        {
            sum += pow(i, 2) - 10*cos(2*M_PI*i);
        }
        break;

      case 3 : //Ackley
        for(int i=1; i<=_pbm.get_dimension(); i++)
        {
            tmp1 += pow(i, 2);
        }

        for(int i=1; i<=_pbm.get_dimension(); i++)
        {
            tmp2 += cos(2*M_PI*i);
        }

        sum += -20 * exp(-0.2 * sqrt((1/_pbm.get_dimension())*tmp1));
        sum -= exp((1/_pbm.get_dimension())*tmp2);
        sum += 20 + exp(1);
        break;

      case 4 : //Schwefel
        for(int i=1; i<=_pbm.get_dimension(); i++)
        {
            tmp1 += i * sin(sqrt(i));
        }
        sum += 418.9829 * _pbm.get_dimension() - tmp1 ;
        break;

      case 5 : //Schaffer
        sum += 0.5 +
        ( pow(sin(pow(1,2)-pow(2,2)),2)  - 0.5 ) / (pow(1+0.001 * (pow(1,2)+pow(2,2)),2));
        break;

      case 6 : //Weierstrass -> à corriger
        for(int i=0; i<=_pbm.get_dimension(); i++)
        {
            sum += pow(0.7, i) * cos ( pow(0.025 * i , i) * M_PI * i);
        }
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

point Solution::get_position() const
{
    return _position;
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

void Solution::set_position(point pos)
{
    _position = pos;
}

void Solution::set_position_X(int x)
{
    _position.x = x;
}

void Solution::set_position_Y(int y)
{
    _position.y = y;
}

/* OPERATEURS DE FLUX */

std::ostream& operator<<(std::ostream& os, const Solution& sol)
{
    os << "Velocite         : " << sol.get_velocity() << endl;
    os << "Acceleration     : " << sol.get_acceleration() << endl;
    os << "Masse            : " << sol.get_mass() << endl;
    os << "Position         : " << sol.get_position().x << "," << sol.get_position().y << endl;
    os << "Fitness actuelle : " << sol.get_current_fitness();
 }

std::istream&  operator>>(std::istream& is, Solution& sol)
{
    cout << "Entrez les valeurs sous la forme (velocite;acceleration;masse;position_x;position_y;fitness)" << endl;

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
        sol.set_position_X((int)tmp);
    is >> c;

    is >> tmp;
        sol.set_position_Y((int)tmp);
    is >> c;

    is >> tmp;
        sol.set_current_fitness(tmp);
    is >> c;
}

std::vector<double>& Solution::get_solution()
{
    return _solution;
}

void Solution::add_solution(double sol)
{
    _solution.push_back(sol);
}

void Solution::delete_solution()
{
    _solution.pop_back();
}










