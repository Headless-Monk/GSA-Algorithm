#include "MyAlgorithm.h"

MyAlgorithm::MyAlgorithm(const Problem& pbm, const SetUpParams& setup):
        _pbm{pbm}, _setup{setup}
{}


MyAlgorithm::~MyAlgorithm()
{}

void MyAlgorithm::evolution(int iter)
{
    if(iter > 0)
    {
        /* évaluation des individus */
        spaceBound();
        evaluate(); //call for evaluation of each objective function (Solution::fitness)

        if(/*minimisation*/)
        {
            //cherche le minimum de l'it�ration
        }
        else if(/*maximisation*/)
        {
            //cherche le maximum de l'it�ration
        }

        //cherche si meilleur que best_cost
        //calcule la nouvelle moyenne dans average_cost



        /* �volution vers nouvelle g�n�ration */
        for(/*each solution*/)
            Solution.mass_calculation();




        evolution(iter-1);
    }
}
