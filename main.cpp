#include <iostream>

#include "SetUpParams.h"

using std::cout;
using std::endl;

int main()
{
    SetUpParams params{};
    cout << params << endl;
    params.edit_params();
    cout << endl << params << endl;



    return 0;
}
