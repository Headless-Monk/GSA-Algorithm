#include "MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup):
        _pbm{pbm}, _setup{setup}, _solutions{}
{
    for(unsigned int i = 0; i < _pbm.get_dimension(); i++)
        _solutions.push_back(new Solution{});
}

MyAlgorithm::~MyAlgorithm()
{
    for(unsigned int i = 0; i < _solutions.size(); i++)
        delete _solutions[i];
}

void MyAlgorithm::evolution(int iter)
{
    if(iter > 0)
    {
        /* évaluation des individus */
        //spaceBound();
        //evaluate(); call for evaluation of each objective function (Solution::fitness)

        /*if(minimisation)
        {
            cherche le minimum de l'it�ration
        }
        else if(maximisation)
        {
            cherche le maximum de l'it�ration
        } */

        //cherche si meilleur que best_cost
        //calcule la nouvelle moyenne dans average_cost

        /* �volution vers nouvelle g�n�ration */
        /*for(each solution)
            Solution.mass_calculation();*/

        evolution(iter-1);
    }
}

void MyAlgorithm::initialize()
{
    for(int i = 0; i < _pbm.get_dimension(); i++)
        _solutions[i].initialize();
}

void MyAlgorithm::upper_cost()
{
    for(unsigned int i = 0; i < _solutions.size(); i++)
        if(_solutions[i].get_current_fitness() > _upper_cost)
            _upper_cost = _solutions[i].get_current_fitness();
}

void MyAlgorithm::lower_cost()
{
    for(unsigned int i = 0; i < _solutions.size(); i++)
        if(_solutions[i].get_current_fitness() > _lower_cost)
            _lower_cost = _solutions[i].get_current_fitness();
}

void MyAlgorithm::best_cost_overall() const
{
    if(_upper_cost > _best_cost_overall)
        _best_cost_overall = _upper_cost;
}
